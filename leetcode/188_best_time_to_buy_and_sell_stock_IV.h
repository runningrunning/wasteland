// NEED clear mind
// how to write most understandable code
// STUPID OPTIMIZE, just don't use K step if it's larger than pricesSize / 2;

// DP SOLUTION is to find the proper way to divide.
// HOW TO USE DP ????????
// DP for all of stocks algorithms !!
// sort a doc about to how to solve them
// add best nothing

// corner cases ??

// buy
// sell

// how to limit it's k times

#define _MAX(a, b) (a) > (b) ? (a) : (b)

int maxProfit(int k, int* prices, int pricesSize)
{
    if (!k || !prices || !pricesSize)
        return 0;

    if (k >= pricesSize /  2)
    {
        int sell = 0;
        int buy = - prices[0];

        for (int i = 1; i < pricesSize; i ++)
        {
            int n_sell = _MAX(buy + prices[i], sell);
            int n_buy = _MAX(sell - prices[i], buy);
            sell = n_sell;
            buy = n_buy;
        }

        return sell > buy ? sell : buy;
    }

    int ks = 0;

    int* ss = calloc(sizeof(int), k + 1);
    int* bs = malloc(sizeof(int) * (k + 1));

    ss[0] = 0;
    bs[0] = - prices[0];

    bool reach = false;
    int max = INT_MIN;

    for (int i = 1; i < pricesSize; i ++)
    {
        for (int j = ks; j >= 0; j --)
        {
            if (bs[j] + prices[i] > ss[j + 1])
            {
                ss[j + 1] = bs[j] + prices[i];
                if (j + 1 > ks)
                {
                    ks = j + 1;

                    if (!reach)
                        bs[ks] = INT_MIN;
                }
            }

            if (ss[j] - prices[i] > bs[j])
                bs[j] = ss[j] - prices[i];
        }

        if (ks >= k)
        {
            reach = true;
            ks = k - 1;
        }
    }

    ks = reach ? k : ks;

    for (int i = 0; i <= ks; i ++)
    {
        if (max < ss[i])
            max = ss[i];

        if (max < bs[i])
            max = bs[i];
    }

    return max < 0 ? 0 : max;
}
