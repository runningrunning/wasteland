bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes)
{
    if (!matrix || !matrixRowSize)
        return true;

    int c = matrixColSizes[0];
    if (matrixRowSize == 1 || c == 1)
        return true;

    for (int i = 1; i < matrixRowSize; i ++)
    {
        for (int j = 1; j < c; j ++)
            if (matrix[i][j] != matrix[i - 1][j - 1])
                return false;
    }

    return true;
}

bool isToeplitzMatrix_1(int** matrix, int matrixRowSize, int *matrixColSizes)
{
    if (!matrix || !matrixRowSize)
        return true;

    int c = matrixColSizes[0];
    if (matrixRowSize == 1 || c == 1)
        return true;

    for (int i = 0; i < c; i ++)
    {
        int exp = matrix[0][i];
        int k = 1;
        int j = i + 1;
        while (k < matrixRowSize && j < c)
        {
            if (matrix[k][j] != exp)
                return false;
            k ++;
            j ++;
        }
    }

    for (int i = 1; i < matrixRowSize; i ++)
    {
        int exp = matrix[i][0];
        int j = 1;
        int k = i + 1;

        while (k < matrixRowSize && j < c)
        {
            if (matrix[k][j] != exp)
                return false;
            k ++;
            j ++;
        }
    }
    return true;
}
