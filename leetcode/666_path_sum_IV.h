int pathSum(int* nums, int numsSize)
{
    int h[15] = {0};
    int all[15] = {0};
    int si[] = {0, 1, 3, 7};

    for (int i = 0; i < numsSize; i ++)
    {
        int n = nums[i];
        int s_i = si[n/100 - 1];
        n %= 100;
        s_i += (n/10) - 1;
        h[s_i] = 1;
        all[s_i] = n % 10;
    }

    int r = 0;
    for (int i = 14; i >= 0; i--)
    {
        if (h[i])
        {
            r += all[i];

            int t = i;
            while (t)
            {
                t = (t - 1) / 2;
                h[t] = 0;
                r += all[t];
            }
        }
    }
    return r;
}
