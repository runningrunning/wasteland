// non-negative !!!!
// READ THE FUCKING QS
void tn_sort(int* n, int s, int e)
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
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

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

    tn_sort(n, cs, e - 1);
    tn_sort(n, e + 1, ce);
}

int triangleNumber(int* nums, int numsSize)
{
    if (!nums || numsSize < 3)
        return 0;

    tn_sort(nums, 0, numsSize - 1);

    int start = 0;
    while (!nums[start])
        start ++;

    if (numsSize - start < 3)
        return 0;

    int t[2048] = {0};
    for (int i = start; i < numsSize - 1; i ++)
        for (int j = i + 1; j < numsSize; j ++)
            t[nums[i] + nums[j]] ++;

    int last = nums[numsSize - 1] + nums[numsSize - 2];

    int pre = 0;
    for (int i = last; i >= 0; i --)
    {
        int tmp = t[i];
        t[i] = pre;
        pre += tmp;
    }

    int a = 0;
    int k = 0;
    for (int i = numsSize - 1; i >= start + 2; i --)
    {
        a += t[nums[i]] - k - (i - start);
        k += (i - start);
    }
    return a;
}
