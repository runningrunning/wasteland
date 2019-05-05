void ish_sort(int* n, int s, int e)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
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
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    ish_sort(n, cs, e - 1);
    ish_sort(n, e + 1, ce);
}

bool isNStraightHand(int* hand, int handSize, int W)
{
    if (handSize % W)
        return false;

    if (W == 1)
        return true;

    ish_sort(hand, 0, handSize - 1);

    int ni = 0;
    int* ns = malloc(sizeof(int) * handSize);
    ns[0] = 1;

    for (int i = 1; i < handSize; i ++)
    {
        if (hand[i] == hand[i - 1])
            ns[ni] ++;
        else
        {
            ni ++;
            hand[ni] = hand[i];
            ns[ni] = 1;
        }
    }

    ni ++;

    if (ni < W)
        return false;

    int num = 0;

    for (int i = 0; i < ni - W + 1; i ++)
    {
        if (ns[i] == 0)
            continue;

        int x = ns[i];
        ns[i] = 0;
        num += x;

        for (int j = 1; j < W; j ++)
        {
            if (hand[i + j] != hand[i + j - 1] + 1)
                return false;
            ns[i + j] -= x;

            if (ns[i + j] < 0)
                return false;

            num += x;
        }
    }
    return num == handSize;
}
