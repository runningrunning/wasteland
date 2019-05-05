// Forward declaration of the knows API.
bool knows(int a, int b);

int findCelebrity(int n)
{
    if (n == 1)
        return 0;

    if (n == 0)
        return -1;

    int ai = 0;
    int* a = malloc(sizeof(int) * n);

    if (n & 1)
        a[ai ++] = 0;

    for (int i = n & 1; i < n; i += 2)
    {
        bool know_i = knows(i + 1, i);
        bool know_i_1 = knows(i, i + 1);

        if (know_i && !know_i_1)
            a[ai ++] = i;

        if (know_i_1 && !know_i)
            a[ai ++] = i + 1;
    }

    if (ai == 0)
        return -1;

    int bi = 0;
    int* b = malloc(sizeof(int) * ai);

    int ti = ai;
    int* t = a;

    int ni = 0;
    int* new = b;

    while (ti > 1)
    {
        int s = 0;
        int e = ti - 1;

        while (s < e)
        {
            bool know_e = knows(t[s], t[e]);
            bool know_s = knows(t[e], t[s]);

            if (know_e && !know_s)
                new[ni ++] = t[e];

            if (know_s && !know_e)
                new[ni ++] = t[s];

            s ++;
            e --;
        }

        if (s == e)
            new[ni ++] = t[s];

        if (ti == ni)
            return -1;

        ti = ni;
        t = new;

        ni = 0;
        new = t == a ? b : a;
    }

    if (!ti)
        return - 1;

    int x = t[0];

    for (int i = 0; i < n; i ++)
    {
        if (i == x) continue;
        if (knows(x, i) || !knows(i, x))
            return - 1;
    }
    return x;
}
