// how to calculate the 24 points
// brute force ?
// how to write better code !!!!!
// more understand code here !
// must take care of 0 here

// how to write clean code here ??? !!!

void _gen(int v1, int v2, int* t, int* ti)
{
    int v1l = v1 & 0xFFFF;
    int v2l = v2 & 0xFFFF;
    int v1h = v1 >> 16;
    int v2h = v2 >> 16;

    int i = 0;

    if (v1h && v2h)
    {
        t[i ++] = (v1h * v2l + v2h * v1l) << 16 | v1l * v2l; // +
        t[i ++] = (v1h * v2l - v2h * v1l) << 16| v1l * v2l; // -
        if (v1h * v2l != v2h * v1l)
            t[i ++] = (v2h * v1l - v1h * v2l) << 16 | v1l * v2l; // -
        t[i ++] = (v1h * v2h) << 16 | v1l * v2l; // *
        t[i ++] = (v1h * v2l) << 16 | v1l * v2h; // /
        t[i ++] = (v2h * v1l) << 16 | v1h * v2l; // /
    }
    else if (v1h || v2h)
    {
        int vh = v1h ? v1h : v2h;
        int vl = v1h ? v1l : v2l;
        t[i ++] = 0 << 16 | 1; // * /
        t[i ++ ] = vh << 16 | vl; // +, -
        t[i ++] = (- vh) << 16 | vl; // -
    }
    else
    {
        t[i ++] = 0 << 16 | 1;
    }

    *ti = i;
}

int* _vals(int* n, int s, int* rs)
{
    /* printf("==== %d \n", s); */

    int ri = 0;
    int* r = NULL;

    int ti = 0;
    int t[10];

    if (s == 1)
    {
        r = malloc(sizeof(int));
        r[0] = n[0] << 16 | 1;
        ri = 1;
    }
    else if (s == 2)
    {
        _gen(n[0] << 16 | 1, n[1] << 16 | 1, t, &ri);
        r = malloc(sizeof(int) * ri);
        memcpy(r, t, sizeof(int) * ri);
    }
    else
    {
        int num = 1 << s;
        int mask = num - 1;
        char* b = calloc(sizeof(char), num);

        int i1 = 0;
        int n1[10];
        int i2 = 0;
        int n2[10];

        for (int i = 0; i < num; i ++)
        {
            if (!b[i])
            {
                b[i] = 1;
                b[(~i) & mask] = 1;

                /* printf("i %d (~i) & mask %d.\n", i, (~i) & mask); */

                int x = i;
                i1 = i2 = 0;

                for (int c = 0; c < s; c ++)
                {
                    if (x & (1 << c))
                        n1[i1 ++] = n[c];
                    else
                        n2[i2 ++] = n[c];
                }

                // if it's 0, don't do that
                if (!i1 || !i2)
                    continue;

                /* printf("== try %d %d.\n", i1, i2); */

                int vi1 = 0;
                int vi2 = 0;
                int* v1 = _vals(n1, i1, &vi1);
                int* v2 = _vals(n2, i2, &vi2);

                for (int _i1 = 0; _i1 < vi1; _i1 ++)
                    for (int _i2 = 0; _i2 < vi2; _i2 ++)
                    {
                        ti = 0;
                        _gen(v1[_i1], v2[_i2], t, &ti);
                        r = realloc(r, sizeof(int) * (ri + ti));
                        memcpy(r + ri, t, sizeof(int) * ti);
                        ri += ti;
                    }

                free(v1);
                free(v2);
            }
        }

        free(b);
    }
    *rs = ri;
    return r;
}

bool judgePoint24(int* nums, int numsSize)
{
    int rs = 0;
    int* r = _vals(nums, numsSize, &rs);

    for (int i = 0; i < rs; i ++)
    {
        int x = r[i];
        int xh = x >> 16;
        int xl = x & 0xFFFF;
        if (24 * xl == xh)
        {
            free(r);
            return true;
        }
    }
    free(r);
    return false;
}

/* bool _got(int v1, int v2, int v) */
/* { */
/*     int v1l = v1 & 0xFFFF; */
/*     int v2l = v2 & 0xFFFF; */
/*     int v1h = v1 >> 16; */
/*     int v2h = v2 >> 16; */
/*     int vl = v & 0xFFFF; */
/*     int vh = v >> 16; */

/*     if (!v1l || !v2l || !vl) */
/*         return false; */

/*     printf("%d %d %d %d %d %d. ", v1l, v2l, v1h, v2h, vl, vh); */

/*     if (v1h * v2h * vl == v1l * v2l * vh) */
/*         return true; */
/*     if (v1h * v2l * vl == v1l * v2h * vh) */
/*         return true; */
/*     if (v1l * v2h * vl == v1h * v2l * vh) */
/*         return true; */

/*     v1h *= v2l; */
/*     v2h *= v1l; */
/*     v1l *= v2l; */

/*     if ((v1h + v2h) * vl == vh * v1l) */
/*         return true; */
/*     if ((v1h - v2h) * vl == vh * v1l) */
/*         return true; */
/*     if ((v2h - v1h) * vl == vh * v1l) */
/*         return true; */

/*     printf("false\n"); */
/*     return false; */
/* } */

/* int _cal(int v1, int v2, char c) */
/* { */
/*     int v1l = v1 & 0xFFFF; */
/*     int v2l = v2 & 0xFFFF; */
/*     int v1h = v1 >> 16; */
/*     int v2h = v2 >> 16; */

/*     if (!v1l || !v2l) */
/*         return 0; */

/*     if (c == '-') */
/*         return (v1h * v2l - v2h * v1l) << 16 | v1l * v2l; */
/*     else if (c == '+') */
/*         return (v1h * v2l + v2h * v1l) << 16 | v1l * v2l; */
/*     else if (c == '/') */
/*         return (v1h * v2l) << 16 | v2h * v1l; */
/*     else if (c == '*') */
/*         return (v1h * v2h) << 16 | v1l * v2l; */

/*     return 0; */
/* } */

/* bool _jp(int* n, int s, int v) */
/* { */
/*     int x; */
/*     int vh = v >> 16; */
/*     int vl = v & 0xFFFF; */

/*     if (!vl) */
/*         return false; */

/*     if (s == 1) */
/*         return (n[0] * vl) == vh; */
/*     else if (s == 2) */
/*         return _got(n[0] ? (n[0] << 16 | 1) : 0, n[1] ? (n[1] << 16 | 1) : 0, v); */
/*     else */
/*     { */
/*         // for just 1 */
/*         int ti = 0; */
/*         int t[4] = {0}; */
/*         for (int i = 0; i < s; i ++) */
/*         { */
/*             ti = 0; */

/*             for (int j = 0; j < s; j ++) */
/*             { */
/*                 if (i != j) */
/*                     t[ti ++] = n[j]; */
/*             } */

/*             x = n[i] << 16 | 1; */
/*             if (_jp(t, ti, _cal(v, x, '-')) */
/*                 || _jp(t, ti, _cal(v, x, '/')) */
/*                 || _jp(t, ti, _cal(x, v, '-')) */
/*                 || _jp(t, ti, _cal(x, v, '+')) */
/*                 || _jp(t, ti, _cal(x, v, '*')) */
/*                 || _jp(t, ti, _cal(x, v, '/'))) */
/*             { */
/*                 printf("%d %d %d %d %d.\n", n[i], vh, vl, ti, s); */
/*                 return true; */
/*             } */
/*         } */

/*         for (int i = 0; i < s; i ++) */
/*             for (int j = i + 1; j < s; j ++) */
/*             { */
/*                 ti = 0; */

/*                 if (i != 0 && j != 0) */
/*                     t[ti ++] = n[0]; */
/*                 if (i != 1 && j != 1) */
/*                     t[ti ++] = n[1]; */
/*                 if (i != 2 && j != 2) */
/*                     t[ti ++] = n[2]; */
/*                 if (i != 3 && j != 3) */
/*                     t[ti ++] = n[3]; */

/*                 int x1 = n[i]; */
/*                 int x2 = n[j]; */

/*                 if (x1 != x2) */
/*                 { */
/*                     x = (x1 - x2) << 16 | 1; */
/*                     if (_jp(t, ti, _cal(v, x, '-')) */
/*                         || _jp(t, ti, _cal(v, x, '/')) */
/*                         || _jp(t, ti, _cal(x, v, '-')) */
/*                         || _jp(t, ti, _cal(x, v, '+')) */
/*                         || _jp(t, ti, _cal(x, v, '*')) */
/*                         || _jp(t, ti, _cal(x, v, '/'))) */
/*                         return true; */

/*                     x = (x2 - x1) << 16 | 1; */
/*                     if (_jp(t, ti, _cal(v, x, '-')) */
/*                         || _jp(t, ti, _cal(v, x, '/')) */
/*                         || _jp(t, ti, _cal(x, v, '-')) */
/*                         || _jp(t, ti, _cal(x, v, '+')) */
/*                         || _jp(t, ti, _cal(x, v, '*')) */
/*                         || _jp(t, ti, _cal(x, v, '/'))) */
/*                         return true; */
/*                 } */

/*                 x = (x1 * x2) << 16 | 1; */
/*                 if (_jp(t, ti, _cal(v, x, '-')) */
/*                     || _jp(t, ti, _cal(v, x, '/')) */
/*                     || _jp(t, ti, _cal(x, v, '-')) */
/*                     || _jp(t, ti, _cal(x, v, '+')) */
/*                     || _jp(t, ti, _cal(x, v, '*')) */
/*                     || _jp(t, ti, _cal(x, v, '/'))) */
/*                     return true; */

/*                 x = (x1 + x2) << 16 | 1; */
/*                 if (_jp(t, ti, _cal(v, x, '-')) */
/*                     || _jp(t, ti, _cal(v, x, '/')) */
/*                     || _jp(t, ti, _cal(x, v, '-')) */
/*                     || _jp(t, ti, _cal(x, v, '+')) */
/*                     || _jp(t, ti, _cal(x, v, '*')) */
/*                     || _jp(t, ti, _cal(x, v, '/'))) */
/*                     return true; */

/*                 x = x1 << 16 | x2; */
/*                 if (_jp(t, ti, _cal(v, x, '-')) */
/*                     || _jp(t, ti, _cal(v, x, '/')) */
/*                     || _jp(t, ti, _cal(x, v, '-')) */
/*                     || _jp(t, ti, _cal(x, v, '+')) */
/*                     || _jp(t, ti, _cal(x, v, '*')) */
/*                     || _jp(t, ti, _cal(x, v, '/'))) */
/*                     return true; */

/*                 x = x2 << 16 | x1; */
/*                 if (_jp(t, ti, _cal(v, x, '-')) */
/*                     || _jp(t, ti, _cal(v, x, '/')) */
/*                     || _jp(t, ti, _cal(x, v, '-')) */
/*                     || _jp(t, ti, _cal(x, v, '+')) */
/*                     || _jp(t, ti, _cal(x, v, '*')) */
/*                     || _jp(t, ti, _cal(x, v, '/'))) */
/*                     return true; */
/*             } */
/*     } */
/*     return false; */
/* } */

/* bool judgePoint24(int* nums, int numsSize) */
/* { */
/*     return _jp(nums, numsSize, 24 << 16 | 1); */
/* } */


// stupid, find better solutions !
/* for (int i = 1; i < s; i ++) */
/*  { */
/*      if (s - i > i) */
/*          break; */

/*      int x = 0; */
/*      int xi = {0, 0, 0, 0, 0}; */

/*      int b = 0; */
/*      while (true) */
/*      { */
/*          int z = xi[x] ++; */
/*          b |= 1 << z; */

/*          if (z >= s) */
/*          { */
/*              x --; */

/*              if (x < 0) */
/*                  break; */
/*              continue; */
/*          } */

/*          if (x == i) */
/*          { */
/*              for (int ) */
/*                  b &= ~(1 << z); */
/*          } */
/*          else */
/*          { */
/*              x ++; */
/*              xi[x] = xi[x - 1]; */
/*          } */
/*      } */
/*  } */
