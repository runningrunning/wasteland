// union find again
// binary search ?
// find the maximum to connect start and end
int comp(const void* a, const void* b)
{
    long la = *((long*)a);
    long lb = *((long*)b);

    return (lb >> 16) - (la >> 16);
}

int root(int** A, int r, int c, int x, int y)
{
    if (x >= r || y >= c || x < 0 || y < 0)
        return 0;

    if (A[x][y] < 0x10000)
        return 0;

    int p = A[x][y];
    p -= 0x10000;

    while (p != (x << 8 | y))
    {
        x = p >> 8;
        y = p & 0xFF;
        p = A[x][y] - 0x10000;
    }
    return A[x][y];
}

int maximumMinimumPath(int** A, int ASize, int* AColSize)
{
    int r = ASize;
    int c = AColSize[0];
    long* all = malloc(sizeof(long) * r * c);
    int low = A[0][0] < A[r - 1][c - 1] ? A[0][0] : A[r - 1][c - 1];

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            all[i * c + j] = ((long) A[i][j]) << 16 | i << 8 | j;
            A[i][j] = i << 8 | j;
        }

    // reverse sort
    qsort(all, r * c, sizeof(long), comp);

    int last_x = r - 1;
    int last_y = c - 1;

    for (int i = 0; i < r * c; i ++)
    {
        long v = all[i] >> 16;

        int x = (all[i] & 0xFFFF) >> 8;
        int y = all[i] & 0xFF;

        int pc = 0x10000 | x << 8 | y;
        int pu = root(A, r, c, x - 1, y);
        int pd = root(A, r, c, x + 1, y);
        int pl = root(A, r, c, x, y - 1);
        int pr = root(A, r, c, x, y + 1);

        if (pu)
            pc = pu < pc ? pu : pc;

        if (pd)
            pc = pd < pc ? pd : pc;

        if (pl)
            pc = pl < pc ? pl : pc;

        if (pr)
            pc = pr < pc ? pr : pc;

        A[x][y] = pc;

        if (pu)
        {
            x = (pu >> 8) & 0xFF;
            y = pu & 0xFF;
            A[x][y] = pc;
        }

        if (pd)
        {
            x = (pd >> 8) & 0xFF;
            y = pd & 0xFF;
            A[x][y] = pc;
        }

        if (pl)
        {
            x = (pl >> 8) & 0xFF;
            y = pl & 0xFF;
            A[x][y] = pc;
        }

        if (pr)
        {
            x = (pr >> 8) & 0xFF;
            y = pr & 0xFF;
            A[x][y] = pc;
        }

        if (i < r + c - 1 || v > low)
            continue;

        pc = root(A, r, c, last_x, last_y);

        if (!pc)
            continue;

        if (pc == 0x10000)
            return v;

        last_x = (pc & 0xFFFF) >> 8;
        last_y = pc & 0xFF;
    }

    return -1;
}
