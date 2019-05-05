/* strstr ? NOT, use simple flags and bits should be enough */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// USING SOME CORNER CASE TO DO SUCH TASK
char** findRepeatedDnaSequences(char* s, int* returnSize)
{
    int i = 0;
    int l = strlen(s);

    *returnSize = 0;
    if (l < 11)
        return NULL;

    // fs index << 16 | number of matched
    int f[1536] = {0};

    int fi = 0;
    int** fs = malloc(sizeof(int*) * 1024);
    int ri = 0;
    char** r = malloc(sizeof(char*) * 256);

    int o[26] = {0};
    o['A' - 'A'] = 0;
    o['C' - 'A'] = 1;
    o['G' - 'A'] = 2;
    o['T' - 'A'] = 3;

    int m = 0;
    int mask = 0xFFFFF;
    char c = 0;
    char oc = 0;

    int tf = 0;
    int t[4] = {1, 11, 121, 0};

    for (i = 0; i < 10; i ++)
    {
        c = s[i] - 'A';
        tf += t[o[c]];
        m <<= 2;
        m |= o[c];
    }

    f[tf] = (fi << 16) | 1;
    fs[fi] = malloc(sizeof(int) * 10);
    fs[fi][0] = m;
    fi ++;

    for (;i < l; i ++)
    {
        oc = s[i - 10] - 'A';
        c = s[i] - 'A';
        tf = tf - t[o[oc]] + t[o[c]];
        m <<= 2;
        m |= o[c];
        m &= mask;

        bool found = false;
        // check exist
        if (f[tf])
        {
            int ftmp = f[tf];

            int ftmp_i = ftmp >> 16;
            int ftmp_n = ftmp & 0xFFFF;

            for (int l = 0; l < ftmp_n; l ++)
            {
                int fsm = fs[ftmp_i][l] & mask;
                if (fsm == m)
                {
                    if (!(fs[ftmp_i][l] & 0xF0000000))
                    {
                        char* tc = malloc(11);
                        strncpy(tc, &s[i - 9], 10);
                        tc[10] = 0;
                        r[ri ++] = tc;
                        if (!((ri + 1) % 256))
                            r = realloc(r, sizeof(char*) * (ri + 1 + 256));
                        fs[ftmp_i][l] |= 0xF0000000;
                    }

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                ftmp ++;
                ftmp_n ++;
                f[tf] = ftmp;
                if (!(ftmp_n % 10))
                    fs[ftmp_i] = realloc(fs[ftmp_i], sizeof(int) * (ftmp_n + 10));
                fs[ftmp_i][ftmp_n - 1] = m;
            }
        }
        else
        {
            f[tf] = (fi << 16) | 1;
            int* tmp = malloc(sizeof(int) * 10);
            tmp[0] = m;
            fs[fi ++] = tmp;
            if (!((fi + 1) % 1024))
                fs = realloc(fs, sizeof(int*) * (fi + 1 + 1024));
        }
    }

    *returnSize = ri;
    return r;
}
