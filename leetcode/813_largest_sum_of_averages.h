// dp with memory !!!
// too much stupid errors, try to do this again!!!
double lsoa(int* A, int i, int ASize, int K, int a, double* m)
{
    if (m[i * a + K - 1] != 0.0)
        return m[i * a + K - 1];

    int ca = 0;

    if (K == 1 || K == ASize - i)
    {
        for (int s = i; s < ASize; s ++)
            ca += A[s];

        if (K == 1)
            m[i * a] = ca / ((double)(ASize - i));
        else
            m[i * a + K - 1] = ca;

        return m[i * a + K - 1];
    }


    double max = 0.0;
    for (int s = i; s < ASize - K + 1; s ++)
    {
        ca += A[s];
        double t = ca / (double) (s - i + 1.0) + lsoa(A, s + 1, ASize, K - 1, a, m);
        if (t > max)
            max = t;
    }

    m[i * a + K - 1] = max;
    return max;
}

double largestSumOfAverages(int* A, int ASize, int K)
{
    double* mem = malloc(sizeof(double) * ASize * K);
    for (int i = 0; i < ASize * K; i ++)
        mem[i] = 0.0;
    return lsoa(A, 0, ASize, K, K, mem);
}
