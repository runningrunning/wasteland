void gen(int s, int e, int k, int* temp, int tl, int** ret, int* cur)
{
    if (!k)
    {
        ret[*cur] = (int*) malloc(sizeof(int) * tl);
        memcpy(ret[*cur], temp, sizeof(int) * tl);
        (*cur) ++;
    }
    else
    {
        for (int i = s; i <= e - k + 1; i ++)
        {
            temp[tl] = i;
            gen(i + 1, e, k - 1, temp, tl + 1, ret, cur);
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int** columnSizes, int* returnSize)
{
    if (k < n)
    {
        int di = 1;
        int dv = 1;

        int kk = k > (n - k) ? (n - k) : k;
        for(int i = 0; i < kk; i ++)
        {
            di *= n - i;
            dv *= 1 + i;
        }
        *returnSize = di / dv;
    }
    else if (k == n)
    {
        *returnSize = 1;
    }
    else
        return NULL;

    int size = *returnSize;

    printf("%d.\n", size);

    *columnSizes = malloc(sizeof(int) * size);

    for(int i = 0; i < size; i ++)
        (*columnSizes)[i] = k;

    int** ret = malloc(sizeof(int*) * size);
    int temp[256] = { 0 };
    int cur = 0;
    gen(1, n, k, temp, 0, ret, &cur);

    return ret;
}


