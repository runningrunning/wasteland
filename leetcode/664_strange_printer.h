// TODO DO IT AGAIN !!!
// STUPID ME,
// PEEK SOLUTIONs !!!
// dp ?? like the remove the box
// just simple corner case, stupid ME
// error can not only take account the first and end
// e.g cdadacbdb (6), and abaca (3)
// and also the middle of them
// find a proper way to represent this issue
// still to complicate

int _sp(char* o, int s, int e, int** dp)
{
    if (s > e)
        return 0;

    if (dp[s][e])
        return dp[s][e] - 1;

    int min = 1 + _sp(o, s + 1, e, dp);
    for (int i = s + 1; i <= e; i ++)
    {
        if (o[i] == o[s])
        {
            // here i - 1 is brilliant !!!!!, keep continue remove the last piece of same
            int r = _sp(o, s, i - 1, dp) + _sp(o, i + 1, e, dp);
            if (min > r)
                min = r;
        }

    }

    /* if (o[s] == o[e]) */
    /* { */
    /*     min = 1 + _sp(o, s + 1, e - 1, dp); */

    /*     int r = 1; */
    /*     int p = s; */
    /*     int i = s + 1; */
    /*     for (i = s + 1; i <= e; i ++) */
    /*         if (o[i] == o[s]) */
    /*         { */
    /*             r += _sp(o, p + 1, i - 1, dp); */
    /*             p = i; */
    /*         } */

    /*     if (min > r) */
    /*         min = r; */
    /* } */

    /* for (int i = s; i < e; i ++) */
    /* { */
    /*     int r = _sp(o, s, i, dp) + _sp(o, i + 1, e, dp); */
    /*     if (min > r) */
    /*         min = r; */
    /* } */

    dp[s][e] = min + 1;
    return min;
}

int strangePrinter(char* s)
{
    if (!s || !s[0])
        return 0;

    int l = strlen(s);
    if (l == 1)
        return 1;

    int oi = 0;
    char* o = strdup(s);

    int p = s[0] - 1;
    for (int i = 0; i < l; i ++)
    {
        if (s[i] != p)
            o[oi ++] = s[i];
        p = s[i];
    }
    o[oi] = 0;

    // printf("%s %d %d.\n", o, strlen(o), oi);
    int** dp = malloc(sizeof(int*) * oi);
    for (int i = 0; i < oi; i ++)
    {
        dp[i] = calloc(sizeof(int), oi);
        dp[i][i] = 2;
    }

    int x = _sp(o, 0, oi - 1, dp);
    // outaaa(dp, oi, oi);
    return x;
}
