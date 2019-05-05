/* TODO rework */
/* void _me_sort(int *nums, int s, int e, int n) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     int t; */
/*     int cs = s; */
/*     int ce = e; */
/*     if (nums[s] > nums[e]) */
/*     { */
/*         t = nums[s]; */
/*         nums[s] = nums[e]; */
/*         nums[e] = t; */
/*     } */

/*     if (s + 1 == e) */
/*         return; */

/*     int nlow = 0; */
/*     int nlar = 0; */
/*     for(int i = s + 1; i <= e; i ++) */
/*     { */
/*         while(nums[i] < nums[s]) */
/*         { */
/*             i ++; */
/*             nlow ++; */
/*         } */
/*         while(nums[e] > nums[s]) */
/*         { */
/*             e --; */
/*             nlar ++; */
/*         } */

/*         if (i >= e) */
/*         { */
/*             if (nums[e] != nums[s]) */
/*             { */
/*                 t = nums[e]; */
/*                 nums[e] = nums[s]; */
/*                 nums[s] = t; */
/*             } */
/*         } */
/*         else */
/*         { */
/*             t = nums[i]; */
/*             nums[i] = nums[e]; */
/*             nums[e] = t; */
/*         } */
/*     } */

/*     if (cs - ce + 1 - nlow - nlar > n) */
/*     { */
/*         nums[n] = nums[e]; */
/*         return; */
/*     } */
/*     if (e == n) */
/*         return; */

/*     if (n < e) */
/*         _me_sort(nums, cs, e - 1, n); */
/*     else */
/*         _me_sort(nums, e + 1, ce, n); */
/* } */

/* int majorityElement(int* nums, int numsSize) */
/* { */
/*     if (!numsSize || !nums) */
/*         return 0; */

/*     if (numsSize <= 2) */
/*         return nums[0]; */

/*     _me_sort(nums, 0, numsSize - 1, numsSize / 2); */
/*     return nums[numsSize / 2]; */
/* } */


int majorityElement(int* nums, int numsSize)
{
    
}
