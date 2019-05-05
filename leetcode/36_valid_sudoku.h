bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
    for(int n = 0; n < 9; n++)
    {
        int m1[12] = {0};
        int m2[12] = {0};
        int m3[12] = {0};
        int bi = (n/3) * 3;
        int bj = (n%3) * 3;
        for(int i = 0; i < 9; i ++)
        {
            int d1 = board[n][i] - '.';
            if (d1 && m1[d1])
                return false;
            m1[d1] = 1;
            int d2 = board[i][n] - '.';
            if (d2 && m2[d2])
                return false;
            m2[d2] = 1;
            int d3 = board[(i/3)+bi][(i%3)+bj] - '.';
            if (d3 && m3[d3])
                return false;
            m3[d3] = 1;
        }
    }
    return true;
}
