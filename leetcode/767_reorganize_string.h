// BRILLIANT IDEA
char* reorganizeString(char* S)
{
    int l = 0;
    int a[26] = {0};

    /* be careful about the l, it should be the last character */
    char c = S[l];
    while (c)
    {
        a[c - 'a'] ++;
        c = S[++ l];
    }

    if (l < 2)
        return S;

    int max = l / 2;
    max += (l & 1);

    int c_i;
    int c_max = 0;
    for (int i = 0; i < 26; i ++)
    {
        if (a[i] > max)
            return "";

        if (c_max < a[i])
        {
            c_i = i;
            c_max = a[i];
        }
    }

    int in = 0;
    /* allocate the last character of t */
    char* t = malloc(l + 1);
    for (int i = c_i; i < c_i + 26; i ++)
    {
        int ch = i % 26;
        int n = a[ch];
        while (n)
        {
            t[in] = ch + 'a';
            in += 2;
            if (in >= l)
                in = 1;
            n --;
        }
    }
    t[l] = 0;
    return t;
}
B
