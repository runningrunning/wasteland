int so(int* price, int** special, int specialRowSize, int* needs, int size, int* mem, int b)
{
    int min = 0;
    int index = 0;

    for (int i = 0; i < size; i ++)
    {
        index = index * b + needs[i];
        min += needs[i] * price[i];
    }

    if (!index)
        return 0;

    if (mem[index])
        return mem[index];

    for (int i = 0; i < specialRowSize; i ++)
    {
        int temp = 0;
        int want[6] = {0};

        int j = 0;
        for (j = 0; j < size; j ++)
        {
            if (needs[j] >= special[i][j])
                want[j] = needs[j] - special[i][j];
            else
                break;
        }

        if (j == size)
        {
            temp = special[i][size] + so(price, special, specialRowSize, want, size, mem, b);
            if (temp < min)
                min = temp;
        }
    }

    mem[index] = min;
    return min;
}

int shoppingOffers(int* price, int priceSize, int** special, int specialRowSize, int *specialColSizes, int* needs, int needsSize)
{
    int n = 0;
    for (int i = 0; i < needsSize; i ++)
        if (n < needs[i])
            n = needs[i];

    int m = 1;
    for (int i = 0; i < priceSize; i ++)
        m *= (n + 1);
    int* mem = calloc(sizeof(int), m);
    return so(price, special, specialRowSize, needs, priceSize, mem, n + 1);
}
