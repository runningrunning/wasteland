/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize)
{
    *columnSizes = AColSizes;
    *returnSize = ARowSize;

    if (!A)
        return A;

    int* cs = malloc(sizeof(int) * ARowSize);
    int** r = malloc(sizeof(int*) * ARowSize);

    for (int i = 0; i < ARowSize; i ++)
    {
        int l = AColSizes[i];
        cs[i] = l;
        r[i] = malloc(sizeof(int) * l);
        for (int j = l - 1; j >= 0; j --)
            r[i][l - 1 - j] = !A[i][j];
        /* int s = 0; */
        /* int e = AColSizes[i] - 1; */
        /* int* a = A[i]; */

        /* while (s < e) */
        /* { */
        /*     int t = a[s]; */
        /*     a[s] = !a[e]; */
        /*     a[e] = !t; */
        /*     s ++; */
        /*     e --; */
        /* } */
        /* if (s == e) */
        /*     a[s] = !a[s]; */
    }
    return r;
}
