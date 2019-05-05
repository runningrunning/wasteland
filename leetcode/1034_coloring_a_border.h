/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void _color(int** g, int r, int c, int x, int y, int oc, int nc)
{
    if (x < 0 || x >= r || y < 0 || y >= c)
        return;

    if (g[x][y] == nc || g[x][y] != oc)
        return;

    g[x][y] = nc;

    _color(g, r, c, x - 1, y, oc, nc);
    _color(g, r, c, x + 1, y, oc, nc);
    _color(g, r, c, x, y - 1, oc, nc);
    _color(g, r, c, x, y + 1, oc, nc);
}

int** colorBorder(int** grid, int gridSize, int* gridColSize, int r0, int c0, int color, int* returnSize, int** returnColumnSizes)
{
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;

    if (!gridSize || !gridColSize || !gridColSize[0])
        return grid;

    int oc = grid[r0][c0];
    int nc = color;

    _color(grid, gridSize, gridColSize[0], r0, c0, oc, -nc);

    for (int i = 1; i < gridSize - 1; i ++)
        for (int j = 1; j < gridColSize[0] - 1; j ++)
        {
            if (grid[i][j] != - nc) continue; // careful here !!!!!
            if ((grid[i - 1][j] == - nc || grid[i - 1][j] == - oc)
                && (grid[i + 1][j] == - nc || grid[i + 1][j] == - oc)
                && (grid[i][j - 1] == - nc || grid[i][j - 1] == - oc)
                && (grid[i][j + 1] == - nc || grid[i][j + 1] == - oc))
                grid[i][j] = - oc;
        }

    for (int i = 0; i < gridSize; i ++)
        for (int j = 0; j < gridColSize[0]; j ++)
        {
            if (grid[i][j] == -oc)
                grid[i][j] = oc;
            else if (grid[i][j] == -nc)
                grid[i][j] = nc;
        }
    return grid;
}
