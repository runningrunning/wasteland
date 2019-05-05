bool escapeGhosts(int** ghosts, int ghostsRowSize, int *ghostsColSizes, int* target, int targetSize)
{
    if (!ghosts || !ghostsRowSize)
        return true;

    int tx = target[0];
    int ty = target[1];

    int d = abs(tx - 0) + abs(ty - 0);

    for (int i = 0; i < ghostsRowSize; i ++)
    {
        int gx = ghosts[i][0];
        int gy = ghosts[i][1];
        int dx = abs(tx - gx) + abs(ty - gy);

        if (dx <= d)
            return false;
    }

    return true;
}
