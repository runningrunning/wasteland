void wag(int** g, int r, int c, int x, int y, int id)
{
    if (x < 0 || y < 0 || x >= r || y >= c || g[x][y] < id)
        return;

    g[x][y] = id;

    wag(g, r, c, x - 1, y, id + 1);
    wag(g, r, c, x + 1, y, id + 1);
    wag(g, r, c, x, y - 1, id + 1);
    wag(g, r, c, x, y + 1, id + 1);
}

void wallsAndGates(int** rooms, int roomsRowSize, int roomsColSize)
{
    if (!roomsRowSize || !roomsColSize)
        return;
    for (int i = 0; i < roomsRowSize; i ++)
        for (int j = 0; j < roomsColSize; j ++)
            if (!rooms[i][j])
            {
                wag(rooms, roomsRowSize, roomsColSize, i - 1, j, 1);
                wag(rooms, roomsRowSize, roomsColSize, i + 1, j, 1);
                wag(rooms, roomsRowSize, roomsColSize, i, j - 1, 1);
                wag(rooms, roomsRowSize, roomsColSize, i, j + 1, 1);
            }
}
