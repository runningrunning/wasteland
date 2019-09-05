int movesToMakeZigzag(int* nums, int numsSize)
{
    if (numsSize == 1)
        return 0;

    int min1 = 0;
    int min2 = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        if (i % 2)
        {
            if (i == numsSize - 1)
                min2 += nums[i - 1] > nums[i] ? 0 : (nums[i] - nums[i - 1] + 1);
            else
            {
                int min = nums[i + 1] < nums[i - 1] ? nums[i + 1] : nums[i - 1];
                min2 += min > nums[i] ? 0 : (nums[i] - min + 1);
            }
        }
        else
        {
            if (i == 0)
                min1 += nums[i + 1] > nums[i] ? 0 : (nums[i] - nums[i + 1] + 1);
            else if (i == numsSize - 1)
                min1 += nums[i - 1] > nums[i] ? 0 : (nums[i] - nums[i - 1] + 1);
            else
            {
                int min = nums[i + 1] < nums[i - 1] ? nums[i + 1] : nums[i - 1];
                min1 += min > nums[i] ? 0 : (nums[i] - min + 1);
            }
        }
    }

    return min1 < min2 ? min1 : min2;
}

