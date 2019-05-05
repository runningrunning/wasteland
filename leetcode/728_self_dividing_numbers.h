/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize)
{
    *returnSize = 0;
    if (left > right)
        return NULL;

    int* ret = malloc(sizeof(int) * (right - left + 1));

    int id = 0;
    for (int i = left; i <= right; i ++)
    {
        int x = i;
        while(x)
        {
            int y = x % 10;
            if (!y || (i % y))
                break;
            x /= 10;
        }

        if (!x)
            ret[id ++] = i;
    }

    *returnSize = id;
    return ret;
}
