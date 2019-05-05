/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int all = 1 << numsSize;
    *returnSize = all;
    *columnSizes = malloc(sizeof(int) * all);
    int** ret = malloc(sizeof(int*) * all);

    for(int i = 0; i < all; i ++)
    {
        ret[i] = malloc(sizeof(int) * numsSize);
        int n = 0;
        int t = i;
        int ii = 0;
        while(t)
        {
            if (t & 1)
                ret[i][n++] = nums[ii];
            ii ++;
            t >>= 1;
        }
        (*columnSizes)[i] = n;
    }
    return ret;
}
