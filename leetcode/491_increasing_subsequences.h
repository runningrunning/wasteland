// learn a lot
// DFS ?, how to remove duplicate !!!, similar with permutation with duplicates !!
// permutation and how to remove duplication, don't try the same number again !!!!!!!
void fsq(int* n, int i, int e, int ti, int* t, int* rs, int** cs, int*** r)
{
    if (ti > 1)
    {
        (*rs) ++;
        int n = *rs;
        *r = realloc(*r, sizeof(int**) * n);
        *cs = realloc(*cs, sizeof(int*) * n);

        (*cs)[n - 1] = ti;
        (*r)[n - 1] = malloc(sizeof(int) * ti);
        memcpy((*r)[n - 1], t, sizeof(int) * ti);
    }

    if (i > e)
        return;

    int sb[8] = {0};
    int c = ti ? t[ti - 1] : -101;

    for (; i <= e; i ++)
    {
        int tb = n[i] + 100;
        int x = tb / 32;
        int y = tb % 32;
        if (sb[x] & (1 << y))
            continue;
        sb[x] |= 1 << y;

        if (n[i] >= c)
        {
            t[ti] = n[i];
            fsq(n, i + 1, e, ti + 1, t, rs, cs, r);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findSubsequences(int* nums, int numsSize, int** columnSizes, int* returnSize)
{
    int rs = 0;
    int* cs = NULL;
    int** r = NULL;
    int* t = malloc(sizeof(int) * numsSize);
    fsq(nums, 0, numsSize - 1, 0, t, &rs, &cs, &r);
    *returnSize = rs;
    *columnSizes = cs;
    return r;
}

/* /\** */
/*  * Return an array of arrays of size *returnSize. */
/*  * The sizes of the arrays are returned as *columnSizes array. */
/*  * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free(). */
/*  *\/ */
/* int** findSubsequences(int* nums, int numsSize, int** columnSizes, int* returnSize) */
/* { */
/*     int bits[15] = {0}; */

/*     for (int i = 0; i < numsSize - 1; i ++) */
/*     { */
/*         int t = nums[i]; */

/*         for (int j = i + 1; j < numsSize; j ++) */
/*             if (nums[j] >= t) */
/*                 bits[i] |= 1 << j; */
/*     } */

/*     for (int i = 0; i < numsSize; i ++) */
/*     { */
/*         int found = 0; */
/*     } */
/* } */
