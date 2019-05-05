/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void gen(int** all, int *a, int n, int c, bool up)
{
    (*a) ^= (1 << c);
    *(*all) = *a;
    (*all) ++;

    for(int i = 0; i < c; i++)
        gen(all, a, c, i, false);

    if (c == n - 1)
        return;

    if (up)
        return gen(all, a, n, c + 1, up);
}

int* grayCode(int n, int* returnSize)
{
    *returnSize = 1 << n;
    int* all = malloc(sizeof(int) * (*returnSize));
    int* ret = all;
    int a = 0;
    *all = a;
    all += 1;

    if (n == 0)
        return ret;

    int** t = &all;
    gen(t, &a, n, 0, true);
    return ret;
}
