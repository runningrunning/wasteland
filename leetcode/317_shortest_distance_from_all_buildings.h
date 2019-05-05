// similar with 296 best meething point
// clear mind !!!
// just brute force ??????
// find every 1 to 0 or every 0 to 1

int shortestDistance(int** grid, int gridRowSize, int gridColSize)
{
    int bn = 0;
    for (int i = 0; i < gridRowSize; i ++)
        for (int j = 0; j < gridColSize; j ++)
            if (grid[i][j] == 1)
                bn ++;

    int id = 3;
    int hi = 0;
    int* hs = malloc(sizeof(int) * gridRowSize * gridColSize);
    char* bs = calloc(sizeof(char), gridRowSize * gridColSize + 4);
    bs[1] = bs[2] = 1;

    int ai = 0;
    int* at = malloc(sizeof(int) * gridRowSize * gridColSize);
    int bi = 0;
    int* bt = malloc(sizeof(int) * gridRowSize * gridColSize);

    int max = INT_MAX;
    for (int i = 0; i < gridRowSize; i ++)
        for (int j = 0; j < gridColSize; j ++)
        {
            if (!grid[i][j] || !bs[grid[i][j]])
            {
                int r = 0;
                int step = 0;
                bool failed = false;

                hi = ai = bi = 0;
                at[ai ++] = i << 16 | j;
                grid[i][j] = id;

                while (ai)
                {
                    step ++;

                    for (int k = 0; k < ai; k ++)
                    {
                        int ax = at[k] >> 16;
                        int ay = at[k] & 0xFFFF;

                        if (ax > 0)
                        {
                            int u = grid[ax - 1][ay];
                            if (u == 1)
                            {
                                hs[hi ++] = (ax - 1) << 16 | ay;
                                r += step;
                                grid[ax - 1][ay] = -1;
                            }
                            else if ((!u || u > 2) && u != id)
                            {
                                if (bs[u])
                                {
                                    failed = true;
                                    break;
                                }
                                bt[bi ++] = (ax - 1) << 16 | ay;
                                grid[ax - 1][ay] = id;
                            }
                        }

                        if (ax < gridRowSize - 1)
                        {
                            int u = grid[ax + 1][ay];
                            if (u == 1)
                            {
                                hs[hi ++] = (ax + 1) << 16 | ay;
                                r += step;
                                grid[ax + 1][ay] = -1;
                            }
                            else if ((!u || u > 2) && u != id)
                            {
                                if (bs[u])
                                {
                                    failed = true;
                                    break;
                                }
                                bt[bi ++] = (ax + 1) << 16 | ay;
                                grid[ax + 1][ay] = id;
                            }
                        }

                        if (ay > 0)
                        {
                            int u = grid[ax][ay - 1];
                            if (u == 1)
                            {
                                hs[hi ++] = ax << 16 | ay - 1;
                                r += step;
                                grid[ax][ay - 1] = -1;
                            }
                            else if ((!u || u > 2) && u != id)
                            {
                                if (bs[u])
                                {
                                    failed = true;
                                    break;
                                }

                                bt[bi ++] =  ax << 16 | ay - 1;
                                grid[ax][ay - 1] = id;
                            }
                        }

                        if (ay < gridColSize - 1)
                        {
                            int u = grid[ax][ay + 1];
                            if (u == 1)
                            {
                                hs[hi ++] = ax << 16 | ay + 1;
                                r += step;
                                grid[ax][ay + 1] = -1;
                            }
                            else if ((!u || u > 2) && u != id)
                            {
                                if (bs[u])
                                {
                                    failed = true;
                                    break;
                                }
                                bt[bi ++] = ax << 16 | ay + 1;
                                grid[ax][ay + 1] = id;
                            }
                        }
                    }

                    if (failed)
                        break;

                    ai = bi;
                    int* t = bt;
                    bt = at;
                    at = t;
                    bi = 0;
                    // printf("bi is %d, ai is %d %d\n", bi, ai, step);
                }

                if (failed || hi < bn)
                    bs[id] = 1;
                else if (r < max)
                    max = r;

                id ++;

                for (int k = 0; k < hi; k++)
                {
                    int x = hs[k] >> 16;
                    int y = hs[k] & 0xFFFF;
                    grid[x][y] = 1;
                }
            }
        }

    return max == INT_MAX ? -1 : max;
}
