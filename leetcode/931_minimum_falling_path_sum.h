// corner case !
// CORNER CASE !!! TOO MUCH ERRORS !!!
// MARCO without (), priority typo
#define MIN_2(a, b) ((a) > (b) ? (b) : (a))
#define MIN_3(a, b, c) ((a) > (b) ? ((b) > (c) ? (c) : (b)) : ((a) > (c) ? (c) : (a)))

int minFallingPathSum(int** A, int ARowSize, int *AColSizes)
{
    if (!A || !ARowSize || !AColSizes[0])
        return 0;

    int r = ARowSize;
    int c = AColSizes[0];

    if (r == 1)
    {
        int min = A[0][0];
        for (int i = 1; i < c; i ++)
            if (min > A[0][i])
                min = A[0][i];
        return min;
    }
    else if (c == 1)
    {
        int min = 0;
        for (int i = 0; i < r; i ++)
            min += A[i][0];
        return min;
    }

    int* t0 = A[0];
    int* t1 = calloc(sizeof(int), c);

    for (int i = 1; i < ARowSize; i ++)
    {
        t1[0] = MIN_2(t0[0], t0[1]) + A[i][0];
        t1[c - 1] = MIN_2(t0[c - 2], t0[c - 1]) + A[i][c - 1];

        for (int j = 1; j < ARowSize - 1; j ++)
            t1[j] = MIN_3(t0[j - 1], t0[j], t0[j + 1]) + A[i][j];

        int* t = t0;
        t0 = t1;
        t1 = t;
    }

    int min = t0[0];
    for (int i = 1; i < c; i ++)
        if (min > t0[i])
            min = t0[i];
    return min;
}
