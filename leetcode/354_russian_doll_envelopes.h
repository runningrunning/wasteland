// TODO FIND better solutions !!!!!
// stupid wrong algorithm !!!! USE TOO MUCH TIME!
// just like rectangle
void me_sort(int* n, int s, int e, int* i)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = i[s];
        i[s] = i[e];
        i[e] = t;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int j = s + 1; j <= e; j ++)
    {
        while (n[j] < n[s]) j ++;
        while (n[e] > n[s]) e --;

        if (j >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = i[s];
            i[s] = i[e];
            i[e] = t;
        }
        else
        {
            t = n[j];
            n[j] = n[e];
            n[e] = t;

            t = i[j];
            i[j] = i[e];
            i[e] = t;
        }
    }

    me_sort(n, cs, e - 1, i);
    me_sort(n, e + 1, ce, i);
}

int me(int** en, int s, int l, int* x, int* xi, int* yi, int* t)
{
    if (t[s])
        return t[s];

    int max = 1;
    int _x = en[s][0];
    int _y = en[s][1];

    if (x[s] < 0)
    {
        int i = - x[s];
        for (; i < l; i ++)
        {
            int c = 0;
            int y = yi[i];

            if (_x < en[y][0] && _y < en[y][1])
                c = me(en, y, l, x, xi, yi, t) + 1;

            if (c > max)
                max = c;
        }
    }
    else
    {
        int i = x[s];

        for (; i < l; i ++)
        {
            int c = 0;
            int y = xi[i];
            if (_x < en[y][0] && _y < en[y][1])
                c = me(en, y, l, x, xi, yi, t) + 1;

            if (c > max)
                max = c;
        }
    }

    t[s] = max;
    return t[s];
}

int maxEnvelopes(int** envelopes, int envelopesRowSize, int envelopesColSize)
{
    int* xi = malloc(sizeof(int) * envelopesRowSize);
    int* xs = malloc(sizeof(int) * envelopesRowSize);
    int* yi = malloc(sizeof(int) * envelopesRowSize);
    int* ys = malloc(sizeof(int) * envelopesRowSize);

    for (int i = 0; i < envelopesRowSize; i ++)
    {
        xi[i] = yi[i] = i;
        xs[i] = envelopes[i][0];
        ys[i] = envelopes[i][1];
    }

    me_sort(xs, 0, envelopesRowSize - 1, xi);
    me_sort(ys, 0, envelopesRowSize - 1, yi);

    int* t = calloc(sizeof(int), envelopesRowSize);

    for (int i = 0; i < envelopesRowSize; i ++)
    {
        int x = xi[i];
        if (!t[x] || abs(t[x]) < (i + 1))
            t[x] = (i + 1);

        x = yi[i];
        if (!t[x] || abs(t[x]) < (i + 1))
            t[x] = - (i + 1);
    }

    memset(xs, 0, sizeof(int) * envelopesRowSize);

    int max = 0;
    for (int i = 0; i < envelopesRowSize; i ++)
    {
        int c = me(envelopes, i, envelopesRowSize, t, xi, yi, xs);

        if (c > max)
            max = c;
    }
    return max;
}

/* int me(int** en, int s, int e, int* t) */
/* { */
/*     if (t[s]) */
/*         return t[s]; */

/*     int x = en[s][0]; */
/*     int y = en[s][1]; */
/*     int max = 1; */

/*     int tmx = INT_MAX; */
/*     int tmy = INT_MAX; */

/*     for (int i = 0; i <= e; i ++) */
/*     { */
/*         if (i == s) */
/*             continue; */

/*         int c = 0; */
/*         int tx = en[i][0]; */
/*         int ty = en[i][1]; */

/*         if (!(tx > tmx && ty > tmy) && x < tx && y < ty) */
/*             c = me(en, i, e, t) + 1; */

/*         if (c > max) */
/*         { */
/*             tmx = tx; */
/*             tmy = ty; */
/*             max = c; */
/*         } */
/*     } */

/*     t[s] = max; */
/*     return t[s]; */
/* } */

/* int maxEnvelopes(int** envelopes, int envelopesRowSize, int envelopesColSize) */
/* { */
/*     int* t = calloc(sizeof(int), envelopesRowSize); */

/*     int max = 0; */
/*     for (int i = 0; i < envelopesRowSize; i ++) */
/*     { */
/*         int c = me(envelopes, i, envelopesRowSize - 1, t); */

/*         if (c > max) */
/*             max = c; */
/*     } */
/*     // out(t, envelopesRowSize); */
/*     return max; */
/* } */
