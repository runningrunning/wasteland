// DP !!! // same with 62 Unique Paths
int minPathSum(int** g, int r, int c)
{
    if (!g || !r || !c)
        return 0;

    // last line
    int* t = g[r - 1];
    for (int i = 1; i < c; i ++)
        t[c - 1 - i] += t[c - i];

    int min = INT_MAX;
    for (int i = 1; i < r; i ++)
    {
        int* l = g[r - 1 - i];
        t[c - 1] += l[c - 1];

        for (int j = 1; j < c; j ++)
            t[c - 1 - j] = l[c - 1 - j] + (t[c - 1 - j] <  t[c - j] ? t[c - 1 - j] : t[c - j]);
    }
    return t[0];
}

/*
int _mps(int** g, int x, int y, int m, int n, int** t)
{
    if (t[x][y] >= 0)
        return t[x][y];

    if (t[x][y] == -1)
        return INT_MAX;

    t[x][y] = -1;

    int up = INT_MAX;
    if (x != 0)
        up = _mps(g, x - 1, y, m, n, t);

    int down = INT_MAX;
    if (x != m)
        down = _mps(g, x + 1, y, m, n, t);

    int left = INT_MAX;
    if (y != 0)
        left = _mps(g, x, y - 1, m, n, t);

    int right = INT_MAX;
    if (y != n)
        right = _mps(g, x, y + 1, m, n, t);

    int min = up < down ? up : down;
    min = min < left ? min : left;
    min = min < right ? min : right;
    t[x][y] = min;
    return min;
}

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    int min = INT_MAX;
    int m = gridRowSize;
    int n = gridColSize;

    if (m == 1)
    {
        int a = 0;
        for (int i = 0; i < n; i ++)
            a += grid[0][i];
        return a;
    }

    if (n == 1)
    {        int a = 0;
        for (int i = 0; i < m; i ++)
            a += grid[i][0];
        return a;
    }

    int** t = malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i ++)
    {
        t[i] = malloc(sizeof(int) * n);

        for (int j = 0; j < n; j ++)
            t[i][j] = -1;
    }

    t[m - 1][n - 1] = grid[m - 1][n - 1];
    t[m - 2][n - 1] = grid[m - 1][n - 1] + grid[m - 2][n - 1];
    t[m - 1][n - 2] = grid[m - 1][n - 1] + grid[m - 1][n - 2];

    return _mps(grid, 0, 0, m - 1, n - 1, t);
}

// STUPID Wrong Algorithm !!!!!
// MUST USE temp storage for any DP method to reduce the time
/*
void _mps(int** g, int m, int n, int x, int y, int num, int* min)
{
    if (m == x && n == y)
    {
        if (num < *min)
            *min = num;

        return;
    }

    if (num > *min)
        return;

    if (m == x || n == y)
    {
        if (m == x)
        {
            for (n = n + 1;n < y; n ++)
                num += g[x][n];
        }
        else
        {
            for (m = m + 1;m < x; m ++)
                num += g[m][y];
        }

        if (num < *min)
            *min = num;
    }
    else
    {
        if (g[m + 1][n] < g[m][n + 1])
        {
            _mps(g, m + 1, n, x, y, num + g[m + 1][n], min);
            _mps(g, m, n + 1, x, y, num + g[m][n + 1], min);
        }
        else
        {
            _mps(g, m, n + 1, x, y, num + g[m][n + 1], min);
            _mps(g, m + 1, n, x, y, num + g[m + 1][n], min);
        }
    }
}

int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
    int min = INT_MAX;
    int m = gridRowSize;
    int n = gridColSize;
    if (m == 1 && n == 1)
        return grid[0][0];

    _mps(grid, 0, 0, m - 1, n - 1, grid[0][0] + grid[m - 1][n - 1], &min);
    return min;
}
*/
