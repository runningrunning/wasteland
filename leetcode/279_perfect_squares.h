// bread first search !!!
// different algorithms
// how to reduce time
int ns(int n, int m, int* t)
{
    if (t[n - 1])
        return t[n - 1];

    int x = sqrt(n);

    if (m <= 1)
        return 0;

    int min = m;
    for (int i = x; i >= 1; i --)
    {
        x = ns(n - i * i, min - 1, t);
        if (x)
        {
            if (min > x + 1)
            {
                min = x + 1;
                t[n - 1] = min;
            }
        }
        else
            return min;
    }
    t[n - 1] = min;
    return min;
    // return 0;
}

int numSquares(int n) {
    int* nums = malloc(sizeof(int) * n);
    memset(nums, 0, sizeof(int) * n);
    for (int i = sqrt(n); i >= 1; i --)
        nums[i * i - 1] = 1;
    return ns(n, n, nums);
}
/* int numSquares(int n) */
/* { */
/*     return ns(n); */
/* } */

int ns2(int n, int* t, int need)
{
    if (t[n - 1])
        return t[n - 1];

    if (need <= 1)
        return 0;

    int min = n;
    for (int i = sqrt(n); i >= 1; i --)
    {
        int o = i * i;
        if (!(n % o))
        {
            if (n / o < min)
                min = n / o;
        }

        int x = 1;
        if (n - o)
        {
            x += ns2(n - o, t, min - 1);
            if (x == 1)
                continue;
        }
        if (x < min)
            min = x;
    }
    t[n - 1] = min;
    return min;
}

int numSquares_2(int n)
{
    int* nums = malloc(sizeof(int) * n);
    memset(nums, 0, sizeof(int) * n);

    for (int i = sqrt(n); i >= 1; i --)
        nums[i * i - 1] = 1;
    return ns2(n, nums, n);
}
