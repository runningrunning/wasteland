// peek hint, be careful !
// math ??
// greedy also ???
// find better ways
// simple heap ???
// stupid wrong algorithm !!!
// simple union find here
// find simple implementation
int removeStones(int** stones, int stonesRowSize, int *stonesColSizes)
{
    int si = 0;
    int** st = malloc(sizeof(int*) * stonesRowSize);
    int g_x[10000] = {0};
    int g_y[10000] = {0};

    int r = 0;
    for (int i = 0; i < stonesRowSize; i ++)
    {
        int x = stones[i][0];
        int y = stones[i][1];

        if (g_x[x] != g_y[y])
        {
            int t;
            if (!g_x[x] || !g_y[y])
            {
                if (g_x[x])
                    g_y[y] = g_x[x];
                else
                    g_x[x] = g_y[y];
                t = g_x[x] - 1;

                st[t] = realloc(st[t], sizeof(int) * (st[t][0] + 2));
                st[t][st[t][0] + 1] = i;
                st[t][0] += 1;
            }
            else
            {
                r --;
                t = g_x[x] - 1;
                int ty = g_y[y] - 1;
                st[t] = realloc(st[t], sizeof(int) * (st[t][0] + st[ty][0] + 2));
                int in = st[t][0] + 1;
                for (int j = 0; j < st[ty][0]; j ++)
                {
                    int nx = st[ty][1 + j];
                    g_x[stones[nx][0]] = t + 1;
                    g_y[stones[nx][1]] = t + 1;
                    st[t][in ++] = nx;
                }

                g_y[y] = g_x[x];
                st[t][in ++] = i;
                st[t][0] = in - 1;
            }
        }
        else if (!g_x[x])
        {
            st[si] = malloc(sizeof(int) * 2);
            st[si][0] = 1;
            st[si][1] = i;
            si ++;
            r ++;
            g_x[x] = g_y[y] = si;
        }
    }
    return stonesRowSize - r;
}

/* int removeStones(int** stones, int stonesRowSize, int *stonesColSizes) */
/* { */
/*     char removed_x[10000] = {0}; */
/*     char removed_y[10000] = {0}; */

/*     int stay_x[10000] = {0}; */
/*     int stay_y[10000] = {0}; */

/*     int r = 0; */

/*     for (int i = 0; i < stonesRowSize; i ++) */
/*     { */
/*         int x = stones[i][0]; */
/*         int y = stones[i][1]; */
/*         printf("try %d %d.\n", x, y); */

/*         bool add = false; */
/*         if (removed_x[x] || removed_y[y]) */
/*         { */
/*             r ++; */
/*             printf("remove %d %d.\n", x, y); */
/*             removed_x[x] = 1; */
/*             removed_y[y] = 1; */
/*             add = true; */
/*         } */

/*         if (stay_x[x] && stay_y[y]) */
/*         { */
/*             r += 2; */
/*             int tx = (stay_x[x] - 1) >> 16; */
/*             int ty = (stay_x[x] - 1) & 0xFFFF; */
/*             stay_x[x] = add ? 0 : (x << 16 | y + 1); */
/*             stay_y[ty] = 0; */

/*             removed_x[tx] = 1; */
/*             removed_y[ty] = 1; */
/*             printf("remove %d %d.\n", tx, ty); */

/*             tx = (stay_y[y] - 1) >> 16; */
/*             ty = (stay_y[y] - 1) & 0xFFFF; */
/*             stay_x[tx] = 0; */
/*             stay_y[y] = add ? 0 : (x << 16 | y + 1); */

/*             removed_x[tx] = 1; */
/*             removed_y[ty] = 1; */
/*             printf("remove %d %d.\n", tx, ty); */
/*         } */
/*         else if (!add) */
/*         { */
/*             if (stay_x[x] || stay_y[y]) */
/*             { */
/*                 r ++; */
/*                 removed_x[x] = 1; */
/*                 removed_y[y] = 1; */
/*                 printf("remove %d %d.\n", x, y); */
/*             } */
/*             else */
/*             { */
/*                 stay_x[x] = x << 16 | y + 1; */
/*                 stay_y[y] = x << 16 | y + 1; */
/*             } */
/*         } */
/*     } */

/*     return r; */
/* } */
