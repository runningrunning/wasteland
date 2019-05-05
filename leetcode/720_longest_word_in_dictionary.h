// TODO String Binary Search !!!!!
// be careful about == or it will break the case in sort
bool bigger(char* a, char* b)
{
    int i = 0;
    while (a[i] && (a[i] == b[i]))
        i ++;
    return a[i] > b[i];
}

bool smaller(char* a, char* b)
{
    int i = 0;
    while (a[i] && (a[i] == b[i]))
        i ++;
    return a[i] < b[i];
}

void lw_sort(char** w, int s, int e, int* l)
{
    if (s >= e)
        return;

    int t;
    char* ts;

    if (l[s] > l[e] || (l[s] == l[e] && bigger(w[s], w[e])))
    {
        t = l[s];
        l[s] = l[e];
        l[e] = t;

        ts = w[s];
        w[s] = w[e];
        w[e] = ts;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        // bigger and smaller should be true, not contain equal in it
        while (l[i] < l[s] || (l[i] == l[s] && smaller(w[i], w[s]))) i ++;
        while (l[e] > l[s] || (l[e] == l[s] && bigger(w[e], w[s]))) e --;

        if (i >= e)
        {
            t = l[s];
            l[s] = l[e];
            l[e] = t;

            ts = w[s];
            w[s] = w[e];
            w[e] = ts;
        }
        else
        {
            t = l[i];
            l[i] = l[e];
            l[e] = t;

            ts = w[i];
            w[i] = w[e];
            w[e] = ts;
        }
    }

    lw_sort(w, cs, e - 1, l);
    lw_sort(w, e + 1, ce, l);
}

char* longestWord(char** words, int wordsSize)
{
    int wl[1024];

    for (int i = 0; i < wordsSize; i ++)
        wl[i] = strlen(words[i]);

    lw_sort(words, 0, wordsSize - 1, wl);

    int ls[31] = {0};

    for (int i = 0; i < wordsSize; i ++)
        if (!ls[wl[i]])
            ls[wl[i]] = i + 1;

    int start = 30;

    for (int i = 1; i < 31; i ++)
        if (!ls[i])
        {
            start = i - 1;
            break;
        }

    if (!start)
        return "";

    int sf = 0;
    for (int i = 0; i < wordsSize; i ++)
    {
        if (wl[i] != 1)
            break;
        sf |= 1 << (words[i][0] - 'a');
    }

    if (!sf)
        return "";

    for (int i = start; i > 0; i --)
    {
        int k = ls[i] - 1;
        while (wl[k] == i && k < wordsSize)
        {
            char* t = words[k];

            if ((sf & (1 << (t[0] - 'a'))))
            {
                int l = i - 1;
                bool found = true;

                while (l > 1)
                {
                    found = false;
                    for (int o = ls[l] - 1; o < ls[l + 1] - 1; o ++)
                    {
                        if (!strncmp(words[o], t, l))
                        {
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                        break;
                    l --;
                }

                if (found)
                    return t;
            }
            k ++;
        }
    }
    return "";
}

/* maybe hash tables, the number is limited */

/* void lw_sort(int* n, int s, int e) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     int t; */

/*     if (n[s] > n[e]) */
/*     { */
/*         t = n[s]; */
/*         n[s] = n[e]; */
/*         n[e] = t; */
/*     } */

/*     if (s + 1 == e) */
/*         return; */

/*     int cs = s; */
/*     int ce = e; */

/*     for (int i = s + 1; i <= e; i ++) */
/*     { */
/*         while(n[i] < n[s]) i ++; */
/*         while(n[e] > n[s]) e --; */


/*         if (i >= e) */
/*         { */
/*             t = n[s]; */
/*             n[s] = n[e]; */
/*             n[e] = t; */
/*         } */
/*         else */
/*         { */
/*             t = n[i]; */
/*             n[i] = n[e]; */
/*             n[e] = t; */
/*         } */
/*     } */

/*     lw_sort(n, cs; e - 1); */
/*     lw_sort(n, e + 1, ce); */
/* } */

/* int lw_search(int* n, int s, int e, int v) */
/* { */
/* } */

/* char* longestWord(char** words, int wordsSize) */
/* { */
/*     int fgs[1024] = {0}; */

/*     int ls[32] = {0}; */
/*     for (int i = 0; i < wordsSize; i++) */
/*     { */
/*         int l = strlen(words[i]); */
/*         ls[l] = 1; */
/*         fgs[i] = l < 24 | (words[i][0] - 'a') << 16 | i; */
/*     } */

/*     lw_sort(fgs, 0, wordsSize - 1); */

/*     int lm = 1; */
/*     while(ls[lm]) */
/*         lm ++; */
/*     lm -= 1; */
/* } */

