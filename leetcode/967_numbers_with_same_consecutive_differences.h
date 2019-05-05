/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void _nscf(int* num, int n, int need, int k, int* ret, int* rs)
{
    if (n == need)
    {
        int x = 0;
        for (int i = 0; i < n; i ++)
            x = x * 10 + num[i];
        ret[*rs] = x;
        *rs = *rs + 1;
        return;
    }

    int p = num[n - 1];

    if (p - k >= 0)
    {
        num[n] = p - k;
        _nscf(num, n + 1, need, k, ret, rs);
    }

    if (k && p + k <= 9)
    {
        num[n] = p + k;
        _nscf(num, n + 1, need, k, ret, rs);
    }
}

// recursive
int* numsSameConsecDiff(int N, int K, int* returnSize)
{
    int ni = 0;
    int* num = malloc(sizeof(int) * 10);

    // just gussing
    int rs = 0;
    int* ret = malloc(sizeof(int) * 2048); // 2048 is print all of them

    int s = N == 1 ? 0 : 1;

    for (int i = s; i <= 9; i ++)
    {
        num[0] = i;
        _nscf(num, 1, N, K, ret, &rs);
    }
    *returnSize = rs;
    return ret;
}
