// how to represent the data structure !
// be careful about the AXIS USED !!! NORTH is +y !!!
// check the maximum distance !
#define OFFSET 30001
int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesRowSize, int *obstaclesColSizes)
{
    int* rs = calloc(sizeof(int), 2048);
    int* cs = calloc(sizeof(int), 2048);

    int dp = 32771;
    int pri[] = {1031, 2053, 4099, 8209, 16411, 32771};

    for (int i = 0; i < sizeof(pri)/sizeof(pri[0]); i ++)
        if (pri[i] > 2 * obstaclesRowSize)
        {
            dp = pri[i];
            break;
        }

    short* hash = calloc(sizeof(short), dp);
    for (int i = 0; i < obstaclesRowSize; i ++)
    {
        int x = obstacles[i][0] + OFFSET;
        int y = obstacles[i][1] + OFFSET;

        rs[x / 32] |= 1 << (x % 32);
        cs[y / 32] |= 1 << (y % 32);

        int k = (x << 16 | y) % dp;
        if (k < 0)
            k += dp;

        while (hash[k])
        {
            x = hash[k] - 1;
            if (obstacles[x][0] == obstacles[i][0] && obstacles[x][1] == obstacles[i][1])
                break;
            k = (k + 1) % dp;
        }

        if (!hash[k])
            hash[k] = i + 1;
    }

    int x = 0;
    int y = 0;
    int d = 0; // 0 UP, 1 RIGHT, 2 DOWN, 3 LEFT

    int r = 0;

    for (int i = 0; i < commandsSize; i ++)
    {
        int c = commands[i];
        if (c >= 1)
        {
            int check = 0;

            int cx = x + OFFSET;
            int cy = y + OFFSET;

            if (d == 0 || d == 2)
                check = rs[cx / 32] & (1 << (cx % 32));
            else
                check = cs[cy / 32] & (1 << (cy % 32));

            if (check)
            {
                int nx = cx;
                int ny = cy;

                while (c)
                {
                    if (d == 0)
                        ny += 1;
                    else if (d == 1)
                        nx += 1;
                    else if (d == 2)
                        ny -= 1;
                    else
                        nx -= 1;

                    int ck = (nx << 16 | ny) % dp;
                    if (ck < 0)
                        ck += dp;

                    bool found = false;

                    while (hash[ck])
                    {
                        int t = hash[ck] - 1;
                        if (obstacles[t][0] == nx - OFFSET && obstacles[t][1] == ny - OFFSET)
                        {
                            found = true;
                            break;
                        }

                        ck = (ck + 1) % dp;
                    }

                    if (found)
                        break;

                    x = nx - OFFSET;
                    y = ny - OFFSET;

                    c --;
                }
            }
            else
            {
                if (d == 0)
                    y += c;
                else if (d == 1)
                    x += c;
                else if (d == 2)
                    y -= c;
                else
                    x -= c;
            }

            printf("x %d y %d.\n", x, y);
            int ed = x * x + y * y;

            if (ed > r)
                r = ed;
        }
        else
        {
            d += c == -1 ? 1 : 3;
            d %= 4;
        }
    }

    return r;
}
