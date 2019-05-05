int bi_search(int* nums, int s, int e, int target)
{
    if (nums[s] >= target)
        return s;
    if (nums[e] < target)
        return e + 1;

    int i = (((e - s) + 1) / 2) + s;

    if (nums[i] == target)
        return i;

    return (nums[i] > target) ?
        bi_search(nums, s + 1, i - 1, target) : bi_search(nums, i + 1, e - 1, target);
}

int searchInsert(int* nums, int numsSize, int target)
{
    if (!numsSize)
        return 0;
    if (nums[0] >= target)
        return 0;
    if (nums[numsSize - 1] < target)
        return numsSize;
    if (numsSize == 2)
        return 1;

    return bi_search(nums, 1, numsSize - 2, target);
}

