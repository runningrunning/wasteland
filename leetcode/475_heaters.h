/* find better solutions ! */
void fr_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;
        }
    }

    fr_sort(n, cs, e - 1);
    fr_sort(n, e + 1, ce);
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize)
{
    int s = 0;
    while (s < housesSize - 1)
    {
        if (houses[s] > houses[s + 1])
        {
            fr_sort(houses, 0, housesSize - 1);
            break;
        }
        s ++;
    }

    s = 0;
    while (s < heatersSize - 1)
    {
        if (heaters[s] > heaters[s + 1])
        {
            fr_sort(heaters, 0, heatersSize - 1);
            break;
        }
        s ++;
    }

    int si = 1;
    for (int i = 1; i < heatersSize; i ++)
    {
        if (heaters[i] != heaters[i - 1])
            heaters[si ++] = heaters[i];
    }

    heatersSize = si;

    int lh, rh;

    if (heatersSize == 1)
    {
        lh = heaters[0] - houses[0];
        rh = houses[housesSize - 1] - heaters[0];
        lh = lh > 0 ? lh : (- lh);
        rh = rh > 0 ? rh : (- rh);
        return lh > rh ? lh : rh;
    }

    int max = 0;
    int min_h = heaters[0];
    int max_h = heaters[heatersSize - 1];

    int pre = houses[0] - 1;

    int pl = 0;
    int pr = 0;
    int ps = 0;

    for (int i = 0; i < housesSize; i ++)
    {
        int h = houses[i];

        if (pre == h)
            continue;

        pre = h;

        if (pl - max < h && h < pl + max)
            continue;
        if (pr - max < h && h < pr + max)
            continue;
        if (h <= min_h)
            max = max < (min_h - h) ? (min_h - h) : max;
        else if (h >= max_h)
            max = max < (h - max_h) ? (h - max_h) : max;
        else
        {
            int s = ps;
            if (h > heaters[ps])
            {
                int e = heatersSize - 1;
                while (s < e)
                {
                    int m = s + (e - s) / 2;
                    if (heaters[m] <= h)
                        s = m + 1;
                    else
                        e = m;
                }
            }

            lh = h - heaters[s - 1];
            rh = heaters[s] - h;

            int dh = lh > rh ? rh : lh;
            max = max < dh ? dh : max;

            pl = heaters[s - 1];
            pr = heaters[s];
            ps = s;
        }
    }
    return max;
}
