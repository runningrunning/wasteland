int maxProfit(int* prices, int pricesSize)
{
    if ((pricesSize <= 1) || !prices)
        return 0;

    int _min = prices[0];
    int _max_pro = 0;

    for(int i = 1; i < pricesSize; i ++)
    {
        if (prices[i] > _min)
        {
            if (_max_pro < prices[i] - _min)
                _max_pro = prices[i] - _min;
        }
        else
            _min = prices[i];
    }
    return _max_pro;
}
