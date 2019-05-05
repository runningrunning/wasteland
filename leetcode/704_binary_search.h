int search(int* nums, int numsSize, int target)
{
    if (!nums)
        return -1;

    int s = 0;
    int e = numsSize - 1;

    if (nums[s] > target || nums[e] < target)
        return -1;

    while (s < e)
    {
        int m = s + (e - s) / 2;
        if (nums[m] < target)
            s = m + 1;
        else
            e = m;
    }
    return nums[s] == target ? s : -1;
}
