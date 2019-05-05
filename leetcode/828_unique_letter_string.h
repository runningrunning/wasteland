#define MOD 1000000007
int uniqueLetterString(char* S)
{
    int s[256] = {0};
    int e[256] = {0};

    int i = 0;
    int c = S[i ++];
    long x = 0;

    while (c)
    {
        if (!s[c])
            s[c] = -1;
        else
        {
            if (s[c] == -1)
                x += e[c] * (i - e[c]);
            else
                x += (e[c] - s[c]) * (i - e[c]);
            x %= MOD;
            s[c] = e[c];
        }
        e[c] = i;
        c = S[i ++];
    }

    int l = S[i - 2];
    for (int j = 0; j < 256; j ++)
        if (s[j] && e[j])
        {
            if (s[j] == -1)
                x += e[j] * (i - e[j]);
            else
                x += (e[j] - s[j]) * (i - e[j]);
            x %= MOD;
        }

    return x;
}
