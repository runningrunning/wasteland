/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize)
{
    if (numsRowSize * numsColSize != r * c)
    {
        *columnSizes = malloc(sizeof(int) * numsRowSize);
        for (int i = 0; i < numsRowSize; i ++)
            (*columnSizes)[i] = numsColSize;
        *returnSize = numsRowSize;
        return nums;
    }

    int** ret = malloc(sizeof(int*) * r);

    *columnSizes = malloc(sizeof(int) * r);
    for (int i = 0; i < r; i ++)
    {
        (*columnSizes)[i] = c;
        ret[i] = malloc(sizeof(int) * c);
        for (int j = 0; j < c; j ++ )
        {
            int a = i * c + j;
            int x = a / numsColSize;
            int y = a % numsColSize;
            ret[i][j] = nums[x][y];
        }
    }
    *returnSize = r;
    return ret;
}
