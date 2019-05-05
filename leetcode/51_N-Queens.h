/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool is_ok(int m, int n, int* c)
{
    for (int i = 0; i < m; i ++)
        if (c[i] == n || abs(m - i) == abs(n - c[i]))
            return false;
    return true;
}

void snq(char**** r, int* ri, int s, int n, int* c)
{
    if (s == n)
    {
        *r = realloc(*r, sizeof(char***) * ((*ri) + 1));
        (*r)[*ri] = malloc(sizeof(char**) * n);
        for (int i = 0; i < n; i ++)
        {
            char* s = malloc(sizeof(char) * (n + 1));
            for (int j = 0; j < n; j ++)
                s[j] = '.';
            s[c[i]] = 'Q';
            s[n] = 0;
            (*r)[*ri][i] = s;
        }
        (*ri) ++;
    }
    else
    {
        for (int i = 0; i < n; i ++)
            if (is_ok(s, i, c))
            {
                c[s] = i;
                snq(r, ri, s + 1, n, c);
            }
    }
}

char*** solveNQueens(int n, int* returnSize)
{
    *returnSize = 0;

    if (!n)
        return NULL;
    int ri = 0;
    char*** r = NULL;

    int* c = malloc(sizeof(int) * n);

    snq(&r, &ri, 0, n, c);

    *returnSize = ri;
    return r;
}
