/* HINTS, this sort need *n to keep tracking previous matching one, or there is no way to handle it */
void _hi(int* ns, int s, int e, int l, int* n)
{
    if (s >= e)
    {
        if (l - e <= ns[e])
            *n = l - e;
        return;
    }

    int t;
    int cs = s;
    int ce = e;

    if (ns[s] > ns[e])
    {
        t = ns[s];
        ns[s] = ns[e];
        ns[e] = t;
    }

    if (s + 1 == e)
    {
        if (l - s <= ns[s])
            *n = l - s;
        else if (l - e <= ns[e])
            *n = l - e;
        return;
    }

    for(int i = s + 1; i <= e; i ++)
    {
        while(ns[i] < ns[s]) i ++;
        while(ns[e] > ns[s]) e --;

        if (i >= e)
        {
            t = ns[s];
            ns[s] = ns[e];
            ns[e] = t;
        }
        else
        {
            t = ns[i];
            ns[i] = ns[e];
            ns[e] = t;
        }
    }

    if (l - e <= ns[e])
    {
        *n = l - e;
        _hi(ns, cs, e - 1, l, n);
    }
    else
    {
        _hi(ns, e + 1, ce, l, n);
    }
}

int hIndex(int* citations, int citationsSize) {
    int n = 0;
    _hi(citations, 0, citationsSize - 1, citationsSize, &n);
    return n;
}
