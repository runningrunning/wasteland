/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int comp (const void * elem1, const void * elem2)
{
    return *((int*)elem1) - *((int*)elem2);
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    qsort(nums, numsSize, sizeof(int), comp);
    int nu = 0;
    int ns = 0;
    int* uniq = malloc(sizeof(int) * numsSize);
    int* same = malloc(sizeof(int) * numsSize);

    int pre = nums[0] - 1;

    for(int i = 0; i < numsSize; i ++)
    {
        if (nums[i] != pre)
            pre = uniq[nu ++] = nums[i];
        else
            same[ns ++] = pre;
    }

    int all = 1 << nu;
    *returnSize = all;
    *columnSizes = malloc(sizeof(int) * all);
    int** ret = malloc(sizeof(int*) * all);

    for(int i = 0; i < all; i ++)
    {
        ret[i] = malloc(sizeof(int) * nu);
        int n = 0;
        int t = i;
        int ii = 0;
        while(t)
        {
            if (t & 1)
                ret[i][n++] = uniq[ii];
            ii ++;
            t >>= 1;
        }
        (*columnSizes)[i] = n;
    }

    if (!ns)
        return ret;

    pre = same[0] - 1;
    int c_all;

    for(int x = 0; x < ns; x ++)
    {
        if (pre != same[x])
            c_all = all / 2;

        all += c_all;
        ret = realloc(ret, sizeof(int*) * all);
        *columnSizes = realloc(*columnSizes, sizeof(int) * all);
        *returnSize = all;

        int need = c_all;
        if (pre != same[x])
        {
            for(int i = 0; i < all - c_all; i ++)
            {
                for(int j = 0; j < (*columnSizes)[i]; j++)
                {
                    if (ret[i][j] == same[x])
                    {
                        int s = (*columnSizes)[i];
                        ret[all - need] = malloc(sizeof(int) * (s + 1));
                        (*columnSizes)[all - need] = s + 1;
                        memcpy(ret[all - need], ret[i], sizeof(int) * s);
                        ret[all - need][s] = same[x];
                        need --;
                        break;
                    }
                }

                if (!need)
                    break;
            }
        }
        else
        {
            for(int i = 0; i < c_all; i ++)
            {
                int s = (*columnSizes)[all - 2 * c_all + i];
                ret[all - c_all + i] = malloc(sizeof(int) * (s + 1));
                (*columnSizes)[all - c_all + i] = s + 1;
                memcpy(ret[all - c_all + i], ret[all - 2 * c_all + i], sizeof(int) * s);
                ret[all - c_all + i][s] = same[x];
            }
        }
        pre = same[x];
    }

    return ret;
}
