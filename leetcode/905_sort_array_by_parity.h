/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
    int t;
    int s = 0;
    int e = ASize - 1;

    *returnSize = ASize;

    if ((A[s] & 1) || !(A[e] & 1))
    {
        if ((A[s] & 1) && !(A[e] & 1))
        {
            t = A[s];
            A[s] = A[e];
            A[e] = t;
        }
        else if (A[s] & 1)
        {
            while (A[s] & 1 && s < e)
                s ++;
            if (s == e)
                return A;
            t = A[0];
            A[0] = A[s];
            A[s] = t;

        }
        else
        {
            while (!(A[e] & 1) && e > s)
                e --;

            if (s == e)
                return A;

            t = A[ASize - 1];
            A[ASize - 1] = A[e];
            A[e] = t;
        }
    }

    s = 0;
    e = ASize - 1;

    while (s < e)
    {
        while (!(A[s] & 1))
            s ++;
        while (A[e] & 1)
            e --;

        if (s < e)
        {
            t = A[s];
            A[s] = A[e];
            A[e] =  t;

            s ++;
            e --;
        }
    }
    return A;
}
