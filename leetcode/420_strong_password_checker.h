// very very brilliant solutions !!!!!
// minus 3n + 2
// brilliant solution !!!
// Questions by chance
// STUPID ME, just copy the solution !!!!!!!!!!!!
// Find the solution and try to do it by my self.

// find the rulesf

int _min(int a, int b)
{
    return a < b ? a : b;
}

int _max(int a, int b)
{
    return a > b ? a : b;
}

int strongPasswordChecker(char* s)
{
    int l = strlen(s);

    bool has_up = false;
    bool has_low = false;
    bool has_digit = false;

    int ns = 0;
    int ni = 0;
    int* num = malloc(sizeof(int) * l);
    num[ni] = 1;

    for (int i = 0; i < l; i ++)
    {
        int c = s[i];
        if (c >= '0' && c <= '9')
        {
            if (!has_digit)
                ns ++;
            has_digit = true;
        }
        else if (c >= 'a' && c <= 'z')
        {
            if (!has_low)
                ns ++;
            has_low = true;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            if (!has_up)
                ns ++;
            has_up = true;
        }

        if (i)
        {
            if (c == s[i - 1])
                num[ni] ++;
            else
                num[++ ni] = 1;
        }
    }

    ni ++;

    ns = 3 - ns;

    int rs = 0;
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < ni; i ++)
    {
        rs += num[i] / 3;
        if (num[i] >= 3)
        {
            if (!(num[i] % 3))
                ones += 1;
            else if ((num[i] % 3) == 1)
                twos += 2;
        }
    }

    if (l < 6)
        return _max(ns, 6 - l);

    if (l <= 20)
        return _max(rs, ns);

    int del = l - 20;

    rs -= _min(del, ones);
    rs -= _min(_max(del - ones, 0), twos) / 2;
    rs -= _max(del - ones - twos, 0) / 3;
    return del + _max(rs, ns);
}


/* // replace and add/delete are not the same number !!! */
/* // add is useless !!! */

/* int comp(const void* e1, const void* e2) */
/* { */
/*     return *((int*)e1) - *((int*)e2); */
/* } */

/* int strongPasswordChecker(char* s) */
/* { */
/*     int l = strlen(s); */
/*     if (l <= 4) */
/*         return 6 - l; */

/*     bool has_low = false; */
/*     bool has_up = false; */
/*     bool has_digit = false; */

/*     int ds = 0; */

/*     int ni = 0; */
/*     int* num = malloc(sizeof(int) * l); */
/*     num[ni] = 1; */

/*     for (int i = 0; i < l; i ++) */
/*     { */
/*         int c = s[i]; */

/*         if (c >= '0' && c <= '9') */
/*         { */
/*             if (!has_digit) */
/*                 ds += 1; */
/*             has_digit = true; */
/*         } */
/*         else if (c >= 'a' && c <= 'z') */
/*         { */
/*             if (!has_log) */
/*                 ds += 1; */
/*             has_low = true; */
/*         } */
/*         else if (c >= 'A' && c <= 'Z') */
/*         { */
/*             if (!has_up) */
/*                 ds += 1; */
/*             has_up = true; */
/*         } */

/*         if (i) */
/*         { */
/*             if (c == s[i - 1]) */
/*                 num[ni] ++; */
/*             else */
/*                 num[++ ni] = 1; */
/*         } */
/*     } */

/*     ni ++; */

/*     // wrong solution !!! */
/*     qsort(num, ni, sizeof(int), comp); */

/*     int* cs = malloc(sizeof(int) * ni); */
/*     int* rs = malloc(sizeof()); */



/*     for (int i = 0; i < ni; i ++) */
/*     { */
/*         cs += nums[i] / 3; */
/*         rs += nums[i] - 2; */
/*         if (num[i] == 3) */
/*             r3s += 1; */
/*     } */

/*     if (cs >= 3 - ds) */
/*     { */
/*         // only replace */
/*         cs -= 3 - ds; */

/*         if (l >= 6 && l <= 20) */
/*             return cs; */

/*         if (l < 6) // 5 */
/*             return cs + 1; */

/*         if (l - rs >= 20) */
/*             return l - 20 + 3 - ds; */

/*     } */
/*     else */
/*         cs = 3 - ds; */


/* } */

