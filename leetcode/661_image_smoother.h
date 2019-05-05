/* find better solutions here !! */
/* TODO: Try hard and pretice more times. */
/* Corner case when MColSize is 1 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize)
{
    if (!M || !MRowSize || !MColSize)
        return NULL;

    *returnSize = MRowSize;
    int c, r;
    int** H = malloc(sizeof(int*) * MRowSize);
    int* CS = malloc(sizeof(int) * MRowSize);
    *columnSizes = CS;

    for (r = 0; r < MRowSize; r ++)
        CS[r] = MColSize;

    H[0] = malloc(sizeof(int) * MColSize);
    for (c = 0; c < MColSize; c ++)
    {
        int cb = (c == 0) ? 0 : M[0][c - 1];
        int cp = (c == MColSize - 1) ? 0 : M[0][c + 1];
        H[0][c] = M[0][c] + cb + cp;
    }

    int c_av_1 = MColSize == 1 ? 1 : 2;
    int c_av_2 = MColSize == 1 ? 2 : 4;
    int c_av_3 = MColSize == 1 ? 3 : 6;

    /* Just one line */
    if (MRowSize == 1)
    {
        for (c = 0; c < MColSize; c ++)
        {
            if (c == 0 || c == MColSize - 1)
                H[0][c] = H[0][c] / c_av_1;
            else
                H[0][c] = H[0][c] / 3;
        }
        return H;
    }

    for (r = 1; r < MRowSize; r ++)
    {
        H[r] = malloc(sizeof(int) * MColSize);
        for (c = 0; c < MColSize; c ++)
        {
            int cb = (c == 0) ? 0 : M[r][c - 1];
            int cp = (c == MColSize - 1) ? 0 : M[r][c + 1];
            H[r][c] = H[r - 1][c] + M[r][c] + cb + cp;
        }
    }

    /* 2 lines */
    if (MRowSize == 2)
    {
        for (c = 0; c < MColSize; c ++)
        {
            if (c == 0 || c == MColSize - 1)
                H[1][c] = H[1][c] / c_av_2;
            else
                H[1][c] = H[1][c] / 6;
        }
        memcpy(H[0], H[1], sizeof(int) * MColSize);
        return H;
    }

    int* LC = malloc(sizeof(int) * MColSize);
    r = MRowSize - 1;
    for (c = 0; c < MColSize; c ++)
    {
        LC[c] = H[r][c] - H[r - 2][c];

        if (c == 0 || c == MColSize - 1)
            LC[c] /= c_av_2;
        else
            LC[c] /= 6;
    }

    for (; r >= 3; r --)
    {
        for (c = 0; c < MColSize; c ++)
        {
            H[r][c] -= H[r - 3][c];

            if (c == 0 || c == MColSize - 1)
                H[r][c] /= c_av_3;
            else
                H[r][c] /= 9;
        }
    }

    for (c = 0; c < MColSize; c ++)
    {
        if (c == 0 || c == MColSize - 1)
        {
            H[1][c] /= c_av_2;
            H[2][c] /= c_av_3;
        }
        else
        {
            H[1][c] /= 6;
            H[2][c] /= 9;
        }
    }

    free(H[0]);
    for (r = 0; r < MRowSize - 1; r ++)
        H[r] = H[r + 1];
    H[MRowSize - 1] = LC;
    return H;
}
