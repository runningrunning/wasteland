bool confusingNumber(int N)
{
    int m;
    int X = 0;
    int O = N;
    int cs[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

    while (N)
    {
        m = cs[N % 10];
        if (m == -1)
            return false;
        X = X * 10 + m;
        N /= 10;
    }
    return X != O;
}

