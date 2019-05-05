int bl_search(int* nums, int s, int e, int target)
{
    if (s > e)
        return -1;

    if (nums[s] == target)
        return s;

    if (s == e)
        return -1;

    int i = ((e - s + 1) / 2) + s;

    if (nums[i] >= target)
        return bl_search(nums, s + 1, i, target);
    return bl_search(nums, i + 1, e, target);
}

int bh_search(int* nums, int s, int e, int target)
{
    if (s > e)
        return -1;

    if (nums[e] == target)
        return e;

    if (s == e)
        return -1;

    int i = ((e - s + 1) / 2) + s;

    if (nums[i] <= target)
        return bh_search(nums, i, e - 1, target);
    return bh_search(nums, s, i - 1, target);
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int l = bl_search(nums, 0, numsSize - 1, target);
    int* ret = malloc(sizeof(int) * *returnSize);
    ret[0] = l;
    if (l == -1)
    {
        ret[1] = -1;
        return ret;
    }
    ret[1] = bh_search(nums, l, numsSize - 1, target);
    return ret;
}
