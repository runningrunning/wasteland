// BFS
int minMutation(char* start, char* end, char** bank, int bankSize)
{
    if (bankSize == 0)
        return -1;

    if (bankSize == 1 && strcmp(bank[0], end))
        return - 1;

    int l = bankSize * bankSize;
    int* bs = calloc(sizeof(int), l);
    char* us = calloc(1, bankSize);

    int ei = -1;
    int x, y;

    for (int i = 0; i < bankSize; i ++)
    {
        char* bi = bank[i];
        int in = i * bankSize + i;

        if (!strcmp(bi, start))
        {
            x = in / 32;
            y = in % 32;
            bs[x] |= 1 << y;
        }
        else if (!strcmp(bi, end))
        {
            ei = i;
            x = in / 32;
            y = in % 32;
            bs[x] |= 1 << y;
        }

        for (int j = i + 1; j < bankSize; j ++)
        {
            char* bj = bank[j];
            int k = 0;
            for (int n = 0; n < 8; n ++)
                k += !!(bj[n] != bi[n]);

            if (k == 1)
            {
                in = i * bankSize + j;
                x = in / 32;
                y = in % 32;
                bs[x] |= 1 << y;
                in = j * bankSize + i;
                x = in / 32;
                y = in % 32;
                bs[x] |= 1 << y;
            }
        }
    }

    if (ei == -1)
        return -1;

    for (int i = 0; i < bankSize; i ++)
    {
        char* bi = bank[i];
        int k = 0;
        for (int n = 0; n < 8; n ++)
            k += !!(bi[n] != start[n]);

        if (k == 1)
            us[i] = 1;
    }

    int si = 0;
    int sn = 1;
    int* stack = malloc(sizeof(int) * (bankSize + 2));
    stack[si] = ei;
    int* level = malloc(sizeof(int) * (bankSize + 2));
    level[si] = 0;

    while (si < sn)
    {
        int ti = stack[si];
        if (us[ti])
            return level[si] + 1;

        for (int i = 0; i < bankSize; i ++)
        {
            int in = i * bankSize + i;
            x = in / 32;
            y = in % 32;

            if (bs[x] & (1 << y))
                continue;

            int tn = ti * bankSize + i;
            int tx = tn / 32;
            int ty = tn % 32;

            if (bs[tx] & (1 << ty))
            {
                stack[sn] = i;
                level[sn] = level[si] + 1;
                bs[x] |= 1 << y;
                sn ++;
            }
        }
        si ++;
    }

    return -1;
}
