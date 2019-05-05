int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int minIncrementForUnique(int* A, int ASize)
{
    if (!A || ASize < 2)
        return 0;

    if (ASize == 2)
        return A[0] == A[1] ? 1 : 0;

    qsort(A, ASize, sizeof(int), comp);

    int n = 0;
    int a = A[0] + 1;
    for (int i = 1; i < ASize; i ++)
    {
        if (A[i] >= a)
            a = A[i] + 1;
        else
        {
            n += a - A[i];
            a ++;
        }
    }
    return n;
}
