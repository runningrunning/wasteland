/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize)
{
    long s = 0L;
    long e = 1000000L;
    long n = num_people;

    while(s < e)
    {
        long m = (s + e) / 2;

        long r = (m - 1) * m * n * n / 2 + m * n * (n + 1) / 2;

        if (r < candies)
            s = m + 1;
        else
            e = m;
    }

    int* r = calloc(sizeof(int), n);
    *returnSize = n;

    int st = 1;

    if (s > 0)
    {
        s --;
        st += s * n;
        for (int i = 0; i < n; i ++)
        {
            r[i] = (s - 1) * s * n / 2 + s * (i + 1);
            candies -= r[i];
        }
    }

    for (int i = 0; i < n; i ++)
    {
        if (st >= candies)
        {
            r[i] += candies;
            break;
        }
        r[i] += st;
        candies -= st ++;
    }

    return r;
}

