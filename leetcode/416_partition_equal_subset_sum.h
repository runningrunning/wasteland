// same as 698_partition_to_k_equal_sum_subsets.h
// my way to do partition, no recursion !!
void _cp_sort(int* n, int s, int e)
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

    _cp_sort(n, cs, e - 1);
    _cp_sort(n, e + 1, ce);
}

bool canPartition(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return false;

    _cp_sort(nums, 0, numsSize - 1);
    int a = 0;
    for (int i = 0; i < numsSize; i ++ )
        a += nums[i];

    if (a & 1)
        return false;

    int m = a / 2;

    int s = 0;
    int e = numsSize - 1;

    int ii = 0;
    int ix[256];
    ix[ii ++] = e;

    int x = nums[e];
    int st = e - 1;

    if (x >= m)
        return x == m;

    while (true)
    {
        if (st >= 0 && x + nums[st] <= m)
        {
            ix[ii ++] = st;
            x += nums[st];
            if (x == m)
                return true;
        }

        st --;

        if (st < 0)
        {
            if (ii <= 1)
                return false;

            st = ix[-- ii];
            x -= nums[st];
            st --;
        }
    }

    return false;
}
