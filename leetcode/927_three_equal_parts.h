// it's simple to count 0s
// for all of zeros, every divide should be correct !!!
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* threeEqualParts(int* A, int ASize, int* returnSize) {

    int ai = 0;
    int* r = malloc(sizeof(int) * 2);
    r[0] = r[1] = -1;
    *returnSize = 2;

    if (!A || ASize < 3)
        return r;

    for (int i = 0; i < ASize; i ++)
        if (A[i])
            A[ai ++] = i;

    if (ai == 0)
    {
        r[0] = 0;
        r[1] = ASize - 1; // 1 should be also correct !!
        return r;
    }

    if (!(ai % 3))
    {
        int e1 = (ai / 3) - 1;
        int e2 = (ai / 3) * 2 - 1;
        int e3 = ai - 1;

        // end of zeros
        int n0 = ASize - A[ai - 1] - 1;

        // zero in the between is enough
        if ((A[e1 + 1] - A[e1] - 1) >= n0 && (A[e2 + 1] - A[e2] - 1) >= n0)
        {
            bool same = true;

            r[0] = A[e1] + n0;
            r[1] = A[e2] + n0 + 1;

            for (int i = 0; i <= e1; i ++)
            {
                int o = A[e1] - A[e1 - i];
                if (o != A[e2] - A[e2 - i] || o != A[e3] - A[e3 - i])
                {
                    same = false;
                    break;
                }
            }

            if (!same)
                r[0] = r[1] = -1;
        }
    }
    return r;
}
