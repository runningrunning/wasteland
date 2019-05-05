void dae_sort(int* n, int s, int e)
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

    dae_sort(n, cs, e - 1);
    dae_sort(n, e + 1, ce);
}

int deleteAndEarn(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    if (numsSize == 1)
        return nums[0];

    dae_sort(nums, 0, numsSize - 1);

    int all_i = 0;
    int pre_i = 0;
    int pre = nums[pre_i];

    for (int i = 1; i < numsSize; i ++)
    {
        if (pre != nums[i])
        {
            nums[all_i ++] = nums[i - 1] | ((i - 1 - pre_i) << 16);
            pre_i = i;
            pre = nums[i];
        }
    }
    nums[all_i ++] = nums[numsSize - 1] | ((numsSize - 1 - pre_i) << 16);

    int mi = 0;
    int max[2] = {0, 0};

    pre = (nums[0] & 0xFFFF) - 1;

    for (int i = 0; i < all_i; i ++)
    {
        int n = (nums[i] >> 16) + 1;
        int c = nums[i] & 0xFFFF;
        if (c - pre == 1)
        {
            int in = (mi ++) % 2;
            if (max[in] > max[1 - in])
                max[1 - in] = max[in];
            max[in] += n * c;
        }
        else
        {
            mi = 1;
            max[0] = max[0] > max[1] ? max[0] : max[1];
            max[1] = max[0];
            max[0] += n * c;
        }
        pre = c;
    }
    return max[0] > max[1] ? max[0] : max[1];
}
