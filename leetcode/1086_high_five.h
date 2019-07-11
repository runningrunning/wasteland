// WORST CODE BEAT 0 !!
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void* a, const void* b)
{
    int* ia = *((int**)a);
    int* ib = *((int**)b);
    return ia[0] == ib[0] ? (ia[1] - ib[1]) : (ia[0] - ib[0]);
}

int** highFive(int** items, int itemsSize, int* itemsColSize, int* returnSize, int** returnColumnSizes)
{
    qsort(items, itemsSize, sizeof(int*), comp);

    int ri = 0;
    int** r = NULL;
    int* c = NULL;

    for (int i = itemsSize - 1; i >= 0;)
    {
        int all = 0;
        int id = items[i][0];
        for (int j = 0; j < 5; j ++)
            all += items[i - j][1];
        r = realloc(r, sizeof(int*) * (ri + 1));
        c = realloc(c, sizeof(int) * (ri + 1));
        r[ri] = malloc(sizeof(int) * 2);
        r[ri][0] = id;
        r[ri][1] = all / 5;
        c[ri] = 2;

        ri ++;
        i -= 5;

        while (i >= 0 && items[i][0] >= id)
            i --;
    }

    int s = 0;
    int e = ri - 1;

    while (s < e)
    {
        int** t = r[s];
        r[s] = r[e];
        r[e] = t;
        s ++;
        e --;
    }

    *returnSize = ri;
    *returnColumnSizes = c;
    return r;
}

/*
int comp(const void* a, const void* b)
{
    return *((int*) a) - *((int*) b);
}
q
int** highFive(int** items, int itemsSize, int* itemsColSize, int* returnSize, int** returnColumnSizes)
{
    int* a = malloc(sizeof(int) * itemsSize);

    for (int i = 0; i < itemsSize; i ++)
        a[i] = items[i][0] << 16 | items[i][1];

    qsort(a, itemsSize, sizeof(int), comp);

    int ri = 0;
    int** r = NULL;
    int* c = NULL;

    for (int i = itemsSize - 1; i >= 0;)
    {
        int all = 0;
        int id = a[i] >> 16;
        int min = id << 16;

        for (int j = 0; j < 5; j ++)
            all += a[i - j] & 0xFFFF;
        r = realloc(r, sizeof(int*) * (ri + 1));
        c = realloc(c, sizeof(int) * (ri + 1));
        r[ri] = malloc(sizeof(int) * 2);
        r[ri][0] = a[i] >> 16;
        r[ri][1] = all / 5;
        c[ri] = 2;

        ri ++;
        i -= 5;

        while (i >= 0&& a[i] >= min)
            i --;
    }

    free(a);

    int s = 0;
    int e = ri - 1;

    while (s < e)
    {
        int** t = r[s];
        r[s] = r[e];
        r[e] = t;
        s ++;
        e --;
    }

    *returnSize = ri;
    *returnColumnSizes = c;
    return r;
}
*/
