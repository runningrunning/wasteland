// practice heap more times
// raw heap function
int h_remove(int* h, int s, int** m)
{
    int r = h[0];

    if (s == 1)
        return r;

    h[0] = h[s - 1];

    int x = h[0] >> 16;
    int y = h[0] & 0xFFFF;
    int xm = m[x][y];

    s --;

    int i = 0;

    while (i < s / 2)
    {
        int r;
        int l = h[2 * i + 1];
        int lx = l >> 16;
        int ly = l & 0xFFFF;
        int lm = m[lx][ly];
        int rm = lm; // prefer lm

        if (2 * i + 2 < s)
        {
            r = h[2 * i + 2];
            int rx = r >> 16;
            int ry = r & 0xFFFF;
            rm = m[rx][ry];
        }

        if (lm <= rm)
        {
            if (lm >= xm)
                break;
            h[2 * i + 1] = h[i];
            h[i] = l;
            i = 2 * i + 1;
        }
        else
        {
            if (rm >= xm)
                break;
            h[2 * i + 2] = h[i];
            h[i] = r;
            i = 2 * i + 2;
        }
    }
    return r;
}

void h_add(int* h, int v, int s, int** m)
{
    if (s == 0)
    {
        h[0] = v;
        return;
    }

    h[s ++] = v;

    int x = v >> 16;
    int y = v & 0xFFFF;
    int xm = m[x][y];

    int i = s - 1;
    while (i > 0)
    {
        int p = h[(i - 1) / 2];
        int px = p >> 16;
        int py = p & 0xFFFF;

        if (m[px][py] <= xm)
            break;

        h[(i - 1) / 2] = h[i];
        h[i] = p;
        i = (i - 1) / 2;
    }
}

int  h_replace(int* h, int v, int s, int** m)
{
    int r = h[0];
    h[0] = v;

    if (s == 1)
        return r;

    int x = h[0] >> 16;
    int y = h[0] & 0xFFFF;
    int xm = m[x][y];

    int i = 0;

    while (i < s / 2)
    {
        int r;
        int l = h[2 * i + 1];
        int lx = l >> 16;
        int ly = l & 0xFFFF;
        int lm = m[lx][ly];
        int rm = lm; // prefer lm

        if (2 * i + 2 < s)
        {
            r = h[2 * i + 2];
            int rx = r >> 16;
            int ry = r & 0xFFFF;
            rm = m[rx][ry];
        }

        if (lm <= rm)
        {
            if (lm >= xm)
                break;
            h[2 * i + 1] = h[i];
            h[i] = l;
            i = 2 * i + 1;
        }
        else
        {
            if (rm >= xm)
                break;
            h[2 * i + 2] = h[i];
            h[i] = r;
            i = 2 * i + 2;
        }
    }
    return r;
}


/* HEAP */
int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k)
{
    if (!matrix || !k)
        return 0;

    if (k == 1)
        return matrix[0][0];

    int r = matrixRowSize;
    int c = matrixColSize;

    if (k == r * c)
        return matrix[r - 1][c - 1];

    if (k > r * c)
        return -1;

    int mi = 1;
    int* m = malloc(sizeof(int) * r * c);

    char* f = malloc(r * c);
    bzero(f, r * c);

    m[0] = 0;
    f[0] = 1;

    int sx;
    int sy;

    for (int i = 0; i < k; i ++)
    {
        int s = m[0];
        // int s = h_remove(m, mi, matrix);
        sx = s >> 16;
        sy = s & 0xFFFF;

        bool down = false;
        // down
        if (sx != r - 1 && !f[(sx + 1) * c + sy])
        {
            f[(sx + 1) * c + sy] = 1;
            down = true;
            h_replace(m, (sx + 1) << 16 | sy, mi, matrix);
        }

        bool right = false;
        // right
        if (sy != c - 1 && !f[sx * c + sy + 1])
        {
            f[sx * c + sy + 1] = 1;
            right = true;

            if (!down)
                h_replace(m, sx << 16 | (sy + 1), mi, matrix);
            else
            {
                h_add(m, sx << 16 | (sy + 1), mi, matrix);
                mi ++;
            }
        }

        if (!right && !down)
        {
            s = h_remove(m, mi, matrix);
            mi --;
        }
    }

    /*
    for (int i = 0; i < k; i ++)
    {
        int s = h_remove(m, mi, matrix);
        mi --;
        sx = s >> 16;
        sy = s & 0xFFFF;

        // down
        if (sx != r - 1 && !f[(sx + 1) * c + sy])
        {
            f[(sx + 1) * c + sy] = 1;
            h_add(m, (sx + 1) << 16 | sy, mi, matrix);
            mi ++;
        }

        // right
        if (sy != c - 1 && !f[sx * c + sy + 1])
        {
            f[sx * c + sy + 1] = 1;
            h_add(m, sx << 16 | (sy + 1), mi, matrix);
            mi ++;
        }
    }
    */
    return matrix[sx][sy];
}
