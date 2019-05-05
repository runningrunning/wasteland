int maxProfit(int* prices, int pricesSize)
{
    int pi = 0;

    // compress !!!!!
    for (int i = 0; i < pricesSize;)
    {
        prices[pi ++] = prices[i];

        if (i + 1 >= pricesSize)
            break;

        if (prices[i] <= prices[i + 1])
            while (i + 1 < pricesSize && prices[i] <= prices[i + 1])
                i ++;
        else
            while (i + 1 < pricesSize && prices[i] > prices[i + 1])
                i ++;
    }

    int buy = - prices[0];
    int sell = 0;
    for (int i = 1; i < pi; i ++)
    {
        sell = (buy + prices[i]) > sell ? (buy + prices[i]) : sell;
        buy = (sell - prices[i]) > buy ? (sell - prices[i]) : buy;
    }

    return sell > buy ? sell : buy;
}

/* int maxProfit(int* prices, int pricesSize) */
/* { */
/*     if (pricesSize <= 1 || !prices) */
/*         return 0; */
/*     int _max_pro = 0; */

/*     for(int i = 0; i < pricesSize - 1; i ++) */
/*     { */
/*         if (prices[i] < prices[i + 1]) */
/*             _max_pro += prices[i + 1] - prices[i]; */
/*     } */
/*     return _max_pro; */
/* } */
