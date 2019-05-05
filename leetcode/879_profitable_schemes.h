// greed or DP
// DP again !!!
// just brute force ?
// #include "./903_valid_permutations_for_DI_sequence.h"
// #include "./918_maximum_sum_circular_subarray.h"

#define MOD 1000000007
int profitableSchemes(int G, int P, int* group, int groupSize, int* profit, int profitSize)
{
    long** dp = malloc(sizeof(long*) * (G + 1));
    for (int i = 0; i <= G; i ++)
        dp[i] = calloc(sizeof(long), (P + 1));

    int* dn = calloc(sizeof(int), (G + 1));

    for (int k = 0; k < groupSize; k ++)
    {
        int g = group[k];
        int p = profit[k];

        if (g > G)
            continue;

        p = p < P ? p : P;

        // must start from the end, otherwise, it will calculate twice
        for (int i = G - g; i >= 0; i --)
        {
            if (!dn[i])
                continue;

            bool got = false;

            for (int j = 0; j < P - p; j ++)
                if (dp[i][j])
                {
                    dp[i + g][j + p] += dp[i][j];
                    dp[i + g][j + p] %= MOD;
                    got = true;
                }

            for (int j = P - p; j <= P; j ++)
                if (dp[i][j])
                {
                    dp[i + g][P] += dp[i][j];
                    dp[i + g][P] %= MOD;
                    got = true;
                }

            if (got)
                dn[i + g] ++;
        }

        dp[g][p] += 1;
        dn[g] ++;
    }

    long ret = 0;
    for (int i = 0; i <= G; i ++)
    {
        ret = ret + dp[i][P];
        ret %= MOD;
    }
    return ret;
}
