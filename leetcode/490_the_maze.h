// optimize, don't clean the bits, as it can not arriave destination !
// water flood?
bool can(int** m, int r, int c, int sx, int sy, int dx, int dy, char* bits)
{
    if (sx == dx && sy == dy)
        return true;

    int bs = sx * c + sy;

    if (bits[bs])
        return false;

    bits[bs] = 1;

    int tx = sx;
    int ty = sy;

    // up
    while (tx && !m[tx - 1][ty])
        tx --;

    if (can(m, r, c, tx, ty, dx, dy, bits))
        return true;

    tx = sx; ty = sy;
    // down
    while (tx != r - 1 && !m[tx + 1][ty])
        tx ++;

    if (can(m, r, c, tx, ty, dx, dy, bits))
        return true;

    tx = sx; ty = sy;
    // left
    while (ty && !m[tx][ty - 1])
        ty --;

    if (can(m, r, c, tx, ty, dx, dy, bits))
        return true;

    tx = sx; ty = sy;
    // right
    while (ty != c - 1 && !m[tx][ty + 1])
        ty ++;

    if (can(m, r, c, tx, ty, dx, dy, bits))
        return true;

    // bits[bs] = 0; no need to clean the flags
    return false;
}

bool hasPath(int** maze, int mazeRowSize, int mazeColSize, int* start, int startSize, int* destination, int destinationSize)
{
    char* bits = calloc(sizeof(char), mazeRowSize * mazeColSize);
    return can(maze, mazeRowSize, mazeColSize, start[0], start[1], destination[0], destination[1], bits);
}
