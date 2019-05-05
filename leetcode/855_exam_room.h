// think too complicate ????
// TOO MUCH ERRORS !!!!!
// CLEAR MIND !!!
// THINK TOO MUCH !!!
// heap can remove from the middle ?
// clear mind !!
typedef struct {
    int i;
    int l;
    int r;
    int s;
} Node;

typedef struct
{
    int x;
    Node* l;
    Node* r;
} HashNode;

typedef struct{
    HashNode** h;
    int c;
    int n;
} HNode;

#define PRIME 16411
typedef struct {
    int n;
    int hn;
    int hi;
    Node** heap;
    HNode** hash;
} ExamRoom;

void _cals(Node* n, int size)
{
    if (n->l == INT_MIN && n->r == INT_MAX)
        n->s = size;
    else if (n->l == INT_MIN)
        n->s = n->r;
    else if (n->r == INT_MAX)
        n->s = size - 1 - n->l;
    else
        n->s = (n->r - n->l) / 2;
}

Node* _mNode(int l, int r, int size)
{
    Node* n = malloc(sizeof(Node));
    n->l = l;
    n->r = r;
    _cals(n, size);
    return n;
}

bool _big(Node* x, Node* y)
{
    return x->s > y->s || (x->s == y->s && x->l < y->l);
}

void _aHeap(ExamRoom* e, Node* n)
{
    if (e->hi == e->hn)
    {
        e->heap = realloc(e->heap, sizeof(Node*) * (e->hn + 2048));
        e->hn += 2048;
    }

    Node** heap = e->heap;
    heap[e->hi] = n;
    n->i = e->hi;

    // printf("add heap %d.\n", e->hi);
    e->hi ++;

    if (e->hi == 1)
        return;

    // printf("heap 0 is %p %d %d %d.\n", heap[0], heap[0]->l, heap[0]->r, heap[0]->s);

    int x = e->hi - 1;
    while (x)
    {
        int p = (x - 1) / 2;
        // printf("p%d p->l %d p->r %d p->s %d, n->l %d n->r %d n->s %d.\n", p, heap[p]->l, heap[p]->r, heap[p]->s, n->l, n->r, n->s);
        if (_big(heap[p], n))
            break;

        heap[x] = heap[p];
        heap[p] = n;
        heap[x]->i = x;
        heap[p]->i = p;
        x = p;
    }
}

void _balance(ExamRoom* e, int i)
{
    Node** heap = e->heap;
    int hi = e->hi;
    int x = i;
    Node* p = heap[i];

    while (x * 2 + 1 < hi)
    {
        Node* l = heap[x * 2 + 1];
        Node* r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l == r || _big(l, r))
        {
            if (_big(p, l))
                break;
            heap[x] = l;
            heap[x]->i = x;
            heap[x * 2 + 1] = p;
            heap[x * 2 + 1]->i = x * 2 + 1;
            x = x * 2 + 1;
        }
        else
        {
            if (_big(p, r))
                break;

            heap[x] = r;
            heap[x]->i = x;
            heap[x * 2 + 2] = p;
            heap[x * 2 + 2]->i = x * 2 + 2;
            x = x * 2 + 2;
        }
    }
}

void _remove(ExamRoom* e, Node* r)
{
    // printf("remove %p %d %d %d %d.\n", r, r->i, r->s, r->l, r->r);
    Node** heap = e->heap;
    e->hi --;
    int x = r->i;
    heap[x] = heap[e->hi];
    heap[x]->i = x;
    _balance(e, x);
}

void _updateHash(HNode** hash, int x, Node* l, Node* r)
{
    int ox = x;
    x = x % PRIME;
    if (hash[x])
    {
        bool insert = true;
        HNode* h = hash[x];
        for (int i = 0; i < h->c; i ++)
        {
            HashNode* hh = h->h[i];
            if (hh->x == ox)
            {
                insert = false;
                if (l)
                    hh->l = l;
                if (r)
                    hh->r = r;
            }
        }

        if (insert)
        {
            if (h->c == h->n)
            {
                h->h = realloc(h->h, sizeof(HashNode*) * (h->n + 10));
                h->n += 10;
            }

            HashNode* hh = malloc(sizeof(HashNode));
            h->h[h->c] = hh;
            hh->x = ox;
            hh->l = hh->r = NULL;
            if (l)
                hh->l = l;
            if (r)
                hh->r = r;
            h->c ++;
        }
    }
    else
    {
        HNode* h = malloc(sizeof(HNode) * 20);
        hash[x] = h;
        h->n = 20;
        h->c = 1;
        h->h = malloc(sizeof(HashNode*));
        HashNode* hh = malloc(sizeof(HashNode));
        h->h[0] = hh;
        hh->x = ox;
        hh->l = hh->r = NULL;

        if (l)
            hh->l = l;
        if (r)
            hh->r = r;
    }
}

void _leave(ExamRoom* e, int x)
{
    int ox = x;
    x %= PRIME;
    HNode** hash = e->hash;
    HNode* h = hash[x];

    Node* l = NULL;
    Node* r = NULL;

    if (!h)
        return;

    for (int i = 0; i < h->c; i ++)
    {
        HashNode* hh = h->h[i];
        if (hh->x == ox)
        {
            l = hh->l;
            r = hh->r;
            h->c --;
            h->h[i] = h->h[h->c];
            break;
        }
    }

    int _l = l == NULL ? INT_MIN : l->l;
    int _r = r == NULL ? INT_MAX : r->r;
    if (l)
        _remove(e, l);
    if (r)
        _remove(e, r);

    int s;

    // printf("leave %d. %p %p %d %d.\n", x, l, r, _l, _r);
    Node* nr = _mNode(_l, _r, e->n);
    // printf("add nr l %d r %d s %d.\n", nr->l, nr->r, nr->s);
    _aHeap(e, nr);
    // printf("add nr in %d %d %d %d %d.\n", nr->i, e->heap[nr->i]->i, e->heap[nr->i]->l, e->heap[nr->i]->r, e->heap[nr->i]->s);
    if (l && _l != INT_MIN)
        _updateHash(e->hash, _l, NULL, nr);
    if (r && _r != INT_MAX)
        _updateHash(e->hash, _r, nr, NULL);
}

int _seat(ExamRoom* e)
{
    Node** heap = e->heap;
    Node* n = heap[0];

    // printf("n %p n n->l %d n->r %d n->s %d.\n", n, n->l, n->r, n->s);
    if (n->l == INT_MIN && n->r == INT_MAX)
    {
        n->l = 0;
        _cals(n, e->n);
        _updateHash(e->hash, n->l, NULL, n);
        return 0;
    }

    if (n->l == INT_MIN)
    {
        n->l = 0;
        _cals(n, e->n);
        _balance(e, 0);
        _updateHash(e->hash, n->l, NULL, n);
        _updateHash(e->hash, n->r, n, NULL);
        return 0;
    }

    if (n->r == INT_MAX)
    {
        n->r = e->n - 1;
        _cals(n, e->n);
        _balance(e, 0);
        _updateHash(e->hash, n->l, NULL, n);
        _updateHash(e->hash, n->r, n, NULL);
        return n->r;
    }

    int l = n->l;
    int r = n->r;
    int nr = (r - l) / 2 + l;
    n->r = nr;
    n->s = (nr - l) / 2;

    _balance(e, 0);
    // printf("seat n %p l %d r %d s %d %d.\n", n, n->l, n->r, n->s, n->i);
    Node* _nl = n;
    Node* _nr = _mNode(nr, r, e->n);
    _aHeap(e, _nr);
    // printf("seat new nr %p l %d r %d s %d %d.\n", _nr, _nr->l, _nr->r, _nr->s, _nr->i);
    _updateHash(e->hash, l, NULL, _nl);
    _updateHash(e->hash, r, _nr, NULL);
    _updateHash(e->hash, nr, _nl, _nr);


    return nr;
}

ExamRoom* examRoomCreate(int N) {
    ExamRoom* e = malloc(sizeof(ExamRoom));
    e->n = N;
    e->hash = calloc(sizeof(HNode*), PRIME);
    e->hn = 2048;
    e->hi = 0;
    e->heap = malloc(sizeof(Node*) * e->hn);
    _aHeap(e, _mNode(INT_MIN, INT_MAX, N));
    return e;
}

int examRoomSeat(ExamRoom* obj) {
    if (obj)
        return _seat(obj);
    return 0;
}

void examRoomLeave(ExamRoom* obj, int p) {
    if (obj)
        _leave(obj, p);
}

void examRoomFree(ExamRoom* obj) {
    if (obj)
    {
        free(obj->heap);
        free(obj->hash);
        free(obj);
    }
}

/**
 * Your ExamRoom struct will be instantiated and called as such:
 * struct ExamRoom* obj = examRoomCreate(N);
 * int param_1 = examRoomSeat(obj);
 * examRoomLeave(obj, p);
 * examRoomFree(obj);
 */

/**
 * Your ExamRoom struct will be instantiated and called as such:
 * struct ExamRoom* obj = examRoomCreate(N);
 * int param_1 = examRoomSeat(obj);
 * examRoomLeave(obj, p);
 * examRoomFree(obj);
 */

/*
// think too complicate ????
// THINK TOO MUCH !!!
// heap can remove from the middle ?
// clear mind !!
typedef struct {
    int i;
    int l;
    int r;
    int s;
} Node;

typedef struct
{
    int x;
    Node* l;
    Node* r;
} HashNode;

typedef struct{
    HashNode** h;
    int c;
    int n;
} HNode;

#define PRIME 16411
typedef struct {
    int n;
    int hn;
    int hi;
    Node** heap;
    HNode** hash;
} ExamRoom;

Node* _mNode(int l, int r, int s)
{
    Node* n = malloc(sizeof(Node));
    n->l = l;
    n->r = r;
    n->s = (s + 1) / 2;
    // printf("%p set ns is %d.\n", n, n->s);
    return n;
}

bool _big(Node* x, Node* y)
{
    return x->s > y->s || (x->s == y->s && x->l < y->l);
}

void _aHeap(ExamRoom* e, Node* n)
{
    if (e->hi == e->hn)
    {
        e->heap = realloc(e->heap, sizeof(Node*) * (e->hn + 1024));
        e->hn += 1024;
    }
    Node** heap = e->heap;
    heap[e->hi] = n;
    n->i = e->hi;
    e->hi ++;

    if (e->hi == 1)
        return;

    int x = e->hi - 1;
    while (x)
    {
        int p = (x - 1) / 2;
        if (_big(heap[p], n))
            break;

        heap[x] = heap[p];
        heap[p] = n;
        heap[x]->i = x;
        heap[p]->i = p;
        x = p;
    }
}

void _balance(ExamRoom* e)
{
    Node** heap = e->heap;
    int hi = e->hi;
    int x = 0;
    Node* p = heap[0];

    while (x * 2 + 1 < hi)
    {
        Node* l = heap[x * 2 + 1];
        Node* r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l == r || _big(l, r))
        {
            if (_big(p, l))
                break;
            heap[x] = l;
            heap[x]->i = x;
            heap[x * 2 + 1] = p;
            heap[x * 2 + 1]->i = x * 2 + 1;
            x = x * 2 + 1;
        }
        else
        {
            if (_big(p, r))
                break;

            heap[x] = r;
            heap[x]->i = x;
            heap[x * 2 + 2] = p;
            heap[x * 2 + 1]->i = x * 2 + 2;
            x = x * 2 + 2;
        }
    }
}

void _remove(ExamRoom* e, Node* r)
{
    Node** heap = e->heap;
    e->hi --;
    int x = r->i;
    heap[x] = heap[e->hi];
    Node* p = heap[x];
    int hi = e->hi;
    p->i = x;
    while (x * 2 + 1 < hi)
    {
        Node* l = heap[x * 2 + 1];
        Node* r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l == r || _big(l, r))
        {
            if (_big(p, l))
                break;
            heap[x] = l;
            heap[x]->i = x;
            heap[x * 2 + 1] = p;
            heap[x * 2 + 1]->i = x * 2 + 1;
            x = x * 2 + 1;
        }
        else
        {
            if (_big(p, r))
                break;

            heap[x] = r;
            heap[x]->i = x;
            heap[x * 2 + 2] = p;
            heap[x * 2 + 1]->i = x * 2 + 2;
            x = x * 2 + 2;
        }
    }
}

void _updateHash(HNode** hash, int x, Node* l, Node* r)
{
    // printf("update hash %d %p %p.\n", x, l, r);
    int ox = x;
    x = x % PRIME;
    if (hash[x])
    {
        bool insert = true;
        HNode* h = hash[x];
        for (int i = 0; i < h->c; i ++)
        {
            HashNode* hh = h->h[i];
            if (hh->x == ox)
            {
                insert = false;
                if (l)
                    hh->l = l;
                if (r)
                    hh->r = r;
            }
        }

        if (insert)
        {
            if (h->c == h->n)
            {
                h->h = realloc(h->h, sizeof(HashNode*) * (h->n + 10));
                h->n += 10;
            }

            HashNode* hh = malloc(sizeof(HashNode));
            h->h[h->c] = hh;
            hh->x = ox;
            hh->l = hh->r = NULL;
            if (l)
                hh->l = l;
            if (r)
                hh->r = r;
            h->c ++;
        }
    }
    else
    {
        HNode* h = malloc(sizeof(HNode));
        hash[x] = h;
        h->n = 1;
        h->c = 1;
        h->h = malloc(sizeof(HashNode*));
        HashNode* hh = malloc(sizeof(HashNode));
        h->h[0] = hh;
        hh->x = ox;
        hh->l = hh->r = NULL;

        if (l)
            hh->l = l;
        if (r)
            hh->r = r;
    }
}

void _leave(ExamRoom* e, int x)
{
    int ox = x;
    x %= PRIME;
    HNode** hash = e->hash;
    HNode* h = hash[x];

    if (!h)
        return;

    Node* l = NULL;
    Node* r = NULL;

    for (int i = 0; i < h->c; i ++)
    {
        HashNode* hh = h->h[i];
        if (hh->x == ox)
        {
            l = hh->l;
            r = hh->r;
            h->c --;
            h->h[i] = h->h[h->c];
            break;
        }
    }

    int _l = l == NULL ? INT_MIN : l->l;
    int _r = r == NULL ? INT_MAX : r->r;
    if (l)
        _remove(e, l);
    if (r)
        _remove(e, r);

    int s;

    // printf("--- %d. %p %p %d %d.\n", x, l, r, _l, _r);
    if (!l && !r)
        s = e->n;
    else if (!l)
        s = (_r) * 2;
    else if (!r)
        s = (e->n - _l) * 2;

    Node* nr = _mNode(_l, _r, s);
    // printf("nr %d %d %d.\n", nr->l, nr->r, nr->s);
    _aHeap(e, nr);

    if (l && _l != INT_MIN)
        _updateHash(e->hash, _l, NULL, nr);
    if (r && _r != INT_MAX)
        _updateHash(e->hash, _r, nr, NULL);
}

int _seat(ExamRoom* e)
{
    Node** heap = e->heap;
    Node* n = heap[0];

    // printf("=== %p n->s %d %d %d.\n", n, n->l, n->r, n->s);
    if (n->l == INT_MIN && n->r == INT_MAX)
    {
        n->l = 0;
        // _updateHash(e->hash, n->l, NULL, n);
        return 0;
    }

    if (n->l == INT_MIN)
    {
        n->l = 0;
        n->s = (n->r - n->l) / 2;
        _updateHash(e->hash, n->l, NULL, n);
        _updateHash(e->hash, n->r, n, NULL);
        return 0;
    }

    if (n->r == INT_MAX)
    {
        n->r = e->n - 1;
        n->s = (n->r - n->l) / 2;
        _updateHash(e->hash, n->l, NULL, n);
        _updateHash(e->hash, n->r, n, NULL);
        return n->r;
    }

    int l = n->l;
    int r = n->r;
    int nr = (r - l) / 2 + l;
    n->r = nr;
    n->s = (nr - l) / 2;

    _balance(e);
    Node* _nl = n;
    Node* _nr = _mNode(nr, r, r - nr - 1);
    _aHeap(e, _nr);
    _updateHash(e->hash, l, NULL, _nl);
    _updateHash(e->hash, r, _nr, NULL);
    _updateHash(e->hash, nr, _nl, _nr);

    return nr;
}

ExamRoom* examRoomCreate(int N) {
    ExamRoom* e = malloc(sizeof(ExamRoom));
    e->n = N;
    e->hash = calloc(sizeof(HNode*), PRIME);
    e->hn = 1024;
    e->hi = 0;
    e->heap = malloc(sizeof(Node*) * e->hn);
    _aHeap(e, _mNode(INT_MIN, INT_MAX, N - 1));
    return e;
}

int examRoomSeat(ExamRoom* obj) {
    if (obj)
        return _seat(obj);
    return 0;
}

void examRoomLeave(ExamRoom* obj, int p) {
    if (obj)
        _leave(obj, p);
}

void examRoomFree(ExamRoom* obj) {
    if (obj)
    {
        free(obj->heap);
        free(obj->hash);
        free(obj);
    }
}

*/
