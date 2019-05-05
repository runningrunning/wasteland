// still BFS, but not the water flood for 490 the maze
// use heap to optimize ?
int rHeap(int* h, int hi)
{
    int t = h[0];
    h[0] = h[-- hi];

    int v = h[0];
    int x = 0;

    while (x * 2 + 1 < hi)
    {
        int l = h[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < hi)
            r = h[x * 2 + 2];

        if (l <= r)
        {
            if (v <= l)
                break;

            h[x * 2 + 1] = v;
            h[x] = l;
            x = x * 2 + 1;
        }
        else
        {
            if (v <= r)
                break;

            h[x * 2 + 2] = v;
            h[x] = r;
            x = x * 2 + 2;
        }
    }
    return t;
}

void aHeap(int* h, int hi, int v)
{
    h[hi ++] = v;

    int x = hi - 1;

    while (x)
    {
        int p = (x - 1) / 2;

        if (h[p] <= v)
            break;

        h[x] = h[p];
        h[p] = v;
        x = p;
    }
}

int shortestDistance(int** maze, int mazeRowSize, int mazeColSize, int* start, int startSize, int* destination, int destinationSize)
{
    if (!maze || !mazeRowSize || !mazeColSize)
        return -1;

    char* bits = calloc(sizeof(char), mazeRowSize * mazeColSize);
    int* heap = malloc(sizeof(int) * mazeRowSize * mazeColSize);

    int hi = 0;
    heap[hi ++] = 0 << 16 | start[0] << 8 | start[1];

    while (hi)
    {
        int top = rHeap(heap, hi --);
        int n = top >> 16;
        int x = (top >> 8) & 0xFF;
        int y = top & 0xFF;

        if (x == destination[0] && y == destination[1])
            return n;

        int nn, nx, ny;

        // up
        if (x && !maze[x - 1][y])
        {
            nn = n;
            nx = x;
            ny = y;

            while (nx - 1 >= 0 && !maze[nx - 1][ny])
            {
                nn ++;
                nx --;
            }

            if (!bits[nx * mazeColSize + ny] || bits[nx * mazeColSize + ny] > nn)
            {
                bits[nx * mazeColSize + ny] = nn;
                aHeap(heap, hi ++, nn << 16 | nx << 8 | ny);
            }
        }

        // left
        if (y && !maze[x][y - 1])
        {
            nn = n;
            nx = x;
            ny = y;

            while (ny - 1 >= 0 && !maze[nx][ny - 1])
            {
                nn ++;
                ny --;
            }

            if (!bits[nx * mazeColSize + ny] || bits[nx * mazeColSize + ny] > nn)
            {
                bits[nx * mazeColSize + ny] = nn;
                aHeap(heap, hi ++, nn << 16 | nx << 8 | ny);
            }
        }

        // down
        if (x != mazeRowSize - 1 && !maze[x + 1][y])
        {
            nn = n;
            nx = x;
            ny = y;

            while (nx + 1 < mazeRowSize && !maze[nx + 1][ny])
            {
                nn ++;
                nx ++;
            }

            if (!bits[nx * mazeColSize + ny] || bits[nx * mazeColSize + ny] > nn)
            {
                bits[nx * mazeColSize + ny] = nn;
                aHeap(heap, hi ++, nn << 16 | nx << 8 | ny);
            }
        }

        // right
        if (y != mazeColSize - 1 && !maze[x][y + 1])
        {
            nn = n;
            nx = x;
            ny = y;

            while (ny + 1 < mazeColSize && !maze[nx][ny + 1])
            {
                nn ++;
                ny ++;
            }

            if (!bits[nx * mazeColSize + ny] || bits[nx * mazeColSize + ny] > nn)
            {
                bits[nx * mazeColSize + ny] = nn;
                aHeap(heap, hi ++, nn << 16 | nx << 8 | ny);
            }
        }
    }
    return -1;
}
