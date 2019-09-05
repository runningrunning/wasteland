// DP again
// Try no recursive DP version
// same as 1092
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

int longestCommonSubsequence(char * str1, char * str2)
{
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    int** dp = malloc(sizeof(int*) * (l1 + 1));
    for (int i = 0; i <= l1; i ++)
        dp[i] = calloc(sizeof(int), (l2 + 1));
    _scs(dp, str1, str2, 0, 0);
    return dp[0][0] - 1;
}
