
int is_nmi(int** g, int x, int y)
{
    int a = g[x][y];
    int b = g[x][y + 1];
    int c = g[x][y + 2];
    int d = g[x + 1][y];
    int e = g[x + 1][y + 1];
    int f = g[x + 1][y + 2];
    int h = g[x + 2][y];
    int i = g[x + 2][y + 1];
    int j = g[x + 2][y + 2];

    int z = 1 << a;
    z |= 1 << b;
    z |= 1 << c;
    z |= 1 << d;
    z |= 1 << e;
    z |= 1 << f;
    z |= 1 << h;
    z |= 1 << i;
    z |= 1 << j;

    if (z != 0x3FE)
        return 0;

    // a b c
    // d e f
    // h i j

    int t = a + e + j;

    if (c + e + h != t)
        return 0;

    if (a + b + c != t)
        return 0;

    if (d + e + f != t)
        return 0;

    if (h + i + j != t)
        return 0;

    if (a + d + h != t)
        return 0;

    if (b + e + i != t)
        return 0;

    if (c + f + j != t)
        return 0;

    return 1;
}

int numMagicSquaresInside(int** grid, int gridRowSize, int *gridColSizes)
{
    if (gridRowSize < 3)
        return 0;
    if (gridRowSize && gridColSizes[0] < 3)
        return 0;
    int num = 0;
    for (int i = 0; i < gridRowSize - 2; i ++)
        for (int j = 0; j < gridColSizes[i] - 2; j ++)
            num += is_nmi(grid, i, j);
    return num;
}
