int longest(char* s, int len, int i)
{
    int m = 0;
    while (i > m && i + m < len - 1 && s[i - m - 1] == s[i + m + 1])
        m ++;
    int c = m * 2 + 1;
    m = 0;
    while (i >= m && i + m < len - 1 && s[i - m] == s[i + m + 1])
        m ++;
    return m * 2 > c ? m * 2 : c;
}

char* longestPalindrome(char* s)
{
    int len = strlen(s);

    int ll = 0;
    int index = 0;

    for (int i = 0; i < len; i++)
    {
        int l = longest(s, len, i);
        if (ll < l)
        {
            ll = l;
            index = i;
        }
    }

    char* ns = malloc(sizeof(char) * (ll + 1));
    strncpy(ns, &s[index - ll / 2 + (ll & 1 ? 0 : 1)], ll);
    ns[ll] = 0;
    return ns;
}
