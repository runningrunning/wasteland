// think too much !!!!! DP questions !!
int minSwap(int* a, int ASize, int* b, int BSize) {
    int pa = 0; int pb = 1;
    for (int i = ASize - 2; i >= 0; i --)
    {
        int ta, tb;
        if (a[i] < a[i + 1] && b[i] < b[i + 1])
        {
            if (b[i] < a[i + 1] && a[i] < b[i + 1])
            {
                ta = pa < pb ? pa : pb;
                tb = pa + 1;
            }
            else
            {
                ta = pa;
                tb = pb + 1;
            }
        }
        else
        {
            ta = pb;
            tb = pa + 1;
        }
        pa = ta;
        pb = tb;
    }
    return pa > pb ? pb : pa;
}

/* int ms(int* a, int* b, int i, int s, int* p) */
/* { */
/*     if (i >= s) */
/*         return 0; */

/*     if (p[i]) */
/*         return p[i] - 1; */

/*     if (i) */
/*     { */
/*         if (a[i] <= a[i - 1] || b[i] <= b[i - 1]) */
/*         { */
/*             int t = a[i]; */
/*             a[i] = b[i]; */
/*             b[i] = t; */
/*             int x = 1 + ms(a, b, i + 1, s, p); */
/*             b[i] = a[i]; */
/*             a[i] = t; */
/*             // p[i] = x + 1; */
/*             return x; */
/*         } */
/*     } */

/*     int d = s + 1; */
/*     if (a[i] < a[i + 1] && b[i] < b[i + 1]) */
/*         d = ms(a, b, i + 1, s, p); */

/*     int l = s + 1; */
/*     int r = s + 1; */

/*     if (a[i] < b[i + 1] && (!i || a[i] > b[i - 1]) */
/*         && b[i] < a[i + 1] && (!i || b[i] > a[i - 1])) */
/*     { */
/*         int t = a[i]; */
/*         a[i] = b[i]; */
/*         b[i] = t; */
/*         l = ms(a, b, i + 1, s, p) + 1; */
/*         b[i] = a[i]; */
/*         a[i] = t; */
/*     } */

/*     if (b[i + 1] > a[i] && a[i + 1] > b[i]) */
/*     { */
/*         int t = a[i + 1]; */
/*         a[i + 1] = b[i + 1]; */
/*         b[i + 1] = t; */
/*         r = ms(a, b, i + 2, s, p) + 1; */
/*         b[i + 1] = a[i + 1]; */
/*         a[i + 1] = t; */
/*     } */


/*     if (d < l || r < l) */
/*     { */
/*         if (d < r) */
/*             p[i] = d + 1; */
/*         return d < r ? d : r; */
/*     } */
/*     if (l != s + 1) */
/*         p[i] = l + 1; */
/*     return l; */
/* } */

/* int minSwap(int* a, int as, int* b, int bs) */
/* { */
/*     int* p = calloc(sizeof(int), as); */
/*     int x = ms(a, b, 0, as - 1, p); */
/*     out(p, as); */
/*     return x; */
/* } */

/*
void ms(int* a, int* b, int i, int s, int* at, int* bt)
{
    if (i >= s)
        return;
    ms(a, b, i + 1, s, at, bt);
    if (a[i] < a[i + 1] && b[i] < b[i + 1])
    {
        if (b[i] < a[i + 1] && a[i] < b[i + 1])
        {
            at[i] = at[i + 1] < bt[i + 1] ? at[i + 1] : bt[i + 1];
            bt[i] = at[i] + 1;
        }
        else
        {
            at[i] = at[i + 1];
            bt[i] = 1 + bt[i + 1];
        }
    }
    else
    {
        at[i] = bt[i + 1];
        bt[i] = 1 + at[i + 1];
    }
}

int minSwap(int* A, int ASize, int* B, int BSize) {
    int* at = malloc(sizeof(int) * ASize);
    int* bt = malloc(sizeof(int) * BSize);
    at[ASize - 1] = 0;
    bt[ASize - 1] = 1;
    ms(A, B, 0, ASize - 1, at, bt);
    return at[0] < bt[0] ? at[0] : bt[0];
}
*/
