/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int* r = malloc(sizeof(int) * ASize);

    int s = 0;
    int e = ASize - 1;

    while (s < e)
    {
        int m = s + (e - s) / 2;

        if (A[m] < 0)
            s = m + 1;
        else
            e = m;
    }

    s = e - 1;

    for (int i = 0; i < ASize; i ++)
    {
        if (s >= 0 && e < ASize)
        {
            if (A[s] * A[s] <= A[e] * A[e])
            {
                r[i] = A[s] * A[s];
                s --;
            }
            else
            {
                r[i] = A[e] * A[e];
                e ++;
            }
        }
        else if (s >= 0)
        {
            r[i] = A[s] * A[s];
            s --;
        }
        else
        {
            r[i] = A[e] * A[e];
            e ++;
        }
    }
    return r;
}
