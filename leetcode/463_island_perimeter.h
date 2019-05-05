int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
    int a = 0;
    bool uin = false;
    bool lin  = false;

    for (int i = 0; i < gridRowSize; i ++)
    {
        lin = false;
        for (int j = 0; j < gridColSize; j++)
        {
            uin = i ? grid[i - 1][j] : false;

            if (grid[i][j])
            {
                if (!uin || !lin)
                {
                    if (uin || lin)
                        a += 2;
                    else
                        a += 4;
                }
            }
            lin = grid[i][j] == 1;
        }
    }
    return a;
}
