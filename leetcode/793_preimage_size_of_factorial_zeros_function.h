// how many fives, but how to optimize code to make it works faster, K can be 0 to 10^9
// is that simple ?? How to optimize this is the most difficult part
// some thing like DP ?
// n / 5 + n / 25 + n / 125 + ... = K
// just binary search
long _num(long x)
{
    long r = 0;
    while (x >= 5)
    {
        r += x / 5;
        x /= 5;
    }
    return r;
}

int preimageSizeFZF(int K)
{
    long s = 1L;
    long e = 4294967296L;

    while (s < e)
    {
        long m = s + (e - s) / 2;
        long nm = _num(m);

        if (nm < K)
            s = m + 1;
        else
            e = m;
    }

    if (_num(s) == K)
        return 5;
    return 0;
}
