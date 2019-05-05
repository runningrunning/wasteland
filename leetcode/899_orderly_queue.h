// brute force ?????, code tricks out of mind
// just some tricks, if k is larger than 2, it always can group together !!
// stupid wrong algorithm !
// "kuh" to "hku" k = 1!!!

/* bool oq(char* s, int l, int k) */
/* { */
/*     bool found = false; */

/*     char c = 0; */
/*     int ci = 0; */

/*     for (int i = 0; i < k; i ++) */
/*     { */
/*         if (s[i] > s[i + 1]) */
/*         { */
/*             if (found) */
/*             { */
/*                 if (s[i] < c) */
/*                 { */
/*                     c = s[i]; */
/*                     ci = i; */
/*                 } */
/*             } */
/*             else */
/*             { */
/*                 c = s[i]; */
/*                 ci = i; */
/*                 found = true; */
/*             } */
/*         } */
/*     } */

/*     if (found) */
/*     { */
/*         for (int i = ci; i < l - 1; i ++) */
/*             s[i] = s[i + 1]; */
/*         s[l - 1] = c; */
/*     } */

/*     return found; */
/* } */

bool is_less(char* s, int ni, int mi, int l)
{
    for (int i = 0; i < l; i ++)
    {
        char nc = s[(ni + i) % l];
        char mc = s[(mi + i) % l];
        if (nc != mc)
            return nc < mc;
    }
    return false;
}

char* orderlyQueue(char* S, int K)
{
    if (!S)
        return NULL;

    char* d = strdup(S);

    if (!K)
        return d;

    int l = strlen(d);

    if (K > 1)
    {
        int cs[26] = {0};

        for (int i = 0; i < l; i ++)
            cs[d[i] - 'a'] ++;

        int di = 0;

        for (int i = 0; i < 26; i ++)
        {
            int n = cs[i];
            while (n)
            {
                d[di ++] = i + 'a';
                n --;
            }
        }
    }
    else
    {
        int mi = 0;
        for (int i = 1; i < l; i ++)
        {
            if (is_less(d, i, mi, l))
                mi = i;
        }

        int di = 0;
        for (int i = mi; i < l; i ++)
            d[di ++] = S[i];

        for (int i = 0; i < mi; i ++)
            d[di ++] = S[i];
    }

    d[l] = 0;
    return d;

    /* char* t = malloc(l + 1); */
    /* t[l] = 0; */

    /* for (int i = 0; i < l; i += K) */
    /* { */
    /*     while (oq(d, l, K)); */

    /*     int in = 0; */
    /*     for (int j = i; j < l; j ++) */
    /*         t[in ++] = t[j]; */
    /*     for (int j = 0; j < i; j ++) */
    /*         t[in ++] = t[j]; */
    /*     t[l] = 0; */

    /*     char* x = d; */
    /*     d = t; */
    /*     t = d; */
    /* } */
    return d;
}
