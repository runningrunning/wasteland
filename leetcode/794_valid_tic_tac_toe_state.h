bool ttt_win(char** b, char x)
{
    if (b[1][1] == x)
    {
        if (b[0][0] == b[2][2] && b[0][0] == b[1][1])
            return true;

        if (b[0][2] == b[2][0] && b[0][2] == b[1][1])
            return true;

        if (b[0][1] == b[2][1] && b[0][1] == b[1][1])
            return true;

        if (b[1][0] == b[1][2] && b[1][0] == b[1][1])
            return true;
    }

    if (b[0][0] == x)
    {
        if (b[0][1] == b[0][2] && b[0][0] == b[0][1])
            return true;
        if (b[1][0] == b[2][0] && b[0][0] == b[1][0])
            return true;
    }

    if (b[2][2] == x)
    {
        if (b[0][2] == b[1][2] && b[0][2] == b[2][2])
            return true;
        if (b[2][0] == b[2][1] && b[2][0] == b[2][2])
            return true;
    }

    return false;
}

bool validTicTacToe(char** board, int boardSize)
{
    int xs = 0;
    int os = 0;

    for (int i = 0; i < 9; i ++)
    {
        char c = board[i / 3][i % 3];
        if (c == 'X')
            xs ++;
        else if (c == 'O')
            os ++;
    }

    if (os > xs || (xs > os + 1))
        return false;

    if (xs < 3)
        return true;

    bool ow = ttt_win(board, 'O');
    bool xw = ttt_win(board, 'X');

    if (ow)
        return !xw && (xs == os);

    return !xw || (xs == os + 1);
}
