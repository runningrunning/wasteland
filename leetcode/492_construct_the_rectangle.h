/* STUPID corner case, sqrt(99) = 9, but 9 * 9 != 99 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize)
{
    *returnSize = 0;
    if (!area)
        return NULL;

    int* ret = malloc(sizeof(int) * 2);
    *returnSize = 2;

    int x = sqrt(area);

    for (int i = x; i > 0 ; i --)
    {
        if (!(area % i))
        {
            ret[0] = area / i;
            ret[1] = i;
            break;
        }
    }
    return ret;
}
