/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
    int c = 0;
    for (int i = ASize - 1; i >= 0 && (K || c); i --)
    {
        A[i] += (K % 10) + c;
        c = A[i] / 10;
        A[i] %= 10;
        K /= 10;
    }
    c += K;
    int b = c > 0 ? 1 : 0;
    int n = 10;

    while (c > n - 1)
    {
        b ++;
        n *= 10;
    }
    n /= 10;
    int* r = calloc(sizeof(int), (ASize + b));

    int ri = 0;
    while (c)
    {
        r[ri ++] = c / n;
        c %= n;
        n /= 10;
    }
    ri = b;
    for (int i = 0; i < ASize; i ++)
        r[ri ++] = A[i];

    *returnSize = ASize + b;
    return r;
}
