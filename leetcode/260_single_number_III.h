/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int xor = 0;
    for(int i = 0; i < numsSize; i ++)
        xor ^= nums[i];

    int bit = xor ^ (xor & (xor - 1));
    int xor_2 = 0;

    for(int i = 0; i < numsSize; i ++)
    {
        if (nums[i] & bit)
            xor_2 ^= nums[i];
    }

    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);
    ret[0] = xor_2;
    ret[1] = xor_2 ^ xor;
    return ret;
}
