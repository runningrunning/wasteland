/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    int* all = malloc(sizeof(int) * matrixRowSize * matrixColSize);

    int n = 0;
    int r = matrixRowSize;
    int c = matrixColSize;
    int l = 0;

    if (r > c)
        l = c >> 1;
    else
        l = r >> 1;

    for (int t = 0; t < l; t ++)
    {
        for (int j = t; j < c - t - 1; j ++)
            all[n++] = matrix[t][j];

        for (int j = t; j < r - t - 1; j ++)
            all[n++] = matrix[j][c - t - 1];

        for (int j = t; j < c - t - 1; j ++)
            all[n++] = matrix[r - t - 1][c - j - 1];

        for(int j = t; j < r - t - 1; j ++)
            all[n++] = matrix[r - j - 1][t];
    }

    if (c >= r && (r & 1))
    {
        int t = r >> 1;
        for (int j = t; j < c - t; j ++)
            all[n++] = matrix[t][j];
    }
    else if (r > c && (c & 1))
    {
        int t = c >> 1;
        for (int j = t; j < r - t; j ++)
            all[n++] = matrix[j][c - t - 1];
    }

    return all;
}
