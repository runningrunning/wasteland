char* shortestPalindrome(char* s)
{
    int si = 0;
    int* st = malloc(sizeof(int) * 1024);

    int ti = 0;
    int x = 0;

    int i = 0;
    int c = s[i ++];

    while (c)
    {
        x ^= c;
        if ((i & 1) ? (x == s[ti ++]) : (!x))
        {
            if (si && !(si % 1024))
                st = realloc(st, sizeof(int) * (si + 1024));

            int t = (i - 1) / 2;
            t = (i & 1) ? t : - t;
            st[si ++] = t;
        }
        c = s[i ++];
    }

    int l = i - 1;

    if (l <= 1)
        return s;

    si -= 1;
    int t;

    for (i = si; i >= 0; i --)
    {
        t = st[i];
        int j, k;

        if (t >= 0)
        {
            j = t - 1;
            k = t + 1;
        }
        else
        {
            j = - t;
            k = - t + 1;
        }
        while (j >= 0)
        {
            if (s[j] != s[k])
                break;

            j --;
            k ++;
        }

        if (j == -1)
            break;
    }

    int ll;

    if (!t)
    {
        if (s[0] == s[1])
            ll = l + l - 2 + 1;
        else
            ll = l + l - 1 + 1;
    }
    else
    {
        if (t > 0)
            ll = l + l - 2 * t - 1 + 1;
        else
            ll = l + l + 2 * t - 1;
    }

    if (ll == l)
        return strdup(s);

    char* r = malloc(ll);

    for (int i = 0; i < ll - l - 1; i ++)
        r[i] = s[l - 1 - i];
    memcpy(&r[ll - l - 1], s, l);
    r[ll - 1] = 0;
    return r;
}
