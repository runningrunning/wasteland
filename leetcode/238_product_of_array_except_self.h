/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    if (!nums || numsSize < 2)
        return NULL;
    *returnSize = numsSize;
    if (numsSize == 2)
    {
        /* When it's 2, we need to switch 0 and 1 */
        int t = nums[0];
        nums[0] = nums[1];
        nums[1] = t;
        return nums;
    }

    int* ret = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    int pro = 1;
    for(int i = 0; i < numsSize; i ++)
    {
        pro *= nums[i];
        ret[i] = pro;
    }

    pro = 1;

    for(int i = numsSize - 1; i >= 0; i --)
    {
        pro *= nums[i];
        nums[i] = pro;
    }

    ret[numsSize - 1] = ret[numsSize - 2];
    for(int i = numsSize - 2; i >= 1; i --)
        ret[i] = ret[i - 1] * nums[i + 1];
    ret[0] = nums[1];
    return ret;
}
