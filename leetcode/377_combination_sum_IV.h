/* how to correct set up lookup table */
void cs_sort(int* n, int s, int e)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;
        }
    }
    cs_sort(n, cs, e - 1);
    cs_sort(n, e + 1, ce);
}

void cs_sort_2(int *n, int s, int e)
{
    bool sorted = false;

    for (int i = 1; i <= e; i ++)
    {
        if (n[i] < n[i - 1])
        {
            cs_sort(n, s, e);
            break;
        }
    }
}

int cs_much(int* nums, int l, int** pss, int** psn, int* psi, int* psz, int left)
{
    int si = *psi;
    int sz = *psz;
    int* ss = *pss;
    int* sn = *psn;

    int all = 0;

    for (int i = 0; i < si; i ++)
    {
        if (ss[i] == left)
            return sn[i];
    }

    for (int i = 0; i < l; i ++)
    {
        int delta = left - nums[i];
        if (delta < 0)
            break;

        if (!delta)
            all ++;
        else
            all += cs_much(nums, l, pss, psn, psi,psz, delta);
    }

    si = (*psi) ++;
    ss[si] = left;
    sn[si] = all;
    return all;
}

int combinationSum4(int* nums, int numsSize, int target)
{
    if (!nums || !numsSize)
        return 0;

    cs_sort_2(nums, 0, numsSize - 1);

    int si = 0;
    int sz = 2048;
    int* sn = malloc(sizeof(int) * sz);
    int* ss = malloc(sizeof(int) * sz);
    int ret =  cs_much(nums, numsSize, &ss, &sn, &si, &sz, target);
    printf("si is %d.\n", si);
    out(ss, 20);
    out(sn, 20);
    return ret;
}

