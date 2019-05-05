void gameOfLife(int** board, int boardRowSize, int boardColSize)
{
    if (!boardRowSize || !boardColSize)
        return;

    int ** b = board;
    int r = boardRowSize;
    int c = boardColSize;

    if (r == 1 | c == 1)
    {
        if (r == 1 && c == 1)
            b[0][0] = 0;

        if (r == 1)
        {
            for (int i = 0; i < c ; i ++)
            {
                int x = 0;
                if (i != 0)
                    x += b[0][i - 1];

                if (i != c - 1)
                    x += b[0][i + 1];

                x &= 0xF;

                if (b[0][i] && x == 2)
                    b[0][i] |= 1 << 8;
            }
        }
        else
        {
            for (int i = 0; i < r ; i ++)
            {
                int x = 0;
                if (i != 0)
                    x += b[i - 1][0];

                if (i != r - 1)
                    x += b[i + 1][0];

                x &= 0xF;

                if (b[i][0] && x == 2)
                    b[i][0] |= 1 << 8;
            }
        }
    }
    else
    {

        for (int i = 0; i < r; i ++)
        {
            for (int j = 0; j < c; j ++)
            {
                int x = 0;
                if (i != 0 && i != r - 1 && j != 0 && j != c -1)
                {
                    x += b[i - 1][j - 1];
                    x += b[i - 1][j];
                    x += b[i - 1][j + 1];
                    x += b[i][j - 1];
                    x += b[i][j + 1];
                    x += b[i + 1][j - 1];
                    x += b[i + 1][j];
                    x += b[i + 1][j + 1];
                }
                else
                {
                    if (i == 0)
                    {
                        if (j == 0)
                        {
                            x += b[i][j + 1];
                            x += b[i + 1][j];
                            x += b[i + 1][j + 1];
                        }
                        else if (j == c - 1)
                        {
                            x += b[i][j - 1];
                            x += b[i + 1][j - 1];
                            x += b[i + 1][j];
                        }
                        else
                        {
                            x += b[i][j - 1];
                            x += b[i][j + 1];
                            x += b[i + 1][j - 1];
                            x += b[i + 1][j];
                            x += b[i + 1][j + 1];
                        }
                    }
                    else if (i == r - 1)
                    {
                        if (j == 0)
                        {
                            x += b[i - 1][j];
                            x += b[i - 1][j + 1];
                            x += b[i][j + 1];
                        }
                        else if (j == c - 1)
                        {
                            x += b[i - 1][j - 1];
                            x += b[i - 1][j];
                            x += b[i][j - 1];
                        }
                        else
                        {
                            x += b[i - 1][j - 1];
                            x += b[i - 1][j];
                            x += b[i - 1][j + 1];
                            x += b[i][j - 1];
                            x += b[i][j + 1];
                        }
                    }
                    else
                    {
                        if (j == 0)
                        {
                            x += b[i - 1][j];
                            x += b[i - 1][j + 1];
                            x += b[i][j + 1];
                            x += b[i + 1][j];
                            x += b[i + 1][j + 1];
                        }
                        else
                        {
                            x += b[i - 1][j - 1];
                            x += b[i - 1][j];
                            x += b[i][j - 1];
                            x += b[i + 1][j - 1];
                            x += b[i + 1][j];
                        }
                    }
                }

                x &= 0xF;
                if (x == 3 || (b[i][j] && x == 2))
                    b[i][j] |= 1 << 8;
            }
        }
    }

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
            b[i][j] >>= 8;
    return;
}
