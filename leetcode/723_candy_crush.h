#define R_FLAG  1 << 18
#define C_FLAG  1 << 20

int** minimizeCC(int** b, int r, int c)
{
    bool has = false;
    bool has_row;

    for (int i = r - 1; i >= 0; i --)
    {
        has_row = false;
        for (int j = 0; j < c; j ++)
        {
            int t = b[i][j] & 0xFFFF;

            if (!t)
                continue;

            has_row = true;

            if (i != 0 && i != r - 1)
            {
                int tr_1 = b[i + 1][j] & 0xFFFF;
                int tr_2 = b[i - 1][j] & 0xFFFF;

                if (tr_1 == tr_2 && tr_1 == t)
                {
                    has = true;
                    b[i + 1][j] |= R_FLAG;
                    b[i - 1][j] |= R_FLAG;
                    b[i][j] |= R_FLAG;
                }
            }

            if (j != 0 && j != c - 1)
            {
                int tc_1 = b[i][j - 1] & 0xFFFF;
                int tc_2 = b[i][j + 1] & 0xFFFF;

                if (tc_1 == tc_2 && tc_1 == t)
                {
                    has = true;
                    b[i][j - 1] |= C_FLAG;
                    b[i][j + 1] |= C_FLAG;
                    b[i][j] |= C_FLAG;
                }
            }
        }

        if (!has_row)
            break;
    }

    if (!has)
        return b;

    for (int i = 0; i < c; i ++)
    {
        int x = r - 1;
        for (int j = r - 1; j >= 0; j --)
        {
            int t = b[j][i];
            if ((t & R_FLAG) || (t & C_FLAG))
                b[j][i] = 0;
            else
            {
                b[j][i] = 0;
                b[x --][i] = t;
            }
        }
    }

    return minimizeCC(b, r, c);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** candyCrush(int** board, int boardRowSize, int boardColSize, int** columnSizes, int* returnSize)
{
    if (!board || !boardRowSize || !boardColSize)
        return NULL;

    *returnSize = boardRowSize;
    *columnSizes = malloc(sizeof(int) * boardRowSize);

    for (int i = 0; i < boardRowSize; i++)
        (*columnSizes)[i] = boardColSize;

    return minimizeCC(board, boardRowSize, boardColSize);
}
