// recursion version !!!!, no need to update parent version
// prefix version
// version to print tree structure !!!!!
// learn a lot !!!
#define TEST 20
#define MAX INT_MAX

int treap_random(long x)
{
    return ((x * 48271L) % MAX) & 0xFFFFFFFF;
}

// treap can also be array !!!
// why store size ? to find the k size number !
// find a way not to store parent node
typedef struct _TreapNode {
    int k;
    int h; // minimum heap
    struct _TreapNode* l;
    struct _TreapNode* r;
} TreapNode;

typedef struct {
    unsigned int random_x;
    TreapNode* r;
} Treap;

Treap* createTreap()
{
    Treap* t = malloc(sizeof(Treap));
    t->random_x = treap_random((long) t);
    t->r = NULL;
    return t;
}

void outTreap(TreapNode* t, int i, int* l)
{
    if (t)
    {
        // printf("(%d:%d ", t->k, t->h);
        outTreap(t->l, i + 1, l);
        outTreap(t->r, i + 1, l);
        // printf(")");
    }
    else
    {
        if (i > (*l))
            *l = i;
        // printf(" NULL ");
    }
}

void _insert(TreapNode** r, TreapNode* i)
{
    if (*r)
    {
        TreapNode* p = *r;

        if (i->k <= p->k)
        {
            _insert(&(p->l), i);
            if (p->l->h < p->h)
            {
                TreapNode* t = p->l;
                p->l = t->r;
                t->r = p;
                *r = t;
            }
        }
        else
        {
            _insert(&(p->r), i);
            if (p->r->h < p->h)
            {
                TreapNode* t = p->r;
                p->r = t->l;
                t->l = p;
                *r = t;
            }
        }
    }
    else
        *r = i;
}

void removeTreap(TreapNode** r, int k)
{
    if (*r)
    {
        TreapNode* p = *r;
        if (p->k < k)
        {
            removeTreap(&(p->r), k);
            if (p->r && p->r->h < p->h)
            {
                TreapNode* t = p->r;
                p->r = t->l;
                t->l = p;
                *r = t;
            }
        }
        else if (p->k > k)
        {
            removeTreap(&(p->l), k);
            if (p->l && p->l->h < p->h)
            {
                TreapNode* t = p->l;
                p->l = t->r;
                t->r = p;
                *r = t;
            }
        }
        else // == // it's WRONG !!!, test this error !
        {
            if (!p->l && !p->r)
                *r = NULL;
            else if (p->l && p->r)
            {
                if (p->l->h < p->r->h)
                {
                    // rotate it down, then do remove
                    TreapNode* t = p->l;
                    p->l = t->r;
                    t->r = p;
                    *r = t;
                    removeTreap(&t->r, k);
                }
                else
                {
                    TreapNode* t = p->r;
                    p->r = t->l;
                    t->l = p;
                    *r = t;
                    removeTreap(&t->l, k);
                }
            }
            else if (p->l)
                *r = p->l;
            else
                *r = p->r;
        }
    }
}

void insertTreap(Treap* t, int k)
{
    TreapNode* n = malloc(sizeof(TreapNode));
    n->k = k;
    n->h = t->random_x;
    n->l = n->r = NULL;
    t->random_x = treap_random(t->random_x);
    _insert(&(t->r), n);
}

void test()
{
    Treap* t = createTreap();

    for (int i = 0; i < TEST; i ++)
    {
        // printf("===============%d======================\n", i);

        insertTreap(t, i);
        int l = 0;
        outTreap(t->r, 0, &l);
        // printf("\n");

        printf("ADD Treap Level %d %d.\n", i, l);
    }

    for (int i = 0; i < TEST; i ++)
    {
        // printf("---------------%d----------------------\n", i);
        removeTreap(&t->r, i);
        int l = 0;
        outTreap(t->r, 0, &l);
        // printf("\n");

        printf("Remove Treap Level %d %d.\n", i, l);
    }

    if (t->r)
        printf("t->r is NOT NULL.\n");

}
