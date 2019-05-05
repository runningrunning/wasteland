// find better solutions !!! use UNION FIND by which algorithms ????
// learn a lot from this !!!
int _hash(char* s, int primer)
{
    int i = 0;
    int c = s[i ++];
    int t = 0;

    while (c)
    {
        t = ((t << 8) + c) % primer;
        c = s[i ++];
    }

    return t;
}

void am_sort(int* n, int s, int e, int* m)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = m[s];
        m[s] = m[e];
        m[e] = t;
    }

    if (s + 1 == e)
        return;

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

            t = m[s];
            m[s] = m[e];
            m[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = m[i];
            m[i] = m[e];
            m[e] = t;
        }
    }

    am_sort(n, cs, e - 1, m);
    am_sort(n, e + 1, ce, m);
}

void am_strsort(char** n, int s, int e)
{
    if (s >= e)
        return;

    char* t;

    if (strcmp(n[s], n[e]) > 0)
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (strcmp(n[i], n[s]) < 0) i ++;
        while (strcmp(n[e], n[s]) > 0) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    am_strsort(n, cs, e - 1);
    am_strsort(n, e + 1, ce);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** accountsMerge(char*** accounts, int accountsRowSize, int *accountsColSizes, int** columnSizes, int* returnSize)
{
    int primer;
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pri_l = sizeof(pri)/sizeof(pri[0]);
    
    int ol = 0;
    for (int i = 0; i < accountsRowSize; i ++)
        ol += accountsColSizes[i] - 1;

    for (int i = 0; i < pri_l; i ++)
    {
        primer = pri[i];
        if (primer / ol > 3)
            break;
    }

    short* hash = calloc(sizeof(short*), primer);

    int as_id = 1;
    char** as = calloc(sizeof(char*), ol+ 1);
    int* sames = calloc(sizeof(int), ol + 1);
    int* names = calloc(sizeof(int), accountsRowSize);

    for (int i = 0; i < accountsRowSize; i ++)
    {
        char** c = accounts[i];
        if (accountsColSizes[i] > 0)
        {
            int mi = 0;
            int merge[10];
            int oid = as_id;

            for (int j = 1; j < accountsColSizes[i]; j ++)
            {
                char* mail = c[j];
                int h = _hash(mail, primer);
                while (hash[h] && strcmp(mail, as[hash[h]]))
                    h = (h + 1) % primer;

                if (hash[h] && sames[hash[h]])
                    merge[mi ++] = names[sames[hash[h]] - 1]; // careful here, must use the current id not the one in sames
                else if (!hash[h])
                {
                    as[as_id] = mail;
                    hash[h] = as_id ++;
                }
            }

            int tid;
            if (mi)
            {
                tid = merge[0];
                for (int k = 0; k < accountsRowSize; k ++)
                    for (int l = 0; l < mi; l ++)
                    {
                        if (names[k] == merge[l])
                            names[k] = tid;
                    }

            }
            else
            {
                tid = i + 1;
            }
            for (oid; oid < as_id; oid ++)
                sames[oid] = tid;
            names[i] = tid;
        }
    }

    for (int i = 0; i < accountsRowSize; i ++)
        sames[i] = i;

    am_sort(names, 0, accountsRowSize - 1, sames);

    int rs = 0;
    int* cs = malloc(sizeof(int) * accountsRowSize);
    char*** ret = malloc(sizeof(char**) * accountsRowSize);

    for (int i = 0; i < accountsRowSize; i ++)
    {
        int oi = i;
        int x = names[i];
        int l = accountsColSizes[sames[i]];
        while (i + 1 < accountsRowSize && names[i + 1] == x)
        {
            i ++;
            l += accountsColSizes[sames[i]] - 1;
        }
        char** rt = malloc(sizeof(char*) * l);
        ret[rs] = rt;

        int ri = 0;
        rt[ri ++] = accounts[sames[oi]][0];

        for (int k = oi; k <= i; k ++)
            for (int j = 1; j < accountsColSizes[sames[k]]; j ++)
                rt[ri ++] = accounts[sames[k]][j];
        am_strsort(rt, 1, l - 1);

        int al = 2;
        for (int k = 2; k < l; k ++)
            if (strcmp(rt[k], rt[k - 1]))
                rt[al ++] = rt[k];

        cs[rs] = al;

        rs ++;
    }

    *returnSize = rs;
    *columnSizes = cs;
    return ret;
}
