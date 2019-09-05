// simple sort
// compact value
// or hash, crc
int comp(const void* a, const void* b, void* c)
{
    int l = *((int*)c);
    int* pa = *((int**)a);
    int* pb = *((int**)b);

    for (int i = 0; i < l; i ++)
        if (pa[i] != pb[i])
            return pa[i] - pb[i];
    return 0;
}

int maxEqualRowsAfterFlips(int** m, int r, int* cs)
{
    int c = cs[0];

    for (int i = 0; i < r; i ++)
    {
        int in = 0;
        int s = 0;
        int reverse = m[i][0];
        while (s < c)
        {
            int e = (s + 30) < c ? (s + 30) : c;
            int v = 0;
            for (; s < e; s ++)
                v = (v << 1) + (reverse ? !m[i][s] : m[i][s]);
            m[i][in ++] = v;
            s = e;
        }
    }

    c = (c + 29) / 30;

    qsort_r(m, r, sizeof(int*), comp, &c);

    int max = 1;
    int cnt = 1;
    int pre = 0;

    for (int i = 1; i < r; i ++)
    {
        bool same = true;

        for (int j = 0; j < c; j ++)
            if (m[i][j] != m[pre][j])
            {
                same = false;
                break;
            }

        if (same)
        {
            cnt ++;
            if (cnt > max)
                max = cnt;
        }
        else
        {
            cnt = 1;
            pre = i;
        }
    }
    return max;
}


