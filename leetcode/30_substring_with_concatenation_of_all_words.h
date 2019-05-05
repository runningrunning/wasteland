// try hash and trie both

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// TRIE VERSION
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
    r->id = -1;
    return r;
}

int aNode(Node* r, char* w, int id)
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
    if (r->id == -1)
        r->id = id;
    return r->id;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    *returnSize = 0;
    if (!s || !words || !wordsSize)
        return NULL;

    int ls = strlen(s);
    int l = strlen(words[0]);
    int lw = l * wordsSize;

    if (ls < lw)
        return NULL;

    int ni = 0;
    int* wn = NULL;

    Node* nr = cNode();
    for (int i = 0; i < wordsSize; i ++)
    {
        int x = aNode(nr, words[i], ni);
        if (x == ni)
        {
            ni ++;
            wn = realloc(wn, sizeof(int) * ni);
            wn[ni - 1] = 0;
        }
        wn[x] ++;
    }

    int need_s = 0;
    int need_i = 0;
    int* need = malloc(sizeof(int) * wordsSize);

    int ri = 0;
    int* r = NULL;

    int* cn = malloc(sizeof(int) * ni);
    for (int i = 0; i < l; i ++)
    {
        need_s = 0;
        need_i = 0;
        memset(cn, 0, sizeof(int) * ni);

        Node* t = nr;
        int next = i + l;

        for (int j = i; j < ls; j ++)
        {
            int c = s[j] - 'a';

            if (!(t->f & (1 << c)))
            {
                j = next - 1;
                next += l;
                need_s = 0;
                need_i = 0;
                memset(cn, 0, sizeof(int) * ni);
                t = nr;
                continue;
            }

            t = t->n[c];
            if (t->id == -1)
                continue;

            next = j + l + 1;

            int id = t->id;
            t = nr;

            if (cn[id] < wn[id])
            {
                cn[id] ++;
                need_s ++;
            }
            else
            {
                int h = (need_i - need_s + wordsSize) % wordsSize;
                while (need[h] != id)
                {
                    cn[need[h]] --;
                    h = (h + 1) % wordsSize;
                    need_s --;
                }
            }
            need[need_i] = id;
            need_i = (need_i + 1) % wordsSize;

            if (need_s == wordsSize)
            {
                ri ++;
                r = realloc(r, sizeof(int) * ri);
                r[ri - 1] = j - lw + 1;
            }
        }
    }
    *returnSize = ri;
    return r;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// HASH
/*
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
    *returnSize = 0;
    if (!s || !words || !wordsSize)
        return NULL;

    int ls = strlen(s);
    int l = strlen(words[0]);
    int lw = l * wordsSize;

    if (ls < lw)
        return NULL;

    // 1 << i
    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp > 4 * wordsSize)
            break;
    }

    int* hash = malloc(sizeof(int) * dp);
    memset(hash, 0, sizeof(int) * dp);

    int ni = 0;
    int* wn = NULL;
    char** ws = NULL;

    for (int i = 0; i < wordsSize; i ++)
    {
        char* w = words[i];

        int j = 0;
        int c = w[j ++];
        int t = 0;
        while (c)
        {
            t = ((t << 8) + c) % dp;
            c = w[j ++];
        }

        while (hash[t] && strcmp(ws[hash[t] - 1], w))
            t = (t + 1) % dp;

        if (!hash[t])
        {
            ni ++;
            wn = realloc(wn, sizeof(int) * ni);
            ws = realloc(ws, sizeof(char*) * ni);
            hash[t] = ni;
            ws[ni - 1] = w;
            wn[ni - 1] = 0;
        }
        wn[hash[t] - 1] ++;
    }

    int need_s = 0;
    int need_i = 0;
    int* need = malloc(sizeof(int) * wordsSize);

    int ri = 0;
    int* r = NULL;

    int* cn = malloc(sizeof(int) * ni);
    for (int i = 0; i < l; i ++)
    {
        memset(cn, 0, sizeof(int) * ni);

        int t = 0;
        int j = i;

        need_s = 0;
        need_i = 0;

        for (; j < ls; j ++)
        {
            t = ((t << 8) + s[j]) % dp;

            if (!((j - i + 1) % l))
            {
                while (hash[t] && strncmp(ws[hash[t] - 1], s + j - l + 1, l))
                    t = (t + 1) % dp;

                if (!hash[t])
                {
                    need_s = 0;
                    need_i = 0;
                    memset(cn, 0, sizeof(int) * ni);
                }
                else
                {
                    int in = hash[t] - 1;
                    if (cn[in] < wn[in])
                    {
                        cn[in] ++;
                        need_s ++;
                        need[need_i] = in;
                        need_i = (need_i + 1) % wordsSize;
                    }
                    else
                    {
                        int h = (need_i - need_s + wordsSize) % wordsSize;
                        while (need[h] != in)
                        {
                            cn[need[h]] --;
                            h = (h + 1) % wordsSize;
                            need_s --;
                        }
                        need[need_i] = in;
                        need_i = (need_i + 1) % wordsSize;
                    }
                    if (need_s == wordsSize)
                    {
                        ri ++;
                        r = realloc(r, sizeof(int) * ri);
                        r[ri - 1] = j - lw + 1;
                    }
                }
                t = 0;
            }
        }
    }

    *returnSize = ri;
    return r;
}
*/
