void swap_c(char* s, int i, int j)
{
    int e = j;
    char t = 0;

    for(int m = i; m < e; m ++)
    {
        t = s[m];
        s[m] = s[e];
        s[e] = t;
        e --;
    }
}

bool isAlpha(char c)
{
    return c > 32;
}

void reverseWords(char *s)
{
    if (!s)
        return;

    int l = strlen(s);
    int in = 0;

    for(int i = 0; i < l; i ++)
    {
        if (isAlpha(s[i]))
            s[in ++] = s[i];
        else if (in && isAlpha(s[in - 1]))
            s[in ++] = s[i];
    }
    l = in;
    s[in] = '\0';

    if (!isAlpha(s[in - 1]))
    {
        s[in - 1] = '\0';
        l --;
    }

    if (l <= 1)
        return;

    swap_c(s, 0, l - 1);

    int m = -1;
    int n = -1;

    for(int i = 0; i < l; i ++)
    {
        if (!isAlpha(s[i]))
            continue;

        m = i;

        for(int j = i; j <= l; j ++)
        {
            if (j == l)
            {
                swap_c(s, m, j - 1);
                return;
            }

            if (isAlpha(s[j]))
                continue;

            i = j;
            n = j - 1;
            swap_c(s, m, n);
            break;
        }
    }
}
