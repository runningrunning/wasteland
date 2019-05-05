int smallestFactorization(int a)
{
    if (a < 10)
        return a;

    int x = a;
    int n = 0;
    int bs[10] = {0};

    for (int i = 9; i > 1; i --)
    {
        while (!(x % i))
        {
            bs[i] ++;
            n ++;
            x /= i;
        }
    }

    if (x != 1 || n > 10)
        return 0;

    long z = 0;

    for (int i = 1; i < 10; i ++)
    {
        while (bs[i])
        {
            z = z * 10 + i;
            bs[i] --;
        }
    }

    if (z > INT_MAX)
        return 0;

    return (int) z;
}
