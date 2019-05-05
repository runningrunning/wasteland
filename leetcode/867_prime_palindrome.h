bool _is_prime(int n)
{
    if (n > 10 && (!(n % 2) || !(n % 3) || !(n % 5) || !(n % 7)))
        return false;

    int r = sqrt(n);
    for (int i = 2; i <= r; i ++)
        if (!(n % i))
            return false;
    return true;
}

int next(int* n, int* ni, bool is)
{
    if (*ni == 1)
    {
        if (n[0] == 9)
        {
            n[0] = 1;
            n[1] = 1;
            *ni = 2;
            return 11;
        }
        n[0] ++;
        return n[0];
    }

    int m = (*ni) / 2;
    int s = m - 1;
    int e = *ni & 1 ? m + 1 : m;

    int i = 0;

    if (is)
        i = m;
    else
        for (i = 0; i < m; i ++)
        {
            if (n[s] < n[e])
                break;

            if (n[s] > n[e])
            {
                i = m;
                break;
            }

            s --;
            e ++;
        }

    if (i == m)
    {
        if (n[m] != 9)
            n[m] ++;
        else
        {
            bool all9 = true;

            for (int i = 0; i < *ni; i ++)
                if (n[i] != 9)
                {
                    all9 = false;
                    break;
                }

            if (all9)
            {
                (*ni) ++;

                for (int i = 0; i < *ni; i ++)
                    n[i] = 0;

                n[0] = 1;
                n[*ni - 1] = 1;
                m = *ni / 2;
            }
            else
            {
                e = m;
                while (n[e] == 9)
                    n[e ++] = 0;

                n[e] ++;
            }
        }

        s = m - 1;
        e = *ni & 1 ? m + 1 : m;
    }

    while (s >= 0)
        n[s --] = n[e ++];

    int x = 0;
    for (int i = (*ni) - 1; i >= 0; i --)
        x = x * 10 + n[i];
    return x;
}

int primePalindrome(int N)
{
    if (N == 1)
        return 2;

    int ON = N;
    int n[10] = {0};
    int ni = 0;
    while (N)
    {
        n[ni ++] = N % 10;
        N /= 10;
    }

    int s = 0;
    int e = ni - 1;

    while (s < e)
    {
        if (n[s] != n[e])
            break;
        s ++;
        e --;
    }

    if (s >= e && _is_prime(ON))
        return ON;

    int x = next(n, &ni, false);

    while (!_is_prime(x))
        x = next(n, &ni, true);
    return x;
}
