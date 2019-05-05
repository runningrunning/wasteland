// BETTER SOLUTION ?????? !!!!
// TODO FIND BETTER ONE!!
// use my tree to do
// forget to how to write treap ???
// my treap way ?

int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

typedef struct _Node {
    long v;
    int i;
    int p; // priority
    struct _Node* l;
    struct _Node* r;
} Node;

Node* cNode(int v, int i, int p)
{
    Node* n = malloc(sizeof(Node));
    n->v = v;
    n->i = i;
    n->p = p;
    n->l = n->r = NULL;
    return n;
}

void aTree(Node** r, long v, int i, int p)
{
    if (*r == NULL)
    {
        *r = cNode(v, i, p);
        return;
    }

    Node* c = *r;

    if (v == c->v)
    {
        c->i = i;
        return;
    }

    if (v < c->v)
    {
        c->i = i;
        aTree(&(c->l), v, i, p);
        if (c->p > c->l->p)
        {
            Node* t = c->l; // t should be its child
            c->l = t->r;
            t->r = c;
            *r = t;
        }
    }
    else
    {
        aTree(&(c->r), v, i, p);
        if (c->p > c->r->p)
        {
            Node* t = c->r; // t should be its child
            c->r = t->l;
            t->l = c;
            *r = t;
        }
    }
}

int fTree(Node* r, int v)
{
    if (!r)
        return -1;

    if (r->v == v)
        return r->i;

    if (r->v > v)
        return fTree(r->l, v);

    // must find the max i of r->v <= v !!!!
    int i = fTree(r->r, v);
    return r->i > i ? r->i : i;
}

int shortestSubarray(int* A, int ASize, int K)
{
    Node* r = NULL;

    int min = INT_MAX;
    long p = 0;
    int pri = ((long) A) & 0xFFFFFFFF;
    aTree(&r, 0, 0, pri);

    for (int i = 0; i < ASize; i ++)
    {
        p += A[i];
        int f = fTree(r, p - K);
        if (f != -1 && min > i + 1 - f)
            min = i + 1 - f;
        pri = _random(pri);
        aTree(&r, p, i + 1, pri);
    }
    return min == INT_MAX ? -1 : min;
}
