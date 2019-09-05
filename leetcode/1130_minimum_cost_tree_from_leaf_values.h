// TODO Better solution, TRY NEW SOLUTION
// 1105
// DP again
// try no recursive version
// no recursive version
int mctFromLeafValues2(int* arr, int arrSize)
{
    int** dp = malloc(sizeof(int*) * arrSize);
    int** mp = malloc(sizeof(int*) * arrSize);

    for (int i = 0; i < arrSize; i ++)
    {
        dp[i] = calloc(sizeof(int), arrSize);
        mp[i] = calloc(sizeof(int), arrSize);
    }

    for (int i = 0; i < arrSize; i ++)
    {
        for (int j = 0; j < arrSize - i; j ++)
        {
            if (i == 0)
            {
                dp[j][j] = 0;
                mp[j][j] = arr[j];
            }
            else
            {
                int max = INT_MIN;
                int min = INT_MAX;
                for (int k = 0; k < i; k ++)
                {
                    int t = dp[j][j + k] + dp[j + k + 1][j + i] +
                        mp[j][j + k] * mp[j + k + 1][j + i];

                    if (t < min)
                    {
                        min = t;
                        max = mp[j][j + k] > mp[j + k + 1][j + i] ?
                            mp[j][j + k] : mp[j + k + 1][j + i];
                    }
                }

                dp[j][j + i] = min;
                mp[j][j + i] = max;
            }
        }
    }
    return dp[0][arrSize - 1];
}

int mflv(int* a, int s, int e, int** dp, int** mp, int* max)
{
    if (dp[s][e])
    {
        *max = mp[s][e];
        return dp[s][e];
    }

    if (s == e)
    {
        *max = a[s];
        mp[s][e] = a[s];
        return 0;
    }

    int m = 0;
    int min = INT_MAX;
    for (int i = s; i < e; i ++)
    {
        int m1, m2;
        int t = mflv(a, s, i, dp, mp, &m1) + mflv(a, i + 1, e, dp, mp, &m2);
        t += m1 * m2;

        if (min > t)
        {
            min = t;
            m = m1 > m2 ? m1 : m2;
        }
    }

    *max = m;
    mp[s][e] = m;
    dp[s][e] = min;
    return dp[s][e];
}

int mctFromLeafValues(int* arr, int arrSize)
{
    int** dp = malloc(sizeof(int*) * arrSize);
    int** mp = malloc(sizeof(int*) * arrSize);
    for (int i = 0; i < arrSize; i ++)
    {
        dp[i] = calloc(sizeof(int), arrSize);
        mp[i] = calloc(sizeof(int), arrSize);
    }

    int max = 0;
    mflv(arr, 0, arrSize - 1, dp, mp, &max);
    return dp[0][arrSize - 1];
}
