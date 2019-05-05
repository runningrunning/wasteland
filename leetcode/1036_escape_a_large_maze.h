// just be more careful !!!!!!!!!!!!!!!!!!!
// just find whether the blocked is a chain
// math ?
// first group blocked
// just find whether the blocked is a chain
// math ?
// first group blocked

void _iep_sort(int** b, int s, int e, int* n)
{
    if (s >= e)
        return;

    int* pt;
    if (n[s] > n[e])
    {
        n[s] ^= n[e];
        n[e] ^= n[s];
        n[s] ^= n[e];

        pt = b[s];
        b[s] = b[e];
        b[e] = pt;
    }

    if (s + 1 == e)
        return;

    int os = s;
    int oe = e;
    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            if (n[s] != n[e])
            {
                n[s] ^= n[e];
                n[e] ^= n[s];
                n[s] ^= n[e];

                pt = b[s];
                b[s] = b[e];
                b[e] = pt;
            }
        }
        else
        {
            if (n[i] != n[e])
            {
                n[i] ^= n[e];
                n[e] ^= n[i];
                n[i] ^= n[e];

                pt = b[i];
                b[i] = b[e];
                b[e] = pt;
            }
        }
    }

    _iep_sort(b, os, e - 1, n);
    _iep_sort(b, e + 1, oe, n);
}

bool _out(int** g, int r, int c, int x, int y, int mx, int my, int lx, int ly)
{
    if (x >= lx || y >= ly || x <= mx || y <= my)
        return false;

    if (x == 0 || y == 0 || x == r - 1 || y == c - 1)
        return true;

    if (g[x][y] == 1 || g[x][y] == -1)
        return false;

    g[x][y] = -1;

    return _out(g, r, c, x - 1, y, mx, my, lx, ly)
        || _out(g, r, c, x + 1, y, mx, my, lx, ly)
        || _out(g, r, c, x, y - 1, mx, my, lx, ly)
        || _out(g, r, c, x, y + 1, mx, my, lx, ly);
}

bool _reach(int** g, int r, int c, int x, int y, int tx, int ty, int mx, int my, int lx, int ly)
{
    if (x >= lx || y >= ly || x <= mx || y <= my)
        return false;

    if (x == tx && y == ty)
        return true;

    if (x < 0 || y < 0 || x >= r || y >= c)
        return false;

    if (g[x][y] == 1 || g[x][y] == -1)
        return false;

    g[x][y] = -1;

    return _reach(g, r, c, x + 1, y, tx, ty, mx, my, lx, ly)
        || _reach(g, r, c, x - 1, y, tx, ty, mx, my, lx, ly)
        || _reach(g, r, c, x, y - 1, tx, ty, mx, my, lx, ly)
        || _reach(g, r, c, x, y + 1, tx, ty, mx, my, lx, ly);
}

bool _try(int** g, int s, int e, int ox, int oy, int or, int oc, int sx, int sy, int tx, int ty)
{
    or += 2;
    oc += 2;
    ox += 1;
    oy += 1;

    int** r = malloc(sizeof(int*) * (or));
    for (int i = 0; i < or; i ++)
        r[i] = calloc(sizeof(int), (oc));

    for (int i = s; i <= e; i ++)
    {
        int gx = g[i][0] + ox;
        int gy = g[i][1] + oy;
        r[gx][gy] = 1;
    }

    return _reach(r, or, oc, sx + ox, sy + oy, tx + ox, ty + oy, -1 + ox, -1 + oy, 1000000 + ox, 1000000 + oy);
}

bool _block(int** g, int s, int e, int ox, int oy, int or, int oc, int x, int y)
{
    or += 2;
    oc += 2;
    ox += 1;
    oy += 1;

    int** r = malloc(sizeof(int*) * or);
    for (int i = 0; i < or; i ++)
        r[i] = calloc(sizeof(int), oc);

    for (int i = s; i <= e; i ++)
    {
        int gx = g[i][0] + ox;
        int gy = g[i][1] + oy;
        r[gx][gy] = 1;
    }
    return !_out(r, or, oc, x + ox, y + oy, -1 + ox, - 1 + oy, 1000000 + ox, 1000000 + oy);
}

bool _can(int** g, int s, int e, int sx, int sy, int tx, int ty)
{
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    int min_y = INT_MAX;
    int max_y = INT_MIN;

    for (int i = s; i <= e; i ++)
    {
        int x = g[i][0];
        int y = g[i][1];

        if (x < min_x)
            min_x = x;
        if (x > max_x)
            max_x = x;

        if (y < min_y)
            min_y = y;
        if (y > max_y)
            max_y = y;
    }

    bool si = sx <= max_x && sx >= min_x && sy <= max_y && sy >= min_y;
    bool ti = tx <= max_x && tx >= min_x && ty <= max_y && ty >= min_y;

    if (si || ti)
    {
        if (si && ti)
            return _try(g, s, e, - min_x, - min_y, max_x - min_x + 1, max_y - min_y + 1, sx, sy, tx, ty);

        return si ? !_block(g, s, e, - min_x, - min_y, max_x - min_x + 1, max_y - min_y + 1, sx, sy)
            : !_block(g, s, e, - min_x, - min_y, max_x - min_x + 1, max_y - min_y + 1, tx ,ty);
    }

    return true;
}

bool isEscapePossible(int** blocked, int blockedSize, int* blockedColSize, int* source, int sourceSize, int* target, int targetSize)
{
    if (!blocked || !blockedSize || !blockedColSize[0])
        return true;

    int* types = malloc(sizeof(int) * blockedSize);
    types[0] = 1;

    int new = 2;
    int all = 1;

    int temp[256] = {0};

    int mi = 0;
    int merged[256];

    for (int i = 1; i < blockedSize; i ++)
    {
        mi = 0;
        int ix = blocked[i][0];
        int iy = blocked[i][1];
        for (int j = 0; j < i; j ++)
        {
            int jx = blocked[j][0];
            int jy = blocked[j][1];

            if (abs(jx - ix) <= 1 && abs(jy - iy) <= 1)
            {
                if (!temp[types[j]])
                {
                    temp[types[j]] = 1;
                    merged[mi ++] = types[j];
                }
            }
        }

        if (!mi)
        {
            types[i] = new ++;
            all ++;
        }
        else
        {
            types[i] = merged[0];
            for (int j = 1; j < mi; j ++)
                for (int k = 0; k < i; k ++)
                    if (types[k] == merged[j])
                        types[k] = merged[0];
            all -= (mi - 1);
        }
        for (int j = 0; j < mi; j ++)
            temp[merged[j]] = 0;
    }

    if (all == blockedSize)
        return true;

    _iep_sort(blocked, 0, blockedSize - 1, types);

    int s = 0;
    int e = s;

    for (int i = 1; i < blockedSize; i ++)
    {
        if (types[i] == types[s])
        {
            e = i;
            continue;
        }

        if (e != s && !_can(blocked, s, e, source[0], source[1], target[0], target[1]))
            return false;

        s = i;
        e = i;
    }

    if (e != s && !_can(blocked, s, e, source[0], source[1], target[0], target[1]))
        return false;

    return true;
}
