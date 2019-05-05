// STUPID FAILED TOO MUCH TIMES, LOTS OF CORNER CASES and OVERFLOW
// TRY TO USE HASH TO DO IT AGAIN ~!!!!!
// cheating read doc about it
// complicated, do more
// can be negative integer !!!
// use too much memory for denominator
// try to use hash for it
// corner cases
// use too much memory
// d is 2147483648
// prime 131071 = 131072 - 1
// pow(2, 17) - 1

#define U_PRIME 131071
#define U_NUMBER ((U_PRIME + 31) / 32)

void s_fgs(int* f, int _n)
{
    int n = _n % U_PRIME;
    f[n/32] |= (1 << (n % 32));
}

bool _fgs(int* f, int _n)
{
    int n = _n % U_PRIME;
    int s = n % 32;
    return f[n/32] & (1 << s);
}

char* fractionToDecimal(int numerator, int denominator)
{
    long n = numerator;
    long d = denominator;

    int ri = 0;
    char* r;
    if (n == d || !(n % d))
    {
        r = malloc(12);
        sprintf(r, "%ld", n / d);
        return r;
    }

    bool minus = false;
    minus = (n < 0 && d > 0) || (n > 0 && d < 0);

    n = n < 0 ? - n : n;
    d = d < 0 ? - d : d;

    while (n % d)
    {
        n = n % d;
        n ^= d;
        d ^= n;
        n ^= d;
    }

    n = numerator / d;
    d = denominator / d;

    n = n < 0 ? - n : n;
    d = d < 0 ? - d : d;

    r = malloc(1024);

    int si = 0;
    int* st = malloc(sizeof(int) * 1024);
    int* sn = malloc(sizeof(int) * 1024);

    int* fs = malloc(sizeof(int) * U_NUMBER);
    memset(fs, 0, sizeof(int) * U_NUMBER);

    if (minus)
        sprintf(r, "-%d.", n / d);
    else
        sprintf(r, "%d.", n / d);

    n = n % d;
    ri = strlen(r);

    s_fgs(fs, n);
    st[si] = ri;
    sn[si] = (int) n;
    si ++;

    while (n < d)
    {
        n *= 10;

        if (n < d)
        {
            r[ri ++] = '0';
            if (!((ri + 1) % 1024))
                r = realloc(r, ri + 1 + 1024);
        }
        else
        {
            r[ri ++] = (n / d) + '0';

            if (!((ri + 1) % 1024))
                r = realloc(r, ri + 1 + 1024);

            n = n % d;

            if (!n)
                break;

        }

        int fn;
        bool has = _fgs(fs, (int) n);

        if (has)
        {
            // double check here
            bool do_has = false;
            for (int i = 0; i < si; i ++)
            {
                if (sn[i] == n)
                {
                    do_has = true;
                    fn = st[i];
                    break;
                }
            }

            has = do_has;
        }

        if (!has)
        {
            s_fgs(fs, n);
            st[si] = ri;
            sn[si] = (int) n;
            si ++;

            if (!((si + 1) % 1024))
            {
                st = realloc(st, sizeof(int) * (si + 1 + 1024));
                sn = realloc(sn, sizeof(int) * (si + 1 + 1024));
            }
        }
        else
        {
            for (int i = ri; i > fn; i --)
                r[i] = r[i - 1];
            r[fn] = '(';
            r[++ ri] = ')';
            ri ++;
            break;
        }
    }
    r[ri] = 0;
    return r;
}
