/* think to much */
/* Just calculate every one's diff with min */
/* int mm_sort(int* nums, int s, int e) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     int t; */
/*     if (nums[s] > nums[e]) */
/*     { */
/*         t = nums[e]; */
/*         nums[e] = nums[s]; */
/*         nums[s] = t; */
/*     } */

/*     int cs = s; */
/*     int ce = e; */

/*     for (int i = s + 1; i <= e; i ++) */
/*     { */
/*         while (nums[i] < nums[s]) i ++; */
/*         while (nums[e] > nums[s]) e --; */

/*         if (i >= e) */
/*         { */
/*             t = nums[e]; */
/*             nums[e] = nums[s]; */
/*             nums[s] = t; */
/*         } */
/*         else */
/*         { */
/*             t = nums[e]; */
/*             nums[e] = nums[i]; */
/*             nums[i] = t; */
/*         } */
/*     } */

/*     mm_sort(nums, cs, e - 1); */
/*     mm_sort(nums, e + 1, ce); */
/* } */

int minMoves(int* nums, int numsSize)
{
    int min = INT_MAX;
    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] < min)
            min = nums[i];
    }

    int all = 0;
    for (int i = 0; i < numsSize; i ++)
        all += nums[i] - min;
    return all;
}
