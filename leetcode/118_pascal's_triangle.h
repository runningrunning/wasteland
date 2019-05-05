/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes)
{
    if (numRows == 0)
        return NULL;

    int** ret = malloc(sizeof(int*) * numRows);
    int* cs = malloc(sizeof(int) * numRows);

    for(int i = 1; i <= numRows; i++)
    {
        cs[i - 1] = i;
        ret[i - 1] = malloc(sizeof(int) * i);
        ret[i - 1][0] = 1;
        ret[i - 1][i - 1] = 1;

        if (i > 2)
        {
            for(int j = 0; j < i - 2; j ++)
                ret[i - 1][1 + j] = ret[i - 2][j] + ret[i - 2][j + 1];
        }
    }
    *columnSizes = cs;
    return ret;
}
