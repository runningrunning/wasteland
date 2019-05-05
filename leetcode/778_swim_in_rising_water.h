// try to use dijkstra's algorithm !!!!!
/* STUPID wrong algorithm !! */

/* void siw(int** g, int r, int x, int y, int* mx, int c) */
/* { */
/*     if (x == r - 1 && y == r - 1) */
/*     { */
/*         if (*mx > c) */
/*         { */
/*             printf("got %d.\n", c); */
/*             *mx = c; */
/*         } */
/*         return; */
/*     } */

/*     int max = g[r - 1][r - 1]; */

/*     if (g[x][y] < 0) */
/*         return; */

/*     if (*mx < g[x][y]) */
/*         return; */

/*     c = c < g[x][y] ? g[x][y] : c; */

/*     g[x][y] = - g[x][y] - 1; */

/*     /\* int i = 0; *\/ */
/*     /\* int min[4] = {0}; *\/ */
/*     /\* int min_i[4] = {0}; *\/ */

/*     if (x != r - 1 && g[x + 1][y] > 0) */
/*     { */
/*         siw(g, r, x + 1, y, mx, c); */
/*         /\* min[i] = g[x + 1][y]; *\/ */
/*         /\* min_i[i ++] = 2; *\/ */
/*     } */

/*     if (y != r - 1 && g[x][y + 1] > 0) */
/*     { */
/*         siw(g, r, x, y + 1, mx, c); */
/*         /\* min[i] = g[x][y + 1]; *\/ */
/*         /\* min_i[i ++] = 3; *\/ */
/*     } */

/*     if (x && g[x - 1][y] > 0) */
/*     { */
/*         siw(g, r, x - 1, y, mx, c); */
/*         /\* min[i] = g[x - 1][y]; *\/ */
/*         /\* min_i[i ++] = 0; *\/ */
/*     } */

/*     if (y && g[x][y - 1] > 0) */
/*     { */
/*         siw(g, r, x, y - 1, mx, c); */
/*         /\* min[i] = g[x][y - 1]; *\/ */
/*         /\* min_i[i ++] = 1; *\/ */
/*     } */

/*     /\* if (i) *\/ */
/*     /\* { *\/ */
/*     /\*     // bubble *\/ */
/*     /\*     for (int m = 0; m < i; m ++) *\/ */
/*     /\*     { *\/ */
/*     /\*         for (int n = 0; n < i - 1 - m; n ++) *\/ */
/*     /\*         { *\/ */
/*     /\*             if (min[n] > min[n + 1]) *\/ */
/*     /\*             { *\/ */
/*     /\*                 int t = min[n + 1]; *\/ */
/*     /\*                 min[n + 1] = min[n]; *\/ */
/*     /\*                 min[n] = t; *\/ */

/*     /\*                 t = min_i[n + 1]; *\/ */
/*     /\*                 min_i[n + 1] = min_i[n]; *\/ */
/*     /\*                 min_i[n] = t; *\/ */
/*     /\*             } *\/ */
/*     /\*         } *\/ */
/*     /\*     } *\/ */

/*     /\*     for (int m = 0; m < i; m ++) *\/ */
/*     /\*     { *\/ */
/*     /\*         int n = min_i[m]; *\/ */

/*     /\*         if (n == 0) *\/ */
/*     /\*             siw(g, r, x - 1, y, mx, c); *\/ */
/*     /\*         else if (n == 1) *\/ */
/*     /\*             siw(g, r, x, y - 1, mx, c); *\/ */
/*     /\*         else if (n == 2) *\/ */
/*     /\*             siw(g, r, x + 1, y, mx, c); *\/ */
/*     /\*         else *\/ */
/*     /\*             siw(g, r, x, y + 1, mx, c); *\/ */
/*     /\*     } *\/ */
/*     /\* } *\/ */
/*     g[x][y] = - (g[x][y] + 1); */
/* } */


void swi(int** g, int x, int y, int r, int m, int id, int* l)
{
    if (g[x][y] > m)
        return;

    if (g[x][y] < 0)
    {
        if (g[x][y] == -1)
            *l = -1;
    }
    else
    {
        g[x][y] = id;

        if (x)
            swi(g, x - 1, y, r, m, id, l);

        if (y)
            swi(g, x, y - 1, r, m, id, l);

        if (x != r - 1)
            swi(g, x + 1, y, r, m, id, l);

        if (y != r - 1)
            swi(g, x, y + 1, r, m, id, l);
    }
}

void populate(int** g, int x, int y, int r, int id)
{
    if (g[x][y] >= 0 || g[x][y] == id)
        return;

        g[x][y] = id;

        if (x)
            populate(g, x - 1, y, r, id);

        if (y)
            populate(g, x, y - 1, r, id);

        if (x != r - 1)
            populate(g, x + 1, y, r, id);

        if (y != r - 1)
            populate(g, x, y + 1, r, id);
}

int swimInWater(int** grid, int gridRowSize, int *gridColSizes)
{
    int max = gridRowSize * gridRowSize - 1;
    if (grid[gridRowSize - 1][gridRowSize - 1] == max)
        return max;

    int l = 0;
    int id = - 1;

    short *vs = malloc(sizeof(short) * max);
    for (int i = 0; i < gridRowSize; i ++)
        for (int j = 0; j < gridRowSize; j ++)
            vs[grid[i][j]] = i << 8 | j;

    int s = grid[0][0];
    int e = grid[gridRowSize - 1][gridRowSize - 1];
    swi(grid, 0, 0, gridRowSize, grid[0][0], id --, &l);

    if (grid[gridRowSize - 1][gridRowSize - 1] == - 1)
        return s;

    l = 0;
    swi(grid, gridRowSize - 1, gridRowSize - 1, gridRowSize, grid[gridRowSize - 1][gridRowSize - 1], id --, &l);
    if (l == -1)
        return e;

    for (int i = 0; i < max; i ++)
    {
        int x = vs[i] >> 8;
        int y = vs[i] & 0xFF;

        if (grid[x][y] < 0)
            continue;

        bool has_s = false;
        bool has_e = false;

        int min = INT_MIN;

        if (x && grid[x - 1][y] < 0)
        {
            has_s = grid[x - 1][y] == -1;
            has_e = grid[x - 1][y] == -2;

            if (min < grid[x - 1][y])
                min = grid[x - 1][y];
        }

        if (y && grid[x][y - 1] < 0)
        {
            has_s = has_s || (grid[x][y - 1] == -1);
            has_e = has_e || (grid[x][y - 1] == -2);

            if (min < grid[x][y - 1])
                min = grid[x][y - 1];
        }

        if (x != gridRowSize - 1 && grid[x + 1][y] < 0)
        {
            has_s = has_s || (grid[x + 1][y] == -1);
            has_e = has_e || (grid[x + 1][y] == -2);

            if (min < grid[x + 1][y])
                min = grid[x + 1][y];
        }

        if (y != gridRowSize - 1&& grid[x][y + 1] < 0)
        {
            has_s = has_s || (grid[x][y + 1] == -1);
            has_e = has_e || (grid[x][y + 1] == -2);

            if (min < grid[x][y + 1])
                min = grid[x][y + 1];
        }

        if (has_s && has_e)
            return i;

        grid[x][y] = id --;

        if (min < 0)
            populate(grid, x, y, gridRowSize, min);
    }
    return -1;
}
