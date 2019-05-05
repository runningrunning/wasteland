void xg_sort(int* n, int s, int e)
{
    if (s >= e)
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

    xg_sort(n, cs, e - 1);
    xg_sort(n, e + 1, ce);
}

bool xg(int* n, int ns, int r, int x, char* t1, char* t2)
{
    if (ns - r <= 1)
        return ns == r;

    if (!x)
        return true;

    if (t1[x])
        return t1[x] != 1;

    // int pre = -1;

    for (int i = 0; i < ns; i ++)
    {
        if (n[i] < 0)
            continue;

        if (!(x ^ n[i]))
            continue;

        /* if (pre == n[i]) */
        /*     continue; */
        /* pre = n[i]; */

        int t = n[i];
        x ^= n[i];
        n[i] = - 1;
        if (!xg(n, ns, r + 1, x, t2, t1))
        {
            n[i] = t;
            t1[x] = 2;
            return true;
        }
        n[i] = t;
        x ^= t;
    }
    t1[x] = 1;
    return false;
}

bool xorGame(int* nums, int numsSize)
{
    int x = 0;
    for (int i = 0; i < numsSize; i ++)
        x ^= nums[i];

    char* t1 = malloc(65537);
    char* t2 = malloc(65537);
    bzero(t1, 65537);
    bzero(t2, 65537);

    if (!x)
        return true;

    // xg_sort(nums, 0, numsSize - 1);
    return xg(nums, numsSize, 0, x, t1, t2);
}

bool xg_1(int* n, int ns, int r, int x)
{
    if (ns - r <= 1)
        return ns == r;

    if (!x)
        return true;

    for (int i = 0; i < ns; i ++)
    {
        if (n[i] < 0)
            continue;

        if (!(x ^ n[i]))
            continue;

        int t = n[i];
        x ^= t;
        n[i] = -1;

        if (!xg_1(n, ns, r + 1, x))
        {
            n[i] = t;
            return true;
        }
        n[i] = t;
        x ^= t;
    }
    return false;
}

bool xorGame_1(int* nums, int numsSize)
{
    int x = 0;
    for (int i = 0; i < numsSize; i ++)
        x ^= nums[i];
    // out(nums, numsSize);

    if (!x)
        return true;

    return xg_1(nums, numsSize, 0, x);
}
