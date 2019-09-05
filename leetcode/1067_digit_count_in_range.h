// read the question
// calculate how many digits
int _dc(int d, int n)
{
    int o = n;
    long b = 1;
    int with = 0;
    while (o)
    {
        int x = o / 10;
        if (d)
            x += 1;
        if ((o % 10) <= d)
            x -= 1;
        with += x * b;
        if ((o % 10) == d)
            with += (n % b) + 1;
        b *= 10;
        o /= 10;
    }
    return with;
}

int digitsCount(int d, int low, int high)
{
    int l = _dc(d, low - 1);
    int h = _dc(d, high);
    return h - l;
}

int digitsCount_test(int d, int low, int high)
{
    int all = 0;
    for (int k = low; k <= high; k ++)
    {
        int i = k;
        while (i)
        {
            if ((i % 10) == d)
                all ++;
            i /= 10;
        }
    }
    return all;
}

// calculate how many numbers
int _dc2(int d, int n, long* nums)
{
    if (!n)
        return d == n ? 1 : 0;

    long b = 1;
    int bits = 0;
    for (int i = 0; i < 10; i ++)
    {
        if (b >= n)
            break;
        b *= 10;
        bits ++;
    }

    if (b > n)
    {
        b /= 10;
        bits --;
    }

    int o = n;
    long without = 0;

    while (b)
    {
        int x = n / b;

        if (d && (x - 1) >= d)
            x -= 1;

        without += x * nums[bits];

        if (n / b == d)
            break;

        n -= (n / b) * b;

        b /= 10;
        bits --;
    }

    printf("without %d.\n", without);
    return o + 1 - without;
}

int digitsCount2(int d, int low, int high)
{
    long x = 1;
    long* nums = malloc(sizeof(long) * 11);

    for (int i = 0; i < 11; i ++)
    {
        nums[i] = x;
        x *= 9;
    }

    int l = _dc2(d, low - 1, nums);
    int h = _dc2(d, high, nums);

    printf("%d %d.\n", l, h);

    return h - l;
}
