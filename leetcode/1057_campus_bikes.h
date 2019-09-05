// just sort ?

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

#define MASK 0x3FF

int* assignBikes(int** workers, int workersSize, int* workersColSize, int** bikes, int bikesSize, int* bikesColSize, int* returnSize)
{
    int ai = 0;
    int delta = 0;
    int* all = malloc(sizeof(int) * workersSize * bikesSize);

    for (int i = 0; i < workersSize; i ++)
        for (int j = 0; j < bikesSize; j ++)
        {
            delta = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
            all[ai ++] = delta << 20 | i << 10 | j;
        }

    int num = 0;
    char* ws = calloc(sizeof(char), workersSize);
    char* bs = calloc(sizeof(char), bikesSize);
    int* r = malloc(sizeof(int) * workersSize);

    qsort(all, ai, sizeof(int), comp);
    for (int i = 0; i < ai; i ++)
    {
        int a = all[i];
        int w = (a >> 10) & MASK;
        int b = a & MASK;

        if (ws[w] || bs[b])
            continue;
        r[w] = b;
        ws[w] = bs[b] = 1;
        num ++;

        if (num == workersSize)
            break;
    }

    *returnSize = workersSize;
    return r;
}

