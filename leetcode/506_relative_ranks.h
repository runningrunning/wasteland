void frr_sort(int* n, int s, int e, int* id)
{
    if (s > e)
        return;

    if (n[s] < n[e])
    {
        n[s] ^= n[e];
        n[e] ^= n[s];
        n[s] ^= n[e];

        id[s] ^= id[e];
        id[e] ^= id[s];
        id[s] ^= id[e];
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(n[i] > n[s]) i ++;
        while(n[e] < n[s]) e --;

        if (i >= e)
        {
            if (e != s)
            {
                n[s] ^= n[e];
                n[e] ^= n[s];
                n[s] ^= n[e];

                id[s] ^= id[e];
                id[e] ^= id[s];
                id[s] ^= id[e];
            }
        }
        else
        {
                n[i] ^= n[e];
                n[e] ^= n[i];
                n[i] ^= n[e];

                id[i] ^= id[e];
                id[e] ^= id[i];
                id[i] ^= id[e];
        }
    }
    frr_sort(n, cs, e - 1, id);
    frr_sort(n, e + 1, ce, id);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* nums, int numsSize, int* returnSize)
{
    *returnSize = numsSize;
    if (!numsSize || !nums)
        return NULL;

    int* rs = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i ++)
        rs[i] = i;
    *returnSize = numsSize;

    frr_sort(nums, 0, numsSize - 1, rs);

    char** r = malloc(sizeof(char*) * numsSize);

    for (int i = 0; i < 3 && i < numsSize; i ++)
    {
        if (i == 0)
            r[rs[i]] = strdup("Gold Medal");
        if (i == 1)
            r[rs[i]] = strdup("Silver Medal");
        if (i == 2)
            r[rs[i]] = strdup("Bronze Medal");
    }

    for (int i = 3; i < numsSize; i++)
    {
        r[rs[i]] = malloc(10);
        int x = sprintf(r[rs[i]], "%d", i + 1);
        r[rs[i]][x] = 0;
    }
    return r;
}
