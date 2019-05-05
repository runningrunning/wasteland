// math again ~~~!!!!!!
// some corner case here !

// can use mod to optimize this
// can be that simple ???
// not the correct solution ?
// on the right direction ~~~ !!!!!

// x base t
// just try and cut
// guess or just try ?
// simple recursion
// binary ?
// hash and remember the result
// how to optimize this ?

int _loet(int* n, int c, int b, int max)
{
    if (max <= 0)
        return INT_MAX;

    // printf("c %d b %d %d.\n", c, b, max);

    if (c == 0)
    {
        int add = n[0] * 2; // + b / b;
        int minus = (b - n[0]) * 2 + 1; // b * b - b / b;
        // printf("add %d minus %d ret is %d.\n", add, minus, add < minus ? add : minus);
        return add < minus ? add : minus;
    }

    if (n[c] == 0)
        return _loet(n, c - 1, b, max);

    /* int cur = INT_MAX; */

    /* if (n[c] == b - 1) */
    /* { */
    /*     int oc = c; */
    /*     while (c >= 0 && n[c] == b - 1) */
    /*         c --; */
    /*     cur = oc + 1 + c + 1; // 1 * oc '*' + '-' + 1 * c '*' + '+' */

    /*     if (c >= 0) */
    /*         cur += _loet(n, c, b, m); */
    /*     else */
    /*         cur += 1; // last '/' */
    /*     // printf("oc %d c %d %d.\n", oc, c, cur); */
    /*     c = oc; */
    /* } */

    int t_add = _loet(n, c - 1, b, max - n[c] * c); // num * (c - 1) '*' + num * '+'o

    if (t_add != INT_MAX)
    {
        t_add += n[c] * c;
        if (max > t_add)
            max = t_add;
    }

    // printf("t_add is %d %d.\n", t_add, c);

    int i = 0;
    int t[64] = {0};

    for (i = c; i >= 0; i --)
        t[i] = b - 1 - n[i];

    t[0] += 1;

    while (t[i] == b)
    {
        t[i ++] = 0;
        t[i] += 1;
    }

    int t_minus = _loet(t, c, b, max - c - 1);

    if (t_minus == INT_MAX)
        return t_add;

    t_minus += c + 1;

    return t_add > t_minus ? t_minus : t_add;
}

int leastOpsExpressTarget(int x, int target)
{
    int* all = malloc(sizeof(int) * 64);

    int ai = 0;
    int t = target;

    while (t)
    {
        all[ai ++] = t % x;
        t /= x;
    }

    x = _loet(all, ai - 1, x, INT_MAX);
    // out(all, ai);
    return x - 1;
}


/* int _loet(long x, long t, long c, long* max, int* hash) */
/* { */
/*     if (t < 0) */
/*         return *max; */

/*     if (hash[t]) */
/*         return hash[t] - 1; */

/*     if (t == 1) */
/*         return 1; */

/*     if (t == 0) */
/*         return -1; */

/*     if (x == t) */
/*         return 0; */

/*     int cur_min = *max - c; */

/*     int num = 0; */
/*     long n = x; */

/*     while (n <= t) */
/*     { */
/*         num ++; */
/*         n *= x; */
/*     } */

/*     if (n >= t) */
/*     { */
/*         n /= x; */
/*         num --; */
/*     } */

/*     while (num >= 0) */
/*     { */
/*         int temp = num + 1 + _loet(x, t - n, c + num + 1, max, hash); */

/*         if (temp + c < *max) */
/*             *max = temp + c; */

/*         if (temp < cur_min) */
/*             cur_min = temp; */

/*         n /= x; */
/*         num --; */
/*     } */

/*     num = 0; */
/*     n = x; */

/*     while (n <= t) */
/*     { */
/*         num ++; */
/*         n *= x; */
/*     } */

/*     while(true) */
/*     { */
/*         if (c + num + 1 >= *max */
/*             || (num > t * 2)) */
/*             break; */

/*         int temp = num + 1 + _loet(x, n - t, c + num + 1, max, hash); */
/*         // printf("==== got here.%d %d %d.\n", temp, num, c); */

/*         if (temp + c < *max) */
/*         { */
/*             // printf("==== update here.%d.\n", temp + c); */
/*             *max = temp + c; */
/*         } */

/*         if (temp < cur_min) */
/*             cur_min = temp; */

/*         n *= x; */
/*         num ++; */
/*     } */
/*     hash[t] = cur_min + 1; */
/*     return cur_min; */
/* } */

/* int leastOpsExpressTarget(int x, int target) */
/* { */
/*     int* hash = calloc(sizeof(int), target); */
/*     long max = (target / x) + (target % x) * 2; */
/*     return _loet(x, target, 0, &max, hash); */
/* } */
 
