/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


class Solution {
public:

    void _ub(vector<vector<char>>& b, int r, int c, int x, int y, char* f)
    {
        if (x < 0 || y < 0 || x >= r || y >= c || b[x][y] != 'E' || f[x * c + y])
            return;

        f[x * c + y] = 1;

        int n = 0;
        int d[] = {-1, 0, 1};

        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j ++)
            {
                int dx = x + d[i];
                int dy = y + d[j];
                if (dx >= 0 && dy >= 0 && dx < r && dy < c)
                    n += b[dx][dy] == 'M' ? 1 : 0;
            }

        if (n)
            b[x][y] = '0' + n;
        else
        {
            b[x][y] = 'B';
            for (int i = 0; i < 3; i ++)
                for (int j = 0; j < 3; j ++)
                {
                    int dx = x + d[i];
                    int dy = y + d[j];
                    ub(b, r, c, dx, dy, f);
                }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];

        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        int r = board.size();
        int c = board[0].size();

        char* bf = (char*) calloc(sizeof(char), r * c);
        _ub(board, r, c, x, y, bf);
        return board;
    }
};


/*
void ub(char** b, int r, int c, int x, int y, char* f)
{
    if (x < 0 || y < 0 || x >= r || y >= c || b[x][y] != 'E' || f[x * c + y])
        return;

    f[x * c + y] = 1;
    int n = 0;

    int d[] = {-1, 0, 1};

    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
        {
            int dx = x + d[i];
            int dy = y + d[j];

            if (dx >= 0 && dy >= 0 && dx < r && dy < c)
                n += b[dx][dy] == 'M' ? 1 : 0;
        }

    if (n)
        b[x][y] = '0' + n;
    else
    {
        b[x][y] = 'B';
        for (int i = 0; i < 3; i ++)
            for (int j = 0; j < 3; j ++)
            {
                int dx = x + d[i];
                int dy = y + d[j];
                ub(b, r, c, dx, dy, f);
            }
    }
}

char** updateBoard(char** board, int boardRowSize, int boardColSize, int* click, int clickSize, int** columnSizes, int* returnSize)
{
    if (!board || !boardRowSize || !boardColSize)
        return NULL;

    int* cs = malloc(sizeof(int) * boardRowSize);
    char** r = malloc(sizeof(char*) * boardRowSize);
    for (int i = 0; i < boardRowSize; i ++)
    {
        r[i] = malloc(boardColSize);
        memcpy(r[i], board[i], boardColSize);
        cs[i] = boardColSize;
    }
    *columnSizes = cs;
    *returnSize = boardRowSize;

    if (!click || !clickSize)
        return board;

    int x = click[0];
    int y = click[1];

    if (x >= boardRowSize || y >= boardColSize)
        return board;


    if (board[x][y] == 'M')
    {
        board[x][y] = 'X';
        return board;
    }

    char* bf = calloc(sizeof(char), boardRowSize * boardColSize);
    ub(r, boardRowSize, boardColSize, x, y, bf);
    return r;
}
*/
