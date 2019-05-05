void frs_sort(int* n, int s, int e, char** src, char** tar)
{
    if (s >= e)
        return;

    int t;
    char* ts;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        ts = src[s];
        src[s] = src[e];
        src[e] = ts;

        ts = tar[s];
        tar[s] = tar[e];
        tar[e] = ts;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            ts = src[s];
            src[s] = src[e];
            src[e] = ts;

            ts = tar[s];
            tar[s] = tar[e];
            tar[e] = ts;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            ts = src[i];
            src[i] = src[e];
            src[e] = ts;

            ts = tar[i];
            tar[i] = tar[e];
            tar[e] = ts;
        }
    }

    frs_sort(n, cs, e - 1, src, tar);
    frs_sort(n, e + 1, ce, src, tar);
}

bool is_same(char* s, char* t)
{
    while ((*s) && (*t) && (*s == *t))
    {
        s ++;
        t ++;
    }

    return !(*t);
}

char* findReplaceString(char* S, int* indexes, int indexesSize, char** sources, int sourcesSize, char** targets, int targetsSize)
{
    if (!indexes || !indexesSize)
        return S ? strdup(S) : NULL;

    bool sort = false;
    for (int i = 1; i < indexesSize; i ++)
        if (indexes[i] < indexes[i - 1])
        {
            sort = true;
            break;
        }

    if (sort)
        frs_sort(indexes, 0, indexesSize - 1, sources, targets);

    int rs = 1024;
    int ri = 0;
    char* r = malloc(rs);

    int ii = 0;

    int l = strlen(S);
    for (int i = 0; i < l; i ++)
    {
        if (ri == rs)
        {
            rs += 1024;
            r = realloc(r, rs);
        }

        if (ii >= indexesSize || indexes[ii] > i)
            r[ri ++] = S[i];
        else
        {
            bool found = false;
            while (ii < indexesSize && indexes[ii] == i)
            {
                if (is_same(S + i, sources[ii]))
                {
                    int sl = strlen(sources[ii]);
                    int tl = strlen(targets[ii]);

                    char* t = targets[ii];

                    if (ri + tl >= rs)
                    {
                        rs += 1024;
                        r = realloc(r, rs);
                    }
                    int j = 0;

                    while (j < tl)
                        r[ri ++] = t[j ++];

                    i += sl - 1; // be careful about minus 1

                    found = true;

                    ii ++;

                    break;
                }
                ii ++;
            }

            if (!found)
                r[ri ++] = S[i];
        }
    }

    r[ri] = 0;
    return r;
}
