int flipgame(int* fronts, int frontsSize, int* backs, int backsSize)
{
    int fs[64] = {0};
    int ns[64] = {0};
    int x, y;
    for (int i =  0; i < frontsSize; i ++)
    {
        if (fronts[i] == backs[i])
        {
            x = backs[i] / 32;
            y = backs[i] % 32;
            fs[x] |= 1 << y;
        }
        else
        {
            x = fronts[i] / 32;
            y = fronts[i] % 32;
            ns[x] |= 1 << y;

            x = backs[i] / 32;
            y = backs[i] % 32;
            ns[x] |= 1 << y;
        }
    }

    int s = 0;

    for (int i = 0; i < 64; i ++)
    {
        if (fs[i] ^ ns[i])
            break;
        s += 32;
    }

    for (int i = s; i <= 2000; i ++)
    {
        x = i / 32;
        y = i % 32;
        if ((!(fs[x] & (1 << y))) && (ns[x] & (1 << y)))
            return i;
    }
    return 0;
}
