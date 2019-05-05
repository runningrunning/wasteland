// find better way to do !!!
// just to fix the hash collision

#define FMASK 0x80000000
#define VMASK 0x7FFFFFFF
#define PRIMER 4099

int ndil2(int** g, int r, int c, int x, int y, int id, int* n, int* x1, int* y1)
{
    if (x < 0 || y < 0 || x == r || y == c || !g[x][y] || g[x][y] == id)
        return 0;
    (*n) ++;
    int tn = (*n);
    int v = 1;
    g[x][y] = id;

    if (x < x1[4] || (x == x1[4] && y > y1[4]))  // reverse
    {
        x1[4] = x;
        y1[4] = y;
    }

    if (y < y1[1] || (y == y1[1] && x > x1[1])) // 90
    {
        x1[1] = x;
        y1[1] = y;
    }

    if (y < y1[5] || (y == y1[5] && x < x1[5])) // 90 + reverse
    {
        x1[5] = x;
        y1[5] = y;
    }

    if (x > x1[2] || (x == x1[2] && y > y1[2])) // 180
    {
        x1[2] = x;
        y1[2] = y;
    }

    if (x > x1[6] || (x == x1[6] && y < y1[6])) // 180 + reverse
    {
        x1[6] = x;
        y1[6] = y;
    }

    if (y > y1[3] || (y == y1[3] && x < x1[3])) // 270
    {
        x1[3] = x;
        y1[3] = y;
    }

    if (y > y1[7] || (y == y1[7] && x > x1[7])) // 270 + reverse
    {
        x1[7] = x;
        y1[7] = y;
    }

    int t = ndil2(g, r, c, x - 1, y, id, n, x1, y1);
    if (t)
        v = (v * (t << 3) + 2 * (tn)) % PRIMER;
    else
        v = (v * 3) % PRIMER;

    t = ndil2(g, r, c, x + 1, y, id, n, x1, y1);
    if (t)
        v = (v * (t << 3) + 3 * (tn)) % PRIMER;
    else
        v = (v * 5) % PRIMER;

    t = ndil2(g, r, c, x, y - 1, id, n, x1, y1);
    if (t)
        v = (v * (t << 3) + 4 * (tn)) % PRIMER;
    else
        v = (v * 7) % PRIMER;

    t = ndil2(g, r, c, x, y + 1, id, n, x1, y1);
    if (t)
        v = (v * (t << 3) + 5 * (tn)) % PRIMER;
    else
        v = (v * 11) % PRIMER;

    return v;
}

int ndil2t(int** g, int r, int c, int x, int y, int id, int* n, int* xs, int* ys)
{
    if (x < 0 || x == r || y < 0 || y == c || !g[x][y] || g[x][y] == id)
        return 0;

    (*n) ++;
    int tn = (*n);
    int v = 1;
    g[x][y] = id;

    int t = ndil2t(g, r, c, x + xs[0], y + ys[0], id, n, xs, ys);
    if (t)
        v = (v * (t << 3) + 2 * (tn)) % PRIMER;
    else
        v = (v * 3) % PRIMER;

    t = ndil2t(g, r, c, x + xs[1], y + ys[1], id, n, xs, ys);
    if (t)
        v = (v * (t << 3) + 3 * (tn)) % PRIMER;
    else
        v = (v * 5) % PRIMER;

    t = ndil2t(g, r, c, x + xs[2], y + ys[2], id, n, xs, ys);
    if (t)
        v = (v * (t << 3) + 4 * (tn)) % PRIMER;
    else
        v = (v * 7) % PRIMER;

    t = ndil2t(g, r, c, x + xs[3], y + ys[3], id, n, xs, ys);
    if (t)
        v = (v * (t << 3) + 5 * (tn)) % PRIMER;
    else
        v = (v * 11) % PRIMER;

    return v;
}

int numDistinctIslands2(int** grid, int gridRowSize, int gridColSize)
{
    if (!gridRowSize || !gridColSize)
        return 0;

    int* hash = calloc(sizeof(int), PRIMER);
    int id = 2;
    int num = 0;

    int inc_x[] = {
        -1,1, 0, 0,
        0, 0, 1,-1, // 90
        1,-1, 0, 0, // 180
        0, 0,-1, 1, // 270

        -1,1, 0, 0, // reverse
        0, 0,-1, 1, // reverse + 90
        1,-1, 0, 0, // reverse + 180
        0, 0, 1,-1, // reverse + 270
    };
    int inc_y[] = {
        0, 0,-1, 1,
        -1,1, 0, 0,
        0, 0, 1,-1,
        1,-1, 0, 0,

        0, 0, 1,-1,
        -1,1, 0, 0,
        0, 0,-1, 1,
        1,-1, 0, 0,
    };

    for (int i = 0; i < gridRowSize; i ++)
        for (int j = 0; j < gridColSize; j ++)
            if (grid[i][j] == 1)
            {
                int t = 0;
                int cor_x[8];
                int cor_y[8];
                cor_x[0] = cor_x[1] = cor_x[2] = cor_x[3] = cor_x[4] = cor_x[5] = cor_x[6] = cor_x[7] = i;
                cor_y[0] = cor_y[1] = cor_y[2] = cor_y[3] = cor_y[4] = cor_y[5] = cor_y[6] = cor_y[7] = j;
                int h = ndil2(grid, gridRowSize, gridColSize, i, j, id ++, &t, cor_x, cor_y);
                h = (h * t) % PRIMER;
                int old_hash = h;
                bool found = false;
                for (int k = 0; k < 8; k ++)
                {
                    if (k != 0)
                    {
                        int n = 0;
                        h = ndil2t(grid, gridRowSize, gridColSize, cor_x[k], cor_y[k], id ++, &n, inc_x + k * 4, inc_y + k * 4);
                        h = (h * t) % PRIMER;
                    }
                    while (hash[h] & FMASK)
                    {
                        int v = hash[h] & VMASK;
                        if ((v >> 16) == t)
                        {
                            found = true;
                            break;
                        }
                        h = (h + 1) % PRIMER;
                    }

                    if (found)
                        break;
                }

                if (!found)
                {
                    num ++;
                    while (hash[old_hash] & FMASK)
                        old_hash = (old_hash + 1) % PRIMER;
                    hash[old_hash] = FMASK | t << 16 | i << 8 | j;
                }
            }
    return num;
}


/* // find better way to do !!! */
/* // just to fix the hash collision */
/* // it's all about how to copper the hash and add check similar function !! */
/* // just add a check same function will make hash function much easier */
/* // be careful about the hash function !! */

/* #define FMASK 0x80000000 */
/* #define VMASK 0x7FFFFFFF */
/* #define PRIMER 4099 */

/* int ndil2(int** g, int r, int c, int x, int y, int id, int* n, int* x1, int* y1) */
/* { */
/*     if (x < 0 || y < 0 || x == r || y == c || !g[x][y] || g[x][y] == id) */
/*         return 0; */
/*     (*n) ++; */
/*     int tn = (*n); */
/*     int v = 1; */
/*     g[x][y] = id; */

/*     if (x < x1[4] || (x == x1[4] && y > y1[4]))  // reverse */
/*     { */
/*         x1[4] = x; */
/*         y1[4] = y; */
/*     } */

/*     if (y < y1[1] || (y == y1[1] && x > x1[1])) // 90 */
/*     { */
/*         x1[1] = x; */
/*         y1[1] = y; */
/*     } */

/*     if (y < y1[5] || (y == y1[5] && x < x1[5])) // 90 + reverse */
/*     { */
/*         x1[5] = x; */
/*         y1[5] = y; */
/*     } */

/*     if (x > x1[2] || (x == x1[2] && y > y1[2])) // 180 */
/*     { */
/*         x1[2] = x; */
/*         y1[2] = y; */
/*     } */

/*     if (x > x1[6] || (x == x1[6] && y < y1[6])) // 180 + reverse */
/*     { */
/*         x1[6] = x; */
/*         y1[6] = y; */
/*     } */

/*     if (y > y1[3] || (y == y1[3] && x < x1[3])) // 270 */
/*     { */
/*         x1[3] = x; */
/*         y1[3] = y; */
/*     } */

/*     if (y > y1[7] || (y == y1[7] && x > x1[7])) // 270 + reverse */
/*     { */
/*         x1[7] = x; */
/*         y1[7] = y; */
/*     } */

/*     int t = ndil2(g, r, c, x - 1, y, id, n, x1, y1); */
/*     if (t) */
/*         v = (v * (t << 3) + 2) % PRIMER; */

/*     t = ndil2(g, r, c, x + 1, y, id, n, x1, y1); */
/*     if (t) */
/*         v = (v * (t << 3) + 3) % PRIMER; */

/*     t = ndil2(g, r, c, x, y - 1, id, n, x1, y1); */
/*     if (t) */
/*         v = (v * (t << 3) + 7) % PRIMER; */

/*     t = ndil2(g, r, c, x, y + 1, id, n, x1, y1); */
/*     if (t) */
/*         v = (v * (t << 3) + 5) % PRIMER; */

/*     return v; */
/* } */

/* int ndil2t(int** g, int r, int c, int x, int y, int id, int* n, int* xs, int* ys) */
/* { */
/*     if (x < 0 || x == r || y < 0 || y == c || !g[x][y] || g[x][y] == id) */
/*         return 0; */

/*     (*n) ++; */
/*     int tn = (*n); */
/*     int v = 1; */
/*     g[x][y] = id; */

/*     int t = ndil2t(g, r, c, x + xs[0], y + ys[0], id, n, xs, ys); */
/*     if (t) */
/*         v = (v * (t << 3) + 2) % PRIMER; */

/*     t = ndil2t(g, r, c, x + xs[1], y + ys[1], id, n, xs, ys); */
/*     if (t) */
/*         v = (v * (t << 3) + 3) % PRIMER; */

/*     t = ndil2t(g, r, c, x + xs[2], y + ys[2], id, n, xs, ys); */
/*     if (t) */
/*         v = (v * (t << 3) + 7) % PRIMER; */

/*     t = ndil2t(g, r, c, x + xs[3], y + ys[3], id, n, xs, ys); */
/*     if (t) */
/*         v = (v * (t << 3) + 5) % PRIMER; */

/*     return v; */
/* } */

/* bool is_same(int** g, int r, int c, int x, int y, int id, int* xs, int* ys, int cx, int cy, int oid) */
/* { */
/*     if (x < 0 || x == r || y < 0 || y == c || !g[x][y]) */
/*         return (cx < 0 || cx == r || cy < 0 || cy == c || !g[cx][cy]); */

/*     if (cx < 0 || cx == r || cy < 0 || cy == c || !g[cx][cy]) */
/*         return (x < 0 || x == r || y < 0 || y == c || !g[x][y]); */

/*     if (g[x][y] == id) */
/*         return true; */

/*     g[x][y] = id; */

/*     if (g[cx][cy] != oid) */
/*         return false; */

/*     if (!is_same(g, r, c, x + xs[0], y + ys[0], id, xs, ys, cx - 1, cy, oid)) */
/*         return false; */

/*     if (!is_same(g, r, c, x + xs[1], y + ys[1], id, xs, ys, cx + 1, cy, oid)) */
/*         return false; */

/*     if (!is_same(g, r, c, x + xs[2], y + ys[2], id, xs, ys, cx, cy - 1, oid)) */
/*         return false; */

/*     if (!is_same(g, r, c, x + xs[3], y + ys[3], id, xs, ys, cx, cy + 1, oid)) */
/*         return false; */

/*     return true; */
/* } */

/* void reset(int** g, int r, int c, int x, int y, int id) */
/* { */
/*     if (x < 0 || x == r || y < 0 || y == c || !g[x][y] || g[x][y] == id) */
/*         return; */

/*     g[x][y] = id; */
/*     reset(g, r, c, x - 1, y, id); */
/*     reset(g, r, c, x + 1, y, id); */
/*     reset(g, r, c, x, y - 1, id); */
/*     reset(g, r, c, x, y + 1, id); */
/* } */

/* int numDistinctIslands2(int** grid, int gridRowSize, int gridColSize) */
/* { */
/*     if (!gridRowSize || !gridColSize) */
/*         return 0; */

/*     int* hash = calloc(sizeof(int), PRIMER); */
/*     int id = 2; */
/*     int num = 0; */

/*     int inc_x[] = { */
/*         -1,1, 0, 0, */
/*         0, 0, 1,-1, // 90 */
/*         1,-1, 0, 0, // 180 */
/*         0, 0,-1, 1, // 270 */

/*         -1,1, 0, 0, // reverse */
/*         0, 0,-1, 1, // reverse + 90 */
/*         1,-1, 0, 0, // reverse + 180 */
/*         0, 0, 1,-1, // reverse + 270 */
/*     }; */
/*     int inc_y[] = { */
/*         0, 0,-1, 1, */
/*         -1,1, 0, 0, */
/*         0, 0, 1,-1, */
/*         1,-1, 0, 0, */

/*         0, 0, 1,-1, */
/*         -1,1, 0, 0, */
/*         0, 0,-1, 1, */
/*         1,-1, 0, 0, */
/*     }; */

/*     for (int i = 0; i < gridRowSize; i ++) */
/*         for (int j = 0; j < gridColSize; j ++) */
/*             if (grid[i][j] == 1) */
/*             { */
/*                 int t = 0; */
/*                 int cor_x[8]; */
/*                 int cor_y[8]; */
/*                 cor_x[0] = cor_x[1] = cor_x[2] = cor_x[3] = cor_x[4] = cor_x[5] = cor_x[6] = cor_x[7] = i; */
/*                 cor_y[0] = cor_y[1] = cor_y[2] = cor_y[3] = cor_y[4] = cor_y[5] = cor_y[6] = cor_y[7] = j; */
/*                 int h = ndil2(grid, gridRowSize, gridColSize, i, j, id ++, &t, cor_x, cor_y); */
/*                 h = (h * t) % PRIMER; */
/*                 int old_hash = h; */
/*                 bool found = false; */
/*                 for (int k = 0; k < 8; k ++) */
/*                 { */
/*                     if (k != 0) */
/*                     { */
/*                         int n = 0; */
/*                         h = ndil2t(grid, gridRowSize, gridColSize, cor_x[k], cor_y[k], id ++, &n, inc_x + k * 4, inc_y + k * 4); */
/*                         h = (h * t) % PRIMER; */
/*                     } */

/*                     while (hash[h] & FMASK) */
/*                     { */
/*                         int v = hash[h] & VMASK; */
/*                         if ((v >> 16) == t) */
/*                         { */
/*                             int ox = (v >> 8) & 0xFF; */
/*                             int oy = v & 0xFF; */
/*                             int oid = grid[ox][oy]; */

/*                             if (is_same(grid, gridRowSize, gridColSize, cor_x[k], cor_y[k], id ++, inc_x + k * 4, inc_y + k * 4, ox, oy, oid)) */
/*                             { */
/*                                 found = true; */
/*                                 break; */
/*                             } */
/*                             else */
/*                             { */
/*                                 reset(grid, gridRowSize, gridColSize, cor_x[k], cor_y[k], id ++); */
/*                             } */
/*                         } */
/*                         h = (h + 1) % PRIMER; */
/*                     } */

/*                     if (found) */
/*                         break; */
/*                 } */

/*                 if (!found) */
/*                 { */
/*                     num ++; */
/*                     while (hash[old_hash] & FMASK) */
/*                         old_hash = (old_hash + 1) % PRIMER; */
/*                     hash[old_hash] = FMASK | t << 16 | i << 8 | j; */
/*                 } */
/*             } */
/*     return num; */
/* } */
