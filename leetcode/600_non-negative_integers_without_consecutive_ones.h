int _fi(int* n, int i, int* t, bool c)
{
    int x = (c ? 32 : 0) + i;
    if (t[x])
        return t[x];

    if (i == 0)
        t[x] = (c || n[i] == 1) ? 2 : 1;
    else if (i == 1)
    {
        if (c || n[i] == 1)
            t[x] = 3;
        else
            t[x] = _fi(n, i - 1, t, c);
    }
    else if (c)
        t[x] = _fi(n, i - 2, t, true) + _fi(n, i - 1, t, true);
    else if (n[i] == 1)
        t[x] = _fi(n, i - 2, t, n[i - 1] != 0) + _fi(n, i - 1, t, true);
    else
        t[x] = _fi(n, i - 1, t, c);

    return t[x];
}

int findIntegers(int num)
{

    if (num < 0)
        return 0;

    int t[64] = {0};
    int r[4] = {1, 2, 3, 3};
    if (num < 4)
        return r[num];

    int ns[32] = {0};
    int i = 0;
    while (num)
    {
        ns[i ++] = num & 1;
        num >>= 1;
    }

    i --;
    return _fi(ns, i, t, false);
}

int findIntegers_2(int num, int all)
{
    int pre = 0;
    bool is = true;
    while (num)
    {
        int t = num & 1;
        num >>= 1;

        if (t && t == pre)
        {
            is = false;
            break;
        }
        pre = t;
    }

    if (is)
        all ++;
    return all;
}
