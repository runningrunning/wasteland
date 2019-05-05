// TOO MUCH CORNER CASE
// m >= 1 && m <= 100000
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    int bits = sizeof(char) * 8;
    char* fs = calloc(sizeof(char), 100000 / bits + 1);

    int* max;
    int* min;
    int max_s, min_s;
    if (ASize < BSize)
    {
        max = B;
        min = A;
        max_s = BSize;
        min_s = ASize;
    }
    else
    {
        max = A;
        min = B;
        max_s = ASize;
        min_s = BSize;
    }

    int all = 0;
    for (int i = 0; i < max_s; i ++)
    {
        int m = max[i];
        fs[m/bits] |= 1 << (m % bits);
        all += m;
    }

    int max_all = all;

    for (int i = 0; i < min_s; i ++)
        all += min[i];

    int need = max_all - all / 2;

    *returnSize = 2;
    int* r = malloc(sizeof(int) * 2);

    for (int i = 0; i < min_s; i ++)
    {
        int m = min[i] + need;

        if (m >= 1 && m <= 100000 && (fs[m/bits] & (1 << (m % bits))))
        {
            if (ASize < BSize)
            {
                r[0] = min[i];
                r[1] = m;
            }
            else
            {
                r[0] = m;
                r[1] = min[i];
            }
            break;
        }
    }

    return r;
}
