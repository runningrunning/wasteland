// be careful about empty string
// stupid wrong answer !! "yzy" and "aba" is "zyabay" !!! not "yzyaba" !
// too much corner cases !!!!!!!!!!!!!
// be more careful !!!
// it's pretty simple !
void re_str(char* c, int s, int e)
{
    while (s < e)
    {
        int t = c[s];
        c[s] = c[e];
        c[e] = t;

        s ++;
        e --;
    }
}

void re(char* c, int l)
{
    bool reverse = false;
    int s = 0;
    int e = l - 1;

    while (s < e)
    {
        if (c[s] > c[e])
            return;

        if (c[s] == c[e])
        {
            s ++;
            e --;
        }
        else
        {
            reverse = true;
            break;
        }
    }

    if (reverse)
    {
        int s = 0;
        int e = l - 1;
        while (s < e)
        {
            int t = c[s];
            c[s] = c[e];
            c[e] = t;

            s ++;
            e --;
        }
    }
}

/* int comp(char** strs, int x, int y, int size) */
/* { */
/*     int ox = x; */
/*     int oy = y; */

/*     int xi = x; */
/*     int yi = y; */

/*     int sxi = 0; */
/*     int syi = 0; */

/*     while (true) */
/*     { */
/*         int cx = strs[xi][sxi]; */

/*         while (!cx) */
/*         { */
/*             xi = (xi + 1) % size; */
/*             sxi = 0; */
/*             cx = strs[xi][sxi]; */

/*             if (xi == ox) */
/*                 return 0; */
/*         } */

/*         int cy = strs[yi][syi]; */
/*         while (!cy) */
/*         { */
/*             yi = (yi + 1) % size; */
/*             syi = 0; */
/*             cy = strs[yi][syi]; */
/*         } */

/*         if (cx != cy) */
/*             return cx > cy ? 1 : -1; */

/*         sxi ++; */
/*         syi ++; */
/*     }; */

/*     return 0; */
/* } */

int compstr(char* x, int xi, char* y, int yi, int size)
{
    int sxi = xi;
    int syi = yi;
    while (true)
    {
        int cx = x[sxi];
        int cy = y[syi];

        if (cx != cy)
            return cx > cy ? 1 : -1;

        sxi ++;
        syi ++;

        if (!x[sxi])
            sxi = 0;

        if (!y[syi])
            syi = 0;

        if (sxi == xi)
            break;
    }
    return 0;
}

char* splitLoopedString(char** strs, int strsSize)
{
    if (!strs || !strsSize)
        return NULL;

    int all = 0;
    char** dups = malloc(sizeof(char*) * strsSize);

    for (int i = 0; i < strsSize; i ++)
    {
        int l = strlen(strs[i]);
        dups[i] = strdup(strs[i]);
        re(dups[i], l);
        all += l;
    }

    if (!all)
        return strdup("");

    /* int max = 0; */
    /* for (int i = 1; i < strsSize; i ++) */
    /* { */
    /*     if (comp(dups, i, max, strsSize) > 0) */
    /*         max = i; */
    /* } */

    char* r = malloc(all + 1);
    r[0] = 0;

    for (int i = 0; i < strsSize; i ++)
        strcat(r, dups[i]);
    r[all] = 0;

    int max = 0;
    for (int i = 1; i < all; i ++)
        if (compstr(r, i, r, max, all) > 0)
            max = i;

    int start = 0;
    char* rev = strdup(r);

    char* cur = r;
    for (int i = 0; i < strsSize; i ++)
    {
        int l = strlen(strs[i]);
        if (l > 1)
        {
            re_str(rev, start, start + l - 1);
            for (int j = 1; j < l; j ++)
                if (compstr(rev, start + j, cur, max, all) > 0)
                {
                    free(cur);
                    cur = strdup(rev);
                    max = start + j;
                }
            re_str(rev, start, start + l - 1);
        }
        start += l;
    }

    strncpy(rev, cur + max, all - max);
    rev[all - max] = 0;
    strncat(rev + all - max, cur, max);
    return rev;
}
