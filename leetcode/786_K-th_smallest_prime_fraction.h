// similar with 719 find K-th smallest pair distance !
// TODO FIND BETTER SOLUTION !!!!!!!!!!
// REWORK Better solutions ??? !!!
// heap is the easiest way !
long gcd(long x, long y)
{
    if (!(y % x))
        return x;
    return gcd(y % x, x);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* A, int ASize, int K, int* returnSize)
{
    if (!A || ASize < 2)
        return NULL;

    int* r = malloc(sizeof(int) * 2);
    *returnSize = 2;

    if (ASize == 2)
    {
        r[0] = A[0];
        r[1] = A[1];
        return r;
    }

    if (K == 1)
    {
        r[0] = A[0];
        r[1] = A[ASize - 1];
        return r;
    }

    long sa = A[0];
    long sb = A[ASize - 1];

    long ea = 1;
    long eb = 1;
    long a = 0;

    long a1;
    long b1;

    long a2;
    long b2;

    while (sa * eb < ea * sb)
    {
        a = 0;

        long ma = (sa * eb) + (ea * sb);
        long mb = 2 * sb * eb;
        long c = gcd(ma, mb);

        ma /= c;
        mb /= c;

        a1 = A[0];
        b1 = A[ASize - 1];
        a2 = 1;
        b2 = 1;

        for (int i = 0; i < ASize - 1; i ++)
        {
            if (A[i] * mb <= A[i + 1] * ma)
            {
                a += ASize - 1 - i;
                if (a1 * A[i + 1] < b1 * A[i])
                {
                    a1 = A[i];
                    b1 = A[i + 1];
                }
            }
            else if (A[i] * mb > A[ASize - 1] * ma)
            {
                if (a2 * A[ASize - 1] > b2 * A[i])
                {
                    a2 = A[i];
                    b2 = A[ASize - 1];
                }
                break;
            }
            else
            {
                int _s = i + 1;
                int _e = ASize - 1;

                while (_s < _e)
                {
                    int _m = _s + (_e - _s) / 2;

                    if (A[i] * mb > A[_m] * ma)
                        _s = _m + 1;
                    else
                        _e = _m;
                }

                if (a1 * A[_s] < b1 * A[i])
                {
                    a1 = A[i];
                    b1 = A[_s];
                }

                if (a2 * A[_s - 1] > b2 * A[i])
                {
                    a2 = A[i];
                    b2 = A[_s - 1];
                }

                a += ASize - _s;
            }
        }

        /* if (a == K) */
        /*     break; */

        // printf("s %d/%d m %d/%d e %d/%d %d %d.\n", sa, sb, ma, mb, ea, eb, a, K);
        if (a < K)
        {
            sa = a2;
            sb = b2;
        }
        else
        {
            ea = a1;
            eb = b1;
        }
    }

    r[0] = sa;
    r[1] = sb;
    return r;
}
