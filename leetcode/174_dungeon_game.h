// BFS with caches ???
// JUST BE careful about the code !
// not the minimal step, but minimal health
int chp(int** d, int h, int x, int y, int r, int c)
{
    int r_need = d[x][y + 1];
    int d_need = d[x + 1][y];
    int need = (r_need < d_need ? r_need : d_need) - h;
    return need <= 0 ? 1 : need;
}

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int *dungeonColSizes)
{
    if (!dungeon || !dungeonRowSize || !(dungeonColSizes[0]))
        return 0;

    int r = dungeonRowSize;
    int c = dungeonColSizes[0];

    r -= 1;
    c -= 1;

    int rl = r;
    int cl = c;


    while ((r >= 0 && c >= 0))
    {
        int i = r >= 0 ? r : 0;
        int j = c >= 0 ? c : 0;

        if (i == rl && j == cl)
        {
            int x = 1 - dungeon[i][j];
            dungeon[i][j] = x <= 0 ? 1 : x;
        }
        else
            dungeon[i][j] = chp(dungeon, dungeon[i][j], i, j, rl, cl);


        if (j == cl)
        {
            for (int n = i - 1; n >= 0; n --)
            {
                int x = dungeon[n + 1][j] - dungeon[n][j];
                dungeon[n][j] = x <= 0 ? 1 : x;
            }
        }
        else
        {
            for (int n = i - 1; n >= 0; n --)
                dungeon[n][j] = chp(dungeon, dungeon[n][j], n, j, rl, cl);
        }

        if (i == rl)
        {
            for (int n = j - 1; n >= 0; n --)
            {
                int x = dungeon[i][n + 1] - dungeon[i][n];
                dungeon[i][n] = x <= 0 ? 1 : x;
            }
        }
        else
        {
            for (int n = j - 1; n >= 0; n --)
                dungeon[i][n] = chp(dungeon, dungeon[i][n], i, n, rl, cl);
        }

        r --;
        c --;
    }

    return dungeon[0][0];
}
