int comp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int maxNumberOfApples(int* arr, int arrSize)
{
    qsort(arr, arrSize, sizeof(int), comp);

    int c = 0;
    for (int i = 0; i < arrSize; i ++)
    {
        if (c + arr[i] > 5000)
            return i;
        c += arr[i];
    }
    return arrSize;
}

