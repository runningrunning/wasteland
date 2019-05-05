// math do calculation
// just need to be careful !!!!
// more careful about the calculation
// stupid wrong algorithm !!!, keep clear mind
// kind of DP
// too much corner case !!!
int atMostNGivenDigitSet(char** D, int DSize, int N)
{
    long n10[10] = {0};
    long num10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    long ds = DSize;
    for (int i = 1; i < 10; i ++)
    {
        n10[i] = ds;
        ds *= DSize;
    }

    n10[0] = 1;

    long num[10] = {0};

    for (int i = 0; i < DSize; i ++)
        num[i] = D[i][0] - '0';

    // outl(n10, 10);
    int x = 0;
    bool keep = true;
    bool start = false;

    for (int i = 9; i >= 0; i --)
    {
        if (N >= num10[i])
        {
            if (!start)
                keep = true;

            start = true;

            if (keep)
            {
                int j = 0;
                int n = N / num10[i];

                while (j < DSize)
                    if (n >= num[j])
                        j ++;
                    else
                        break;

                if (!j)
                    keep = false;
                else
                {
                    x += (j - ((i && n == num[j - 1]) ? 1 : 0)) * n10[i];
                    keep = keep && (n == num[j - 1]);
                }
            }
            N %= num10[i];
        }
        else
            keep = false;

        // printf("keep is %d i %d.\n", keep, i);

        if (start)
        {
            // printf("x %d %d.\n", x, i ? n10[i] : 0);
            x += i ? n10[i] : 0;
        }

    }
    return x;
}
