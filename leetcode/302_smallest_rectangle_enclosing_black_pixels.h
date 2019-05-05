void ma(char** i, int r, int c, int x, int y, int* minx, int* maxx, int* miny, int* maxy)
{
    i[x][y] = '2';

    if (x < *minx)
        *minx = x;
    if (x > *maxx)
        *maxx = x;

    if (y < *miny)
        *miny = y;

    if (y > *maxy)
        *maxy = y;

    if (x && i[x - 1][y] == '1')
        ma(i, r, c, x - 1, y, minx, maxx, miny, maxy);

    if (y && i[x][y - 1] == '1')
        ma(i, r, c, x, y - 1, minx, maxx, miny, maxy);

    if (x != r && i[x + 1][y] == '1')
        ma(i, r, c, x + 1, y, minx, maxx, miny, maxy);

    if (y != c && i[x][y + 1] == '1')
        ma(i, r, c, x, y + 1, minx, maxx, miny, maxy);
}

int minArea(char** image, int imageRowSize, int imageColSize, int x, int y)
{
    int minx = x;
    int maxx = x;
    int miny = y;
    int maxy = y;

    ma(image, imageRowSize - 1, imageColSize - 1, x, y, &minx, &maxx, &miny, &maxy);
    return (maxx - minx + 1) * (maxy - miny + 1);
}
