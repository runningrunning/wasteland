// todo write common hash primer
// try to take a look at java string hash

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 100 * 3 * (6) 1/6 linear probing 1801
char** subdomainVisits(char** cpdomains, int cpdomainsSize, int* returnSize)
{
    int* ha = malloc(sizeof(int) * 1801);
    memset(ha, 0, sizeof(int) * 1801);

    int di = 0;
    int* dn = malloc(sizeof(int) * 300);
    char** ds = malloc(sizeof(char*) * 300);

    *returnSize = 0;
    for (int i = 0; i < cpdomainsSize; i ++)
    {
        char* d;
        char* c = cpdomains[i];
        int n = 0;

        int j = 0;
        char t = c[j ++];

        while (t != ' ')
        {
            n = n * 10 + (t - '0');
            t = c[j ++];
        }

        d = &c[j];

        int hi = 1;
        int hs[3] = {0};
        char* hc[3];
        hc[0] = d;

        j = 0;
        t = d[j ++];

        while (t)
        {
            for (int k = 0; k < hi; k ++)
                hs[k] = (128 * hs[k] + t) % 1801;
            if (t == '.')
            {
                hc[hi] = &d[j];
                hi ++;
            }
            t = d[j ++];
        }

        for (int k = 0; k < hi; k ++)
        {
            int j = hs[k];
            while (ha[j])
            {
                int l = ha[j] - 1;
                if (!strcmp(ds[l], hc[k]))
                    break;
                j = (j + 1) % 1801;
            }

            if (ha[j])
                dn[ha[j] - 1] += n;
            else
            {
                ds[di] = hc[k];
                dn[di] = n;
                di ++;
                ha[j] = di;
            }
        }
    }

    char** ret = malloc(sizeof(char*) * di);

    for (int i = 0; i < di; i ++)
    {
        char* r = malloc(strlen(ds[i]) + 10);
        sprintf(r, "%d %s", dn[i], ds[i]);
        ret[i] = r;
    }

    *returnSize = di;
    return ret;
}
