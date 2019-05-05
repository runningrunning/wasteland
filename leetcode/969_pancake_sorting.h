/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void _ps(int* a, int s, int* rs, int* ri)
{
    if (s <= 1)
        return;

    int i = 0;
    for (i = 0; i < s; i ++)
        if (a[i] == s)
            break;

    if (i != s - 1)
    {
        int st = 0;
        int ed = i;

        if (i != 0)
        {
            rs[*ri] = i + 1;
            *ri = *ri + 1;

            while (st < ed)
            {
                a[st] ^= a[ed];
                a[ed] ^= a[st];
                a[st] ^= a[ed];
                st ++;
                ed --;
            }
        }

        rs[*ri] = s;
        *ri = *ri + 1;

        st = 0;
        ed = s - 1;

        while (st < ed)
        {
            a[st] ^= a[ed];
            a[ed] ^= a[st];
            a[st] ^= a[ed];
            st ++;
            ed --;
        }
    }
    _ps(a, s - 1, rs, ri);
}

int* pancakeSort(int* A, int ASize, int* returnSize)
{
    int ri = 0;
    int* ret = malloc(sizeof(int) * ASize * 2);
    _ps(A, ASize, ret, &ri);
    *returnSize = ri;
    return ret;
}
