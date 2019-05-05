#define N 26
typedef struct _Node {
    int f;
    int id;
    struct _Node* n[N];
} Node;

Node* cNode()
{
    Node* r = malloc(sizeof(Node));
    r->f = 0;
    r->id = 0;
    return r;
}

void aNode(Node* r, Node* re, char* s, int id)
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
    r->id = id + 1;

    i -= 2;
    c = s[i --];

    while (i >= -1)
    {
        c -= 'a';
        if (!(re->f & (1 << c)))
        {
            re->f |= 1 << c;
            re->n[c] = cNode();
        }
        re = re->n[c];
        c = s[i --];
    }
    re->id = id + 1;
}

void fNode(Node* r)
{
    for (int i = 0; i < N; i ++)
        if (r->f & (1 << i))
            fNode(r->n[i]);
    free(r);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** palindromePairs(char** words, int wordsSize, int** columnSizes, int* returnSize)
{
    if (wordsSize <= 1)
        return NULL;

    Node* r = cNode();
    Node* re = cNode();

    for (int i = 0; i < wordsSize; i ++)
        aNode(r, re, words[i], i);

    int rs = 0;
    int** rt = NULL;

    for (int i = 0; i < wordsSize; i ++)
    {
        char* w = words[i];
        int l = strlen(w) - 1;

        int j = 0;
        int c = w[j ++];
        bool found = true;

        Node* t = re;

        while (c)
        {
            c -= 'a';
            if (t->id)
            {
                int s = j - 1;
                int e = l;
                while (w[s] == w[e] && s < e)
                {
                    s ++;
                    e --;
                }
                if (e <= s)
                {
                    if (i != t->id - 1)
                    {
                        if (!rt)
                            rt = malloc(sizeof(int*));
                        else
                            rt = realloc(rt, sizeof(int*) * (rs + 1));
                        rt[rs] = malloc(sizeof(int) * 2);
                        rt[rs][0] = i;
                        rt[rs][1] = t->id - 1;
                        rs ++;
                    }
                }
            }

            if (!(t->f & (1 << c)))
            {
                found = false;
                break;
            }
            t = t->n[c];
            c = w[j ++];
        }

        if (found && t->id)
        {
            if (i != t->id - 1)
            {
                if (!rt)
                    rt = malloc(sizeof(int*));
                else
                    rt = realloc(rt, sizeof(int*) * (rs + 1));
                rt[rs] = malloc(sizeof(int) * 2);
                rt[rs][0] = i;
                rt[rs][1] = t->id - 1;
                rs ++;
            }
        }

        j = l;
        c = w[j --];
        t = r;

        while (j >= -1)
        {
            c -= 'a';
            if (t->id)
            {
                int s = 0;
                int e = j + 1;
                while (w[s] == w[e] && s < e)
                {
                    s ++;
                    e --;
                }
                if (e <= s)
                {
                    if (i != t->id - 1)
                    {
                        if (!rt)
                            rt = malloc(sizeof(int*));
                        else
                            rt = realloc(rt, sizeof(int*) * (rs + 1));
                        rt[rs] = malloc(sizeof(int) * 2);
                        rt[rs][1] = i;
                        rt[rs][0] = t->id - 1;
                        rs ++;
                    }
                }
            }
            if (!(t->f & (1 << c)))
                break;
            t = t->n[c];
            c = w[j --];
        }
    }
    fNode(r);
    fNode(re);
    *returnSize = rs;
    int* cs = malloc(sizeof(int) * rs);
    for (int i = 0; i < rs; i++)
        cs[i] = 2;
    *columnSizes = cs;
    return rt;
}
