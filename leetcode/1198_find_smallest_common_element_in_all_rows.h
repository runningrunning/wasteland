int smallestCommonElement(int** mat, int matSize, int* matColSize)
{
    int r = matSize;
    int c = matColSize[0];
    int** m = mat;

    int si = 0;
    int st[512];
    int ns[10000 + 1] = {0};

    int max_start = m[0][0];
    int min_end = m[0][c - 1];

    for (int i = 0; i < c; i ++)
    {
        int x = mat[0][i];
        st[si ++] = x;
        ns[x] = 1;
    }

    for (int i = 1; i < r; i ++)
    {
        int p = m[i][0] - 1;
        int s = m[i][0];
        int e = m[i][c - 1];

        if (s > max_start)
            max_start = s;

        if (e < min_end)
            min_end = e;

        if (max_start > min_end)
            return -1;

        si = 0;

        for (int j = 0; j < c; j ++)
        {
            if (m[i][j] == p)
                continue;

            p = m[i][j];

            if (ns[p] == i)
            {
                st[si ++] = p;
                ns[p] ++;
            }
        }

        if (!si)
            return -1;
    }

    return st[0];
}

