int largestUniqueNumber(int* A, int ASize)
{
    int max = 0;
    int* bs = calloc(sizeof(int), 1024);

    for (int i = 0; i < ASize; i ++)
    {
        bs[A[i]] ++;
        if (max < A[i])
            max = A[i];
    }

    for (int i = max; i >= 0; i --)
        if (bs[i] == 1)
            return i;

    return -1;
}
