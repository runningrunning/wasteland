int jss(int c, int s, int e)
{
    if (s >= e)
        return s;

    int m = (s + e) >> 1;
    int x = m * m;

    if (x == c)
        return m;

    if (x > c)
        return jss(c, s, m - 1);
    return jss(c, m + 1, e);
}

bool judgeSquareSum(int c)
{
    /* int x = jss(c, 0, 46340); */
    /* int m = x * x; */
    int x = sqrt(c);
    if (m  == c)
        return true;

    int y = 1;
    int t = m + 1;

    while (y <= x)
    {
        m = x * x;
        t = y * y + m;
        while(t > 0 && t < c)
        {
            y ++;
            t = y * y + m;
        }
        if (t == c)
            return true;
        x --;
    }
    return false;
}
