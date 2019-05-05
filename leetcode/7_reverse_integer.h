int reverse(int x)
{
    int max = 2147483647;
    int m_max = -2147483648;

    if (x == m_max || x == max)
        return 0;

    bool minus = x < 0;
    x = x < 0 ? -x : x;
    int i = 0;
    int bits[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while(x)
    {
        bits[i++] = x % 10;
        x = x / 10;
    }

    for (int j = 0; j < i && j < 9; j ++)
        x = x * 10 + bits[j];

    if (i >= 10)
    {
        if (x > (max / 10))
            return 0;
        else if ((x == max / 10) && bits[9] > 1)
            return 0;

        x = x * 10 + bits[9];
    }

    return minus ? -x : x;
}
