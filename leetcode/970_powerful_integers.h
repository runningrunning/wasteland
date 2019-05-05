/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize)
{
    int ri = 0;
    int rs = 1024;
    int* r = malloc(sizeof(int) * 1024);
    char* bits = calloc(sizeof(char), bound + 1);

    int cx = 1;
    while (cx < bound)
    {
        int cy = 1;
        while (cx + cy <= bound)
        {
            if (!bits[cx + cy])
            {
                if (ri == rs)
                {
                    rs += 1024;
                    r = realloc(r, sizeof(int) * rs);
                }
                r[ri ++] = cx + cy;
                bits[cx + cy] = 1;
            }
            cy *= y;

            if (y == 1)
                break;
        }
        cx *= x;

        if (x == 1)
            break;
    }

    *returnSize = ri;
    return r;
}
