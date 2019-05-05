void fp(int* n, int s, int e)
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
        while(n[i] < n[s]) i ++;
        while(n[e] > n[s]) e --;

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

    fp(n, cs, e - 1);
    fp(n, e + 1, ce);
}

int findPairs(int* nums, int numsSize, int k)
{
    if (numsSize < 2)
        return 0;

    fp(nums, 0, numsSize - 1);

    int all = 0;
    int i = 0;
    int j = 1;
    int pre_s = INT_MIN;
    int pre = INT_MIN;

    int s = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        if (pre != nums[i])
        {
            nums[s ++] = nums[i];
            pre = nums[i];
        }
        else
        {
            if (pre_s != pre)
            {
                all ++;
                pre_s = pre;
            }
        }
    }

    if (!k)
        return all;

    all = 0;
    pre = INT_MIN;
    while(j < s)
    {
        if (i >= j)
            j ++;
        else
        {
            int d = nums[j] - nums[i];
            if (d == k)
            {
                if (pre != nums[i])
                    all ++;
                pre = nums[i];

                i ++;
                j ++;
            }
            else if (d < k)
                j ++;
            else
                i ++;
        }
    }
    return all;
}
