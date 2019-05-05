int maxProfit(int* prices, int pricesSize, int fee)
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

    int buy = - prices[0] - fee;
    int sell = 0;
    for (int i = 1; i < pi; i ++)
    {
        sell = (buy + prices[i]) > sell ? (buy + prices[i]) : sell;
        buy = (sell - prices[i] - fee) > buy ? (sell - prices[i] - fee) : buy;
    }

    return sell > buy ? sell : buy;
}
