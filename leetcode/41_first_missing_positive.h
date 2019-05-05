int firstMissingPositive(int* nums, int numsSize)
{
    int start = 0;
    for(int i = 0; i < numsSize; i ++)
    {
        if (nums[i] <= 0 || nums[i] > numsSize)
        {
            nums[i] = 0;
            q_swap(&nums[i], &nums[start]);
            start ++;
        }
    }
    out(nums, numsSize);

    int t = 0;
    for(int i = start; i < numsSize; i ++)
    {
        if (nums[i] != i + 1)
        {
            while (nums[i] > i + 1)
            {
                t = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                if (t == nums[i])
                {
                    nums[i] = 0;
                    break;
                }
                nums[i] = t;
            }

            if (nums[i] && (nums[i] < i + 1))
            {
                nums[nums[i] - 1] = nums[i];
                nums[i] = 0;
            }
        }
    }

    out(nums, numsSize);

    for(int i = 0; i < numsSize; i ++)
        if (i != nums[i] - 1)
            return i + 1;
    return numsSize;
}
