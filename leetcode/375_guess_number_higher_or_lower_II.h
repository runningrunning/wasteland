// PEEK SOLUTIONS !!!!!!!!!!!!!!!!!!!!!!!!
// TODO CODE OPTIMIZE !!!, not recursive !!!!!!!!!!!!!!!!!
// think too much, just simple DP !!
// STUPID WRONG algorithm by me !!!!
// there is no such intelligence
/* DP, find better solution ? */
/* TODO find better solution !!! */
// it's not a calculated questions, it's DP ?
// how to solve this with DP ?
// hot to optimize this code ?

int ga(int* cs, int s, int e, int n)
{
    if (s == e)
        return 0;

    if (s + 1 == e)
    {
        cs[s * n + e] = s;
        return s;
    }

    if (s + 2 == e)
    {
        cs[s * n + e] = s + 1;
        return s + 1;
    }

    if (cs[s * n + e])
        return cs[s * n + e];

    int cur = s + ga(cs, s + 1, e, n);

    for (int i = s + 1; i < e; i ++)
    {
        int p1 = ga(cs, s, i - 1, n);
        int p2 = ga(cs, i + 1, e, n);

        int t = p1 > p2 ? p1 : p2;
        if (t + i <= cur)
            cur = t + i;

        if (p1 >= p2)
            break;
    }
    cs[s * n + e] = cur;
    return cur;
}

int getMoneyAmount(int n)
{
    /* int** cs = malloc(sizeof(int*) * (n + 1)); */
    /* for (int i = 1; i <= n; i ++) */
    /*     cs[i] = calloc(sizeof(int), n + 1); */

    int* cs = calloc(sizeof(int), (n + 1) * (n + 1));
    return ga(cs, 1, n, n + 1);
}
