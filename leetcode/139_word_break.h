// DP ?
// STUPID WRONG ALGORITHM !
// FIND ANOTHER SOLUTION !
// DP with memory the previous status

#define N 26
typedef struct _Node {
    int f;
    struct _Node* n[N];
} Node;

Node* cNode()
{
    Node* r = malloc(sizeof(Node));
    r->f = 0;
    return r;
}

void aNode(Node* r , char* w)
{
    int i = 0;
    int c = w[i ++];

    while (c)
    {
        c -= 'a';
        if (!(r->f & (1 << c)))
        {
            r->f |= 1 << c;
            r->n[c] = cNode();
        }
        r = r->n[c];
        c = w[i ++];
    }
    r->f |= 1 << 30;
}

bool fNode(Node* o, char* s, int i, char* f)
{
    Node* r = o;
    int c = s[i ++];

    while (c)
    {
        c -= 'a';
        if (!(r->f & (1 << c)))
            return false;
        r = r->n[c];

        if ((r->f & (1 << 30)) && !f[i])
        {
            if (!s[i] || fNode(o, s, i, f))
                return true;
            f[i] = 1;
        }
        c = s[i ++];
    }
    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    if (!wordDictSize || !wordDict)
        return false;
    Node* r = cNode();
    for (int i = 0; i < wordDictSize; i ++)
        aNode(r, wordDict[i]);
    int l = strlen(s);
    char* f = malloc(l);
    bzero(f, l);
    return fNode(r, s, 0, f);
}

/*
struct WB {
    int cf; // char flag bit
    int ef; // end flag bit
    struct WB* dc[26];
};

char low(char c)
{
    if (c >= 'a' && c <= 'z')
        return c;
    return c - 'A' + 'a';
}

void preWB(struct WB** r, char* w, int* all)
{
    struct WB* t;
    int n = 0;
    int l = strlen(w);

    for(int i = 0; i < l; i ++)
    {
        t = *r;
        if (!t)
        {
            *r = malloc(sizeof(struct WB));
            t = *r;
            t->cf = t->ef = 0;
            memset(&t->dc, 0, sizeof(t->dc));
        }
        n = low(w[i]) - 'a';
        t->cf |= 1 << n;
        r = &(t->dc[n]);

        *all |= 1 << n;
    }
    t->ef |= 1 << n;
}

bool check(char* s, struct WB* r, struct WB* h)
{
    char lo = low(s[0]);
    int i = lo - 'a';
    int n = 1 << i;

    if (!(r->cf & n))
        return false;

    if (r->ef & n)
    {
        if (!s[1])
            return true;

        if (!r->dc[i])
            return check(s + 1, h, h);

        return check(s + 1, r->dc[i], h)
            || check(s + 1, h, h);
    }

    if (!s[1])
        return false;

    return check(s + 1, r->dc[i], h);
}

bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    if (!wordDictSize || !wordDict)
        return !s || !strlen(s);

    int all_bits = 0;
    struct WB* r = NULL;
    for (int i = 0; i < wordDictSize; i ++)
        preWB(&r, wordDict[i], &all_bits);

    int  l = strlen(s);
    for (int i = 0; i < l; i ++)
    {
        int f = 1 << (low(s[i]) - 'a');
        if (!(f & all_bits))
            return false;
    }

    char* f = malloc(l);
    bzero(f, l);
    return check(s, r, r, f);
}
*/
