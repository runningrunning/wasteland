typedef struct {
    int size;
    // int* board; /* size * size */
    // int* vs; /* size + size + 2  horizontal, vertical, diagonal */
    int* hs;
    int* vs;
    int ds[2];
} TicTacToe;

/** Initialize your data structure here. */
TicTacToe* ticTacToeCreate(int n) {
    TicTacToe* t = malloc(sizeof(TicTacToe));
    t->size = n;
    t->hs = malloc(sizeof(int) * n);
    t->vs = malloc(sizeof(int) * n);
    /* t->board = malloc(sizeof(int) * n * n); */
    /* t->vs = malloc(sizeof(int) * (n + n + 2)); */

    /* memset(t->board, 0, sizeof(int) * n * n); */
    /* memset(t->vs, sizeof(int) * (n + n + 2)); */

    memset(t->hs, 0, sizeof(int) * n);
    memset(t->vs, 0, sizeof(int) * n);
    t->ds[0] = t->ds[1] = 0;
    return t;
}

/** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
int ticTacToeMove(TicTacToe* obj, int row, int col, int player) {
    if (!obj)
        return 0;

    int n = obj->size;
    int v = (player & 1) ? 1 : - 1;
    obj->hs[row] += v;
    if (obj->hs[row] == n || obj->hs[row] == - n)
        return player;

    obj->vs[col] += v;
    if (obj->vs[col] == n || obj->vs[col] == - n)
        return player;


    if (row == col)
        obj->ds[0] += v;

    if (col == n - 1 - row)
        obj->ds[1] += v;

    if (obj->ds[0] == n || obj->ds[0] == - n ||
        obj->ds[1] == n || obj->ds[1] == - n)
        return player;

    return 0;
}

void ticTacToeFree(TicTacToe* obj) {
    if (obj)
    {
        free(obj->hs);
        free(obj->vs);
        free(obj);
    }
}

/**
 * Your TicTacToe struct will be instantiated and called as such:
 * struct TicTacToe* obj = ticTacToeCreate(n);
 * int param_1 = ticTacToeMove(obj, row, col, player);
 * ticTacToeFree(obj);
 */
