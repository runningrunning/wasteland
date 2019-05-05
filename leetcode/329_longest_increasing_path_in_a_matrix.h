int lip(int** m, int x, int y, int r, int c, short* b)
{
    if (b[x * c + y])
        return b[x * c + y];

    int t = 0;

    int n = 0;
    if (x && m[x][y] > m[x - 1][y])
        n = lip(m, x - 1, y, r, c, b);

    if (n > t)
        t = n;

    if (y && m[x][y] > m[x][y - 1])
        n = lip(m, x, y - 1, r, c, b);

    if (n > t)
        t = n;

    if (x != r - 1 && m[x][y] > m[x + 1][y])
        n = lip(m, x + 1, y, r, c, b);

    if (n > t)
        t = n;

    if (y != c - 1 && m[x][y] > m[x][y + 1])
        n = lip(m, x, y + 1, r, c, b);

    if (n > t)
        t = n;

    b[x * c + y] = t + 1;

    return t + 1;
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize)
{
    short* b = calloc(sizeof(short), matrixRowSize * matrixColSize);
    int max = 0;
    for (int i = 0; i < matrixRowSize; i ++)
        for (int j = 0; j < matrixColSize; j ++)
        {
            int t = lip(matrix, i, j, matrixRowSize, matrixColSize, b);
            if (t > max)
                max = t;
        }

    return max;
}
