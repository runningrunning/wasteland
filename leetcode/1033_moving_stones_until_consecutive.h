/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize)
{
    int min = a < b ? a : b;
    min = min < c ? min : c;
    int max = a > b ? a : b;
    max = max > c ? max : c;
    int mid = a + b + c - min - max;

    int d = max - min - 1 - 1;
    int* ret = malloc(sizeof(int) * 2);

    *returnSize = 2;

    if (d == 0)
        ret[0] = ret[1] = 0;
    else if (d == 1)
        ret[0] = ret[1] = 1;
    else
    {
        ret[0] = ((mid - min == 1) || (max - mid == 1) || (mid - min == 2) || (max - mid == 2)) ? 1 : 2;
        ret[1] = d;
    }
    return ret;
}
