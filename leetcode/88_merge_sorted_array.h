void merge(int* nums1, int m, int* nums2, int n)
{
    int a = m + n;
    while(m && n)
    {
        if (nums1[m - 1] > nums2[n - 1])
            nums1[a--  - 1] = nums2[m-- - 1];
        else
            nums1[a-- - 1] = nums2[n-- - 1];
    }

    while(n)
        nums1[a-- - 1] = nums2[n-- - 1];
}
