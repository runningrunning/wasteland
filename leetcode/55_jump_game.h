bool canJump(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return true;

    if (numsSize == 2)
        return nums[0] > 0;

    int i_max = 0 + nums[0];

    for(int i = 1; i <= i_max; i ++)
    {
        if (i_max < i + nums[i])
            i_max = i + nums[i];

        if (i_max >= numsSize - 1)
            return true;
    }

    return false;
}
