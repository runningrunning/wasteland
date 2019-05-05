
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
    *returnSize = num + 1;
    int* ret = malloc(sizeof(int) * (num + 1));
    ret[0] = 0;

    for(int i = 1; i <= num; i ++)
    {
        ret[i] = ret[i >> 1];
        ret[i] += i & 1;
    }
    return ret;
}
