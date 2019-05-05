// Be careful about the corner cases
// TODO REDO, complicated
// t is less than s
// can not find
char* minWindow(char* s, char* t)
{
    if (!s || !t || !s[0] || !t[0])
        return "";

    int n = strlen(t);
    int ls = strlen(s);
    if (n > ls)
        return "";

    if (n == 1)
    {
        int i = 0;
        int c = s[i ++];
        while(c)
        {
            if (c == t[0])
            {
                char* r = malloc(2);
                r[0] = t[0];
                r[1] = 0;
                return r;
            }
            c = s[i ++];
        }
        return "";
    }

    int i = 0;
    int c = t[i ++];
    int ts[256] = {0};

    while (c)
    {
        ts[c] ++;
        c = t[i ++];
    }

    int ns[256] = {0};

    int last_i = 0;
    int* last = malloc(sizeof(int) * n);

    int start_i = 0;

    int r_s = -1;
    int min = INT_MAX;

    int got = 0;
    bool found = false;

    i = 0;
    c = s[i ++];

    while(c)
    {
        if (ts[c])
        {
            if (!found)
            {
                if (ns[c] < ts[c])
                    got ++;

                if (got == n)
                {
                    found = true;
                    start_i = 0;
                }
            }

            ns[c] ++;

            if (!((last_i + 1) % n))
                last = realloc(last, sizeof(int) * (last_i + 1 + n));
            last[last_i ++] = i - 1;

            if (found)
            {
                while (start_i < last_i)
                {
                    int x = s[last[start_i]];
                    if (ns[x] <= ts[x])
                        break;
                    ns[x] --;
                    start_i ++;
                }

                if (min > i - last[start_i])
                {
                    r_s = last[start_i];
                    min = i - last[start_i];
                }
            }

        }
        c = s[i ++];
    }

    if (r_s == -1)
        return "";

    char* r = malloc(min + 1);
    strncpy(r, s + r_s, min);
    r[min] = 0;
    return r;
}

/* struct LN */
/* { */
/*     int pos; */
/*     struct LN* next; */
/* }; */

/* void insert(int* heap, int* pos, struct LN** multi, int c, int val) */
/* { */
/*     int ni = val << 8; */
/*     int os = heap[c] & 0xFF; */

/*     if (c > 128) */
/*     { */
/*         heap[c] = ni | os; */
/*         pos[os] = ni | c; */
/*     } */

/*     while(c <= 128) */
/*     { */
/*         int nl = heap[2 * c + 1]; */
/*         int nr = heap[2 * c + 2]; */

/*         if (nl == 0 && nr == 0) */
/*         { */
/*             heap[c] = ni | os; */
/*             pos[os] = ni | c; */
/*             break; */
/*         } */

/*         int n, nc; */

/*         if (nl == 0 || nr == 0) */
/*         { */
/*             if (nl) */
/*             { */
/*                 n = nl; */
/*                 nc = 2 * c + 1; */
/*             } */
/*             else */
/*             { */
/*                 n = nr; */
/*                 nc = 2 * c + 2; */
/*             } */

/*             /\* if (multi[n & 0xFF]) *\/ */
/*             /\* { *\/ */
/*             /\*     int nx = (n & ~0xFF) | nc; *\/ */
/*             /\*     struct LN* mp = multi[n&0xFF]; *\/ */

/*             /\*     while((mp->pos & ~0xFF) != (nx & ~0xFF)) *\/ */
/*             /\*         mp = mp->next; *\/ */
/*             /\*     mp->pos =  (n & ~0xFF) | c; *\/ */
/*             /\*     heap[c] = n; *\/ */
/*             /\* } *\/ */
/*             /\* else *\/ */
/*             { */
/*                 pos[n & 0xFF] = (n & ~0xFF) | c; */
/*                 heap[c] = n; */
/*             } */

/*             pos[os] = ni | nc; */
/*             heap[nc] = ni | os; */
/*             break; */
/*         } */

/*         if (nl > nr) */
/*         { */
/*             n = nr; */
/*             nc = 2 * c + 2; */
/*         } */
/*         else */
/*         { */
/*             n = nl; */
/*             nc = 2 * c + 1; */
/*         } */

/*         /\* if (multi[n & 0xFF]) *\/ */
/*         /\* { *\/ */
/*         /\*     int nx = (n & ~0xFF) | nc; *\/ */
/*         /\*     struct LN* mp = multi[n&0xFF]; *\/ */
/*         /\*     while((mp->pos & ~0xFF) != (nx & ~0xFF)) *\/ */
/*         /\*     { *\/ */
/*         /\*         printf("mp->pos %d nx %d %d %d\n", mp->pos, nx, mp->pos & ~0xFF, nx & ~0xFF); *\/ */
/*         /\*         mp = mp->next; *\/ */
/*         /\*     } *\/ */
/*         /\*     mp->pos =  (n & ~0xFF) | c; *\/ */
/*         /\*     heap[c] = n; *\/ */
/*         /\* } *\/ */
/*         /\* else *\/ */
/*         { */
/*             pos[n & 0xFF] = (n & ~0xFF) | c; */
/*             heap[c] = n; */
/*         } */


/*         pos[os] = ni | nc; */
/*         heap[nc] = ni | os; */
/*         c = nc; */
/*     } */

/*     if (multi[os]) */
/*     { */
/*         int op = pos[os]; */
/*         multi[os]->pos = pos[os]; */
/*         multi[os] = multi[os]->next; */
/*         pos[os] = multi[os]->pos; */
/*     } */
/* } */

/* char* minWindow(char* s, char* t) */
/* { */
/*     if (!strlen(t)) */
/*         return ""; */

/*     int all[256] = {0}; */
/*     int pos[256] = {0}; */
/*     int heap[65536] = {0}; */
/*     struct LN* multi[256] = {0}; */

/*     int lt = strlen(t); */
/*     int ls = strlen(s); */

/*     int need = lt; */
/*     for(int i = 0; i < lt; i ++) */
/*         all[t[i]] ++; */

/*     for(int i = 0; i < 256; i ++) */
/*     { */
/*         if (all[i] > 1) */
/*         { */
/*             int j = all[i]; */
/*             struct LN** p = &multi[i]; */
/*             while(j) */
/*             { */
/*                 *p = malloc(sizeof(struct LN)); */
/*                 (*p)->pos = 0; */
/*                 (*p)->next = NULL; */
/*                 p = &((*p)->next); */
/*                 j --; */
/*             } */
/*             *p = multi[i]; */
/*         } */
/*     } */

/*     /\* heap = malloc(sizeof(int) * (need + 1)); *\/ */
/*     /\* memset(heap, 0, sizeof(int) * (need + 1)); *\/ */

/*     //    printf("%d %d.\n", lt, ls); */
/*     if (ls < need) */
/*         return ""; */

/*     int min = ls; */
/*     int min_i = 0; */
/*     int cur = 0; */
/*     for(int i = 0; i < ls; i++) */
/*     { */
/*         if (all[s[i]]) */
/*         { */
/*             int p = ((i + 1) << 8) | cur; */

/*             if (!pos[s[i]]) */
/*                 pos[s[i]] = p; */

/*             heap[cur] = ((i + 1) << 8) | s[i]; */

/*             if (multi[s[i]]) */
/*             { */
/*                 multi[s[i]]->pos = p; */
/*                 multi[s[i]] = multi[s[i]]->next; */
/*             } */

/*             all[s[i]] --; */
/*             cur ++; */

/*             if (cur == need) */
/*             { */
/*                 min_i = (heap[0] >> 8) - 1; */
/*                 min = i - min_i + 1; */
/*                 if (min == need) */
/*                     break; */
/*             } */
/*         } */
/*         else if (pos[s[i]]) */
/*         { */
/*             //            printf("try %d.\n", i); */
/*             if (multi[s[i]]) */
/*                 pos[s[i]] = multi[s[i]]->pos; */

/*             int oc = pos[s[i]] & 0xFF; */
/*             insert(heap, pos, multi, oc, i + 1); */

/*             if (cur == need) */
/*             { */
/*                 if (min > (i - (heap[0] >> 8) + 2)) */
/*                 { */
/*                     min_i = (heap[0] >> 8) - 1; */
/*                     min = i - min_i + 1; */
/*                     if (min == need) */
/*                         break; */
/*                 } */
/*             } */
/*         } */
/*     } */

/*     if (cur < need) */
/*         return ""; */

/*     char* ret = malloc(sizeof(char) * (min + 1)); */
/*     memcpy(ret, s + min_i, min); */
/*     ret[min] = 0; */

/*     return ret; */
/* } */
