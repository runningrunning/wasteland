// binary search ??
int _swd(int* w, int s, int c)
{
    int n = 0;
    int p = 0;
    for (int i = 0; i < s; i ++)
    {
        if (p + w[i] > c)
        {
            p = w[i];
            n ++;
        }
        else
            p += w[i];
    }
    if (p)
        n ++;
    return n;
}

int shipWithinDays(int* weights, int weightsSize, int D)
{
    int max = INT_MIN;
    int all = 0;
    for (int i = 0; i < weightsSize; i ++)
    {
        if (weights[i] > max)
            max = weights[i];
        all += weights[i];
    }

    if (D == 1)
        return all;

    int s = max;
    int e = all;

    while (s < e)
    {
        int m = (s + e) / 2;
        int d = _swd(weights, weightsSize, m);

        if (d > D)
            s = m + 1;
        else
            e = m;
    }

    return s;
}
