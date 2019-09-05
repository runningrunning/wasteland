// reverse
int comp(const void* a, const void* b)
{
    return *((int*)b) - *((int*)a);
}

char * minimizeError(char ** prices, int pricesSize, int target)
{
    int all = 0;
    int low = 0;
    int* round = malloc(sizeof(int) * pricesSize);
    int same = 0;
    char* r = malloc(sizeof(char) * 33);

    for (int i = 0; i < pricesSize; i ++)
    {
        char* s = prices[i];
        int x = 0;
        int si = 0;
        while (s[si] != '.')
            x = x * 10 + s[si ++] - '0';
        si ++;
        low += x;

        round[i] = (s[si] - '0') * 100 + (s[si + 1] - '0') * 10 + (s[si + 2] - '0');
        if (!round[i])
            same ++;
        all += round[i];
    }

    if (target < low || target > low + pricesSize - same)
    {
        strcpy(r, "-1");
        return r;
    }

    target -= low;

    qsort(round, pricesSize, sizeof(int), comp);

    for (int i = 0; i < target; i ++)
    {
        all -= round[i];
        all += 1000 - round[i];
    }

    sprintf(r, "%.3f", all / 1000.0);
    return r;
}
