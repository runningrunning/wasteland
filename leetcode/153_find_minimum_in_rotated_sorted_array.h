int _find(int* nums, int s, int e)
{
    if (s >= e)
        return nums[s];
    int m = s + (e - s) / 2;

    if (nums[m] < nums[e])
        return _find(nums, s, m);
    else if (nums[m] == nums[e])
    {
        if (nums[s] != nums[m])
            return _find(nums, s, m);
        else
        {
            int a = _find(nums, s, m - 1);
            int b = _find(nums, m + 1, e);
            return a < b ? a : b;
        }
    }
    return _find(nums, m + 1, e);
}

int findMin(int* nums, int numsSize)
{
    return _find(nums, 0, numsSize - 1);
}
