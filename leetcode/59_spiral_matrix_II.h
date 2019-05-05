/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int** all = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
        all[i] = malloc(sizeof(int) * n);

    int t = 1;
    int l = n >> 1;

    for(int i = 0; i < l; i++)
    {
        int skip = n - 2 * i - 1;
        for(int k = i; k < n - 1 - i; k++)
        {
            all[i][k] = t;
            all[k][n - 1 - i] = t + skip;
            all[n - 1 - i][n - 1 - k] = t + skip * 2;
            all[n - 1 - k][i] = t + skip * 3;
            t ++;
        }
        t += skip * 3;
    }

    if (n&1)
    {
        all[l][l] = n * n;
    }
    return all;
}
