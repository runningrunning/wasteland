int largestOverlap(int** A, int ARowSize, int *AColSizes, int** B, int BRowSize, int *BColSizes)
{
    int max = 0;

    for (int x = 0; x < ARowSize; x ++)
        for (int y = 0; y < ARowSize; y ++)
        {
            if (max >= (ARowSize - x) * (ARowSize - y))
                continue;

            int c1 = 0;
            for (int i = 0; i < ARowSize - x; i ++)
                for (int j = 0; j < ARowSize - y; j ++)
                    c1 += A[x + i][y + j] & B[i][j];

            int c2 = 0;

            for (int i = 0; i < ARowSize - x; i ++)
                for (int j = 0; j < ARowSize - y; j ++)
                    c2 += A[i][j] & B[x + i][y + j];

            if (c1 > max)
                max = c1;

            if (c2 > max)
                max = c2;
        }

    return max;
}
