int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize;

    int j = 1;
    for(int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
            nums[j ++] = nums[i];
    }
    return j;
}
