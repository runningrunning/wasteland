int findMinDifference(char** timePoints, int timePointsSize)
{
    int a[1500] = {0};
    int all = timePointsSize;

    int x;
    int h, m;
    int min = INT_MAX;

    bool min_1 = false;

    for (int i = 0; i < all; i ++)
    {
        char* c = timePoints[i];
        h = (c[0] - '0') * 10 + (c[1] - '0');
        m = (c[3] - '0') * 10 + (c[4] - '0');
        // sscanf(timePoints[i], "%d:%d", &h, &m);
        x = h * 60 + m;

        if (min > x)
            min = x;

        if (a[x])
            return 0;
        a[x] ++;

        if (x && x < 1439)
            if (a[x - 1] || a[x + 1])
                min_1 = true;
    }

    if (min_1 || (a[0] && a[1439]))
        return 1;

    int min_i = min;
    int max_i;

    min = INT_MAX;

    int pre = min_i;
    for (int i = pre + 1; i < 1440; i ++)
    {
        if (a[i])
        {
            max_i = i;
            if (min > max_i - pre)
                min = max_i - pre;
            pre = i;
        }
    }

    if (min > (min_i + 1440 - max_i))
        min = min_i + 1440 - max_i;

    return min;
}
