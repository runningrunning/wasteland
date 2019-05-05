int numRookCaptures(char** board, int boardRowSize, int boardColSize)
{
    if (!board || !boardRowSize || !boardColSize)
        return 0;
    int x = 0;
    int y = 0;

    if (board[x][y] != 'R')
        for (int i = 0; i < boardRowSize; i ++)
        {
            for (int j = 0; j < boardColSize; j ++)
            {
                if (board[i][j] == 'R')
                {
                    x = i;
                    y = j;
                    break;
                }
            }
            if (x || y)
                break;
        }

    int n = 0;
    int _x, _y;
    if (x != 0)
    {
        _x = x - 1;
        while (_x >= 0 && board[_x][y] == '.')
            _x --;

        if (_x >= 0 && board[_x][y] == 'p')
            n ++;
    }

    if (y != 0)
    {
        _y = y - 1;
        while (_y >= 0 && board[x][_y] == '.')
            _y --;
        if (_y >= 0 &&  board[x][_y] == 'p')
            n ++;
    }

    if (x != boardRowSize - 1)
    {
        _x = x + 1;
        while (_x < boardRowSize && board[_x][y] == '.')
            _x ++;
        if (_x < boardRowSize && board[_x][y] == 'p')
            n ++;
    }

    if (y != boardColSize - 1)
    {
        _y = y + 1;
        while (_y < boardColSize && board[x][_y] == '.')
            _y ++;
        if (_y < boardColSize && board[x][_y] == 'p')
            n ++;
    }

    return n;
}
