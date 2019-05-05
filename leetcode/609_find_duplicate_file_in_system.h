/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// need better hash implementation !!!
// HASH must be positive number, can never be negative number !!!
// only need duplicate

char*** findDuplicate(char** paths, int pathsSize, int** columnSizes, int* returnSize)
{
    *returnSize = 0;
    *columnSizes = NULL;
    if (!paths || !pathsSize)
        return NULL;

    // 1 << i
    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 8; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 10 > pathsSize)
            break;
    }

    int* hs = malloc(sizeof(int) * dp);
    int hl = ((dp + 31) / 32) + 1;
    int* hf = malloc(sizeof(int) * hl);
    memset(hf, 0, sizeof(int) * hl);

    int rs = 0;
    char** vs = NULL;
    int* cs = NULL;
    char*** ret = NULL;

    for (int j = 0; j < pathsSize; j ++)
    {
        char* p = paths[j];

        int i = 0;
        int c = p[i ++];

        int pe = -1;
        int s = -1;

        while (c)
        {
            while (c && c != ' ')
                c = p[i ++];

            if (pe == -1)
            {
                pe = i - 1;
                s = i;
            }
            else
            {
                char* f = malloc(pe + 1 + 1 + i - s);
                int fe = pe;
                strncpy(f, p, fe);
                f[fe ++] = '/';

                int k = s;
                int t = p[k ++];

                while (t != '(')
                {
                    f[fe ++] = t;
                    t = p[k ++];
                }
                f[fe] = 0;

                int hash = 0;

                int content = k;
                t = p[k];
                while (t != ')')
                {
                    hash = (32 * hash + t) % dp;
                    t = p[k ++];
                }

                s = i;

                int x = hash / 32;
                int y = hash % 32;

                while ((hf[x] & (1 << y)) && strncmp(vs[hs[hash]], p + content, k - content - 1))
                {
                    hash = (hash + 1) % dp;
                    x = hash /32;
                    y = hash % 32;
                }

                if (hf[x] & (1 << y))
                {
                    int in = hs[hash];
                    cs[in] ++;
                    ret[in] = realloc(ret[in], sizeof(char*) * cs[in]);
                    ret[in][cs[in] - 1] = f;
                }
                else
                {
                    hf[x] |= 1 << y;
                    hs[hash] = rs;
                    rs ++;
                    if (rs > 1)
                    {
                        vs = realloc(vs, sizeof(char*) * rs);
                        cs = realloc(cs, sizeof(int) * rs);
                        ret = realloc(ret, sizeof(char**) * rs);
                    }
                    else
                    {
                        vs = realloc(vs, sizeof(char*) * rs);
                        cs = realloc(cs, sizeof(int) * rs);
                        ret = realloc(ret, sizeof(char**) * rs);
                    }

                    vs[rs - 1] = p + content;
                    cs[rs - 1] = 1;
                    ret[rs - 1] = malloc(sizeof(char*));
                    ret[rs - 1][0] = f;
                }
            }
            if (c == ' ')
                c = p[i];
        }
    }

    int need = 0;
    for (int i = 0; i < rs; i ++)
    {
        if (cs[i] > 1)
        {
            cs[need] = cs[i];
            ret[need ++] = ret[i];
        }
        else
        {
            free(ret[i][0]);
            free(ret[i]);
        }
    }
    free(hs);
    free(hf);

    rs = need;

    *returnSize = rs;
    *columnSizes = cs;
    return ret;
}

