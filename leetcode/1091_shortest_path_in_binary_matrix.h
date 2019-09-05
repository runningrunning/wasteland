// BFS again
// be careful the corner case ! start & end point
// just write code
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize)
{
    int r = gridSize;
    int c = gridColSize[0];

    if (grid[0][0] || grid[r - 1][c - 1])
        return -1;

    int* sta = malloc(sizeof(int) * r * c);
    int* stb = malloc(sizeof(int) * r * c);

    int n = 2;
    int si = 0;
    int nsi = 0;
    int* st = sta;
    int* nst = stb;

    st[si ++] = 0;

    while (si)
    {
        for (int i = 0; i < si; i ++)
        {
            int x = st[i] >> 8;
            int y = st[i] & 0xFF;

            if (x)
            {
                if (y && !grid[x - 1][y - 1])
                {
                    grid[x - 1][y - 1] = n;
                    nst[nsi ++] = (x - 1) << 8 | (y - 1);
                }

                if (!grid[x - 1][y])
                {
                    grid[x - 1][y] = n;
                    nst[nsi ++] = (x - 1) << 8 | y;
                }

                if (y != c - 1 && !grid[x - 1][y + 1])
                {
                    grid[x - 1][y + 1] = n;
                    nst[nsi ++] = (x - 1) << 8 | y + 1;
                }
            }

            if (y && !grid[x][y - 1])
            {
                grid[x][y - 1] = n;
                nst[nsi ++] = x << 8 | y - 1;
            }

            if (y != c - 1 && !grid[x][y + 1])
            {
                grid[x][y + 1] = n;
                nst[nsi ++] = x << 8 | y + 1;
           }

            if (x != r - 1)
            {
                if (y && !grid[x + 1][y - 1])
                {
                    grid[x + 1][y - 1] = n;
                    nst[nsi ++] = (x + 1) << 8 | (y - 1);
                }

                if (!grid[x + 1][y])
                {
                    grid[x + 1][y] = n;
                    nst[nsi ++] = (x + 1) << 8 | y;
                }

                if (y != c - 1 && !grid[x + 1][y + 1])
                {
                    grid[x + 1][y + 1] = n;
                    nst[nsi ++] = (x + 1) << 8 | y + 1;
                }
            }
        }

        n ++;
        si = nsi;
        nsi = 0;
        st = st == sta ? stb : sta;
        nst = nst == sta ? stb : sta;
    }

    return grid[r - 1][c - 1] ? grid[r - 1][c - 1] : -1;
}
