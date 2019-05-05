/* STUPID CORNER CASE */
/* EMPTY pass, Single one in the middle is pass */
/* how to sort on 2 array */
/* (0, 0) and (1, 0) is TRUE !!!*/
/* (-16, 1), (16, 1), (16, 1) is TRUE !!!! */
/* whether float of not */
/* EMPTY, DUPLICATE, other !*/
void ir_sort(int* n, int s, int e, int* m)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;

        t = m[e];
        m[e] = m[s];
        m[s] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;

            t = m[e];
            m[e] = m[s];
            m[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;

            t = m[e];
            m[e] = m[i];
            m[i] = t;
        }
    }

    ir_sort(n, cs, e - 1, m);
    ir_sort(n, e + 1, ce, m);
}

bool isReflected(int** points, int pointsRowSize, int pointsColSize)
{
    if (!points)
        return false;

    int ps = pointsRowSize;

    if (ps <= 1)
        return true;

    int* xs = malloc(sizeof(int) * ps);
    int* ys = malloc(sizeof(int) * ps);

    for (int i = 0; i < ps; i ++)
    {
        xs[i] = points[i][0];
        ys[i] = points[i][1];
    }

    // sort xs at the first
    ir_sort(xs, 0, ps - 1, ys);

    // then sort ys at the second
    int c = 1;
    int pre = xs[0];
    for (int i = 1; i < ps; i ++)
    {
        if (pre == xs[i])
            c ++;
        else
        {
            if (c > 1)
                ir_sort(ys, i - c, i - 1, xs);
            c = 1;
        }
        pre = xs[i];
    }

    if (c > 1)
        ir_sort(ys, ps - c, ps - 1, xs);

    int in = 1;
    int pre_x = xs[0];
    int pre_y = ys[0];

    int y_xor = pre_y;
    long x_all = pre_x;

    for (int i = 1; i < ps; i ++)
    {
        if (pre_x != xs[i] || pre_y != ys[i])
        {
            xs[in] = xs[i];
            ys[in] = ys[i];

            x_all += xs[i];
            y_xor ^= ys[i];

            in ++;
        }

        pre_x = xs[i];
        pre_y = ys[i];
    }

    ps = in;

    long mid = (x_all * 2) / ps;

    if (!(x_all % ps))
    {
        ps = 0;
        y_xor = 0;

        int m = mid / 2;
        for (int i = 0; i < in; i ++)
        {
            if (xs[i] != m)
            {
                y_xor ^= ys[i];
                xs[ps] = xs[i];
                ys[ps] = ys[i];
                ps ++;
            }
        }

        if (!ps)
            return true;
    }

    if (y_xor || (ps & 1))
        return false;

    // then sort ys at the second
    c = 1;
    pre = xs[0];
    int m = ps / 2;

    for (int i = 1; i < ps; i ++)
    {
        if (pre == xs[i])
            c ++;
        else
        {
            if (c > 1)
            {
                ir_sort(ys, i - c, i - 1, xs);

                if (i <= m)
                {
                    int t;
                    for (int k = 0; k < c / 2; k ++)
                    {
                        t = ys[i - c + k];
                        ys[i - c + k] = ys[i - 1 - k];
                        ys[i - 1 - k] = t;
                    }
                }
            }
            c = 1;
        }
        pre = xs[i];
    }

    if (c > 1)
        ir_sort(ys, ps - c, ps - 1, xs);

    /* out(xs, ps); */
    /* out(ys, ps); */

    for (int i = 0; i < m; i ++)
    {
        if (ys[i] != ys[ps - i - 1])
            return false;

        if (mid != xs[ps - i - 1] + xs[i])
            return false;
    }
    return true;
}
