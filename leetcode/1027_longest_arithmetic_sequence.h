// CPP is better than C ???
// use unorder map replace fix length ???????
// better solution ?
// just brute force ????
// hash ?
// find better data structure ??
// dp[i][j] ?
// heap ??????
// just stupid dp ????
int longestArithSeqLength(int* A, int ASize)
{
    if (ASize < 3)
        return ASize;

    int min = A[0];
    int max = A[0];
    int min_l = INT_MAX;
    int max_l = INT_MIN;

    for (int i = 1; i < ASize; i ++)
    {
        if (A[i] - min > max_l)
            max_l = A[i] - min;
        if (A[i] - max < min_l)
            min_l = A[i] - max;

        if (A[i] < min)
            min = A[i];

        if (A[i] > max)
            max = A[i];
    }

    int l = abs(max_l) < abs(min_l) ? abs(min_l) : abs(max_l);

    short** dp = malloc(sizeof(short*) * ASize);
    dp[0] = calloc(sizeof(short), l * 2 + 2);
    max = INT_MIN;
    for (int i = 1; i < ASize; i ++)
    {
        dp[i] = calloc(sizeof(short), l * 2 + 2);
        for (int j = i - 1; j >= 0; j --)
        {
            int d = A[i] - A[j] + l;
            if (dp[i][d] < dp[j][d] + 1)
                dp[i][d] = dp[j][d] + 1;
            max = max < dp[i][d] ? dp[i][d] : max;
        }
    }
    return max + 1;
}
