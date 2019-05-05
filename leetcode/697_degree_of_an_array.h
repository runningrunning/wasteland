int findShortestSubArray(int* nums, int numsSize)
{
    if (!numsSize)
        return 0;

    int a[50001] = {0};
    int c_en = 0;
    int c_st = 0;
    int max = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        int x = nums[i];
        if (a[x])
        {
            a[x] ++;
            int cur = a[x] & 0xFFFF;
            if (cur > max)
            {
                max = cur;
                c_st = a[x];
                c_en = i;
            }
            else if (cur == max)
            {
                if (i - (a[x] >> 16) < (c_en - (c_st >> 16)))
                {
                    c_st = a[x];
                    c_en = i;
                }
            }
        }
        else
            a[x] = (i << 16) | 1;
    }

    return c_en - (c_st >> 16) + 1;
}
