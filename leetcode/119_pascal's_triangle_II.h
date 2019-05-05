/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    if (rowIndex < 0)
        return NULL;

    int rs = rowIndex + 1;
    *returnSize = rs;

    int* a = malloc(sizeof(int) * rs);
    int* b = malloc(sizeof(int) * rs);

    for(int i = 1; i <= rs; i ++)
    {
        int* r1 = (i & 1) ? a : b;
        int* r2 = r1 == a ? b : a;

        r1[0] = 1;
        r1[i - 1] = 1;

        if (i > 2)
        {
            for (int j = 0; j < i - 2; j ++)
                r1[1 + j] = r2[j] + r2[j + 1];
        }
    }
    return (rs & 1) ? a : b;
}
