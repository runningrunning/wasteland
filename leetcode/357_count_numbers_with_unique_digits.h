int countNumbersWithUniqueDigits(int n)
{
    if (!n)
        return 1;

    if (n == 1)
        return 10;

    int x,y;
    int all = 10;

    for (int i = 2; i <= n; i ++)
    {
        x = 9;
        y = 9;
        int j = i;
        while(-- j)
            x *= (y --);
        all += x;
    }

    return all;
}
