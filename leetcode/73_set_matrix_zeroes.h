/* TODO all of Qs with something in place is remembering it into itself !!! */
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize)
{
    int** m = matrix;
    int r = matrixRowSize;
    int c = matrixColSize;

    bool has = false;
    for(int i = 0; i < c; i ++)
    {
        if (m[0][i] == 0)
        {
            has = true;
            break;
        }
    }

    for(int i = 1; i < r; i ++)
    {
        bool z = false;
        for(int j = 0; j < c; j ++)
        {
            if (m[i][j] == 0)
            {
                m[0][j] = 0;
                z = true;
            }
        }
        if (z)
            memset(m[i], 0, sizeof(int) * c);
    }

    for(int i = 0; i < c; i++)
    {
        if (m[0][i] == 0)
        {
            for(int j = 1; j < r; j ++)
                m[j][i] = 0;
        }
    }

    if (has)
        memset(m[0], 0, sizeof(int) * c);
}
