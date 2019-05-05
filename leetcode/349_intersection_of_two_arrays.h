void is_sort(int* ns, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (ns[s] > ns[e])
    {
        t = ns[s];
        ns[s] = ns[e];
        ns[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for(int i = s + 1; i <= e; i ++)
    {
        while(ns[i] < ns[s]) i ++;
        while(ns[e] > ns[s]) e --;

        if (i >= e)
        {
            t = ns[s];
            ns[s] = ns[e];
            ns[e] = t;
        }
        else
        {
            t = ns[i];
            ns[i] = ns[e];
            ns[e] = t;
        }
    }

    is_sort(ns, cs, e - 1);
    is_sort(ns, e + 1, ce);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0;

    if (!nums1 || !nums1Size || !nums2 || !nums2Size)
        return NULL;

    int mi1 = nums1[0];
    int ma1 = nums1[0];
    int mi2 = nums2[0];
    int ma2 = nums2[0];

    for (int i = 1; i < nums1Size; i ++)
    {
        if (mi1 > nums1[i])
            mi1 = nums1[i];
        else if (ma1 < nums1[i])
            ma1 = nums1[i];
    }

    for (int i = i; i < nums2Size; i ++)
    {
        if (mi2 > nums2[i])
            mi2 = nums2[i];
        else if (ma2 < nums2[i])
            ma2 = nums2[i];
    }

    if (ma1 < mi2 || ma2 < mi1)
        return NULL;

    if (ma1 == mi2 || mi1 == ma2)
    {
        *returnSize = 1;
        int* ret = malloc(sizeof(int));
        ret[0] = ma1 == mi2 ? ma1 : ma2;
    }

    int mi = mi1 >  mi2 ? mi1 : mi2;
    int ma = ma1 > ma2 ? ma2 : ma1;

    int j1 = 0;
    for(int i = 0; i < nums1Size; i ++)
    {
        if (nums1[i] >= mi && nums1[i] <= ma)
            nums1[j1 ++] = nums1[i];
    }

    int j2 = 0;
    for(int i = 0; i < nums2Size; i ++)
    {
        if (nums2[i] >= mi && nums2[i] <= ma)
            nums2[j2 ++] = nums2[i];
    }

    is_sort(nums1, 0, j1 - 1);
    is_sort(nums2, 0, j2 - 1);

    int rs = 0;
    int* ret = malloc(sizeof(int) * (j1 > j2 ? j2 : j1));

    int i1 = 0;
    int i2 = 0;

    int pre = 0;
    while(i1 < j1 && i2 < j2)
    {
        if (nums1[i1] == nums2[i2])
        {
            ret[rs ++] = nums1[i1];
            i1 ++;
            i2 ++;
        }
        else if (nums1[i1] > nums2[i2])
            i2 ++;
        else
            i1 ++;
    }

    *returnSize = rs;
    return ret;
}
