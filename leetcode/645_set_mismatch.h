/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 2;
    int* ret = malloc(sizeof(int) * 2);

    int xor = 0;
    int f1 = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        int y = nums[i];
        y = y < 0 ? - y : y;

        if (nums[y - 1] < 0)
            f1 = y;

        xor ^= (i + 1);
        xor ^= y;
        nums[y - 1] = - nums[y - 1];
    }
    xor ^= f1;
    ret[0] = f1;
    ret[1] = xor;

    return ret;
}
