// stupid corner case for 0 and 1 input
void lds_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    lds_sort(n, cs, e - 1);
    lds_sort(n, e + 1, ce);
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    if (numsSize < 2)
    {
        if (numsSize == 0)
            return NULL;
        int* r = malloc(sizeof(int));
        r[0] = nums[0];
        *returnSize = 1;
        return r;
    }

    for (int i = 1; i < numsSize; i ++)
        if (nums[i - 1] > nums[i])
        {
            lds_sort(nums, 0, numsSize - 1);
            break;
        }

    int max = 0;
    int max_i = 0;

    int* m = malloc(sizeof(int) * numsSize);
    int* n = malloc(sizeof(int) * numsSize);

    for (int i = numsSize - 1; i>= 0; i --)
    {
        int mj = 1;
        int max_j = mj;
        for (int j = i + 1; j < numsSize; j ++)
        {
            if (!(nums[j] % nums[i]))
            {
                if (mj < 1 + n[j])
                    mj = 1 + n[j];

                if (mj >= 1 + m[j])
                    break;
            }
        }

        n[i] = mj;
        if (max < mj)
        {
            max = mj;
            max_i = i;
        }
        m[i] = max;
    }

    *returnSize = n[max_i];

    int t = nums[max_i];
    int ri = 0;
    int* r = malloc(sizeof(int) * n[max_i]);
    for (int i = max_i; i < numsSize; i ++)
    {
        if ((!(nums[i] % t)) && n[i] == max)
        {
            r[ri++] = nums[i];
            max --;
            t = nums[i];
        }
    }
    return r;
}
