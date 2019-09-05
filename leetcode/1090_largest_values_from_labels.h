// sort

int comp(const void* a, const void* b)
{
    return *((int*)b) - *((int*)a);
}

int largestValsFromLabels(int* values, int valuesSize, int* labels, int labelsSize, int num_wanted, int use_limit)
{
    int max_label = 0;
    for (int i = 0; i < valuesSize; i ++)
    {
        values[i] = values[i] << 16 | labels[i];
        if (max_label < labels[i])
            max_label = labels[i];
    }
    int* bs = calloc(sizeof(int), max_label + 1);
    qsort(values, valuesSize, sizeof(int), comp);

    int num = 0;
    int sum = 0;

    for (int i = 0; i < valuesSize; i ++)
    {
        int v = values[i] >> 16;
        int l = values[i] & 0xFFFF;

        if (bs[l] < use_limit)
        {
            bs[l] ++;
            num ++;
            sum += v;

            if (num == num_wanted)
                break;
        }
    }

    return sum;
}
