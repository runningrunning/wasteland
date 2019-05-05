/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    int c = 0;
    int* ret = malloc(sizeof(int) * 256);

    for (int i = 0; i < numsSize; i ++)
    {
        int n = nums[i];
        n = n > 0 ? n : -n;

        if (nums[n - 1] < 0)
        {
            if (!((c + 1) % 256))
                ret = realloc(ret, sizeof(int) * (c + 257));
            ret[c ++] = n;
        }
        else
            nums[n - 1] = -nums[n - 1];
    }
    *returnSize = c;
    return ret;
}
