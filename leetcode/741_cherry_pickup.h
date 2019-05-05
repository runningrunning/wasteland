// corner cases  ???? why ? as 0 is also a valid answer, so we need to distinguish block and 0 collect
// and out of the range will be block except the last piece of the end point !!!!
// it's really fun to have it :P

// peak hint, peek solution, just put them together !
// is about how to create the code structure !
// change the view and it's really a simple DP
// simple multiple dimension DP !, but need to be more careful
// In this case, I shall call that the definition of the subproblem is not self-contained and its solution relies on information external to the subproblem itself.
// modify the definition of the problem to absorb the external information so that the new one is self-contained.
// 3 DP, find the expression !!!!
// GREEDY DOESN'T WORK, make each time have the most cherries, that doesn't works
// 675. Cut Off Trees for Golf Event  NOT THE SAME !
// should be easy
// 3 layer GP
int _cp(int** g, int x1, int y1, int x2, int r, int c, int*** dp)
{
    if (x1 >= r || y1 >= r || x2 >= r || x1 + y1 - x2 >= r)
        return INT_MIN;
    // printf("=== %d %d %d is %d.\n", x1, y1, x2, dp[x1][y1][x2]);

    if (dp[x1][y1][x2])
        return dp[x1][y1][x2] == INT_MIN ? INT_MIN : (dp[x1][y1][x2] - 1);

    if (g[x1][y1] == -1 || g[x2][x1 + y1 - x2] == -1)
    {
        dp[x1][y1][x2] = INT_MIN;
        return INT_MIN;
    }

    int n = g[x1][y1];
    int max = _cp(g, x1 + 1, y1, x2 + 1, r, c, dp);

    if (x1 == x2)
    {
        int t = _cp(g, x1, y1 + 1, x2, r, c, dp);
        if (max < t)
            max = t;

        t = _cp(g, x1 + 1, y1, x2, r, c, dp);

        if (max < t)
            max = t;
    }
    else
    {
        n += g[x2][x1 + y1 - x2];

        int t = _cp(g, x1, y1 + 1, x2, r, c, dp);
        if (max < t)
            max = t;

        t = _cp(g, x1 + 1, y1, x2, r, c, dp);

        if (max < t)
            max = t;

        t = _cp(g, x1, y1 + 1, x2 + 1, r, c, dp);

        if (max < t)
            max = t;
    }

    // be careful, 0 can also be valid answer here
    if (max != INT_MIN)
    {
        dp[x1][y1][x2] = max + n + 1;
        // printf("%d %d %d is %d.\n", x1, y1, x2, dp[x1][y1][x2]);
        return dp[x1][y1][x2] - 1;
    }
    // printf("--- %d %d %d is %d %d.\n", x1, y1, x2, dp[x1][y1][x2], max);

    dp[x1][y1][x2] = INT_MIN;
    return INT_MIN;
}

int cherryPickup(int** grid, int gridRowSize, int gridColSize)
{
    if (!grid || !gridRowSize || !gridColSize)
        return 0;

    int*** dp = malloc(sizeof(int**) * gridColSize);
    for (int i = 0; i < gridColSize; i ++)
    {
        dp[i] = malloc(sizeof(int*) * gridColSize);
        for (int j = 0; j < gridColSize; j ++)
            dp[i][j] = calloc(sizeof(int), gridColSize);
    }

    dp[gridColSize - 1][gridColSize - 1][gridColSize - 1] = grid[gridRowSize - 1][gridColSize - 1] + 1;
    _cp(grid, 0, 0, 0, gridRowSize, gridColSize, dp);
    return dp[0][0][0] == INT_MIN ?  0 : (dp[0][0][0] - 1);
}
