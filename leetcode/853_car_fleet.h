void _cf_sort(int* n, int s, int e, int* p)
{
    if (s > e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = p[s];
        p[s] = p[e];
        p[e] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = p[s];
            p[s] = p[e];
            p[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = p[i];
            p[i] = p[e];
            p[e] = t;
        }
    }

    _cf_sort(n, cs, e - 1, p);
    _cf_sort(n, e + 1, ce ,p);
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize)
{
    if (!positionSize || !speedSize)
        return 0;
    _cf_sort(position, 0, positionSize - 1, speed);

    int c = 1;
    long _p = target - position[positionSize - 1];
    long _s = speed[positionSize - 1];

    for (int i = positionSize - 1; i > 0; i --)
    {
        long p1 = _p * ((long) speed[i - 1]);
        long p2 = ((long)(target - position[i - 1])) * _s;

        if (p1 < p2)
        {
            _p = target - position[i - 1];
            _s = speed[i - 1];
            c ++;
        }
    }
    return c;
}
