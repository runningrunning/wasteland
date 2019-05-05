int countDigitOne(int n)
{
    if (n <= 0)
        return 0;

    int l = 1;
    int num = 0;
    int on = n;
    while (n)
    {
        int pn = n;

        int x = n % 10;
        n /= 10;
        num += n * l;

        if (x > 1)
            num += l;
        else if (x == 1)
            num += (on - pn * l + 1);
        l *= 10;
    }
    return num;
}


int countDigitOne_1(int n)
{
    int num = 0;
    for (int i = 0 ; i <= n; i ++)
    {
        int x = i;

        while (x)
        {
            if (x % 10 == 1)
                num ++;
            x /= 10;
        }
    }

    return num;
}
