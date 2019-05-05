// check NULL and overflow of at as 0 will be add more than once !!
// corner case, how to check whether the day is calculated
// simple dp
int maxVacationDays(int** flights, int flightsRowSize, int *flightsColSizes, int** days, int daysRowSize, int *daysColSizes)
{
    int day = daysColSizes[0];
    int** dp = malloc(sizeof(int*) * day);
    for (int i = 0; i < day; i ++)
        dp[i] = calloc(sizeof(int), flightsRowSize);

    int ai = 0;
    int* at = malloc(sizeof(int) * flightsRowSize);
    int bi = 0;
    int* bt = malloc(sizeof(int) * flightsRowSize);
    at[ai ++] = 0;

    for (int i = 0; i < day; i ++)
    {
        for (int j = 0; j < ai; j ++)
        {
            int x = at[j];
            int p = i ? (dp[i - 1][x] - 1) : 0; // must - 1
            int* fs = flights[x];

            if (!dp[i][x])  // must + 1, or it will add x more than once
                bt[bi ++] = x;

            if (!dp[i][x] || dp[i][x] - 1 < p + days[x][i])
                dp[i][x] = p + days[x][i] + 1; // add 1

            for (int f = 0; f < flightsColSizes[x]; f ++)
                if (fs[f])
                {
                    if (!dp[i][f]) // must + 1, or it will add f more than once
                        bt[bi ++] = f;

                    if (!dp[i][f] || dp[i][f] - 1 < p + days[f][i])
                        dp[i][f] = p + days[f][i] + 1; // add 1
                }
        }

        int* t = bt;
        bt = at;
        at = t;
        ai = bi;
        bi = 0;
    }

    int max = dp[day - 1][0];
    for (int i = 1; i < flightsRowSize; i ++)
        if (max < dp[day - 1][i])
            max = dp[day - 1][i];

    /* for (int i = 0; i < day; i ++) */
    /*     free(dp[i]); */

    /* free(dp); */
    return max - 1;
}

