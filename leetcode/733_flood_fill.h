void ff(int** i, int r, int c, int d, int x, int y, int old, int new)
{
    if (x < 0 || x >= r || y < 0 || y >= c || old != i[x][y])
        return;

    if (i[x][y] == new)
        return;

    i[x][y] = new;

    if (d != 0)
        ff(i, r, c, 2, x + 1, y, old, new);

    if (d != 1)
        ff(i, r, c, 3, x, y - 1, old, new);

    if (d != 2)
        ff(i, r, c, 0, x - 1, y, old, new);

    if (d != 3)
        ff(i, r, c, 1, x, y + 1, old, new);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageRowSize, int imageColSize, int sr, int sc, int newColor, int** columnSizes, int* returnSize)
{
    if (!image)
        return NULL;

    *returnSize = imageRowSize;

    int oldColor = image[sr][sc];
    image[sr][sc] = newColor;

    ff(image, imageRowSize, imageColSize, 0, sr - 1, sc, oldColor, newColor);
    ff(image, imageRowSize, imageColSize, 1, sr, sc + 1, oldColor, newColor);
    ff(image, imageRowSize, imageColSize, 2, sr + 1, sc, oldColor, newColor);
    ff(image, imageRowSize, imageColSize, 3, sr, sc - 1, oldColor, newColor);

    int* cs = malloc(sizeof(int) * imageRowSize);
    // int** ret = malloc(sizeof(int*) * imageRowSize);

    for (int i = 0; i < imageRowSize; i ++)
    {
        cs[i] = imageColSize;
        /* ret[i] = malloc(sizeof(int) * imageColSize); */
        /* memcpy(ret[i], image[i], sizeof(int) * imageColSize); */
    }

    *columnSizes = cs;
    return ret;
}
