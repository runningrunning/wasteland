int findLengthOfLCIS(int* nums, int numsSize)
{
    if (!nums || numsSize < 2)
        return numsSize;

    int max = INT_MIN;
    int c = 1;
    for (int i = 1; i < numsSize; i ++)
    {
        if (nums[i] > nums[i - 1])
            c ++;
        else
        {
            if (c > max)
                max = c;
            c = 1;
        }
    }

    return c > max ? c : max;
}
