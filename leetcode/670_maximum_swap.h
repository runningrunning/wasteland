int maximumSwap(int num)
{
    int ni = 0;
    int ns[10] = {0};
    int nl[10] = {0};
    int n_num = num;

    int l = 1;
    while (n_num)
    {
        nl[ni] = l;
        ns[ni] = n_num % 10;

        l *= 10;
        n_num /= 10;
        ni ++;
    }

    if (ni == 1)
        return num;

    int max;
    int max_i;

    for (int i = ni - 1; i > 0; i --)
    {
        max = ns[i];
        for (int j = 0; j < i; j ++)
        {
            if (ns[j] > max)
            {
                max = ns[j];
                max_i = j;
            }
        }

        if (max != ns[i])
        {
            return num - ns[i] * nl[i] - ns[max_i] * nl[max_i]
                + ns[max_i] * nl[i] + ns[i] * nl[max_i];
        }
    }
    return num;
}
