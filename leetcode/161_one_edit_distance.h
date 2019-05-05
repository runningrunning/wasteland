bool isOneEditDistance(char* s, char* t)
{
    int ls = strlen(s);
    int lt = strlen(t);

    int d = ls - lt;
    if (d < 0)
        d = - d;

    if (d > 1)
        return false;

    if (!ls || !lt)
        return ls || lt;

    if (d)
    {
        char* min_s = s;
        char* max_s = t;

        if (lt < ls)
        {
            min_s = t;
            max_s = s;
        }

        int i = 0;
        while (min_s[i] == max_s[i])
            i ++;

        while (min_s[i] && (min_s[i] == max_s[i + 1]))
            i ++;

        return !min_s[i] && !max_s[i + 1];
    }
    else
    {
        int c = 0;
        for (int i = 0; i < ls; i ++)
        {
            if (s[i] != t[i])
            {
                c ++;
                if (c > 1)
                    return false;
            }
        }
        return c == 1;
    }
    return false;
}
