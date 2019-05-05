void flw_sort(int* n, int s, int e, char** d)
{
    if (s >= e)
        return;

    int  t;
    char* td;

    if (n[s] < n[e] || (n[s] == n[e] && strcmp(d[s], d[e]) > 0))
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
        td = d[s];
        d[s] = d[e];
        d[e] = td;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] > n[s] || (n[i] == n[s] && strcmp(d[i], d[s]) < 0)) i ++;
        while (n[e] < n[s] || (n[e] == n[s] && strcmp(d[e], d[s]) > 0)) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
            td = d[s];
            d[s] = d[e];
            d[e] = td;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
            td = d[i];
            d[i] = d[e];
            d[e] = td;
        }
    }

    flw_sort(n, cs, e - 1, d);
    flw_sort(n, e + 1, ce, d);
}

char* findLongestWord(char* s, char** d, int dSize)
{
    int* l = malloc(sizeof(int) * dSize);
    for (int i = 0; i < dSize; i ++)
        l[i] = strlen(d[i]);
    flw_sort(l, 0, dSize - 1, d);

    int ia[26] = {0};
    int ls = strlen(s);
    for (int i = 0; i < ls; i ++)
        ia[s[i] - 'a'] = i + 1;

    for (int i = 0; i < dSize; i ++)
    {
        char* t = d[i];

        int j = 0;
        int is = 0;
        for (j = 0; j < l[i]; j ++)
        {
            char c = t[j] - 'a';
            if (!ia[c] || ia[c] - 1 < is)
                break;

            while (s[is] != t[j])
                is ++;
            is ++; // must skip the latest matched
        }

        if (j == l[i])
            return t;
    }

    return strdup("");
}
