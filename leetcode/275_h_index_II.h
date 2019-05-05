/* HINTS, this sort need *n to keep tracking previous matching one, or there is no way to handle it */
void _hi(int* ns, int s, int e, int l, int* n)
{
    if (s >= e)
    {
        if (l - e <=  ns[e])
            *n = l - e;
        return;
    }

    int m = s + (e - s) / 2;
    if (l - m <= ns[m])
    {
        *n = l - m;
        _hi(ns, s, m - 1, l, n);
    }
    else
        _hi(ns, m + 1, e, l, n);
}

int hIndex(int* citations, int citationsSize)
{
    if (!citations || !citationsSize)
        return 0;

    int n = 0;
    _hi(citations, 0, citationsSize - 1, citationsSize, &n);
    return n;
}
