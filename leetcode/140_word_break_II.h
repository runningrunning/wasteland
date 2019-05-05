// DP + TRIE
// failed too much times, more careful, for corner cases !!!
#define N 26
typedef struct _Node
{
    int e;
    int f;
    struct _Node* n[N];
} Node;

Node* cNode()
{
    Node* n = malloc(sizeof(Node));
    n->e = n->f = 0;
    return n;
}

void aNode(Node* r, char* s, int id)
{
    int i = 0;
    int c = s[i ++];
    while (c)
    {
        c -= 'a';
        if (!(r->f & (1 << c)))
        {
            r->f |= 1 << c;
            r->n[c] = cNode();
        }
        r = r->n[c];
        c = s[i ++];
    }
    r->e = id + 1;
}

bool fNode(char* s, int si, Node* n, char* f, int* h, int hi, int* ri, char*** r, char** w)
{
    if (!s[si])
    {
        int _ri = (*ri) + 1;
        *r = realloc(*r, sizeof(char*) * _ri);
        int ti = 0;
        char* t = malloc(si + hi);
        for (int i = 0; i < hi; i ++)
        {
            char* ts = w[h[i]];
            int j = 0;
            int c = ts[j ++];
            while (c)
            {
                t[ti ++] = c;
                c = ts[j ++];
            }
            t[ti ++] = ' ';
        }
        t[ti - 1] = 0;
        (*r)[_ri - 1] = t;
        (*ri) ++;
        return true;
    }

    bool found = false;
    Node* o = n;
    int c = s[si ++];
    while (c)
    {
        c -= 'a';
        if (!(n->f & (1 << c)))
            return found;
        n = n->n[c];

        if (n->e && !f[si])   // after n = n->n[c], then it will check the correct n and not update si !!!
        {
            h[hi] = n->e - 1;
            if (!fNode(s, si, o, f, h, hi + 1, ri, r, w))
                f[si] = 1;
            else
                found = true;
        }

        c = s[si ++];
    }
    return found;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize)
{
    Node* n = cNode();
    for (int i = 0; i < wordDictSize; i ++)
        aNode(n, wordDict[i], i);

    int l = strlen(s);
    char* f = malloc(sizeof(char) * (l + 1)); // must use l + 1 as si could be used
    bzero(f, (l + 1));
    int* h = malloc(sizeof(int) * l);

    int ri = 0;
    char** r = NULL;

    fNode(s, 0, n, f, h, 0, &ri, &r, wordDict);
    *returnSize = ri;
    return r;
}
