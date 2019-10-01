bool isMajorityElement(int* nums, int numsSize, int target)
{
    int need = (numsSize / 2) + 1;
    for (int i = 0; i <= numsSize - need; i ++)
    {
        if (nums[i] == target)
            return nums[i + need - 1] == target;
    }
    return false;
}

