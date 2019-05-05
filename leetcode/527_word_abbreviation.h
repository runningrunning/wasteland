// try to use different solution !!!, just sort !
bool wa_large(char* a, char* b, int l)
{
    int xa = (a[0] << 8) | a[l - 1];
    int xb = (b[0] << 8) | b[l - 1];
    return (xa > xb) || (xa == xb && strcmp(a, b) > 0);
}

void wa_sort(int* n, int s, int e, int* id, char** d)
{
    if (s >= e)
        return;

    int t;
    char* td;

    if (n[s] > n[e] || (n[s] == n[e] && wa_large(d[s], d[e], n[s])))
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = id[s];
        id[s] = id[e];
        id[e] = t;

        td = d[s];
        d[s] = d[e];
        d[e] = td;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s] || (n[i] == n[s] && !wa_large(d[i], d[s], n[i]))) i ++;
        while (n[e] > n[s] || (n[e] == n[s] && wa_large(d[e], d[s], n[e]))) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = id[s];
            id[s] = id[e];
            id[e] = t;

            td = d[s];
            d[s] = d[e];
            d[e] = td;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = id[i];
            id[i] = id[e];
            id[e] = t;

            td = d[i];
            d[i] = d[e];
            d[e] = td;
        }
    }

    wa_sort(n, cs, e - 1, id, d);
    wa_sort(n, e + 1, ce, id, d);
}

void dabr(char** d, int s, int e, int l, int si, char** r, int* id, char* t)
{
    if (s == e)
    {
        int i = 0;
        for (; i <= si; i ++)
            t[i] = d[s][i];
        i += sprintf(t + si + 1, "%d", l - 2 - si);
        i += sprintf(t + i, "%c", d[s][l - 1]);
        t[i] = 0;
        if (strlen(t) < l)
            r[id[s]] = strdup(t);
        else
            r[id[s]] = strdup(d[s]);
    }
    else
    {
        si ++;
        int st = s;
        int pre = -1;
        for (int x = s; x <= e; x ++)
        {
            char* y = d[x];
            if (pre == -1)
                pre = y[si];
            else if (pre != y[si])
            {
                dabr(d, st, x - 1, l, si, r, id, t);
                st = x;
            }
            pre = y[si];
        }
        dabr(d, st, e, l, si, r, id, t);
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordsAbbreviation(char** dict, int dictSize, int* returnSize)
{
    int* ls = malloc(sizeof(int) * dictSize);
    int* id = malloc(sizeof(int) * dictSize);

    for (int i = 0; i < dictSize; i ++)
    {
        id[i] = i;
        ls[i] = strlen(dict[i]);
    }
    wa_sort(ls, 0, dictSize - 1, id, dict);
    int ri = dictSize;
    char** r = calloc(sizeof(char*), ri);
    char t[512];
    for (int i = 0; i < dictSize; i ++)
    {
        if (ls[i] <= 3)
            r[id[i]] = strdup(dict[i]);
        else
        {
            int l = ls[i];
            int c = (dict[i][0] << 8) | dict[i][l - 1];

            int j = i + 1;
            for (; j < dictSize; j ++)
            {
                if (ls[j] != l)
                    break;

                int jc = (dict[j][0] << 8) | dict[j][l - 1];
                if (jc != c)
                    break;
            }
            dabr(dict, i, -- j, l, 0, r, id, t);
            i = j;
        }
    }
    *returnSize = dictSize;
    return r;
}
