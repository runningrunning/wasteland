int countBattleships(char** board, int boardRowSize, int boardColSize)
{
    int a = 0;
    bool lin = false;

    for (int i = 0; i < boardRowSize; i ++)
    {
        lin = false;
        for (int j = 0; j < boardColSize; j ++)
        {
            if (board[i][j] == 'X')
            {
                if (!lin && !(i && (board[i - 1][j] == 'X')))
                    a ++;
                lin = true;
            }
            else
                lin = false;
        }
    }
    return a;
}
