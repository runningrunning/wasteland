/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** spiralMatrixIII(int R, int C, int r0, int c0, int** columnSizes, int* returnSize)
{
    int ri = 0;
    int** r = malloc(sizeof(int*) * R * C);
    int* cs = malloc(sizeof(int) * R * C);

    r[ri] = malloc(sizeof(int) * 2);
    r[ri][0] = r0;
    r[ri][1] = c0;
    cs[ri] = 2;
    ri ++;

    int st = 1;
    while (ri < R * C)
    {
        if (r0 >= 0)
        {
            int c = c0;
            for (int i = 0; i < st; i ++)
            {
                c ++;

                if (c < 0)
                    continue;

                if (c >= C)
                    break;

                r[ri] = malloc(sizeof(int) * 2);
                r[ri][0] = r0;
                r[ri][1] = c;
                cs[ri] = 2;
                ri ++;
            }
        }

        c0 += st;

        if (c0 < C)
        {
            int _r = r0;
            for (int i = 0; i < st; i ++)
            {
                _r ++;

                if (_r < 0)
                    continue;

                if (_r >= R)
                    break;

                r[ri] = malloc(sizeof(int) * 2);
                r[ri][0] = _r;
                r[ri][1] = c0;
                cs[ri] = 2;
                ri ++;
            }
        }

        r0 += st;

        st ++;

        if (r0 < R)
        {
            int c = c0;
            for (int i = 0; i < st; i ++)
            {
                c --;

                if (c < 0)
                    break;

                if (c >= C)
                    continue;

                r[ri] = malloc(sizeof(int) * 2);
                r[ri][0] = r0;
                r[ri][1] = c;
                cs[ri] = 2;
                ri ++;
            }
        }

        c0 -= st;

        if (c0 >= 0)
        {
            int _r = r0;
            for (int i = 0; i < st; i ++)
            {
                _r --;

                if (_r < 0)
                    break;

                if (_r >= R)
                    continue;
                r[ri] = malloc(sizeof(int) * 2);
                r[ri][0] = _r;
                r[ri][1] = c0;
                cs[ri] = 2;
                ri ++;
            }
        }

        r0 -= st;
        st ++;
    }

    *returnSize = R * C;
    *columnSizes = cs;
    return r;
}
