// try to do without recursion
// remember to recover the t in isAN !!!
//     sme
// 1123458
// last  [m, e)
// first [s, m)
// take care 0
bool isAN(char* n, int s, int m, int e, char* t)
{
    if ((e - m > 1 && n[m] == '0')
        || (m - s > 1 && n[s] == '0'))
        return false;


    int c = 0;
    int l = s - 1;
    int f = m - 1;
    e = e - 1;
    int oe = e;
    int nc = 0;

    memcpy(t + m, n + m, e - m + 1);

    while (e >= m && (f >= s || c == -1))
    {
        int d = 0;
        int x = f >= s ? n[f] : '0';
        if (n[e] + c >= x)
            nc = 0;
        else
        {
            d = 10;
            nc = -1;
        }

        t[e] = n[e] + c - x + '0' + d;
        c = nc;

        if (f >= s)
            f --;
        e --;
    }

    if (c == -1 || f >= s)
        return false;

    e = m;

    if (t[e] == '0')
    {
        while (t[e] == '0')
            e ++;

        // when result is 0, then it's 0
        if (e > oe)
            e = oe;
    }

    while (oe >= e && l >= 0)
    {
        if (t[oe] != n[l])
            return false;
        oe --;
        l --;
    }

    if (oe != e - 1)
        return false;

    if (l < 0)
        return true;

    return isAN(n, l + 1, s, m, t);
}

bool isAdditiveNumber(char* num)
{
    char* d = strdup(num);
    int l = strlen(num);

    if (l < 3)
        return false;

    for (int i = l - 1; i >= l / 2; i --)
    {
        for (int j = 0; j < l - i; j ++)
        {
            if (isAN(num, i - j - 1, i, l, d))
                return true;
        }
    }
    return false;
}
