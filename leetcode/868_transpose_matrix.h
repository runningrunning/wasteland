/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize)
{
    if (!ARowSize || !A || !AColSizes)
        return NULL;

    int** r = malloc(sizeof(int*) * AColSizes[0]);
    int* cs = malloc(sizeof(int) * AColSizes[0]);

    for (int i = 0; i < AColSizes[0]; i ++)
    {
        cs[i] = ARowSize;
        r[i] = malloc(sizeof(int) * ARowSize);

        for (int j = 0; j < ARowSize; j ++)
            r[i][j] = A[j][i];
    }

    *returnSize = AColSizes[0];
    *columnSizes = cs;
    return r;
}
