/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

unsigned char _nx(unsigned char c)
{
    unsigned char r = 0;
    r |= (!!(c & (1 << 7)) == !!(c & (1 << 5))) ? (1 << 6) : 0;
    r |= (!!(c & (1 << 6)) == !!(c & (1 << 4))) ? (1 << 5) : 0;
    r |= (!!(c & (1 << 5)) == !!(c & (1 << 3))) ? (1 << 4) : 0;
    r |= (!!(c & (1 << 4)) == !!(c & (1 << 2))) ? (1 << 3) : 0;
    r |= (!!(c & (1 << 3)) == !!(c & (1 << 1))) ? (1 << 2) : 0;
    r |= (!!(c & (1 << 2)) == !!(c & (1 << 0))) ? (1 << 1) : 0;
    return r;
}

int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize)
{
    // create the next
    unsigned char next[256] = {0};

    for (int i = 0; i < 256; i ++)
        next[i] = _nx(i);

    unsigned char c = 0;
    for (int i = 0; i < 8; i ++)
        c = (c << 1) | (cells[i]);

    char bits[256] = {0};

    for (int i = 0; i < N; i ++)
    {
        if (bits[c])
        {
            int d = i + 1 - bits[c];

            if (N - i >= d)
            {
                N = i + (N - i) % d;
                if (i >= N)
                    break;
            }
        }

        bits[c] = i + 1;
        c = next[c];
    }

    int* r = malloc(sizeof(int) * 8);
    *returnSize = 8;
    for (int i = 0; i < 8; i ++)
        r[7 - i] = ((1 << i) & c) ? 1 : 0;
    return r;
}
