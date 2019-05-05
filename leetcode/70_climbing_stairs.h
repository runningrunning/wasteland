int cs(int n, int* c, int a)
{
    if (n <= 1)
        return 1;

    if (!c[n - 2])
        c[n - 2] = cs(n - 1, c, a);

    if (!c[n - 3])
        c[n - 3] = cs(n - 2, c, a);
    return c[n - 2] + c[n - 3];
}

int climbStairs(int n)
{
    int* cur = malloc(sizeof(int) * (n + 2));
    memset(cur, 0, sizeof(int) * (n + 2));
    cur[0] = 1;
    cur[1] = 2;
    return cs(n, cur, n);
}

/*
int climbStairs(int n) {
    if (n > 1)
        return climbStairs(n - 1) + climbStairs(n - 2);
    return 1;
}
*/
