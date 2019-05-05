/* take care about the corner case of INT_MAX */
/* int mySqrt(int x) */
/* { */
/*     if (x == 0) */
/*         return 0; */
/*     if (x == 1) */
/*         return 1; */

/*     int a = 1; */
/*     int b = 46340; */

/*     int t = (a + b) >> 1; */
/*     while(1) */
/*     { */
/*         if (x > t * t) */
/*             a = t; */
/*         else */
/*             b = t; */

/*         if (b - a <= 1) */
/*             return (b * b <= x) ? b : a; */

/*         t = (a + b) >> 1; */
/*     } */
/* } */

/* slower than binary search !! */
int mySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;

    int pt = 46340;
    int t = x / pt;
    int dt = abs(pt - t);

    while(dt > 1)
    {
        pt = (t + pt) / 2;
        t = x / pt;
        dt = abs(pt - t);
    }
    return t < pt ? t : pt;
}
