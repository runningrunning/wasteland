// there is simple way to do so.
// keep clear mind !!!
int candy(int* ratings, int ratingsSize)
{
    if (!ratings || !ratingsSize)
        return 0;

    int a = 1;
    int s = 0;
    int p = 1;

    int lp = 0;
    bool le = true;

    for (int i = 1; i < ratingsSize; i ++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            ++ p;
            s = -1;
            le = false;
        }
        else
        {
            if (ratings[i] == ratings[i - 1])
            {
                le = true;
                s = -1;
            }

            if (s == -1)
            {
                lp = p;
                s = i;
                p = 1;
            }
            else
            {
                if (p == 1)
                {
                    a += i - s;

                    if (!le && (i - s + 1) >= lp)
                    {
                        a += i - s + 1 + 1 - lp;
                        lp = i - s + 1 + 1;
                    }
                }
                else
                    p = 1;
            }

        }

        // printf("%d %d %d.\n", p, a, i);
        a += p;
    }
    return a;
}
