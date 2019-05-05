// corner case ? or typo error ?
int snakesAndLadders(int** board, int boardRowSize, int *boardColSizes)
{
    if (!board || !boardRowSize || !boardColSizes)
        return 0;

    int r = boardRowSize;
    int c = boardColSizes[0];

    int e = r * c;

    if (r == 2)
        return 1;

    char* fs = calloc(sizeof(char), r * c + 1);
    fs[1] = 1;

    int step = 0;
    int ai = 1;
    int* sa = malloc(sizeof(int) * r * c);
    sa[0] = 1;

    int bi = 0;
    int* sb = malloc(sizeof(int) * r * c);

    while (true)
    {
        step ++;

        for (int i = 0; i < ai; i ++)
        {
            int x = sa[i];

            if (x + 6 >= e)
                return step;

            for (int j = 1; j <= 6; j ++)
            {
                if (fs[x + j])
                    continue;

                fs[x + j] = 1;

                int t = x + j - 1;

                int _r = r - 1 - (t / r);
                int _c = ((t / r) & 1) ? (c - 1 - (t % r)) : (t % r);

                if (board[_r][_c] != -1)
                {
                    if (!fs[board[_r][_c]])
                    {
                        // only jump once, don't set it
                        // fs[board[_r][_c]] = 1;
                        if (board[_r][_c] == e)
                            return step;
                        sb[bi ++] = board[_r][_c];
                    }
                }
                else
                {
                    sb[bi ++] = x + j;
                }
            }
        }

        out(sb, bi);
        if (bi == 0)
            return -1;

        int* t = sa;
        sa = sb;
        sb = t;
        ai = bi;
        bi = 0;
    }

    return step;
}
