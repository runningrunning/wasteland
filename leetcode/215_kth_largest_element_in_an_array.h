int fk_sort(int* ns, int s, int e, int k)
{
    int t;
    if (s >= e)
        return ns[k];

    if (ns[s] > ns[e])
    {
        t = ns[s];
        ns[s] = ns[e];
        ns[e] = t;
    }

    if (s + 1 == e)
        return ns[k];

    if (k == s || k == e)
    {
        int min = INT_MAX;
        int max = INT_MIN;

        for(int i = s; i <= e; i ++)
        {
            if (ns[i] < min)
                min = ns[i];

            if (ns[i] > max)
                max = ns[i];
        }
        return k == s ? min : max;
    }

    int cs = s;
    int ce = e;

    for(int i = s + 1; i <= e; i ++)
    {
        while(ns[i] < ns[s]) i ++;
        while(ns[e] > ns[s]) e --;

        if (i >= e)
        {
            t = ns[e];
            ns[e] = ns[s];
            ns[s] = t;
        }
        else
        {
            t = ns[e];
            ns[e] = ns[i];
            ns[i] = t;
        }
    }

    if (e == k)
        return ns[k];

    if (k > e)
        return fk_sort(ns, e + 1, ce, k);
    else
        return fk_sort(ns, cs, e - 1, k);
}

int findKthLargest(int* nums, int numsSize, int k)
{
    return fk_sort(nums, 0, numsSize - 1, numsSize - k);
}
