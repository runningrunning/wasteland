// INT OVERFLOW !!! should use 1L << 36  1 << 36 will be 16, but 1L << 36 will be the correct one !!!!
int minSwapsCouples(int* row, int rowSize)
{
    int ni = 0;
    int a[60] = {0};
    int n[60] = {0};

    for (int i = 0; i < rowSize - 1; i += 2)
    {
        if ((row[i + 1] - row[i] == 1 && row[i + 1] & 1)
            || (row[i] - row[i + 1] == 1 && row[i] & 1))
            continue;

        n[ni ++] = row[i];
        n[ni ++] = row[i + 1];

        a[row[i]] = row[i + 1];
        a[row[i + 1]] = row[i];
    }


    int ti = 0;
    int t[60];

    int num = 0;

    long d = 0;
    for (int i = 0; i < ni; i += 2)
    {
        if (d & (1L << n[i])) // MUST 1L
            continue;

        long f = 0;

        ti = 0;
        t[ti ++] = n[i];
        f |= 1L << n[i];
        t[ti ++] = n[i + 1];
        f |= 1L << n[i + 1];

        for (int j = 0; j < ti; j ++)
        {
            long x = t[j];

            if (x & 1)
                x -= 1;
            else
                x += 1;

            if (!(f & (1L << x))) // MUST 1L
            {
                f |= 1L << x; // MUST 1L
                t[ti ++] = x;
            }

            if (!(f & (1L << a[x]))) // MUST 1L
            {
                f |= 1L << a[x]; // MUST 1L
                t[ti ++] = a[x];
            }
        }

        num += ti / 2 - 1;
        d |= f;
    }
    return num;
}
