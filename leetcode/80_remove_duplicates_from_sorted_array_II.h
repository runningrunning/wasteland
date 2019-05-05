int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2)
        return numsSize;

    bool enough = true;
    int pre = nums[0] - 1;
    int len = 0;
    for(int i = 0; i < numsSize; i ++)
    {
        
        if (pre != nums[i])
        {
            enough = false;
            nums[len++] = nums[i];
            pre = nums[i];
        }
        else if (!enough)
        {
            enough = true;
            nums[len++] = pre;
        }
    }
    return len;
}
