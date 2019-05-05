// how to enumerate trie ?
// tree backtracking !!!!!!!
// no need to use tree backtracking, we can store indexs for matched prefix strings !!!!
// then we can just test one by one !
// store matched string in the Node

#define N 26
typedef struct _Node {
    int id;
    int f;
    int* pre_i;
    int pre_n;
    struct _Node* n[N];
} Node;
Node* cNode()
{
    Node* r = malloc(sizeof(Node));
    r->id = 0;
    r->f = 0;
    r->pre_i = 0;
    r->pre_n = 0;
    return r;
}
void aNode(Node* r, char* w, int id)
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
            r = r->n[c];
            r->pre_n = 1;
            r->pre_i = malloc(sizeof(int));
        }
        else
        {
            r = r->n[c];
            r->pre_n ++;
            r->pre_i = realloc(r->pre_i, sizeof(int) * (r->pre_n));
        }

        r->pre_i[r->pre_n - 1] = id;
        c = w[i ++];
    }
    r->id = id + 1;
}

void backTrack(char** ws, Node* o, char** ts, int l, int n, char**** ret, int* rs)
{
    Node* r = o;
    for (int i = 0; i < l; i ++)
    {
        int c = ts[i][l] - 'a';
        if (!(r->f & (1 << c)))
            return;
        r = r->n[c];
    }
    for (int i = 0; i < r->pre_n; i ++)
    {
        ts[l] = ws[r->pre_i[i]];
        if (l == n - 1)
        {
            if (!(*ret))
            {
                *rs = 1;
                *ret = malloc(sizeof(char**));
            }
            else
            {
                (*rs) ++;
                *ret = realloc(*ret, sizeof(char**) * (*rs));
            }
            int in = (*rs) - 1;
            (*ret)[in] = malloc(sizeof(char*) * n);
            for (int j = 0; j < n; j ++)
                (*ret)[in][j] = ts[j];
        }
        else
        {
            backTrack(ws, o, ts, l + 1, n, ret, rs);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** wordSquares(char** words, int wordsSize, int** columnSizes, int* returnSize)
{
    *returnSize = 0;
    *columnSizes = NULL;
    if (!words || !wordsSize)
        return NULL;

    int l = strlen(words[0]);

    int* cs = NULL;
    char*** r = NULL;

    if (l == 1)
    {
        cs = malloc(sizeof(int) * wordsSize);
        r = malloc(sizeof(char**) * wordsSize);
        for (int i = 0; i < wordsSize; i ++)
        {
            cs[i] = 1;
            r[i] = malloc(sizeof(char*) * 1);
            r[i][0] = words[i];
        }

        *columnSizes = cs;
        *returnSize = wordsSize;
        return r;
    }

    Node* o = cNode();
    for (int i = 0; i < wordsSize; i ++)
        aNode(o, words[i], i);


    int rs;
    char*** ret = NULL;

    char* t[5];
    for (int i = 0; i < wordsSize; i ++)
    {
        t[0] = words[i];
        backTrack(words, o, t, 1, l, &ret, &rs);
    }

    *returnSize = rs;
    *columnSizes = malloc(sizeof(int) * rs);
    for (int i = 0; i < rs; i ++)
        (*columnSizes)[i] = l;
    return ret;
}
