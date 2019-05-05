int br_search(int* nums, int s, int e, int target)
{
    if (s > e)
        return -1;

    if (nums[s] == target)
        return s;

    if (s == e)
        return -1;

    int i = ((e - s + 1) / 2) + s;

    if (nums[i] == target)
        return i;

    if (nums[s] < nums[i])
    {
        if (nums[s] > target || nums[i] < target)
            return br_search(nums, i + 1, e, target);
        return br_search(nums, s + 1, i - 1, target);
    }
    else
    {
        if (nums[s] < target || nums[i] > target)
            return br_search(nums, s + 1, i - 1, target);
        return br_search(nums, i + 1, e, target);
    }
}

int search(int* nums, int numsSize, int target)
{
    return br_search(nums, 0, numsSize - 1, target);
}
