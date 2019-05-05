// DP with memorization
int lps(char* a, int s, int e, int m, int n, short* t)
{
    if (s >= e)
        return m;

    int x = s * n + e;

    if (t[x] >= 1024)
        return m + t[x] - 1024;

    if (a[s] == a[e])
    {
        int l = lps(a, ++ s, -- e, m, n, t);
        t[x] = l - m + 1024;
        return l;
    }

    if (s + 1 == e)
    {
        t[x] = 1 + 1024;
        return m + 1;
    }

    int l = lps(a, 1 +  s, e, m + 1, n, t);
    int r = lps(a, s, e - 1, m + 1, n, t);
    t[x] = (l < r ? l : r) - m + 1024;
    return l < r ? l : r;
}

int longestPalindromeSubseq(char* s)
{
    int l = strlen(s);
    short* t = calloc(sizeof(short), l * l);
    return l - lps(s, 0, l - 1, 0, l, t);
}

