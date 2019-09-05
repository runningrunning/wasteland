// practice more and read the description carefully
// After partitioning, each subarray has their values changed to become the maximum
// value of that subarray, it means the value in that subarray will be the maximum one
int maxSumAfterPartitioning(int* A, int ASize, int K)
{
    int max = 0;
    int* d = calloc(sizeof(int), K);

    for (int i = 0; i < K; i ++)
    {
        max = max < A[i] ? A[i] : max;
        d[i] = max * (i + 1);
    }

    max = d[K - 1];
    for (int i = K; i < ASize; i ++)
    {
        int cur = 0;
        for (int j = 0; j < K; j ++)
        {
            if (A[i - j] > cur)
                cur = A[i - j];

            if (max < cur * (j + 1) + d[(i - j - 1) % K])
                max = cur * (j + 1) + d[(i - j - 1) % K];
        }
        d[i % K] = max;
    }
    return max;
}
