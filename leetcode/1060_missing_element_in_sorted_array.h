// use binary search to optimize
/* int missingElement2(int* nums, int numsSize, int k) */
/* { */
/*     if (k > nums[numsSize - 1] - nums[0] + 1 - numsSize) */
/*         return k + nums[0] - 1 + numsSize; */

/*     int last; */
/*     for (int i = 0; i < numsSize; i ++) */
/*     { */
/*         last = nums[i]; */
/*         if (i != numsSize - 1) */
/*         { */
/*             int d = nums[i + 1] - nums[i] - 1; */
/*             if (d >= k) */
/*                 break; */
/*             k -= d; */
/*         } */
/*     } */
/*     return last + k; */
/* } */

int missingElement(int* nums, int numsSize, int k)
{
    if (k > nums[numsSize - 1] - nums[0] + 1 - numsSize)
        return k + nums[0] - 1 + numsSize;

    int s = 0;
    int e = numsSize - 1;

    while (s < e)
    {
        int m = (s + e) / 2;
        int d = nums[m] - nums[0] + 1 - (m + 1);

        if (k > d)
            s = m + 1;
        else
            e = m;
    }
    return k + nums[0]  - 1 + s;
}
