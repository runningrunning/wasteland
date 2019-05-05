// just brute force ?
// how to write code !
// too complicated !
// how to represent ?
// do it twice !
// check no virus !

void _mark(int** g, int x, int y, int r, int c, long* hws, long* vws, int id, int* num, int* mark, int oid)
{
    if (x < 0 || x >= r || y < 0 || y >= c || g[x][y] == id)
        return;

    if (oid != INT_MIN && g[x][y] != oid)
        return;

    g[x][y] = id;

    if (x)
    {
        if (!(vws[y] & (1L << (x - 1))))
        {
            if (g[x - 1][y] <= 0)
            {
                if (g[x - 1][y] != - id)
                {
                    g[x - 1][y] = - id;
                    if (mark)
                        mark[*num] = (x - 1) << 8 | y;
                    (*num) ++;
                }
            }
            else
            {
                _mark(g, x - 1, y, r, c, hws, vws, id, num, mark, oid);
            }
        }
    }


    if (x < r - 1)
    {
        if (!(vws[y] & (1L << x)))
        {
            if (g[x + 1][y] <= 0)
            {
                if (g[x + 1][y] != - id)
                {
                    g[x + 1][y] = - id;
                    if (mark)
                        mark[*num] = (x + 1) << 8 | y;
                    (*num) ++;
                }
            }
            else
            {
                _mark(g, x + 1, y, r, c, hws, vws, id, num, mark, oid);
            }
        }
    }

    if (y)
    {
        if (!(hws[x] & (1L << (y - 1))))
        {
            if (g[x][y - 1] <= 0)
            {
                if (g[x][y - 1] != - id)
                {
                    g[x][y - 1] = - id;
                    if (mark)
                        mark[*num] = x << 8 | (y - 1);
                    (*num) ++;
                }
            }
            else
            {
                _mark(g, x, y - 1, r, c, hws, vws, id, num, mark, oid);
            }
        }
    }

    if (y < c - 1)
    {
        if (!(hws[x] & (1L << y)))
        {
            if (g[x][y + 1] <= 0)
            {
                if (g[x][y + 1] != - id)
                {
                    g[x][y + 1] = - id;
                    if (mark)
                        mark[*num] = x << 8 | (y + 1);
                    (*num) ++;
                }
            }
            else
                _mark(g, x, y + 1, r, c, hws, vws, id, num, mark, oid);
        }
    }
}

void _wall(int** g, int x, int y, int r, int c, long* hws, long* vws, int id, int* num)
{
    if (x < 0 || x >= r || y < 0 || y >= c || g[x][y] == id)
        return;

    g[x][y] = id;

    if (x)
    {
        if (!(vws[y] & (1L << (x - 1))))
        {
            if (g[x - 1][y] <= 0)
            {
                vws[y] |= 1L << (x - 1);
                (*num) ++;
            }
            else
                _wall(g, x - 1, y, r, c, hws, vws, id, num);
        }
    }


    if (x < r - 1)
    {
        if (!(vws[y] & (1L << x)))
        {
            if (g[x + 1][y] <= 0)
            {
                vws[y] |= 1L << x;
                (*num) ++;
            }
            else
                _wall(g, x + 1, y, r, c, hws, vws, id, num);
        }
    }

    if (y)
    {
        if (!(hws[x] & (1L << (y - 1))))
        {
            if (g[x][y - 1] <= 0)
            {
                hws[x] |= 1L << (y - 1);
                (*num) ++;
            }
            else
                _wall(g, x, y - 1, r, c, hws, vws, id, num);
        }
    }

    if (y < c - 1)
    {
        if (!(hws[x] & (1L << y)))
        {
            if (g[x][y + 1] <= 0)
            {
                hws[x] |= 1L << y;
                (*num) ++;
            }
            else
                _wall(g, x, y + 1, r, c, hws, vws, id, num);
        }
    }
}

void _extend(int** g, int x, int y, int r, int c, long* hws, long* vws, int oid, int id, int* mark)
{
    int mi = 0;
    _mark(g, x, y, r, c, hws, vws, id, &mi, mark, oid);
    for (int i = 0; i < mi; i ++)
    {
        x = mark[i] >> 8;
        y = mark[i] & 0xFF;
        g[x][y] = id;
    }
}

int containVirus(int** grid, int gridRowSize, int gridColSize)
{
    int ws = 0;
    long* hws = calloc(sizeof(long), gridRowSize);
    long* vws = calloc(sizeof(long), gridColSize);
    char* ids = calloc(sizeof(char), gridRowSize * gridColSize);

    int ai = 0;
    int* all = malloc(sizeof(int) * gridRowSize * gridColSize);
    int* mark = malloc(sizeof(int) * gridRowSize * gridColSize);

    int max_a = 0;
    int max_x = 0;
    int max_y = 0;
    int max_num = INT_MIN;
    int id = 2;

    while (true)
    {
        max_num = INT_MIN;

        if (ai == 0)
        {
            for (int i = 0; i < gridRowSize; i ++)
                for (int j = 0; j < gridColSize; j ++)
                    if (grid[i][j] == 1)
                    {
                        int num = 0;
                        // mark zero as -ID
                        _mark(grid, i, j, gridRowSize, gridColSize, hws, vws, id, &num, 0, INT_MIN);
                        if (num > max_num)
                        {
                            max_num = num;
                            max_x = i;
                            max_y = j;
                            max_a = ai;
                        }

                        all[ai ++] = id << 16 | i << 8 | j;
                        id ++;
                    }

        }
        else
        {
            for (int i = 0; i < ai; i ++)
            {
                int x = (all[i] >> 8) & 0xFF;
                int y = all[i] & 0xFF;
                int oid = all[i] >> 16;

                if (grid[x][y] != oid || ids[oid - 1])
                {
                    ids[oid - 1] = 1;
                    all[i] = all[ai - 1];
                    i --;
                    ai --;
                    continue;
                }

                int num = 0;
                _mark(grid, x, y, gridRowSize, gridColSize, hws, vws, id, &num, 0, INT_MIN);
                if (num > max_num)
                {
                    max_num = num;
                    max_x = x;
                    max_y = y;
                    max_a = i;
                }
                // update id
                all[i] = id << 16 | x << 8 | y;
                id ++;
            }
        }

        // printf("max_num is %d %d.\n", max_num, ai);

        if (max_num == INT_MIN)
            break;

        ids[id - 1] = 1;
        _wall(grid, max_x, max_y, gridRowSize, gridColSize, hws, vws, id, &ws);
        id ++;
        all[max_a] = all[ai - 1];
        ai --;

        // outaaa(grid, gridColSize, gridRowSize);

        // outa(ids, gridRowSize * gridColSize);
        for (int i = 0; i < ai; i ++)
        {
            int x = (all[i] >> 8) & 0xFF;
            int y = all[i] & 0xFF;
            int oid = all[i] >> 16;

            if (grid[x][y] != oid || ids[oid - 1])
            {
                // printf("=== %d %d is %d should %d %d.\n", x, y, oid, grid[x][y], ids[oid - 1]);
                ids[oid - 1] = 1;
                all[i] = all[ai - 1];
                i --;
                ai --;
                continue;
            }
            _extend(grid, x, y, gridRowSize, gridColSize, hws, vws, oid, id, mark);
            // update id
            all[i] = id << 16 | x << 8 | y;
            id ++;
        }

        // printf("ws is %d ai %d.\n", ws, ai);
        // outaaa(grid, gridColSize, gridRowSize);

        if (!ai)
            break;
    }

    return ws;
}
