/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize)
{
    int s = 0;
    int e = ASize - 1;

    if (!A || !ASize || !returnSize)
        return NULL;

    while (true)
    {
        while (!(A[s] & 1) && s < ASize)
            s += 2;

        while ((A[e] & 1) && e > 0)
            e -= 2;

        if (s >= ASize || e <= 0)
            break;

        A[s] ^= A[e];
        A[e] ^= A[s];
        A[s] ^= A[e];
    }

    *returnSize = ASize;
    return A;
}
