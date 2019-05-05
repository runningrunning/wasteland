int arrayNesting(int* nums, int numsSize)
{
    if (!nums || numsSize < 2)
        return numsSize;

    int max = 1;
    int left = numsSize;

    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] == i)
        {
            left --;

            if (left <= max)
                return max;

            continue;
        }

        if (!nums[i])
            continue;

        int cur = 1;
        int tag = i;

        while (nums[tag] != i)
        {
            cur ++;
            int t = nums[tag];
            nums[tag] = 0;
            tag = t;
        }
        nums[tag] = 0;

        if (cur > max)
            max = cur;

        left -= cur;

        if (left <= max)
            return max;
    }
    return max;
}
