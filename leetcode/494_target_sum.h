/*
void fts_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(n[i] < n[s]) i ++;
        while(n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    fts_sort(n, cs, e - 1);
    fts_sort(n, e + 1, ce);
}
*/

int fts(int* nums, int n, int s, int T)
{
    if (!T)
        return 1;

    int all = 0;
    for (int i = n; i <= s; i ++)
    {
        if (nums[i] <= T)
            all += fts(nums, i + 1, s, T - nums[i]);
    }
    return all;
}

int findTargetSumWays(int* nums, int numsSize, int S)
{
    int i = 0;
    int all = 0;
    int zero = 0;
    int mul = 1;

    for (i = 0; i < numsSize; i ++)
    {
        all += nums[i];
        if (!nums[i])
        {
            nums[i] = nums[zero];
            nums[zero ++] = 0;
            mul *= 2;
        }
    }
    if ((all - S) & 1)
        return 0;

    return mul * fts(nums, zero, numsSize - 1, (all - S) >> 1);
}
