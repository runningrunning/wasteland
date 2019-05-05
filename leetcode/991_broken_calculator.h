// same as 650 2 keys keyboard
// just be careful !
// simple is the fastest
int brokenCalc(int X, int Y)
{
    if (X >= Y)
        return X - Y;

    int n = 0;
    long y = Y;
    int step = 0;
    int left = 0;
    while (y + left > X)
    {
        if (!left && (y & 1))
            left = 1;
        y >>= 1;
        n ++;
    }

    step += X - (y + left);
    step += n;

    long l = (y + left) << n;
    l -= Y;
    for (int i = 0; i < 32; i ++)
        if (l & (1L << i))
            step ++;
    return step;
}
