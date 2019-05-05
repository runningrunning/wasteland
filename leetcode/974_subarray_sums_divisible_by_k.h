int subarraysDivByK(int* A, int ASize, int K)
{
    int* mod = calloc(sizeof(int), (K + 1));

    int all = 0;
    int sum = ((A[0] % K) + K) % K;
    mod[sum] ++;
    if (sum == 0)
        all ++;

    for (int i = 1; i < ASize; i ++)
    {
        sum = (((sum + A[i]) % K) + K) % K;
        mod[sum] ++;
        all += mod[sum] - 1;
        // printf("%d %d %d.\n", sum, mod[sum], all);
        if (!sum)
            all ++;
    }
    return all;
}

