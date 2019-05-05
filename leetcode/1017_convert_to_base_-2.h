// NOT CORRECT !!!
// Try to use bu ma
char* baseNeg2(int N)
{
    if (!N)
        return strdup("0");


    long n = N;
    long x = 0;
    long m = 0;

    while (n)
    {
        int o = 0;
        while (!(n & (1 << o)))
            o ++;
        if (o % 2)
        {
            m += 1 << o;
            n += 1 << o;
        }
        else
        {
            x += 1 << o;
            n -= 1 << o;
        }
    }
    char* r = malloc(sizeof(char) * 32);
    x += m;

    int ri = 0;
    bool start = false;
    for (int i = 31; i >= 0; i --)
    {
        if (x & (1 << i))
            start = true;

        if (start)
            r[ri ++] = (x & (1 << i)) ? '1' : '0';
    }
    r[ri] = 0;
    return r;
}
