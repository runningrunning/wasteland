int smallestRepunitDivByK(int K)
{
    if (!(K & 1))
        return -1;

    char* f = calloc(sizeof(char), K);

    int n = 1;
    int x = 1;

    while (true)
    {
        while (x < K)
        {
            x = x * 10 + 1;
            n ++;
        }

        if (!(x % K))
            return n;

        x %= K;
        if (f[x])
            return -1;
       f[x] = 1;
    }
    return -1;
}
