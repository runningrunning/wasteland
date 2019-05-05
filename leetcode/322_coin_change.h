// learn a lot, don't use internal storage for temporary calculated result
// use current min to reduce the steps and then get the better result
// it's the sprite of DP !!!! pruning !!!
// There are totally different method to do this !!!! 3ms solution !!
// DP is about pruning !
void cc_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;
        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    cc_sort(n, cs, e - 1);
    cc_sort(n, e + 1, ce);
}

int cc_dp(int* cs, int s, int e, int c, int m)
{
    if (e < s)
        return - 1;

    int oc = c;
    int y = 0;
    int x = c / cs[e];
    c = c % cs[e];

    if (m < x)
        return -1;

    if (!c)
        return x;

    while (x >= 0)
    {
        int y = cc_dp(cs, s, e - 1, c, m - x);
        if (y != -1)
            m = x + y;
        if (x)
            c += cs[e];
        x --;
    }

    if (m != INT_MAX)
        return m;
    return - 1;
}

int coinChange(int* coins, int coinsSize, int amount)
{
    if (!coins || !coinsSize || !amount)
        return amount ? - 1 : 0;
    cc_sort(coins, 0, coinsSize - 1);
    return cc_dp(coins, 0, coinsSize - 1, amount, INT_MAX);
}
