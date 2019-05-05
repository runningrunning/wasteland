// my own hash table ?

#define PRIME 1031

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool same(char** as, int k, int v, int a)
{
    int s1 = (v >> 16) & 0xFF;
    int i1 = (v >> 8) & 0xFF;
    int l1 = v & 0xFF;

    int s2 = (a >> 16) & 0xFF;
    int i2 = (a >> 8) & 0xFF;
    int l2 = a & 0xFF;

    return (l1 == l2) && !strncmp(as[s1] + i1, as[s2] + i2, l1);
}

bool has(int* hash, char** as, int k, int v, int n, int* all)
{
    k = k % PRIME;
    while (hash[k] && !same(as, k, v, all[hash[k] - 1]))
        k = (k + 1) % PRIME;

    if (hash[k])
    {
        all[hash[k] - 1] |= 1 << 24;
        return false;
    }
    hash[k] = n + 1;
    all[n] = v;
    return true;
}

char** uncommonFromSentences(char* A, char* B, int* returnSize)
{
    int all[256] = {0};
    int hash[PRIME] = {0};

    char* as[2];
    as[0] = A;
    as[1] = B;

    int i = 0;
    int ai = 0;

    while (A[i])
    {
        while (A[i] == ' ')
            i ++;

        int s = i;

        if (A[i])
        {
            int v = 0;
            int c = 0;

            while (A[i] && A[i] != ' ')
            {
                v += A[i] - 'a';
                c ^= A[i];
                i ++;
            }

            int k = v << 16 | (i - s) << 8 | c;
            v = s << 8 | (i - s);

            if (has(hash, as, k, v, ai, all))
                ai ++;
        }
    }

    i = 0;
    while (B[i])
    {
        while (B[i] == ' ')
            i ++;

        int s = i;

        if (B[i])
        {
            int v = 0;
            int c = 0;

            while (B[i] && B[i] != ' ')
            {
                v += B[i] - 'a';
                c ^= B[i];
                i ++;
            }

            int k = v << 16 | (i - s) << 8 | c;
            v = 1 << 16 | s << 8 | (i - s);

            if (has(hash, as, k, v, ai, all))
                ai ++;
        }
    }

    int ri = 0;
    char** r = 0;

    for (int i = 0; i < ai; i ++)
        if (!(all[i] & (1 << 24)))
        {
            int a = all[i];
            int s2 = (a >> 16) & 0xFF;
            int i2 = (a >> 8) & 0xFF;
            int l2 = a & 0xFF;

            r = realloc(r, sizeof(char*) * (ri + 1));
            r[ri] = strndup(as[s2] + i2, l2);
            ri ++;
        }

    *returnSize = ri;
    return r;
}
