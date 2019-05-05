/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize)
{
    int** m = matrix;
    int r = matrixRowSize;
    int c = matrixColSize;
    *returnSize = r * c;

    int n = 0;
    int* ret = malloc(sizeof(int) * r * c);

    bool left = true;
    int l = r + c - 1;

    int dx = 0;
    int dy = 0;
    int x = 0;
    int y = 0;
    for (int i = 0; i < l; i ++)
    {
        if (left)
        {
            x = i > (r - 1) ? (r - 1) : i;
            y = i > (r - 1) ? (i - r + 1) : 0;
            dx = -1;
            dy = 1;
        }
        else
        {
            x = i < (c - 1) ? 0 : (i - c + 1);
            y = i < (c - 1) ? i : (c - 1);
            dx = 1;
            dy = -1;
        }

        left = !left;
        while (x >= 0 && x < r && y >= 0 && y < c)
        {
            ret[n ++] = m[x][y];
            x += dx;
            y += dy;
        }
    }
    return ret;
}
