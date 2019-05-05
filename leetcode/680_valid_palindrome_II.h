bool _vp(char* s, int o, int l)
{
    int m = l >> 1;
    if (o == -1)
    {
        for(int i = 0; i < m; i ++)
        {
            if (s[i] != s[l - i - 1])
                return false;
        }
        return true;
    }
    else
    {
        int len = l - o - 1 - o;
        int i = o + 1;

        if (o > m)
        {
            i = l - o - 1;
            len = o + o - l + 1;
        }

        m = len >> 1;
        s += i;

        for (int j = 0; j < m; j ++)
        {
            if (s[j] != s[len - j - 1])
                return false;
        }
        return true;
    }
}

bool validPalindrome(char* s) {
    if (!s)
        return true;

    int l = strlen(s);
    if (l <= 2)
        return true;

    if (s[0] != s[l - 1] && s[0] != s[l - 2] && s[l - 1] != s[1])
        return false;

    int x = 0;
    int f = 0;

    for(int i = 0; i < l; i ++)
    {
        f |= 1 << (s[i] - 'a');
        x ^= s[i];
    }

    int m = l >> 1;

    if (l & 1)
    {
        if (x < 'a' || x > 'z')
            return false;

        if (!(f & (1 << (x - 'a'))))
            return false;

        if (s[m] == x && _vp(s, -1, l))
            return true;

        for (int i = 0; i < m; i ++)
        {
            if (s[i] != x && s[l - i - 1] != x)
            {
                if (s[i] != s[l - i - 1])
                    return false;
            }
            else
            {
                if (s[i] == x && _vp(s, i, l))
                    return true;

                if (s[l - i - 1] == x && _vp(s, l - i - 1, l))
                    return true;

                if (s[i] != s[l - i - 1])
                    return false;
            }
        }
    }
    else
    {
        if (!x && _vp(s, -1, l))
            return true;

        char r1 = x ^ s[m];
        char r2 = x ^ s[m - 1];

        for (int i = 0; i < m; i ++)
        {
            if (s[i] != r1 && s[l - i - 1] != r2)
            {
                if (s[i] != s[l - i - 1])
                    return false;
            }
            else
            {
                if (s[i] == r1 && _vp(s, i, l))
                    return true;

                if (s[l - i - 1] == r2 && _vp(s, l - i - 1, l))
                    return true;

                if (s[i] != s[l - i - 1])
                    return false;
            }
        }
    }
    retrun true;
}
