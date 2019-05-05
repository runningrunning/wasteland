// TODO
// binary search ?
// be careful about how to write Binary Search !!!!!!
// LEARN A LOT, DO IT AGAIN !!
// binary search have different variation with find the first one and fine the last one
// the first one is s + (e - s) / 2, the last one is e - (e - s) / 2

int comp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int minEatingSpeed(int* piles, int pilesSize, int H)
{
    if (!piles || !pilesSize)
        return 0;
    qsort(piles, pilesSize, sizeof(int), comp);

    int s = 1;
    int e = piles[pilesSize - 1];

    if (pilesSize == H)
        return e;

    while (s < e)
    {
        long x = 0;
        int m = s + (e - s) / 2; // find the first one ==

        int is = 0;
        int ie = pilesSize - 1;

        while (is < ie)
        {
            int im = ie - (ie - is) / 2;   // find the latest one ==, change e with m
            if (piles[im] > m)
                ie = im - 1;
            else
                is = im;
        }

        x = is + (piles[is] <= m ? 1 : 0);

        for (int i = x; i < pilesSize; i ++)
            x += (piles[i] + m - 1) / m;

        if (x > H) // fine the first one, change s with m
            s = m + 1;
        else
            e = m;

    }
    return s;
}
