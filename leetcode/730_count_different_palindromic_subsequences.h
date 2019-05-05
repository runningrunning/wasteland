// TODO: top down to bottom up !
// be patient
// it's simple, just need to find the how to calculate it !!!
// mush generic method
// simple dp ??
// why DP is so hard !
// dp is not simple at all !
// by guessing or emulating ?
// as it's only ['a', 'b', 'c', 'd']
// https://leetcode.com/problems/count-different-palindromic-subsequences/discuss/109507/Java-96ms-DP-Solution-with-Detailed-Explanation
// wTF, just brilliant solution and easy to understand !
// top down to bottom up !
#define MOD 1000000007
int _cps(char* s, int i, int j, int** dp)
{
    if (i > j)
        return 0;

    if (dp[i][j])
        return dp[i][j] - 1;

    if (i == j)
    {
        dp[i][j] = 2;
        return dp[i][j] - 1;
    }

    long r = 0;
    if (s[i] != s[j])
        r = _cps(s, i + 1, j, dp) + _cps(s, i, j - 1, dp) - _cps(s, i + 1, j - 1, dp);
    else
    {
        int low = i + 1;
        int high = j - 1;

        while (low <= j && s[low] != s[j])
            low ++;

        while (high >= i && s[high] != s[i])
            high --;

        if (low > high)
            r = _cps(s, i + 1, j - 1, dp) * 2 + 2;
        else if (low == high)
            r = _cps(s, i + 1, j - 1, dp) * 2 + 1;
        else // brilliant here !!!
            r = _cps(s, i + 1, j - 1, dp) * 2 - _cps(s, low + 1, high - 1, dp);
    }

    r %= MOD;
    r += MOD + 1;
    dp[i][j] = r % MOD;
    return dp[i][j]  - 1;
}

int countPalindromicSubsequences(char* S)
{
    if (!S || !S[0])
        return 0;

    int l = strlen(S);
    if (l == 1)
        return 1;

    int** dp = malloc(sizeof(int*) * l);
    for (int i = 0; i < l; i ++)
        dp[i] = calloc(sizeof(int), l);
    return _cps(S, 0, l - 1, dp) % MOD;
}
