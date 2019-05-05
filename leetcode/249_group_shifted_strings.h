void gs_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 >= e)
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
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }
    gs_sort(n, cs, e - 1);
    gs_sort(n, e + 1, ce);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupStrings(char** strings, int stringsSize, int** columnSizes, int* returnSize)
{
    *returnSize = 0;
    *columnSizes = NULL;
    if (!strings)
        return NULL;

    int* n = malloc(sizeof(int) * (stringsSize + 1));
    for (int i = 0; i < stringsSize; i ++)
        n[i] = (strlen(strings[i]) << 16) | (i + 1);
    n[stringsSize] = INT_MAX;
    gs_sort(n, 0, stringsSize - 1);

    int rs = 1;
    int* c = malloc(sizeof(int) * rs);
    char*** r = malloc(sizeof(char**) * rs);

    int mask = (0xFFFF << 16);
    int pre_i = 0;
    int pre = n[pre_i];

    int sl = 0;
    int sample[64] = {0};
    int temp[64] = {0};

    for (int i = 0; i <= stringsSize; i ++)
    {
        if ((n[i] & mask) == (pre & mask))
            continue;

        int l = i - pre_i;
        int s = (pre & mask) >> 16;

        if (s <= 1 || l == 1)
        {
            c[rs - 1] = l;
            r[rs - 1] = malloc(sizeof(char*) * l);
            for (int j = pre_i; j < i; j ++)
                r[rs - 1][j - pre_i] = strings[(n[j] & 0xFFFF) - 1];
            r = realloc(r, sizeof(char**) * (++ rs));
            c = realloc(c, sizeof(int) * rs);
        }
        else
        {
            while (l)
            {
                int new = 0;
                bool none = true;
                for (int j = pre_i; j < i; j ++)
                {
                    sl = (s  + 2) / 4;

                    if (n[j])
                    {
                        int c = 0;
                        int df = 0;

                        char* str = strings[(n[j] & 0xFFFF) - 1];
                        int* diff = none ? sample : temp;
                        for (int x = 0; x < s - 1; x ++)
                        {
                            c = (str[x + 1] - str[x] + 26) % 26;
                            df |= (c << ((x % 4) * 8));

                            if (!((x + 1) % 4))
                            {
                                diff[x / 4] = df;
                                df = 0;
                            }
                        }

                        if (((s - 1) % 4))
                            diff[(s - 2) / 4] = df;

                        bool need = true;
                        if (!none)
                        {
                            for (int y = 0; y < sl; y ++)
                                if (diff[y] != sample[y])
                                {
                                    need = false;
                                    break;
                                }
                        }

                        if (need)
                        {
                            new ++;
                            n[j] &= 0xFFFF;
                        }
                        none = false;
                    }
                }

                int new_i = 0;
                c[rs - 1] = new;
                r[rs - 1] = malloc(sizeof(char*) * new);

                for (int j = pre_i; j < i; j ++)
                    if (n[j] && (!(n[j] & mask)))
                    {
                        r[rs - 1][new_i ++] = strings[n[j] - 1];
                        n[j] = 0;
                    }
                r = realloc(r, sizeof(char**) * (++ rs));
                c = realloc(c, sizeof(int) * rs);
                l -= new;
            }
        }
        pre_i = i;
        pre = n[i];
    }
    *returnSize = rs - 1;
    *columnSizes = c;
    return r;
}
