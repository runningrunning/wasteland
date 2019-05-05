// find better solution
int _max(int* prices, int pricesSize)
{
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

int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize <= 1 || !prices)
        return 0;

    int c = 0;
    int* t = malloc(sizeof(int) * pricesSize);

    bool drop = true;
    for(int i = 0; i < pricesSize - 1; i ++)
    {
        bool cur = prices[i + 1] <= prices[i];
        if (cur != drop)
        {
            if (drop)
            {
                t[c++] = prices[i];
                drop = false;
            }
            else
            {
                t[c++] = prices[i];
                drop = true;
            }
        }
    }

    if (prices[pricesSize - 1] > prices[pricesSize - 2])
        t[c ++] = prices[pricesSize - 1];

    if (c < 2)
        return 0;

    if (c == 2)
        return t[c - 1] - t[c - 2];

    int max = 0;
    for(int i = 2; i < c; i += 2)
    {
        int m1 = _max(t, i);
        int m2 = _max(t + i, c - i);
        if (max < m1 + m2)
            max = m1 + m2;
    }

    return max;
}
