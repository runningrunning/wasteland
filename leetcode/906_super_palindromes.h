// just be careful
// next palindromes algorithms ?

int superpalindromesInRange(char* L, char* R)
{
    long l = 0L;
    long r = 0L;

    int i = 0;
    int c = L[i ++];

    while (c)
    {
        l = l * 10L + (c - '0');
        c = L[i ++];
    }

    i = 0;
    c = R[i ++];

    while (c)
    {
        r = r * 10L + (c - '0');
        c = R[i ++];
    }

    int ks[] = {1, 4, 9};
    int kl = sizeof(ks) / sizeof(ks[0]);

    int num = 0;

    for (int i = 0; i < kl; i ++)
        if (ks[i] >= l && ks[i] <= r)
            num ++;

    if (r <= ks[kl - 1])
        return num;

    long s = sqrtl(l);
    long e = sqrtl(r);

    if (s * s < l)
        s ++;


    long bs = 10L;

    long b = 2;

    while (true)
    {
        long t = b * bs + 2;

        if (t >= s && t <= e)
        {
            // printf("%d:%ld\n", num, t);
            num ++;
        }
        else if (t > e)
            break;

        t = b * bs * 10L + 2;

        if (t >= s && t <= e)
        {
            // printf("%d:%ld\n", num, t);
            num ++;
        }

        t = b * bs * 10L + bs + 2;
        if (t >= s && t <= e)
        {
            // printf("%d:%ld\n", num, t);
            num ++;
        }

        bs *= 10L;
        b *= 10L;
    }

    for (int i = 1; i < 1024; i ++)
    {
        long low = 0;
        long high = 0;
        long bs = 1L;

        int bi = i;
        int ci = 0;

        while (bi)
        {
            low *= 10L;

            if (bi & 1)
            {
                high += 1L * bs;
                low = low + 1L;
                ci ++;
            }

            bs *= 10L;
            bi >>= 1;
        }

        ci *= 2;

        long t = high * bs + low;

        if (t >= s && t <= e)
        {
            // printf("%d:%ld\n", num, t);
            num ++;
        }
        else if (t > e)
            break;

        t = high * bs * 10L + low;

        if (t >= s && t <= e)
        {
            // printf("%d:%ld\n", num, t);
            num ++;
        }
        else if (t > e)
            continue;

        if (ci < 9)
        {
            t = high * bs * 10L + low + bs;
            if (t >= s && t <= e)
            {
                // printf("%d:%ld\n", num, t);
                num ++;
            }
            else if (t > e)
                continue;
        }

        if (ci < 6)
        {
            t = high * bs * 10L + low + bs * 2L;
            if (t >= s && t <= e)
            {
                // printf("ci %d %d:%ld\n", ci, num, t);
                num ++;
            }
        }
    }
    return num;
}
