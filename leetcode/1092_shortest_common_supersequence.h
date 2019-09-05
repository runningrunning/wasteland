// DP again
// Try no recursive DP version
int _scs(int** dp, char* a1, char* a2, int s1, int s2)
{
    if (dp[s1][s2])
        return dp[s1][s2] - 1;

    if (!a1[s1] || !a2[s2])
    {
        dp[s1][s2] = 1;
        return 0;
    }

    int max = _scs(dp, a1, a2, s1 + 1, s2);
    int max1 = _scs(dp, a1, a2, s1, s2 + 1);

    max = max > max1 ? max : max1;

    if (a1[s1] == a2[s2])
    {
        max1 = 1 + _scs(dp, a1, a2, s1 + 1, s2 + 1);
        max = max > max1 ? max : max1;
    }

    dp[s1][s2] = max + 1;
    return max;
}

void _str(int** dp, char* a1, char* a2, int s1, int s2, char* s, int si)
{
    if (!a1[s1] && !a2[s2])
        return;

    if (!a1[s1])
    {
        while (a2[s2])
            s[si ++] = a2[s2 ++];
        return;
    }

    if (!a2[s2])
    {
        while (a1[s1])
            s[si ++] = a1[s1 ++];
        return;
    }

    if (dp[s1][s2] == dp[s1 + 1][s2])
        s[si ++] = a1[s1 ++];
    else if (dp[s1][s2] == dp[s1][s2 + 1])
        s[si ++] = a2[s2 ++];
    else
    {
        s[si ++] = a1[s1 ++];
        s2 ++;
    }
    _str(dp, a1, a2, s1, s2, s, si);
}

char* shortestCommonSupersequence(char * str1, char * str2)
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int** dp = malloc(sizeof(int*) * (l1 + 1));
    for (int i = 0; i <= l1; i ++)
        dp[i] = calloc(sizeof(int), (l2 + 1));
    _scs(dp, str1, str2, 0, 0);
    int l = l1 + l2 - dp[0][0] + 1;
    char* s = malloc(sizeof(char) * (l + 1));
    // _str(dp, str1, str2, 0, 0, s, 0);

    int s1 = 0;
    int s2 = 0;
    int si = 0;

    while (si < l)
    {
        if (!str1[s1])
        {
            while (str2[s2])
                s[si ++] = str2[s2 ++];
            break;
        }

        if (!str2[s2])
        {
            while (str1[s1])
                s[si ++] = str1[s1 ++];
            break;
        }

        if (dp[s1][s2] == dp[s1 + 1][s2])
            s[si ++] = str1[s1 ++];
        else if (dp[s1][s2] == dp[s1][s2 + 1])
            s[si ++] = str2[s2 ++];
        else
        {
            s[si ++] = str1[s1 ++];
            s2 ++;
        }
    }

    s[l] = 0;
    return s;
}

