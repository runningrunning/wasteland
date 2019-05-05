/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize)
{
    *returnSize = ASize;
    if (!A || !ASize)
        return NULL;

    bool* a = malloc(sizeof(bool) * ASize);

    int p = 0;

    for (int i = 0; i < ASize; i ++)
    {
        int c = p * 2 + A[i];
        a[i] = (c % 5) ? false : true;
        p = c % 5;
    }
    return a;
}
