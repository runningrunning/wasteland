int pivotIndex(int* nums, int numsSize) {
    int all = 0;
    for (int i = 0; i < numsSize; i ++)
        all += nums[i];

    int l = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        all -= nums[i];
        if (l == all)
            return i;
        l += nums[i];
    }
    return -1;
}
