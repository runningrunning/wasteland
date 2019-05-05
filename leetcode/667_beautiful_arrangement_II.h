/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArray(int n, int k, int* returnSize) {
    if (!n || !k || k >= n)
        return NULL;

    *returnSize = n;

    int* ret = malloc(sizeof(int) * n);
    int min = 1;
    int max = n;

    int st = 0;
    ret[st ++] = min ++;

    while(k > 2)
    {
        ret[st ++] = max --;
        ret[st ++] = min ++;
        k -= 2;
    }

    int end = n;
    if (k == 2)
    {
        end = n - 3;
        ret[n - 2] = max --;
        ret[n - 1] = max --;
        ret[n - 3] = max --;
    }

    while(st < end)
        ret[st ++] = min ++;

    return ret;
}
