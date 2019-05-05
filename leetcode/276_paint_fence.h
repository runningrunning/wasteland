// reading Qs, DP, DP always need to store the inter calculation result
int ns(int n, int k, int* t)
{
    if (!n)
        return 1;
    if (n < 0)
        return 0;
    if (!t[n])
        t[n] = k * ns(n - 1, k, t) + k * ns(n - 2, k, t);
    return t[n];
}

int numWays(int n, int k)
{
    if (!n || !k)
        return 0;
    if (k == 1)
        return n <= 2 ? 1 : 0;

    int* t = malloc(sizeof(int) * n);
    memset(t, 0, sizeof(int) * n);
    return k * ns(n - 1, k - 1, t) + k * ns(n - 2, k - 1, t);
}
