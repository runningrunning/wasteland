// recursion version !!!!, no need to update parent version
// prefix version
// version to print tree structure !!!!!
#define TEST 10
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
    struct _TreapNode* p;
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

void rotate_up(Treap* t, TreapNode* i)
{
    while (i->p)
    {
        if (i->p->h <= i->h)
            break;

        TreapNode* ip = i->p;
        TreapNode* ipp = i->p->p;

        i->p->p = i;

        // left
        if (i == i->p->l)
        {
            i->p->l = i->r;
            i->r = i->p;
            i->p = ipp;
        }
        else // right
        {
            i->p->r = i->l;
            i->l = i->p;
            i->p = ipp;
        }

        if (ipp)
        {
            if (ip == ipp->l)
                ipp->l = i;
            else
                ipp->r = i;
        }
        else
        {
            t->r = i;
        }
    }
}

void rotate_down_remove(Treap* t, TreapNode* i)
{
    while (i->l || i->r)
    {
        TreapNode* ni;
        TreapNode* ip = i->p;
        if ((i->l && i->r && i->l->h < i->r->h) || !i->r)
        {
            // right rotate
            ni = i->l;
            i->l = ni->r;
            ni->r = i;
            ni->p = ip;
            i->p = ni;
        }
        else // left rotate
        {
            ni = i->r;
            i->r = ni->l;
            ni->l = i;
            ni->p = ip;
            i->p = ni;
        }

        if (ip)
        {
            if (i == ip->l)
                ip->l = ni;
            else
                ip->r = ni;
        }
        else
        {
            t->r = ni;
        }
    }

    if (!i->p)
        t->r = NULL;
    else
    {
        if (i->p->l == i)
            i->p->l = NULL;
        else
            i->p->r = NULL;
    }
}

void insertTreap(Treap* t, int k)
{
    TreapNode* n = malloc(sizeof(TreapNode));
    n->k = k;
    n->h = t->random_x;
    n->l = n->r = n->p = NULL;
    t->random_x = treap_random(t->random_x);

    TreapNode* p = NULL;
    TreapNode** in = &t->r;
    while ((*in))
    {
        p = *in;
        if (k <= (*in)->k)
            in = &(*in)->l;
        else
            in = &(*in)->r;
    }
    n->p = p;
    *in = n;
    rotate_up(t, *in);
}

void removeTreap(Treap* t, int k)
{
    TreapNode* r = t->r;
    while (r)
    {
        if (r->k == k)
            break;
        if (r->k > k)
            r = r->l;
        else
            r = r->r;
    }

    if (r)
    {
        r->h = INT_MAX;
        rotate_down_remove(t, r);
    }
}

void outTreap(TreapNode* t, int i, int* l)
{
    if (t)
    {
        printf("(%d:%d ", t->k, t->h);
        outTreap(t->l, i + 1, l);
        outTreap(t->r, i + 1, l);
        printf(")");
    }
    else
    {
        if (i > (*l))
            *l = i;
        printf(" NULL ");
    }
}

void test()
{
    Treap* t = createTreap();

    for (int i = 0; i < TEST; i ++)
    {
        printf("===============%d======================\n", i);

        insertTreap(t, i);
        int l = 0;
        outTreap(t->r, 0, &l);
        printf("\n");

        // printf("ADD Treap Level %d %d.\n", i, l);
    }

    for (int i = 0; i < TEST; i ++)
    {
        printf("---------------%d----------------------\n", i);
        removeTreap(t, i);
        int l = 0;
        outTreap(t->r, 0, &l);
        printf("\n");

        // printf("Remove Treap Level %d %d.\n", i, l);
    }

    if (t->r)
        printf("t->r is NOT NULL.\n");

}
