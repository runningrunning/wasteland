bool isArmstrong(int N)
{
    if (N < 10)
        return true;

    int k = 0;
    int o = N;
    int n = 0;

    while (N)
    {
        k ++;
        N /= 10;
    }

    N = o;

    while (N)
    {
        int b = N % 10;
        int x = 1;
        for (int i = 0; i < k; i ++)
            x *= b;
        n += x;
        N /= 10;
    }

    return n == o;
}

