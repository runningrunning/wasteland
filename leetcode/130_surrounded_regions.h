void sr(char** b, int r, int c, int x, int y)
{
    if (b[x][y] == 'O')
    {
        b[x][y] = 'o';

        if (x)
            sr(b, r, c, x - 1, y);

        if (x != r - 1)
            sr(b, r, c, x + 1, y);

        if (y)
            sr(b, r, c, x, y - 1);

        if (y != c - 1)
            sr(b, r, c, x, y + 1);
    }
}

void solve(char** b, int boardRowSize, int boardColSize)
{
    if (boardRowSize <= 2 || boardColSize <= 2)
        return;

    for (int i = 0; i < boardColSize; i ++)
    {
        if (b[0][i] == 'O')
            sr(b, boardRowSize, boardColSize, 0, i);

        if (b[boardRowSize - 1][i] == 'O')
            sr(b, boardRowSize, boardColSize, boardRowSize - 1, i);
    }

    for (int i = 1; i < boardRowSize - 1; i ++)
    {
        if (b[i][0] == 'O')
            sr(b, boardRowSize, boardColSize, i, 0);

        if (b[i][boardColSize - 1] == 'O')
            sr(b, boardRowSize, boardColSize, i, boardColSize - 1);
    }

    for (int i = 0; i < boardRowSize; i ++)
        for (int j = 0; j < boardColSize; j ++)
        {
            if (b[i][j] == 'o')
                b[i][j] = 'O';
            else if (b[i][j] == 'O')
                b[i][j] = 'X';
        }

    return;
}
