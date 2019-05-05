int maxSubArray(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    if (numsSize == 1)
        return nums[0];

    int a_max = nums[0];
    int c_max = nums[0];

    for(int i = 1; i < numsSize; i++)
    {
        if (nums[i] < 0)
        {
            if (a_max < c_max)
                a_max = c_max;
        }

        if (c_max < 0)
            c_max = 0;

        c_max += nums[i];
    }

    if ( a_max < c_max)
        a_max = c_max;

    return a_max;
}
