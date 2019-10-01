int calculateTime(char * keyboard, char * word)
{
    int cs[26] = {0};
    for (int i = 0; i < 26; i ++)
        cs[keyboard[i] - 'a'] = i;

    int r = 0;
    int p = 0;

    int i = 0;
    while (word[i])
    {
        int n = cs[word[i ++] - 'a'];
        r += abs(n - p);
        p = n;
    }
    return r;
}

