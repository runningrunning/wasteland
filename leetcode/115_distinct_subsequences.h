int nd(char* s, char* t, int si, int ti, int ls, int lt, int* d)
{
    int tc = t[ti];
    if (!tc)
        return 1;

    if (!s[si])
        return 0;

    int o = si * lt + ti;
    if (d[o])
        return d[o] - 1;

    int x = 0;
    for (si; si <= ls - lt + ti; si ++)
    {
        if (s[si] != tc)
            continue;
        x += nd(s, t, si + 1, ti + 1, ls, lt, d);
    }
    d[o] = x + 1;
    return x;
}

int numDistinct(char* s, char* t)
{
    int ls = strlen(s);
    int lt = strlen(t);
    if (!ls)
        return ls == lt ? 1 : 0;
    if (ls < lt)
        return 0;
    int* d = calloc(sizeof(int), ls * lt);
    return nd(s, t, 0, 0, ls, lt, d);
}

/*
void nd(char* s, char* t, int* n)
{
    if (!(*t))
        (*n) ++;
    else
    {
        int i = 0;
        int c = s[i ++];
        while (c)
        {
            if (c == t[0])
                nd(s + i, t + 1, n);
            c = s[i ++];
        }
    }
}

int numDistinct(char* s, char* t)
{
    int n = 0;
    nd(s, t, &n);
    return n;
}
*/
