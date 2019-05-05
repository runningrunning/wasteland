// binary search for each item? for smaller number, it maybe not that good
// how to solve this in DP ways ???
// it should be DP problems ?
// find DP to do this issue
// how to write binary search start from the front and back from end

int _sa(int* n, int s, int m, int* t, int x)
{
    int nums = 0;

    for (int i = 0; i < s;)
    {
        nums ++;
        if (nums > x || (n[s] - n[i]) > (x - nums + 1) * m)
            return x + 1;

        int c = n[i] + m;

        int _s = i + 1;
        int _e = s;

        while (_s < _e)
        {
            int _m = _e - (_e - _s) / 2;

            if (n[_m] > c)
                _e = _m - 1;
            else
                _s = _m;
        }

        if (*t < (n[_e] - n[i]))
            *t = n[_e] - n[i];

        i = _e;
    }

    return nums;
}

int splitArray(int* nums, int numsSize, int m)
{
    if (!nums || !numsSize)
        return 0;

    int* a = malloc(sizeof(int) * (numsSize + 1));
    a[0] = 0;

    int all = 0;
    int ma = nums[0];
    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] > ma)
            ma = nums[i];
        a[i + 1] = nums[i] + a[i];
    }

    all = a[numsSize];

    if (m == 1)
        return all;

    if (m >= numsSize)
        return ma;

    int s = ma;
    int t = ma;
    int e = all - a[m - 2];

    while (s < e)
    {
        t = ma;
        int mid = (s + e) / 2;
        int x = _sa(a, numsSize, mid, &t, m);

        if (x > m)
            s = mid + 1;
        else
            e = mid;

        // printf("%d %d.\n", s, e);
    }

    t = ma;
    _sa(a, numsSize, s, &t, m);

    return t;
}
