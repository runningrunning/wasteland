// just pure DP  with some kind of optimization ? dp with the smallest
// could be all 0 !!!!!
// what the hell !!!!!!!, it's smaller
// [0,0,0,0,0,0]
// 3

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* cheapestJump(int* A, int ASize, int B, int* returnSize)
{
    if (!A || !ASize || !B || A[0] == -1)
    {
        *returnSize = 0;
        return NULL;
    }

    long* dp = calloc(sizeof(long), ASize);
    dp[0] = A[0];

    for (int i = 1; i < ASize; i ++)
    {
        if (A[i] == -1)
            continue;

        int s = i - B;

        if (s < 0)
            s = 0;

        int m = INT_MAX;
        long ms = 0;
        long ml = 0;

        for (; s < i; s ++)
        {
            if (A[s] == -1)
                continue;

            int om = dp[s] & 0xFFFFFFFF;
            int ol = (dp[s] >> 32) & 0xFFFF;

            if ((s == 0 || dp[s])
                && ((om < m) || (om == m && ol > ml)))
            {
                m = dp[s] & 0xFFFFFFFF;
                ms = s + 1;
                ml = ol;
            }
        }

        if (m == INT_MAX)
        {
            *returnSize = 0;
            return NULL;
        }

        dp[i] = (ms << 48) | ((ml + 1) << 32) | (A[i] + m);
    }

    if (!dp[ASize - 1])
    {
        *returnSize = 0;
        return NULL;
    }


    int n = 1;
    int i = ASize - 1;
    while (dp[i] >> 48)
    {
        n ++;
        i = (dp[i] >> 48) - 1;
    }

    *returnSize = n;
    int* r = malloc(sizeof(int) * n);

    i = ASize - 1;
    while (dp[i] >> 48)
    {
        r[-- n] = i + 1;
        i = (dp[i] >> 48) - 1;
    }
    r[0] = 1;
    return r;
}
