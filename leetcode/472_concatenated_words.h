void facw_sort(int* n, int s, int e, char** w)
{
    if (s >= e)
        return;

    int t;
    char* tw;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        tw = w[s];
        w[s] = w[e];
        w[e] = tw;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            tw = w[s];
            w[s] = w[e];
            w[e] = tw;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            tw = w[i];
            w[i] = w[e];
            w[e] = tw;
        }
    }

    facw_sort(n, cs, e - 1, w);
    facw_sort(n, e + 1, ce, w);
}

#define N 26
typedef struct _Node {
    int e;
    struct _Node* n[N];
} Node;

Node* cNode()
{
    Node* n = malloc(sizeof(Node));
    n->e = 0;
    memset(n->n, 0, sizeof(Node*) * N);
    return n;
}

void aNode(Node* r, char* s)
{
    int i = 0;
    int c = s[i ++];

    while (c)
    {
        c -= 'a';
        if (!r->n[c])
            r->n[c] = cNode();

        r = r->n[c];
        c = s[i ++];
    }
    r->e = 1;
}

bool fNode(Node* o, char* s, char* t)
{
    int i = 0;
    int c = s[i ++];

    if (!c)
        return true;

    Node* r = o;
    while (c)
    {
        c -= 'a';
        if (!r->n[c])
            return false;
        r = r->n[c];
        if (r->e && (t[i] || fNode(o, s + i, t)))
        {
            t[i] = 1;
            return true;
        }
        c = s[i ++];
    }
    return false;
}

void dNode(Node* r)
{
    for(int i = 0; i < N; i ++)
        if (r->n[i])
            dNode(r->n[i]);

    free(r);
}

bool can(int f, char* w)
{
    int i = 0;
    int c = w[i ++];
    while (c)
    {
        c -= 'a';
        if (!(f & (1 << c)))
            return false;
        c = w[i ++];
    }
    return true;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAllConcatenatedWordsInADict(char** words, int wordsSize, int* returnSize)
{
    int* ls = malloc(sizeof(int) * wordsSize);

    for (int i = 0; i < wordsSize; i ++)
        ls[i] = strlen(words[i]);

    facw_sort(ls, 0, wordsSize - 1, words);

    Node* o = cNode();

    int ri = 0;
    char** r = NULL;

    int fa = 0;

    char* t = malloc(ls[wordsSize - 1] + 1);

    for (int i = 0; i < wordsSize; i ++)
    {
        if (!ls[i])
            continue;

        char* w = words[i];

        if (ls[i] == 1)
            fa |= 1 << (w[0] - 'a');
        else if (fa)
        {
            if (fa == 0x3FFFFFF || can(fa, w))
            {
                ri ++;
                r = realloc(r, sizeof(char*) * ri);
                r[ri - 1] = w;
                continue;
            }
        }

        memset(t, 0, ls[i] + 1);

        if (!fNode(o, w, t))
            aNode(o, w);
        else
        {
            ri ++;
            r = realloc(r, sizeof(char*) * ri);
            r[ri - 1] = w;
        }
    }
    dNode(o);
    *returnSize = ri;
    return r;
}
