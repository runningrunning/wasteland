// DP here, find better way ?
int mincostTickets(int* days, int daysSize, int* costs, int costsSize)
{
    int* dp = malloc(sizeof(int) * (daysSize + 1));
    dp[0] = 0;
    for (int i = 1; i <= daysSize; i ++)
    {
        int day = days[i - 1];
        int cur = dp[i - 1] + costs[0];
        bool check_7 = true;
        bool check_30 = true;
        for (int j = i - 1; j >= 0; j --)
        {
            int cday = j == 0 ? 0 : days[j - 1];
            if (check_7)
            {
                check_7 = cday + 6 >= day;
                cur = cur < (dp[j] + costs[1]) ? cur : (dp[j] + costs[1]);
            }
            if (check_30)
            {
                check_30 = cday + 29 >= day;
                cur = cur < (dp[j] + costs[2]) ? cur : (dp[j] + costs[2]);
            }
            else
                break;
        }
        dp[i] = cur;
    }
    return dp[daysSize];
}

