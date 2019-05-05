int comp(const void* e1, const void* e2)
{
    return *((int*) e1) - *((int*) e2);
}

int largestPerimeter(int* A, int ASize)
{
    qsort(A, ASize, sizeof(int), comp);

    for (int i = ASize - 1; i >= 2; i --)
    {
        if (A[i] - A[i - 1] >= A[i - 2])
            continue;

        return A[i] + A[i - 1] + A[i - 2];
    }
    return 0;
}
