/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* could the nums with some duplicates ? */
/* Stupid corner case of overflow! */
char** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize)
{
    *returnSize = 0;

    int rt = 0;
    char** ret = NULL;

    if (!nums || !numsSize)
    {
        if (lower > upper)
            return NULL;
        *returnSize = 1;

        ret = malloc(sizeof(char*));
        char* t = malloc(32);
        if (lower == upper)
            sprintf(t, "%d", lower);
        else
            sprintf(t, "%d->%d", lower, upper);
        ret[0] = t;
        return ret;
    }

    int s = 0;
    int e = numsSize - 1;

    if (nums[0] == lower && nums[e] == upper && numsSize == upper - lower + 1)
        return NULL;

    long st = lower;
    for (int i = 0; i < numsSize; i ++)
    {
        if (st < nums[i])
        {
            rt ++;
            if (!ret)
                ret = malloc(sizeof(char*));
            else
                ret = realloc(ret, sizeof(char*) * rt);
            char* t = malloc(32);

            if (st == nums[i] - 1)
                sprintf(t, "%d", st);
            else
                sprintf(t, "%d->%d", st, nums[i] - 1);
            ret[rt - 1] = t;
            st = (long) nums[i] + 1;
        }
        else
        {
            s = i;
            e = numsSize - 1;

            while(s < e)
            {
                int m = e - (e - s) / 2;
                if (nums[m] > nums[i] + m - i)
                    e = m - 1;
                else
                    s = m;
            }
            st = (long) nums[s] + 1;
        }
        i = s;
    }

    if (st <= upper)
    {
        rt ++;
        if (!ret)
            ret = malloc(sizeof(char*));
        else
            ret = realloc(ret, sizeof(char*) * rt);
        char* t = malloc(32);

        if (st == upper)
            sprintf(t, "%d", st);
        else
            sprintf(t, "%d->%d", st, upper);
        ret[rt - 1] = t;
    }
    *returnSize = rt;
    return ret;
}
