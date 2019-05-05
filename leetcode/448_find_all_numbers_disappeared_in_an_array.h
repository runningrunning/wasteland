/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int n = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int c = nums[i];
        c = c > 0 ? c : - c;
        c -= 1;
        if (nums[c] < 0)
            n ++;
        else
            nums[c] = - nums[c];
    }

    int* ret = malloc(sizeof(int) * n);
    *returnSize = n;
    n = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] > 0)
            ret[n ++] = i + 1;
    }
    return ret;
}
