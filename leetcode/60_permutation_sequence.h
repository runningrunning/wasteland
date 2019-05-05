char* getPermutation(int n, int k)
{
    int i = 0;
    int used[9] = {0};
    int ret[10] = {0};

    int r = 1;
    for(i = 1; i < n; i ++)
        r *= i;

    k -= 1;

    for(i = 0; i < n; i ++)
    {
        if (r > 1)
        {
            ret[i] = (k / r) + 1;
            k = k % r;
            r /= n - 1 - i;
        }
        else
        {
            if (i == n - 1)
                ret[i] = 1;
            else
                ret[i] = k + 1;
        }

        int t = 0;
        for(int j = 0; j < 9; j ++)
        {
            if (!used[j])
                t ++;
            if (t == ret[i])
            {
                ret[i] = j + 1;
                used[j] = 1;
                break;
            }
        }
    }

    char* a = malloc(sizeof(char) * 10);
    for(i = 0; i < n; i++)
        a[i] = ret[i] + '0';
    a[i] = 0;
    return a;
}
