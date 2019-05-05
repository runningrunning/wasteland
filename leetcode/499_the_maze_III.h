// similar with 505 the maze II
// hole could in the middle of moving
// how to define the moving and how to remember the steps
// how to write correct code !!!!!!

// corner cases ???, when it's arrive same point, it must check which path is smaller !!!!!!!!

long rHeap(long* h, int hi)
{
    long t = h[0];
    h[0] = h[-- hi];

    long v = h[0];
    int x = 0;

    while (x * 2 + 1 < hi)
    {
        long l = h[x * 2 + 1];
        long r = l;

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

void aHeap(long* h, int hi, long v)
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

char* findShortestWay(int** maze, int mazeRowSize, int *mazeColSizes, int* ball, int ballSize, int* hole, int holeSize)
{
    if (!maze || !mazeRowSize || !mazeColSizes || !mazeColSizes[0] || !ball || !ballSize || !hole || !holeSize)
        return strdup("impossible");

    int r = mazeRowSize;
    int c = mazeColSizes[0];

    int* bits = calloc(sizeof(int), r * c);
    long* heap = malloc(sizeof(long) * r * c);

    int bx = ball[0];
    int by = ball[1];

    int hx = hole[0];
    int hy = hole[1];

    long mi = 0;
    int ms = 2048;
    int* m = malloc(sizeof(int) * 2048);
    m[mi ++] = 0;

    int ri = 0;
    int* ret = NULL;

    int hi = 0;
    heap[hi ++] = 0 << 16 | bx << 8 | by;

    int min = 2048;

    while (hi)
    {
        long top = rHeap(heap, hi --);
        long id = (top >> 16) & 0x7FFFFFFF;
        long n = (top >> 48) & 0xFFFF;
        long x = (top >> 8) & 0xFF;
        long y = (top) & 0xFF;

        int hitn = 0;
        int hit = -1;

        if (n > min)
            break;

        long nn, nx, ny;

        if (mi + 4 >= ms)
        {
            m = realloc(m, sizeof(int) * (ms + 1024));
            ms += 1024;
        }

        bool found = false;

        // up
        if (x && !maze[x - 1][y])
        {
            nn = n;
            nx = x;
            ny = y;

            found = false;

            while (nx && !maze[nx - 1][ny])
            {
                nn ++;
                nx --;

                if (nx == hx && ny == hy)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                found = false;
                hitn = nn;
                hit = id << 8 | 'u';
            }
            else if (!bits[nx * c + ny] || bits[nx * c + ny] >= nn)
            {
                bits[nx * c + ny] = nn;
                top = nn << 48 | mi << 16 | nx << 8 | ny;
                m[mi ++] = id << 8 | 'u';
                aHeap(heap, hi ++, top);
            }
        }

        // left
        if (y && !maze[x][y - 1])
        {
            nn = n;
            nx = x;
            ny = y;

            while (ny && !maze[nx][ny - 1])
            {
                nn ++;
                ny --;

                if (nx == hx && ny == hy)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                found = false;
                hitn = nn;
                hit = id << 8 | 'l';
            }
            else if (!bits[nx * c + ny] || bits[nx * c + ny] >= nn)
            {
                bits[nx * c + ny] = nn;
                top = nn << 48 | mi << 16 | nx << 8 | ny;
                m[mi ++] = id << 8 | 'l';
                aHeap(heap, hi ++, top);
            }
        }

        // down
        if (x != r - 1 && !maze[x + 1][y])
        {
            nn = n;
            nx = x;
            ny = y;

            while (nx != r - 1 && !maze[nx + 1][ny])
            {
                nn ++;
                nx ++;

                if (nx == hx && ny == hy)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                found = false;
                hitn = nn;
                hit = id << 8 | 'd';
            }
            else if (!bits[nx * c + ny] || bits[nx * c + ny] >= nn)
            {
                bits[nx * c + ny] = nn;
                top = nn << 48 | mi << 16 | nx << 8 | ny;
                m[mi ++] = id << 8 | 'd';
                aHeap(heap, hi ++, top);
            }
        }

        // right
        if (y != c - 1 && !maze[x][y + 1])
        {
            nn = n;
            nx = x;
            ny = y;

            while (ny != c - 1 && !maze[nx][ny + 1])
            {
                nn ++;
                ny ++;

                if (nx == hx && ny == hy)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                found = false;
                hitn = nn;
                hit = id << 8 | 'r';
            }
            else if (!bits[nx * c + ny] || bits[nx * c + ny] >= nn)
            {
                bits[nx * c + ny] = nn;
                top = nn << 48 | mi << 16 | nx << 8 | ny;
                m[mi ++] = id << 8 | 'r';
                aHeap(heap, hi ++, top);
            }
        }

        if (hit != -1 && hitn <= min)
        {
            if (hitn == min)
            {
                ret = realloc(ret, sizeof(int) * (ri + 1));
                ret[ri ++] = hit;
            }
            else
            {
                ret = realloc(ret, sizeof(int));
                ret[0] = hit;
                ri = 1;
            }

            min = hitn;
        }
    }

    if (min == 2048)
        return strdup("impossible");

    // printf("ri is %d\n", ri);

    char* p = NULL;

    for (int i = 0; i < ri; i ++)
    {
        int bi = 0;
        int id = ret[i];

        while (id)
        {
            bits[bi ++] = id & 0xFF;
            id = m[id >> 8];
        }

        char* t = malloc(sizeof(char) * (bi + 1));
        t[bi --] = 0;

        int si = 0;
        for (; bi >= 0; bi --)
            t[si ++] = bits[bi];

        // printf("%s .\n", t);

        if (!p || strcmp(t, p) < 0)
        {
            free(p);
            p = t;
        }
    }

    return p;
}

