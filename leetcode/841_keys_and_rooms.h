bool canVisitAllRooms(int** rooms, int roomsRowSize, int *roomsColSizes)
{
    if (roomsRowSize < 2)
        return 1;
    int es = 0;
    int si = 0;
    int* stack = malloc(sizeof(int) * (roomsRowSize + 1));
    char* f = malloc(roomsRowSize + 1);
    bzero(f, roomsRowSize + 1);
    f[0] = 1;

    es ++;
    stack[si ++] = 0;

    while (si --)
    {
        int x = stack[si];
        int* z = rooms[x];

        if (z && roomsColSizes[x])
        {
            for (int i = 0; i < roomsColSizes[x]; i ++)
            {
                if (z[i] < roomsRowSize && !f[z[i]])
                {
                    f[z[i]] = 1;
                    es ++;
                    stack[si ++] = z[i];
                }
            }
        }
    }
    return es == roomsRowSize;
}
