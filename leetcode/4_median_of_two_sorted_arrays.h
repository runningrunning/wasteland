/* Need to find better way */

/* O(m+n) */
double findMedianSortedArrays(int* nums1, int nums1Size, int *nums2, int nums2Size)
{
    int num = ((nums1Size + nums2Size) & 1) ? 1 : 2;
    int index = (nums1Size + nums2Size) / 2;
    index -= num == 2 ? 1 : 0;

    double total = 0.0;
    int i = 0;
    int j = 0;
    while(num)
    {
        int val = 0;
        if (i < nums1Size && j < nums2Size)
            val = nums1[i] > nums2[j] ? nums2[j ++] :  nums1[i ++];
        else if (i == nums1Size)
        {
            if (index > 0)
            {
                j += index;
                index = 0;
            }
            val = nums2[j ++];
        }
        else
        {
            if (index > 0)
            {
                i += index;
                index = 0;
            }
            val = nums1[i++];
        }

        if (index -- <= 0)
        {
            total += val;
            num --;
        }
    }
    return total / (0.0 + (((nums1Size + nums2Size) & 1) ? 1 : 2));
}

/* how much less than */
int bSearch(int* nums, int numsSize, int target)
{
    if (nums[0] >= target)
        return 0;
    if (nums[numsSize - 1] < target)
        return numsSize;

    if (numsSize <= 2)
    {
        return 1;
    }

    int need = 0;
    int mid = numsSize/2;
    if (nums[mid] >= target)
        need = bSearch(nums, mid, target);
    else
        need = mid + bSearch(&nums[mid + 1], numsSize - mid - 1, target) + 1;

    return need;
}

double findNth(int* nums1, int nums1Size, int *nums2, int nums2Size, int nth)
{
    if (nums1Size == 0)
    {
        return nums2[nth];
    }
    else if (nums2Size == 0)
    {
        return nums1[nth];
    }

    if (nth >= nums1Size)
    {
        int index = nth - nums1Size;
        int f = bSearch(nums1, nums1Size, nums2[index]);
        if (f == nums1Size)
            return nums2[index];
        return findNth(&nums1[f], nums1Size - f, &nums2[nth - nums1Size + 1], nums2Size - nth + nums1Size - 1, nums1Size - f - 1);
    }
    else
    {
        int f = bSearch(nums2, nums2Size, nums1[nth]);
        if (!f)
            return nums1[nth];
        return findNth(nums1, nth, nums2, f, nth);
    }
}

/* Olog(mn) */
double findMedianSortedArrays_2(int* nums1, int nums1Size, int *nums2, int nums2Size)
{
    int* max;
    int* min;
    int maxSize, minSize;
    int num = ((nums1Size + nums2Size) & 1) ? 1 : 2;
    int index = (nums1Size + nums2Size) / 2;
    index -= num == 2 ? 1 : 0;

    if (num == 1)
        return findNth(nums1, nums1Size, nums2, nums2Size, index);
    else
        return (findNth(nums1, nums1Size, nums2, nums2Size, index) +
                findNth(nums1, nums1Size, nums2, nums2Size, index + 1)) / 2.0;

}
