/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize)
{
    int ri = 0;
    int* cs = NULL;
    int** r = NULL;

    int pre = S[0];

    int i = 0;
    int c = S[i ++];

    int st = 0;
    while (true)
    {
        if (c != pre)
        {
            if (i - 1 - st >= 3)
            {
                r = realloc(r, sizeof(int*) * (ri + 1));
                cs = realloc(cs, sizeof(int) * (ri + 1));
                r[ri] = malloc(sizeof(int) * 2);
                r[ri][0] = st;
                r[ri][1] = i - 2;
                cs[ri] = 2;
                ri += 1;
            }
            st = i - 1;
        }

        if (!c)
            break;

        pre = c;
        c = S[i ++];
    }

    *columnSizes = cs;
    *returnSize = ri;
    return r;
}
