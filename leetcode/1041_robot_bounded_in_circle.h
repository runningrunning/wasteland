bool isRobotBounded(char * instructions)
{
    int temp[512] = {0};

    int cx = 512;
    int cy = 512;
    int cf = 1;

    int d[] = {-1, 0, 0, 1, 1, 0, 0, -1};

    for (int k = 0; k < 4; k ++)
    {
        int i = 0;
        int c = 0;
        int si = 128 * k;
        while (c = instructions[i])
        {
            if (c == 'G')
            {
                cx += d[(cf - 1) * 2];
                cy += d[(cf - 1) * 2 + 1];
            }
            else if (c == 'L')
                cf = 1 + (((cf - 1 - 1) + 4) % 4);
            else if (c == 'R')
                cf = 1 + (cf % 4);

            for (int j = 0; j < k; j ++)
            {
                if (temp[j * 128 + i] == (cf << 20 | cx << 10 | cy))
                    return true;
            }
            temp[si ++] = cf << 20 | cx << 10 | cy;
            i ++;
        }
    }

    return cx == 512 && cy == 512 && cf == 1;
}

