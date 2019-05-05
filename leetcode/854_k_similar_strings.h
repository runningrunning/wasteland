// try to not use recursion !!
// how to detect the wrong divide !! how to prove it?
// better solutions ???????
// prove it works !!!!
// use bfs to do find the smallest one
// use dp to find the smallest swap !!
void _can(int** g, int c, int r, long ri, int left, int start, int n, long* fs, int* fi, long* fg)
{
    if (!g[c])
        return;

    if ((*fg) & (1 << r))
        return;

    int l = g[c][0];
    if (left == 0)
    {
        for (int i = 1; i < l; i += 2)
            if (g[c][i + 1] && g[c][i] == start)
            {
                (*fg) |= 1 << r;
                // printf("got %c |%d| %ld \n", g[c][i] + 'a', r, ri);
                fs[*fi] = (ri << 32) | ((n < g[c][i + 1] ? n : g[c][i + 1]) << 24) | start;
                (*fi) ++;
                return;
            }
    }
    else
    {
        for (int i = 1; i < l; i += 2)
        {
            if (g[c][i + 1])
            {
                // printf("try %c %d %d %d", g[c][i] + 'a', left, ri, ri * 6 + g[c][i]);
                _can(g, g[c][i], r | (1 << g[c][i]), ri * 6 + g[c][i], left - 1, start, n < g[c][i + 1] ? n : g[c][i + 1], fs, fi, fg);
            }
        }
    }
}

void _more(int* ca, int* a, int c, int fi, int* t, int ti, int* max, int* maxi)
{
    if (c == fi)
    {
        if (ti > *maxi)
        {
            *maxi = ti;
            memcpy(max, t, sizeof(int) * ti);
        }
        return;
    }

    bool can = true;
    int tca[36];
    memcpy(tca, ca, sizeof(int) * 36);
    for (int i = 0; i < 6; i ++)
    {
        if (a[c * 6 + i] && !ca[a[c * 6 + i]])
        {
            can = false;
            break;
        }
        tca[a[c * 6 + i]] --;
    }

    if (can)
    {
        t[ti] = c;
        _more(tca, a, c + 1, fi, t, ti + 1, max, maxi);
    }
    _more(ca, a, c + 1, fi, t, ti, max, maxi);
}

void _divide(int* cs, long* fs, int fi, int n, int* m, int* mi)
{
    int a[6 * 32] = {0};
    for (int i = 0; i < fi; i ++)
    {
        int s = i * 6;
        long fz = fs[i] >> 32;
        int x = n;
        int p = fs[i] & 0xFF;
        int ai = 0;
        while (x)
        {
            a[s + ai ++] = (fz % 6) * 6 + p;
            p = fz % 6;
            fz /= 6;
            x --;
        }
    }
    int ti = 0;
    int t[32] = {0};
    _more(cs, a, 0, fi, t, ti, m, mi);
}

int kSimilarity(char* A, char* B)
{
    int l = strlen(A);

    int d = 0;
    int n = 0;
    int cs[36] = {0};
    for (int i = 0; i < l; i ++)
    {
        int a = A[i] - 'a';
        int b = B[i] - 'a';
        if (a != b)
        {
            int ab = a * 6 + b;
            int ba = b * 6 + a;
            if (cs[ba])
            {
                // printf("%c %c.\n", A[i], B[i]);
                cs[ba] --;
                d --;
                n ++;
            }
            else
            {
                cs[ab] ++;
                d ++;
            }
        }
    }

    if (d)
    {
        int* ga[6] = {0};
        for (int i = 0; i < 36; i ++)
        {
            if (cs[i])
            {
                int a = i / 6;
                int b = i % 6;

                if (!ga[a])
                {
                    ga[a] = malloc(sizeof(int) * 3);
                    ga[a][0] = 3;
                    ga[a][1] = b;
                    ga[a][2] = cs[i];
                }
                else
                {
                    int l = ga[a][0];
                    ga[a] = realloc(ga[a], sizeof(int) * (l + 2));
                    ga[a][0] = l + 2;
                    ga[a][l] = b;
                    ga[a][l + 1] = cs[i];
                }
            }
        }

        /* printf("== n %d d %d \n", n, d); */
        /* for (int i = 0; i < 6; i ++) */
        /*     if (ga[i]) */
        /*         out(ga[i], ga[i][0]); */

        // printf("== n %d d %d \n", n, d);

        // find all of them
        long fg = 0;
        long fs[64] = {0};
        for (int i = 2; i <= 6; i ++)
        {
            int fi = 0;
            for (int j = 0; j < 6; j ++)
            {
                if (ga[j])
                {
                    int r = 1 << j;
                    int t = INT_MAX;
                    _can(ga, j, r, j, i - 1, j, t, fs, &fi, &fg);
                }
            }

            if (fi)
            {
                int mi = 0;
                int m[32] = {0};
                _divide(cs, fs, fi, i, m, &mi);
                // printf("mi is \n");
                // out(m, mi);
                for (int j = 0; j < mi; j ++)
                {
                    int t[7] = {0};
                    long fz = fs[m[j]] >> 32;
                    int x = i;
                    while (x)
                    {
                        t[x - 1] = fz % 6;
                        fz /= 6;
                        x --;
                    }
                    t[i] = t[0];

                    // out(t, 7);
                    x = (fs[m[j]] >> 24) & 0xFF;
                    for (int k = 0; k < i; k ++)
                    {
                        int* _l = ga[t[k]];
                        // out(_l, _l[0]);
                        // printf("find %d.\n", t[k + 1]);
                        for (int m = 1; m < _l[0]; m +=2)
                        {
                            if (_l[m] == t[k + 1])
                            {
                                _l[m + 1] -= x;
                                cs[t[k] * 6 + t[k + 1]] --;
                                break;
                            }
                        }
                    }
                    // printf("x is %d, i is %d.\n", x, i);
                    n += x * (i - 1);
                    // out(cs, 36);
                }
            }
        }
    }
    return n;
}


/* // try to not use recursion !! */
/* bool _can(int** g, int c, int* r, int ri, int left, int start, int* n) */
/* { */
/*     if (!g[c] || g[c][0] == 1) */
/*         return false; */

/*     int l = g[c][0]; */
/*     if (left == 0) */
/*     { */
/*         for (int i = 1; i < l; i += 2) */
/*             if (g[c][i + 1] && g[c][i] == start) */
/*             { */
/*                 if (g[c][i + 1] < *n) */
/*                     *n = g[c][i + 1]; */
/*                 r[ri] = start; */
/*                 return true; */
/*             } */
/*     } */
/*     else */
/*     { */
/*         for (int i = 1; i < l; i += 2) */
/*         { */
/*             r[ri] = g[c][i]; */
/*             if (g[c][i + 1] && _can(g, r[ri], r, ri + 1, left - 1, start, n)) */
/*             { */
/*                 if (g[c][i + 1] < *n) */
/*                     *n = g[c][i + 1]; */
/*                 return true; */
/*             } */
/*         } */
/*     } */
/*     return false; */
/* } */

/* int kSimilarity(char* A, char* B) */
/* { */
/*     int l = strlen(A); */

/*     int d = 0; */
/*     int n = 0; */
/*     int cs[36] = {0}; */
/*     for (int i = 0; i < l; i ++) */
/*     { */
/*         int a = A[i] - 'a'; */
/*         int b = B[i] - 'a'; */
/*         if (a != b) */
/*         { */
/*             int ab = a * 6 + b; */
/*             int ba = b * 6 + a; */
/*             if (cs[ba]) */
/*             { */
/*                 cs[ba] --; */
/*                 d --; */
/*                 n ++; */
/*             } */
/*             else */
/*             { */
/*                 cs[ab] ++; */
/*                 d ++; */
/*             } */
/*         } */
/*     } */

/*     if (d) */
/*     { */
/*         int* ga[6] = {0}; */
/*         for (int i = 0; i < 36; i ++) */
/*         { */
/*             if (cs[i]) */
/*             { */
/*                 int a = i / 6; */
/*                 int b = i % 6; */

/*                 if (!ga[a]) */
/*                 { */
/*                     ga[a] = malloc(sizeof(int) * 3); */
/*                     ga[a][0] = 3; */
/*                     ga[a][1] = b; */
/*                     ga[a][2] = cs[i]; */
/*                 } */
/*                 else */
/*                 { */
/*                     int l = ga[a][0]; */
/*                     ga[a] = realloc(ga[a], sizeof(int) * (l + 2)); */
/*                     ga[a][0] = l + 2; */
/*                     ga[a][l] = b; */
/*                     ga[a][l + 1] = cs[i]; */
/*                 } */
/*             } */
/*         } */

/*         // printf("d %d n %d.\n", d, n); */

/*         int r[6] = {0}; */
/*         for (int i = 2; i <= 6; i ++) */
/*         { */
/*             for (int j = 0; j < 6; j ++) */
/*             { */
/*                 if (ga[j]) */
/*                 { */
/*                     r[0] = j; */
/*                     int t = INT_MAX; */
/*                     while(_can(ga, j, r, 1, i - 1, j, &t)) */
/*                     { */
/*                         for (int k = 0; k < i; k ++) */
/*                         { */
/*                             int* _l = ga[r[k]]; */
/*                             for (int m = 1; m < _l[0]; m += 2) */
/*                             { */
/*                                 if (_l[m] == r[k + 1]) */
/*                                 { */
/*                                     _l[m + 1] -= t; */
/*                                     break; */
/*                                 } */
/*                             } */
/*                         } */
/*                         n += t * (i - 1); */
/*                     } */
/*                 } */
/*             } */
/*         } */
/*     } */
/*     return n; */
/* } */


