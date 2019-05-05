int _cmc(int a, int b)
{
    if (!(a % b))
        return b;
    return _cmc(b, a % b);
}

int mirrorReflection(int p, int q)
{
    if (q == 0)
        return 0;

    if (q == p)
        return 1;

    int c = _cmc(p, q);
    int _p = p / c;
    int _q = q / c;

    if (_p & 1)
        return _q & 1;
    return 2;
}
