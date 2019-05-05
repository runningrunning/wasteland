// how to represent a sparse matrix
/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
   https://en.wikipedia.org/wiki/Sparse_matrix
 */
int** multiply(int** A, int ARowSize, int AColSize, int** B, int BRowSize, int BColSize)
{
    // a is col
    int* al = calloc(sizeof(int), ARowSize);
    int** a = calloc(sizeof(int*), ARowSize);

    // b is row
    int* bl = calloc(sizeof(int), BColSize);
    int** b = calloc(sizeof(int*), BColSize);

    int** r = malloc(sizeof(int*) * ARowSize);

    for (int i = 0; i < ARowSize; i ++)
    {
        r[i] = calloc(sizeof(int), BColSize);
        for (int j = 0; j < AColSize; j ++)
            if (A[i][j])
            {
                if (!a[i])
                    a[i] = malloc(sizeof(int));
                else
                    a[i] = realloc(a[i], sizeof(int) * (al[i] + 1));
                a[i][al[i]] = j;
                al[i] ++;
            }
    }

    for (int i = 0; i < BColSize; i ++)
        for (int j = 0; j < BRowSize; j ++)
            if (B[j][i])
            {
                if (!b[i])
                    b[i] = malloc(sizeof(int));
                else
                    b[i] = realloc(b[i], sizeof(int) * (bl[i] + 1));
                b[i][bl[i]] = j;
                bl[i] ++;
            }

    for (int i = 0; i < ARowSize; i ++)
        for (int j = 0; j < BColSize; j ++)
        {
            int ai = 0;
            int bi = 0;
            while (ai < al[i] && bi < bl[j])
            {
                if (a[i][ai] > b[j][bi])
                    bi ++;
                else if (a[i][ai] < b[j][bi])
                    ai ++;
                else
                {
                    int x = a[i][ai];
                    r[i][j] += A[i][x] * B[x][j];
                    ai ++;
                    bi ++;
                }
            }
        }
    return r;
}
