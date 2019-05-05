int findLonelyPixel(char** picture, int pictureRowSize, int pictureColSize)
{
    int rs[501] = {0};
    int cs[501] = {0};
    int fr_c[501] = {0};

    int n;
    int r = pictureRowSize;
    int c = pictureColSize;

    if (!picture || !r || !c)
        return 0;

    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (picture[i][j] == 'B')
            {
                if (!rs[i])
                    fr_c[i] = j;
                rs[i] ++;
                cs[j] ++;
            }
        }

    n = 0;
    for (int i = 0; i < r; i ++)
        if (rs[i] == 1 && cs[fr_c[i]] == 1)
            n ++;

    return n;
}
