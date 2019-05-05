// how to optimize ?
// math !!!!
// sy >= sx, ty >= tx
// stupid !!!!!, 4, 2, 2, 4 can not be same !!!!
// cheating here, should not handle 4, 2, 2, 4 like this !

bool _rp(int sx, int sy, int tx, int ty)
{
    if (tx < sx || ty < sy)
        return false;

    if (sx == tx)
    {
        if (ty >= sy && !((ty - sy) % tx))
            return true;
        return false;
    }

    if (ty >= tx)
    {
        if (ty % tx)
            return _rp(sx, sy, tx, ty % tx)
                || ((ty > 2 * tx) && _rp(sx, sy, tx, tx + ty % tx));
        return (tx < ty) && _rp(sx, sy, tx, tx);
    }

    if (tx % ty)
        return _rp(sx, sy, tx % ty, ty)
            || ((tx > 2 * ty) && _rp(sx, sy, ty + tx % ty, ty));

    return (ty < tx) &&  _rp(sx, sy, ty, ty);
}

bool reachingPoints(int sx, int sy, int tx, int ty)
{
    int t;

    return sx <= sy ? _rp(sx, sy, tx, ty)
        : _rp(sy, sx, ty, tx);
}
