int longestLine(int** m, int r, int c)
{
    if (!m || !r || !c)
        return 0;

    int max = INT_MIN;
    int* v = malloc(sizeof(int) * c);
    memset(v, 0, sizeof(int) * c);
    int* d = malloc(sizeof(int) * (c + r));
    memset(d, 0, sizeof(int) * (c + r));
    int* ad = malloc(sizeof(int) * (c + r));
    memset(d, 0, sizeof(int) * (c + r));

    for (int i = 0; i < r; i ++)
    {
        int l = 0;
        int* t = m[i];

        for (int j = 0; j < c; j ++)
        {
            if (t[j])
            {
                l ++;
                d[r + j - i] ++;
                ad[i + j] ++;
                v[j] ++;
            }
            else
            {
                if (l > max)
                    max = l;
                if (d[r + j - i] > max)
                    max = d[r + j - i];
                if (ad[i + j] > max)
                    max = ad[i + j];
                if (v[j] > max)
                    max = v[j];
                l = 0;
                d[r + j - i] = 0;
                ad[i + j] = 0;
                v[j] = 0;
            }
        }

        if (l > max)
            max = l;
    }


    for (int i = 0; i < c; i ++)
        if (max < v[i])
            max = v[i];


    for (int i = 0; i < c + r; i ++)
    {
        if (max < d[i])
            max = d[i];
        if (max < ad[i])
            max = ad[i];
    }
    return max;
}
