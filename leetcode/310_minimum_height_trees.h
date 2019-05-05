// complicated, try to do more !!! find better solutions !!!
// think too much ???
// how to optimize this?
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int _dph(int** ns, int x, char* f)
{
    int max = 0;
    int* a = ns[x];
    int s = a[0] & 0xFFFF;
    for (int i = 1; i < s; i ++)
    {
        int y = a[i];
        if (f[y])
            continue;
        f[y] = 1;
        int t = _dph(ns, y, f) + 1;
        if (max < t)
            max = t;
        f[y] = 0;
    }
    a[0] = (max << 16) | a[0];
    return max;
}

int _sph(int** ns, int x, int m, int* l)
{
    int* a = ns[x];
    int s = a[0] & 0xFFFF;
    int max = a[0] >> 16;

    l[x] = max < m ? m : max;

}

void _fmh(int** ns, int x, int* l, int* t, char* f)
{
    int max = -1;
    int max_i = -1;
    int pmax = -1;
    int pmax_i = -1;
    int* a = ns[x];
    int s = a[0] & 0xFFFF;
    for (int i = 1; i < s; i ++)
    {
        int y = a[i];
        f[y] = 1;
        t[i] = 1 + _dph(ns, y, f);
        if (max <= t[i])
        {
            pmax = max;
            pmax_i = max_i;
            max = t[i];
            max_i = i;
        }
        else if (pmax <= t[i])
        {
            pmax = t[i];
            pmax_i = i;
        }
        f[y] = 0;
    }

    l[x] = max;

    if (s == 2)
        _sph(ns, a[1], 1, l);
    else
    {
        for (int i = 1; i < s; i ++)
        {
            int y = a[i];
            if (i == max_i)
                _sph(ns, y, pmax + 1, l);
            else
                _sph(ns, y, max + 1, l);
        }
    }
}
*/

int _fmhm(int** ns, int x, int** ms, char* f)
{
    int max = 0;
    int max_i = -1;
    int pmax = -1;
    int* a = ns[x];

    for (int i = 1; i < a[0]; i ++)
    {
        int y = a[i];
        if (f[y])
            continue;
        f[y] = 1;
        int t = 1 + _fmhm(ns, y, ms, f);
        if (max <= t)
        {
            pmax = max;
            max = t;
            max_i = i;
        }
        else if (pmax <= t)
        {
            pmax = t;
        }
        f[y] = 0;
    }

    ms[x] = malloc(sizeof(int) * 3);
    ms[x][0] = max;
    ms[x][1] = max_i;
    ms[x][2] = pmax;
    return max;
}

void _fmht(int** ns, int x, int** ms, char* f, int c, int* r, int* ri)
{
    int* a = ns[x];
    int* m = ms[x];

    if (m[0] == -1 && m[2] == -1)
        return;

    if (c - m[0] >= 2)
        return;

    if (c <= m[2])
    {
        if (abs(m[0] - m[2]) <= 1)
        {
            r[*ri] = x;
            (*ri) ++;
        }
    }
    else
    {
        if (abs(c - m[0]) <= 1)
        {
            r[*ri] = x;
            (*ri) ++;
        }
    }

    for (int i = 1; i < a[0]; i ++)
    {
        int y = a[i];
        if (f[y])
            continue;

        f[y] = 1;
        int nc;
        if (i == m[1])
            nc = (m[2] > c ? m[2] : c) + 1;
        else
            nc = (m[0] > c ? m[0] : c) + 1;
        _fmht(ns, y, ms, f, nc, r, ri);
        f[y] = 0;
    }
}

int* findMinHeightTrees(int n, int** edges, int edgesRowSize, int edgesColSize, int* returnSize)
{
    *returnSize = 0;
    if (!n)
        return NULL;

    // corner case here !!
    if (n <= 2)
    {
        *returnSize = n;
        int* ret = malloc(sizeof(int) * n);
        if (n == 1)
            ret[0] = 0;
        else
        {
            ret[0] = 0;
            ret[1] = 1;
        }
        return ret;
    }
    int** ns = calloc(sizeof(int*), n);

    for (int i = 0; i < edgesRowSize; i ++)
    {
        int x = edges[i][0];
        int y = edges[i][1];

        if (!ns[x])
        {
            ns[x] = malloc(sizeof(int) * 2);
            ns[x][0] = 2;
            ns[x][1] = y;
        }
        else
        {
            int l = ns[x][0];
            ns[x] = realloc(ns[x], sizeof(int) * (l + 1));
            ns[x][0] = l + 1;
            ns[x][l] = y;
        }

        if (!ns[y])
        {
            ns[y] = malloc(sizeof(int) * 2);
            ns[y][0] = 2;
            ns[y][1] = x;
        }
        else
        {
            int l = ns[y][0];
            ns[y] = realloc(ns[y], sizeof(int) * (l + 1));
            ns[y][0] = l + 1;
            ns[y][l] = x;
        }
    }

    int** ms = calloc(sizeof(int*), n);
    char* f = calloc(sizeof(char), n);

    f[0] = 1;
    _fmhm(ns, 0, ms, f);
    f[0] = 0;

    int ri = 0;
    int* r = malloc(sizeof(int) * n);
    f[0] = 1;
    _fmht(ns, 0, ms, f, 0, r, &ri);
    f[0] = 0;
    *returnSize = ri;
    return r;


    /* for (int i = 0; i < n; i ++) */
    /* { */
    /*     if (!l[i]) */
    /*     { */
    /*         f[i] = 1; */
    /*         _fmh(ns, i, l, t, f); */
    /*         f[i] = 0; */
    /*     } */
    /* } */

    /* int ti = 0; */
    /* int min = l[0]; */
    /* t[ti ++] = 0; */
    /* for (int i = 1; i < n; i ++) */
    /* { */
    /*     if (l[i] == min) */
    /*         t[ti ++] = i; */
    /*     else if (l[i] < min) */
    /*     { */
    /*         min = l[i]; */
    /*         ti = 0; */
    /*         t[ti ++] = i; */
    /*     } */
    /* } */
    /* *returnSize = ti; */
    /* return t; */
}
