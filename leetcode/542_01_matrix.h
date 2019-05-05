/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize)
{
    if (!matrix || !matrixRowSize || !matrixColSize)
        return NULL;


    int r = matrixRowSize;
    int c = matrixColSize;

    int* cs = calloc(r, sizeof(int));
    int** ret = malloc(sizeof(int *) * r);

    int all = 0;

    for (int i = 0; i < r; i ++)
    {
        int a = 0;
        ret[i] = malloc(sizeof(int) * c);

        for (int j = 0; j < c; j ++)
        {
            if (matrix[i][j])
            {
                a += 1;
                ret[i][j] = -1;
            }
            else
                ret[i][j] = 0;
        }
        cs[i] = a;
        all += a;
    }

    int n = 0;
    while (all)
    {
        n ++;

        for (int i = 0; i < r; i ++)
        {
            if (!cs[i])
                continue;

            for (int j = 0; j < c; j ++)
            {
                if (ret[i][j] < 0)
                {
                    int up = (i == 0 || ret[i - 1][j] < 0) ? INT_MAX : ret[i - 1][j];
                    int down = (i == r - 1 || ret[i + 1][j] < 0) ? INT_MAX : ret[i + 1][j];
                    int left = (j == 0 || ret[i][j - 1] < 0) ? INT_MAX : ret[i][j - 1];
                    int right = (j == c - 1 || ret[i][j + 1] < 0)  ? INT_MAX : ret[i][j + 1];

                    int min = up < down ? up : down;
                    min = min < left ? min : left;
                    min = min < right ? min : right;

                    if (min <= n)
                    {
                        ret[i][j] = min + 1;
                        cs[i] --;
                        all --;
                    }
                }
            }
        }
    }

    *returnSize = r;
    *columnSizes = cs;

    for (int i = 0; i < r; i ++)
        cs[i] = c;

    return ret;
}
