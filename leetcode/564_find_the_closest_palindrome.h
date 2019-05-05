// 99 should be 101
// corner cases
void np_sort(long* n, int s, int e)
{
    if (s >= e)
        return;

    long t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }
    np_sort(n, cs, e - 1);
    np_sort(n, e + 1, ce);
}

// sort and find the smallest with the closet value
long np_ret(long* n, int s, long x)
{
    np_sort(n, 0, s - 1);

    int di = 0;
    long d = labs(n[0] - x);

    for (int i = 1; i < s; i ++)
        if (labs(n[i] - x) < d)
        {
            d = labs(n[i] - x);
            di = i;
        }
    return n[di];
}

char* nearestPalindromic(char* y)
{
    long x = 0;
    int i = 0;
    int n[24] = {0};
    int c = y[i ++];
    char* r = malloc(24);
    long ti = 0;
    long tn[16] = {0};

    long l = 0;
    long h = 1;

    while (c)
    {
        h = h * 10;
        l = l * 10 + 9;
        x = x * 10 + c - '0';
        c = y[i ++];
    }
    i -= 1;

    l /= 10;
    h += 1;
    tn[ti ++] = l;
    tn[ti ++] = h;

    long t = x;
    for (int j = 0; j < i; j ++)
    {
        n[j] = t % 10;
        t /= 10;
    }

    if (x < 10)
    {
        sprintf(r, "%d", x - 1);
        return r;
    }

    int m = i / 2;
    long mmax = 0;
    long lmax = LONG_MAX;
    long hmax = LONG_MAX;

    if (i & 1)
    {
        for (int j = 0; j < i; j ++)
        {
            mmax *= 10;
            if (j < m)
                mmax += n[i - 1 - j];
            else
                mmax += n[j];
        }

        if (mmax != x)
            tn[ti ++] = mmax;

        if (n[m] != 0)
        {
            lmax = 0;
            for (int j = 0; j < i; j ++)
            {
                lmax *= 10;
                if (j < m)
                    lmax += n[i - 1 - j];
                else
                    lmax += n[j] - (j == m ? 1 : 0);
            }
            tn[ti ++] = lmax;
        }

        if (n[m] != 9)
        {
            hmax = 0;
            for (int j = 0; j < i; j ++)
            {
                hmax *= 10;
                if (j < m)
                    hmax += n[i - 1 - j];
                else
                    hmax += n[j] + (j == m ? 1 : 0);
            }
            tn[ti ++] = hmax;
        }

        sprintf(r, "%ld", np_ret(tn, ti, x));
        return r;
    }

    m --;
    mmax = 0;
    lmax = LONG_MAX;
    hmax = LONG_MAX;

    for (int j = 0; j < i; j ++)
    {
        mmax *= 10;

        if (j < m)
            mmax += n[i - 1 - j];
        else if (j > m + 1)
            mmax += n[j];
        else
            mmax += n[m];
    }

    if (mmax != x)
        tn[ti ++] = mmax;

    if (n[m] != 0)
    {
        lmax = 0;
        for (int j = 0; j < i; j ++)
        {
            lmax *= 10;
            if (j < m)
                lmax += n[i - 1 - j];
            else if (j > m + 1)
                lmax += n[j];
            else
                lmax += n[m] - 1;
        }
        tn[ti ++] = lmax;
    }

    if (n[m] != 9)
    {
        hmax = 0;
        for (int j = 0; j < i; j ++)
        {
            hmax *= 10;
            if (j < m)
                hmax += n[i - 1 - j];
            else if (j > m + 1)
                hmax += n[j];
            else
                hmax += n[m] + 1;
        }
        tn[ti ++] = hmax;
    }

    m ++;
    mmax = 0;
    lmax = LONG_MAX;
    hmax = LONG_MAX;
    for (int j = 0; j < i; j ++)
    {
        mmax *= 10;

        if (j < m - 1)
            mmax += n[i - 1 - j];
        else if (j > m)
            mmax += n[j];
        else
            mmax += n[m];
    }

    if (mmax != x)
        tn[ti ++] = mmax;

    if (n[m] != 0)
    {
        lmax = 0;
        for (int j = 0; j < i; j ++)
        {
            lmax *= 10;
            if (j < m - 1)
                lmax += n[i - 1 - j];
            else if (j > m)
                lmax += n[j];
            else
                lmax += n[m] - 1;
        }
        tn[ti ++] = lmax;
    }

    if (n[m] != 9)
    {
        hmax = 0;
        for (int j = 0; j < i; j ++)
        {
            hmax *= 10;
            if (j < m - 1)
                hmax += n[i - 1 - j];
            else if (j > m)
                hmax += n[j];
            else
                hmax += n[m] + 1;
        }
        tn[ti ++] = hmax;
    }
    sprintf(r, "%ld", np_ret(tn, ti, x));
    return r;
}
