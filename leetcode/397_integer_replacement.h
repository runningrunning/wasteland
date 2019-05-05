/* stupid corner case 2147483647 */
int integerReplacement(int n)
{
    if (n < 1)
        return n;

    if (n == INT_MAX)
        return 32;

    int step = 0;

    while (n)
    {
        if (!(n & (n - 1)))
        {
            int m = n >> 1;
            while (m)
            {
                m >>= 1;
                step ++;
            }
            return step;
        }

        if (n == 3)
            return step + 2;

        step ++;

        if (n & 1)
        {
            if ((n & 3) == 3)
                n ++;
            else
                n --;
        }
        else
        {
            n >>= 1;
        }
    }

    return step;
}
