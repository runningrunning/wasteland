int _snd(int* nums, int s, int e)
{
    if (s >= e)
        return nums[s];

    int d = (e - s) / 2;
    int m = s + d;

    if (d & 1)
    {
        if (nums[m] == nums[m - 1])
            return _snd(nums, m + 1, e);
        else if (nums[m] == nums[m + 1])
            return _snd(nums, s, m - 1);
        return nums[m];
    }
    else
    {
        if (nums[m] == nums[m - 1])
            return _snd(nums, s, m - 2);
        else if (nums[m] == nums[m + 1])
            return _snd(nums, m + 2, e);
        return nums[m];
    }
}

int singleNonDuplicate(int* nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    return _snd(nums, 0, numsSize - 1);
}
