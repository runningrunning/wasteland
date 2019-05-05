int comp (const void * elem1, const void * elem2)
{
    return  *((int*)elem1) - *((int*)elem2);
}

void record(int*** all, int** cSize, int* rSize, int* limit, int* ret, int s)
{
    if ((*rSize) + 24 > (*limit))
    {
        *all = realloc(*all, sizeof(int*) * ((*limit) + 128));
        *cSize = realloc(*cSize, sizeof(int) * ((*limit) + 128));
        (*limit) += 128;
    }
    (*all)[*rSize] = malloc(sizeof(int) * s);
    memcpy((*all)[*rSize], ret, sizeof(int) * s);
    (*cSize)[*rSize] = s;
    (*rSize) ++;
}

void findSum(int* cs, int size, int target, int* result, int base, int ***all, int** cSize, int* rSize, int *rLimit )
{
    if (size <= 0 || cs[0] > target)
        return;


    int tg = target;
    int t = cs[0];
    int ri = 0;
    findSum(&cs[1], size - 1, tg, result, base + ri, all, cSize, rSize, rLimit);

    while(t <= tg)
    {
        result[base + ri ++]  = t;
        if (t == tg)
        {
            record(all, cSize, rSize, rLimit, result, base + ri);
            return;
        }
        else
        {
            tg -= t;
            findSum(&cs[1], size - 1, tg, result, base + ri, all, cSize, rSize, rLimit);
        }
    }
    return;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSize, int* returnSize)
{
    if (!candidatesSize)
    {
        *columnSize = NULL;
        *returnSize = 0;
        return NULL;
    }

    qsort(candidates, candidatesSize, sizeof(int), comp);
    int* result = malloc(sizeof(int) * target);
    memset(result, 0, sizeof(int) * target);


    int** all = malloc(sizeof(int*) * 128);
    memset(all, 0, sizeof(int*) * 128);
    int* cSize = malloc(sizeof(int) * 128);
    memset(cSize, 0, sizeof(int) * 128);
    int rSize = 0;
    int rlimit = 128;

    for(int i = 0; i < candidatesSize; i ++)
    {
        int tg = target;
        int t = candidates[i];
        int ri = 0;

        if (t > tg)
            break;

        while(t <= tg)
        {
            result[ri++] = t;
            if (t == tg)
            {
                record(&all, &cSize, &rSize, &rlimit, result, ri);
                break;
            }
            else
            {
                tg -= t;
                findSum(&(candidates[i + 1]), candidatesSize - i - 1, tg, result, ri, &all, &cSize, &rSize, &rlimit);
            }
        }
    }
    *columnSize = cSize;
    *returnSize = rSize;
    return all;
}
