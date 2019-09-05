int tribonacci(int n)
{
    int T[52] = {0};

    T[0] = 0;
    T[1] = 1;
    T[2] = 1;
    T[3] = 2;

    for (int i = 4; i <= n; i ++)
        T[i] = T[i - 1] + T[i - 2] + T[i - 3];

    return T[n];
}

