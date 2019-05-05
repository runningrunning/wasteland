void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
    if (matrixRowSize <= 1)
        return;

    int** m = matrix;
    int ml = matrixRowSize;
    int l = ml / 2;

    for(int i = 0; i < l; i ++)
    {
        for (int j = i; j < ml - i - 1; j ++)
        {
            int t = m[i][j];
            m[i][j] = m [ml - j - 1][i];
            m[ml - j - 1][i] = m[ml - i - 1][ml - j - 1];
            m[ml - i - 1][ml - j - 1] = m[j][ml - i - 1];
            m[j][ml - i - 1] = t;
        }
    }
    return;
}
