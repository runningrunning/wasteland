// how to remove from tries ?
// be careful about char, char is signed
#define N 26
typedef struct _Node{
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
        }
        r = r->n[c];
        c = w[i ++];
    }
    r->id = id + 1;
}

void fw(char** b, int r, int c, int x, int y, Node* o, int* f)
{
    if (o->id)
    {
        int i = o->id - 1;
        f[i / 32] |= 1 << (i % 32);
    }

    if (o->f)
    {
        if (x > 0 && b[x - 1][y] >= 'a')
        {
            int n = b[x - 1][y] - 'a';
            if (o->f & (1 << n))
            {
                b[x - 1][y] -= 32;
                fw(b, r, c, x - 1, y, o->n[n], f);
                b[x - 1][y] += 32;
            }
        }

        if (y > 0 && b[x][y - 1] >= 'a')
        {
            int n = b[x][y - 1] - 'a';
            if (o->f & (1 << n))
            {
                b[x][y - 1] -= 32;
                fw(b, r, c, x, y - 1, o->n[n], f);
                b[x][y - 1] += 32;
            }
        }

        if (x < r - 1 && b[x + 1][y] >= 'a')
        {
            int n = b[x + 1][y] - 'a';
            if (o->f & (1 << n))
            {
                b[x + 1][y] -= 32;
                fw(b, r, c, x + 1, y, o->n[n], f);
                b[x + 1][y] += 32;
            }
        }

        if (y < c - 1 && b[x][y + 1] >= 'a')
        {
            int n = b[x][y + 1] - 'a';
            if (o->f & (1 << n))
            {
                b[x][y + 1] -= 32;
                fw(b, r, c, x, y + 1, o->n[n], f);
                b[x][y + 1] += 32;
            }
        }
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize)
{
    Node* r = cNode();
    for (int i = 0; i < wordsSize; i ++)
        aNode(r, words[i], i);

    int fl = (wordsSize + 31) / 32;
    int* f = malloc(sizeof(int) * fl);
    memset(f, 0, sizeof(int) * fl);

    for (int i = 0; i < boardRowSize; i++)
        for (int j = 0; j < boardColSize; j ++)
        {
            int c = board[i][j] - 'a';
            if (r->f & (1 << c))
            {
                board[i][j] -= 32;
                fw(board, boardRowSize, boardColSize, i, j, r->n[c], f);
                board[i][j] += 32;
            }
        }

    int rs = 0;
    char** ret = NULL;

    for (int i = 0; i < wordsSize; i ++)
    {
        int x = i / 32;
        int y = i % 32;

        if (f[x] & (1 << y))
        {
            if (!ret)
                ret = malloc(sizeof(char*));
            else
                ret = realloc(ret, sizeof(char*) * (rs + 1));
            ret[rs] = words[i];
            rs ++;
        }
    }

    *returnSize = rs;
    return ret;
}
