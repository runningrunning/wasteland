#define MAX_INT INT_MAX
#define MIN_INT INT_MIN
bool div2(int d, int dor, int* mul, int* left)
{
    if (d > dor || !d)
        return false;

    if (d == dor)
    {
        *left = 0;
        *mul = 1;
        return true;
    }

    int l2 = 0;
    int init = d;
    int between = 1;
    while(init < dor)
    {
        init >>= 1;
        between <<= 1;
        l2 ++;
    }

    *left = d - (dor << (l2 - 1));
    *mul = (between >> 1);
    return true;
}

int divide(int dividend, int divisor) {
    if (!divisor)
        return MAX_INT;
    if (!dividend)
        return 0;

    bool minus = (dividend > 0 && divisor < 0) ||
        (dividend < 0 && divisor > 0);

    dividend = dividend > 0 ? - dividend : dividend;
    divisor = divisor > 0 ? - divisor : divisor;

    if (dividend > divisor)
        return 0;

    if (divisor == -1)
    {
        if (dividend == MIN_INT)
            return minus ? MIN_INT : MAX_INT;
        return minus ? dividend : -dividend;
    }

    if (divisor == -2)
    {
        dividend = (dividend + 1) >> 1;
        return minus ? dividend : -dividend;
    }

    int ret = 0;
    int mul = 0;
    int left = 0;

    while(div2(dividend, divisor, &mul, &left))
    {
        ret += mul;
        dividend = left;
    }
    return minus ? -ret : ret;
}
