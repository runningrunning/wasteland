int comp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes)
{
    qsort(arr, arrSize, sizeof(int), comp);

    int min = INT_MAX;
    for (int i = 0; i < arrSize - 1; i ++)
        if (min > arr[i + 1] - arr[i])
            min = arr[i + 1] - arr[i];

    int ri = 0;
    int* cs = NULL;
    int** rs = NULL;

    for (int i = 0; i < arrSize - 1; i ++)
    {
        if (arr[i + 1] - arr[i] == min)
        {
            cs = realloc(cs, sizeof(int) * (ri + 1));
            rs = realloc(rs, sizeof(int*) * (ri + 1));
            rs[ri] = malloc(sizeof(int) * 2);
            cs[ri] = 2;
            rs[ri][0] = arr[i];
            rs[ri][1] = arr[i + 1];
            ri ++;
        }
    }

    *returnSize = ri;
    *returnColumnSizes = cs;
    return rs;
}

