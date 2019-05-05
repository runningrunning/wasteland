// too much corner cases !!!!!!!!!!!!!!!!!!!!!
int movesToChessboard(int** board, int boardRowSize, int *boardColSizes)
{
    int ri = 1;
    int rn[2] = {1, 0};
    int rs[2] = {0};

    int ra[31] = {0};
    int c = boardColSizes[0];
    for (int i = 1; i < boardRowSize; i ++)
    {
        if (!memcmp(board[0], board[i], sizeof(int) * c))
        {
            ra[i] = 0;
            rn[0] ++;
        }
        else
        {
            if (ri == 1)
                rs[ri ++] = i;
            else
                if (memcmp(board[i], board[rs[1]], sizeof(int) * c))
                    return -1;
            ra[i] = rs[1];
            rn[1] ++;
        }
    }

    if ((boardRowSize & 1) ? (abs(rn[0] - rn[1]) != 1) : (rn[0] != rn[1]))
        return -1;
    for (int i = 0; i < c; i ++)
        if (board[0][i] == board[rs[1]][i])
            return -1;

    int ks = 0;
    int num = 0;
    for (int i = 0; i < boardRowSize; i += 2)
        if (!ra[i]) ks ++;

    if (boardRowSize & 1)
    {
        if (rn[0] > rn[1])
            num = ((boardRowSize / 2) + 1) - ks;
        else
            num = ks;
    }
    else
        num = (boardRowSize / 2 - ks) > ks ? ks : (boardRowSize / 2 - ks);

    ks = 0;

    int al = 0;
    for (int i = 0; i < c; i ++)
    {
        al += board[0][i];
        if (!(i & 1) && !board[0][i]) ks ++;
    }

    // must check whether it's equal size
    if ((boardRowSize & 1) ? (abs(boardRowSize - 2 * al) != 1) : (boardRowSize != 2 * al))
        return -1;

    if (boardRowSize & 1)
    {
        if (boardRowSize - al > al)
            num += ((boardRowSize / 2) + 1) - ks;
        else
            num += ks;
    }
    else
    {
        num += (boardRowSize / 2 - ks) > ks ? ks : (boardRowSize / 2  - ks);
    }

    return num;
}
