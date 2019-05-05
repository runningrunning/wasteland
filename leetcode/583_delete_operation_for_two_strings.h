// code optimization
int md(char* w1, char* w2, int i1, int i2, int l1, int l2, short* t)
{
    if (i1 == l1 || i2 == l2)
        return 0;

    int i = i1 * l2 + i2;
    if (t[i])
        return t[i] - 1;

    if (w1[i1] == w2[i2])
    {
        t[i] = md(w1, w2, i1 + 1, i2 + 1, l1, l2, t) + 1 + 1;
    }
    else
    {

            int x1 = md(w1, w2, i1 + 1, i2, l1, l2, t);
            int x2 = -1;


                x2 = md(w1, w2, i1, i2 + 1, l1, l2, t);

            if (x1 >= x2)
                t[i] = x1 + 1;
            else
                t[i] = x2 + 1;
    }
    return t[i] - 1;
}

int minDistance(char* word1, char* word2)
{
    int l1 = strlen(word1);
    int l2 = strlen(word2);

    if (!l1)
        return l2;
    if (!l2)
        return l1;

    short* t = calloc(sizeof(short), l1 * l2);

    int x = md(word1, word2, 0, 0, l1, l2, t);
    return l1 + l2 - x * 2;
}

// try to lookup the start and end
/* int md(char* w1, char* w2, int i1, int i2, int l1, int l2, short* t, int* s, int* e) */
/* { */
/*     if (i1 == l1 || i2 == l2) */
/*         return 0; */

/*     int i = i1 * l2 + i2; */
/*     if (t[i]) */
/*         return t[i] - 1; */

/*     if (w1[i1] == w2[i2]) */
/*     { */
/*         t[i] = md(w1, w2, i1 + 1, i2 + 1, l1, l2, t, s, e) + 1 + 1; */
/*         return t[i] - 1; */
/*     } */

/*     int c1 = w1[i1] - 'a'; */
/*     int e1 = e[c1] - 1; */

/*     int x1 = md(w1, w2, i1 + 1, i2, l1, l2, t, s, e); */

/*     if (i2 <= e1) */
/*     { */
/*         int x2 = md(w1, w2, i1, i2 + 1, l1, l2, t, s, e); */

/*         if (x1 >= x2) */
/*             t[i] = x1 + 1; */
/*         else */
/*         { */
/*             t[i] = x2 + 1; */
/*         } */
/*     } */
/*     else */
/*     { */
/*         if (i2 <= e1) */
/*             printf("i2 %d e1 %d x1 %d.\n", i2, e1, x1); */
/*         t[i] = x1 + 1; */
/*     } */

/*     return t[i] - 1; */
/* } */

/* int minDistance(char* word1, char* word2) */
/* { */
/*     int l1 = strlen(word1); */
/*     int l2 = strlen(word2); */

/*     if (!l1) */
/*         return l2; */
/*     if (!l2) */
/*         return l1; */

/*     char* w1 = word1; */
/*     char* w2 = word2; */

/*     if (l1 < l2) */
/*     { */
/*         int t = l1; */
/*         l1 = l2; */
/*         l2 = t; */

/*         w1 = word2; */
/*         w2 = word1; */
/*     } */

/*     int s[26] = {0}; */
/*     int e[26] = {0}; */

/*     for (int i = 0; i < l2; i ++) */
/*     { */
/*         int x = w2[i] - 'a'; */
/*         if (s[x]) */
/*             e[x] = i + 1; */
/*         else */
/*         { */
/*             s[x] = i + 1; */
/*             e[x] = i + 1; */
/*         } */
/*     } */

/*     short* t = calloc(sizeof(short), l1 * l2); */
/*     int x = md(w1, w2, 0, 0, l1, l2, t, s, e); */

/*     return l1 + l2 - x * 2; */
/* } */
