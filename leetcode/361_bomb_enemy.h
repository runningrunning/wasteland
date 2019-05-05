int maxKilledEnemies(char** grid, int gridRowSize, int gridColSize)
{
    int* rs = malloc(sizeof(int) * 2 * gridColSize);
    memset(rs, 0, sizeof(int) * 2 * gridColSize);

    int* cs = malloc(sizeof(int) * 3 * gridColSize);
    int max = 0;
    for (int i = 0; i < gridRowSize; i ++)
    {
        int wsi = 0;
        int esi = gridColSize;
        int nsi = gridColSize << 1;

        int wse = wsi;
        int ese = esi;
        int nse = nsi;

        int es = 0;

        for (int j = 0; j < gridColSize; j ++)
        {
            char c = grid[i][j];
            if (c == 'W')
            {
                cs[ese ++] = es;
                cs[wse ++] = j;
                es = 0;
            }
            else if (c == 'E')
                es ++;
            else
                cs[nse ++] = j;
        }

        if (nse != nsi)
        {
            cs[ese ++] = es;
            cs[wse ++] = gridColSize;

            int x = nsi;
            while (x < nse)
            {
                int n = cs[x];

                while (n > cs[wsi])
                {
                    wsi ++;
                    esi ++;
                }

                if (i >= rs[n])
                {
                    int je = 0;
                    int is = i;

                    while (is >= 0)
                    {
                        char z = grid[is][n];
                        if (z == 'W')
                            break;
                        else if (z == 'E')
                            je ++;
                        is --;
                    }

                    is = i;
                    while (is < gridRowSize)
                    {
                        char z = grid[is][n];
                        if (z == 'W')
                            break;
                        else if (z == 'E')
                            je ++;
                        is ++;
                    }
                    rs[n] = is;
                    rs[n + gridColSize] = je;
                }

                if (max < cs[esi] + rs[n + gridColSize])
                    max = cs[esi] + rs[n + gridColSize];
                x ++;
            }
        }
    }
    return max;
}
