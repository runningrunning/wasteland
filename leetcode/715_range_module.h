// try to use 1e9 segment tree !!!
// try to use dynamic segment tree
// don't remove, just mark it removed
// find better solution
// add INT_MAX and INT_MIN to make it easy
// my own treap tree !
int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

typedef struct _Node {
    int s;
    int e;
    int p; // priority
    bool removed;
    struct _Node* _l;
    struct _Node* _r;
} Node;

typedef struct {
    int p;
    Node* r;
} RangeModule;

void _out(Node* r)
{
    if (r)
    {
        printf("(%d -> %d : %d, ", r->s, r->e, r->removed);
        _out(r->_l);
        _out(r->_r);
        printf(")");
    }
    else
    {
        printf(" NULL ");
    }
}

void _mark(Node* r, int s, int e, bool remove, int* t, int* ti)
{
    if (r)
    {
        if (r->s < e && r->e > s)
        {
            // r->s -- s -- e -- r->e
            if (r->s <= s && r->e >= e)
            {
                *ti = 2;
                if (r->removed != remove)
                {
                    t[0] = r->s;
                    t[1] = s;
                    t[2] = r->removed;

                    t[4] = e;
                    t[5] = r->e;
                    t[6] = r->removed;

                    r->s = s;
                    r->e = e;
                    r->removed = remove;
                }
                else
                {
                    t[0] = t[1] = s;
                    t[4] = t[5] = e;
                }
                return;
            }

            // s -- r->s -- r->e -- e
            if (s <= r->s && e >= r->e)
            {
                if (!(*ti))
                {
                    *ti = 2;
                    t[0] = s;
                    t[1] = r->s;
                    t[2] = remove;

                    t[4] = r->e;
                    t[5] = e;
                    t[6] = remove;
                }
                else
                {
                    if (r->s < t[1])
                        t[1] = r->s;
                    if (r->e > t[4])
                        t[4] = r->e;
                }

                if (r->removed != remove)
                    r->removed = remove;

            }
            // r->s -- s -- r->e -- e
            else if (s >= r->s && s <= r->e && e > r->e)
            {
                if (!(*ti))
                {
                    *ti = 2;
                    if (r->removed != remove)
                    {
                        t[0] = s;
                        t[1] = r->e;
                        t[2] =remove;
                        r->e = s;
                    }
                    else
                    {
                        t[0] = s;
                        t[1] = s;
                    }

                    t[4] = r->e;
                    t[5] = e;
                    t[6] = remove;
                }
                else
                {
                    if (r->removed != remove)
                    {
                        if (r->e < t[1])
                            t[1] = r->e;
                        r->e = s;
                    }
                    else
                    {
                        t[0] = s;
                        t[1] = s;
                    }
                }
            }
            // s -- r->s -- e -- r->e
            else if (e >= r->s && e <= r->e && s < r->s)
            {
                if (!(*ti))
                {
                    *ti = 2;
                    t[0] = s;
                    t[1] = r->s;
                    t[2] = remove;

                    if (r->removed != remove)
                    {
                        t[4] = r->s;
                        t[5] = e;
                        t[6] = remove;
                        r->s = e;
                    }
                    else
                    {
                        t[4] = e;
                        t[5] = e;
                    }
                }
                else
                {
                    if (r->removed != remove)
                    {
                        if (r->s > t[4])
                            t[4] = r->s;
                        r->s = e;
                    }
                    else
                    {
                        t[4] = e;
                        t[5] = e;
                    }
                }
            }
        }

        if (r->e > s)
            _mark(r->_l, s, e, remove, t, ti);
        if (r->s < e)
            _mark(r->_r, s, e, remove, t, ti);
    }
}

void _add(Node** r, Node* n)
{
    if (*r)
    {
        Node* p = *r;

        if (n->s <= p->s)
        {
            _add(&p->_l, n);
            if (p->p > p->_l->p)
            {
                Node* t = p->_l;
                p->_l = t->_r;
                t->_r = p;
                *r = t;
            }
        }
        else
        {
            _add(&p->_r, n);
            if (p->p > p->_r->p)
            {
                Node* t = p->_r;
                p->_r = t->_l;
                t->_l = p;
                *r = t;
            }
        }
    }
    else
        *r = n;
}

bool _query(Node* r, int s, int e)
{
    if (r)
    {
        if (r->s < e && r->e > s)
            if (r->removed)
                return false;

        if (r->e > s && !_query(r->_l, s, e))
            return false;

        if (r->s < e && !_query(r->_r, s, e))
            return false;
    }
    return true;
}


RangeModule* rangeModuleCreate() {
    RangeModule* r = malloc(sizeof(RangeModule));
    r->r = NULL;
    r->p = _random((long) r);
    Node* n = malloc(sizeof(Node));
    n->_l = n->_r = NULL;
    n->removed = true;
    n->s = INT_MIN;
    n->e = INT_MAX;
    n->p = r->p;
    r->p = _random(r->p);
    _add(&r->r, n);
    return r;
}

void rangeModuleAddRange(RangeModule* obj, int left, int right)
{
    if (obj)
    {
        int ti = 0;
        int t[8] = {0};
        _mark(obj->r, left, right, false, t, &ti);
        if (ti)
        {
            for (int i = 0; i < ti; i ++)
            {
                int oi = i * 4;
                if (t[oi] != t[oi + 1])
                {
                    Node* n = malloc(sizeof(Node));
                    n->_l = n->_r = NULL;
                    n->removed = t[oi + 2];
                    n->s = t[oi];
                    n->e = t[oi + 1];
                    n->p = obj->p;
                    obj->p = _random(obj->p);
                    _add(&obj->r, n);
                }
            }
        }
        else
        {
            Node* n = malloc(sizeof(Node));
            n->_l = n->_r = NULL;
            n->removed = false;
            n->s = left;
            n->e = right;
            n->p = obj->p;
            obj->p = _random(obj->p);
            _add(&obj->r, n);
        }
    }
    /* _out(obj->r); */
    /* printf("\n"); */
}

bool rangeModuleQueryRange(RangeModule* obj, int left, int right) {
    return obj ? _query(obj->r, left, right) : false;
}

void rangeModuleRemoveRange(RangeModule* obj, int left, int right) {
    if (obj)
    {
        int ti = 0;
        int t[8] = {0};
        _mark(obj->r, left, right, true, t, &ti);
        if (ti)
        {
            for (int i = 0; i < ti; i ++)
            {
                int oi = i * 4;
                if (t[oi] != t[oi + 1])
                {
                    Node* n = malloc(sizeof(Node));
                    n->_l = n->_r = NULL;
                    n->removed = t[oi + 2];
                    n->s = t[oi];
                    n->e = t[oi + 1];
                    n->p = obj->p;
                    obj->p = _random(obj->p);
                    _add(&obj->r, n);
                }
            }
        }
        else
        {
            Node* n = malloc(sizeof(Node));
            n->_l = n->_r = NULL;
            n->removed = true;
            n->s = left;
            n->e = right;
            n->p = obj->p;
            obj->p = _random(obj->p);
            _add(&obj->r, n);
        }
    }
    /* _out(obj->r); */
    /* printf("\n"); */
}

void rangeModuleFree(RangeModule* obj) {
    if (obj)
        free(obj);
}

/**
 * Your RangeModule struct will be instantiated and called as such:
 * struct RangeModule* obj = rangeModuleCreate();
 * rangeModuleAddRange(obj, left, right);
 * bool param_2 = rangeModuleQueryRange(obj, left, right);
 * rangeModuleRemoveRange(obj, left, right);
 * rangeModuleFree(obj);
 */
