void nextPermutation(int* nums, int numsSize) {

    if (numsSize <= 1)
        return;

    int last = -1;
    for (int i = 0; i < numsSize - 1; i ++)
    {
        if (nums[i] < nums[i + 1])
            last = i;
    }

    int s = (last == -1) ? 0 : (last + 1);

    if (numsSize - 2 == last)
    {
        int t = nums[last];
        nums[last] = nums[last + 1];
        nums[last + 1] = t;
    }
    else
    {
        for(int i = 0; i < (numsSize - last  - 1) / 2; i ++)
        {
            int t = nums[s + i];
            nums[s + i] = nums[numsSize - 1 - i];
            nums[numsSize - 1 - i] = t;
        }

        if (last != -1)
        {
            int i = last + 1;
            for (; i < numsSize; i ++)
            {
                if (nums[i] > nums[last])
                    break;
            }
            int t = nums[i];
            nums[i] = nums[last];
            nums[last] = t;
        }
    }
}
