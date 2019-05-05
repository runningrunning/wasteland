// optimize the code
// just be carefule and try to optimize
// why, graphic to get two node distance?
// is that simple ?
void _walk(int** f, int x, int y, int r, int c, int* num)
{
    if (x < 0 || x >= r || y < 0 || y >= c || f[x][y] <= 0)
        return;

    f[x][y] = - f[x][y];
    (*num) ++;

    _walk(f, x - 1, y, r, c, num);
    _walk(f, x + 1, y, r, c, num);
    _walk(f, x, y - 1, r, c, num);
    _walk(f, x, y + 1, r, c, num);
}

int _dis(int** f, int px, int py, int cx, int cy, int r, int c,
         char* bits, int* sa, int* sb)
{
    int st = 0;
    int ai = 0;
    int bi = 0;
    sa[ai ++] = px << 8 | py;

    while (ai)
    {
        for (int i = 0; i < ai; i ++)
        {
            int ax = sa[i] >> 8;
            int ay = sa[i] & 0xFF;

            if (ax == cx && ay == cy)
            {
                // printf("st is %d.\n", st);
                return st;
            }

            if (ax > 0 && f[ax - 1][ay] && !bits[(ax - 1) * c + ay])
            {
                bits[(ax - 1) * c + ay] = 1;
                sb[bi ++] = (ax - 1) << 8 | ay;
            }

            if (ax < r - 1 && f[ax + 1][ay] && !bits[(ax + 1) * c + ay])
            {
                bits[(ax + 1) * c + ay] = 1;
                sb[bi ++] = (ax + 1) << 8 | ay;
            }

            if (ay > 0 && f[ax][ay - 1] && !bits[ax * c + ay - 1])
            {
                bits[ax * c + ay - 1] = 1;
                sb[bi ++] = (ax) << 8 | (ay - 1);
            }

            if (ay < c - 1 && f[ax][ay + 1] && !bits[ax * c + ay + 1])
            {
                bits[ax * c + ay + 1] = 1;
                sb[bi ++] = (ax) << 8 | (ay + 1);
            }
        }

        int* t = sa;
        sa = sb;
        sb = t;
        ai = bi;
        bi = 0;
        st ++;
    }
    return -1;
}

int comp(const void* elem1, const void* elem2)
{
    long d = *((long*) elem1) - *((long*) elem2);
    return d ? (d < 0 ? -1 : 1) : 0;
}

int cutOffTree(int** forest, int forestRowSize, int *forestColSizes)
{
    if (!forest || !forestRowSize || !forestColSizes || !forestColSizes[0])
        return 0;

    if (!forest[0][0])
        return -1;

    int r = forestRowSize;
    int c = forestColSizes[0];

    long or = 0;
    long oc = 0;
    int ai = 0;

    long* all = malloc(sizeof(long) * r * c);

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            long f = forest[i][j];
            if (f)
            {
                all[ai ++] = f << 32 | i << 8 | j;
            }
            else
            {
                or |= 1L << i;
                oc |= 1L << j;
            }
        }

    int num = 0;
    _walk(forest, 0, 0, r, c, &num);
    if (num != ai)
        return -1;

    num = 0;
    qsort(all, ai, sizeof(long), comp);
    int* sa = malloc(sizeof(int) * r * c);
    int* sb = malloc(sizeof(int) * r * c);
    char* bits = malloc(sizeof(char) * r * c);

    long pre = 0;
    for (int i = 0; i < ai; i ++)
    {
        long cur = all[i];
        int px = (pre >> 8) & 0xFF;
        int py = pre & 0xFF;
        int cx = (cur >> 8) & 0xFF;
        int cy = cur & 0xFF;

        if ((!(or & (1L << px)) &&
             !(oc & (1L << cy)))
            || (!(or & (1L << cx)) &&
                !(oc & (1L << py))))
        {
            num += abs(px - cx) + abs(py - cy);
        }
        else
        {
            memset(bits, 0, sizeof(char) * r * c);
            num += _dis(forest, px, py, cx, cy, r, c, bits, sa, sb);
        }
        pre = cur;
    }
    return num;
}
