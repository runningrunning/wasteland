/* numsSize is 1 is also true */
int dominantIndex(int* nums, int numsSize) {
    if (!nums || !numsSize)
        return -1;

    if (numsSize == 1)
        return 0;

    int pi = -1;
    int max_1 = 0;
    int max_2 = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] >= max_2)
        {
            if (nums[i] >= max_1)
            {
                max_2 = max_1;
                max_1 = nums[i];
                pi = i;
            }
            else
                max_2 = nums[i];
        }
    }

    if (!max_1)
        return -1;

    return max_1 >= 2 * max_2 ? pi : -1;
}
