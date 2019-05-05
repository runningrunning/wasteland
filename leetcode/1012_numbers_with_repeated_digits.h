// count the number without repeated
// be more careful and find better solutions for this one !!!
// clear mind here
// complicated, be careful
// same with 996 ??? cached the result ?
// repeated digits means 1001 is repeated also
// math again, stupid me
// find simple solutions !
int ndd(int p, int n)
{
    if (!n)
        return 1;
    int x = p ? (10 - p) : 9;
    int t = p ? (10 - p - 1) : 9;
    for (int i = 1; i < n; i ++)
        x *= t --;
    return x;
}

int numDupDigitsAtMostN(int N)
{
    int y = N;
    if (N <= 10)
        return 0;
    int x = 1000000000;
    while (N < x)
        x /= 10;
    int num = 0;
    int b = 1;

    int n = 10;
    while (x >= n)
    {
        num += ndd(0, b);
        n *= 10;
        b ++;
    }

    // printf("num %d b %d n %d.\n", num, b, n);
    int v[10] = {0};
    int o = 0;
    int s = 1;

    // check every bits
    while (b - o)
    {
        int z = N / x;
        // printf("z is %d.\n", z);
        o ++;
        for (int i = s; i < z; i ++)
        {
            // printf("i is %d %d %d %d %d.\n", i, o, b - o, num, ndd(o, b - o));
            if (!v[i])
                num += ndd(o, b - o);
        }

        if (v[z])
            break;

        // whether the last one is no repeat
        if (!(b - o))
            num ++;

        v[z] = 1;

        N %= x;
        x /= 10;
        s = 0;
    }
    // printf("num is %d\n", num);
    return y - num;
}
