// 3 step,
// with 1 current
// with 2 current
// with 3 current

#define MOD 1000000007

long p(int x, int n)
{
    long r = 1;
    for (long i = 0; i < n; i ++)
        r *= x - i;
    for (long i = 1; i <= n; i ++)
        r /= i;
    return r;
}

int threeSumMulti(int* A, int ASize, int target)
{
    int all[101] = {0};

    int max = 0;
    for (int i = 0; i < ASize; i ++)
    {
        if (max < A[i])
            max = A[i];
        all[A[i]] ++;
    }

    int t = 0;
    long num = 0;

    for (int i = 0; i <= max; i ++)
    {
        if (all[i])
        {
            int x = i;
            if (3 * i >= target)
            {
                if (3 * x == target && all[i] >= 3)
                    num += p(all[i], 3);
                break;
            }

            t = target - 2 * i;

            if (all[i] >= 2 && t <= 100 && all[t])
                num += p(all[i], 2) * all[t];

            num %= MOD;

            t = target - i;
            for (int s = i + 1; s <= t - s && s <= 100; s ++)
                if (all[s] && t - s <= 100 && all[t - s])
                {
                    if (s == t - s)
                        num += p(all[s], 2) * all[i];
                    else
                        num += all[s] * all[t - s] * all[i];
                    num %= MOD;
                }
        }
    }
    return num % MOD;
}
