int firstUniqChar(char* s)
{
    if (!s)
        return -1;

    int l = strlen(s);

    if (!l)
        return -1;

    if (l == 1)
        return 0;

    int a[26] = {0};

    for (int i = 0; i < l; i ++)
    {
        int c = s[i] - 'a';

        if (!a[c])
            a[c] = i + 1;
        else
            a[c] = -1;
    }

    int mi = INT_MAX;
    for (int i = 0; i < 26; i ++)
        if (a[i] > 0 && mi > a[i])
            mi = a[i];

    return mi == INT_MAX ? -1 : mi - 1;
}
