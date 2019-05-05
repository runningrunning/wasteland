int comp (const void * elem1, const void * elem2)
{
    return *((int*)elem1) - *((int*)elem2);
}

int largestSumAfterKNegations(int* A, int ASize, int K)
{
    int in = 0;
    int all_p = 0;
    int all_m = 0;
    int min = 102; // must be 102, it's trick that if there is no min
    int max = - 101;
    for (int i = 0; i < ASize; i ++)
    {
        if (A[i] >= 0)
        {
            if (A[i] < min)
                min = A[i];
            all_p += A[i];
        }
        else
        {
            if (A[i] > max)
                max = A[i];
            all_m += A[i];
            A[in ++] = A[i];
        }
    }

    if (K >= in)
    {
        if ((K - in) % 2)
        {
            if (min > - max)
                return all_p - all_m + max * 2;
            return all_p - all_m - min * 2;
        }
        return all_p - all_m;
    }

    qsort(A, in, sizeof(int), comp);

    for (int i = 0; i < K; i ++)
    {
        all_p -= A[i];
        all_m -= A[i];
    }
    return all_p + all_m;
}
