// better solution?
int matrixScore(int** A, int ARowSize, int *AColSizes)
{
    int r = 0;
    r = ARowSize * (1 << (AColSizes[0] - 1));

    for (int j = 1; j < AColSizes[0]; j ++)
    {
        int x = 0;
        for (int i = 0; i < ARowSize; i ++)
            x += (A[i][0]) ? (!A[i][j]) : (A[i][j]);
        r += (x < ARowSize - x ? ARowSize - x : x) * (1 << (AColSizes[0] - 1 - j));
    }
    return r;
}
