int gcd(int x, int y)
{
    if (!(x % y))
        return y;
    return gcd(y, x % y);
}

bool hasGroupsSizeX(int* deck, int deckSize)
{
    int ni = 1;
    int nums = 0;

    short* ds = calloc(sizeof(short), 10000);
    short* ns = malloc(sizeof(short) * 10000);

    for (int i = 0; i < deckSize; i ++)
    {
        int x = deck[i];

        if (!ds[x])
        {
            ds[x] = ni;
            ns[ni] = 0;

            ni ++;
            nums ++;
        }
        else if (ns[ds[x]] == 1)
            nums --;
        ns[ds[x]] ++;
    }

    if (nums)
        return false;

    int n = ns[1];

    /* if (ni == 2) */
    /*     return n > 1; */

    for (int i = 2; i < ni; i ++)
    {
        n = n > ns[i] ? gcd(n, ns[i]) : gcd(ns[i], n);
        if (n == 1)
            return false;
    }
    return true;
}
