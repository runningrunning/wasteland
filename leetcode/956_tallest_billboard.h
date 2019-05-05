// how to solve this in DP
// why DP ?
// DP is much faster ???
// try no recursion
// how to solve this kinda of issue ?
// should I take care of the same ??????
// just write code ? any fancy algorithm for this one ??
int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int tallestBillboard(int* rods, int rodsSize)
{
    if (!rods || rodsSize < 2)
        return 0;

    if (rodsSize == 2)
        return rods[0] == rods[1] ? rods[0] : 0;

    int min = INT_MAX;
    int all = 0;
    for (int i = 0; i < rodsSize; i ++)
    {
        if (rods[i] < min)
            min = rods[i];
        all += rods[i];
    }

    qsort(rods, rodsSize, sizeof(int), comp);

    all /= 2;

    int* ns = malloc(sizeof(int) * rodsSize);
    int* xns = malloc(sizeof(int) * rodsSize);

    // how to permutation those result ?
    for (int i = all; i >= min;)
    {
        int ni = 0;
        int new = 0;
        int cur = 0;
        int need = i;
        int max = min - 1;

        while (true)
        {
            if (new < rodsSize && cur + rods[new] <= need)
            {
                cur += rods[new];
                rods[new] = - rods[new];
                ns[ni ++] = new;
                new += 1;

                if (cur != need)
                {
                    if (cur > max)
                        max = cur;

                    continue;
                }

                int xni = 0;
                int xnew = 0;
                int xcur = 0;

                while (true)
                {
                    while (xnew < rodsSize && rods[xnew] < 0)
                        xnew ++;

                    if (xnew < rodsSize && xcur + rods[xnew] <= need)
                    {
                        xcur += rods[xnew];
                        rods[xnew] = - rods[xnew];
                        xns[xni ++] = xnew;
                        xnew += 1;

                        if (xcur != need)
                            continue;

                        return need;
                    }

                    if (!xni)
                        break;

                    int top = xns[-- xni];
                    xcur += rods[top];
                    rods[top] = - rods[top];
                    xnew = top + 1;

                    int pre = rods[top];
                    while (xnew < rodsSize && (rods[xnew] < 0 || rods[xnew] == pre))
                        xnew ++;
                }
            }

            if (!ni)
                break;

            int top = ns[-- ni];
            cur += rods[top];
            rods[top] = - rods[top];
            new = top + 1;

            int pre = rods[top];
            while (new < rodsSize && rods[new] == pre)
                new ++;
        }

        // printf("max is %d.\n", max);
        i = max;
    }
    return 0;
}
