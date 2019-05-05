/* int comp (const void * elem1, const void * elem2) */
/* { */
/*     int f = *((int*)elem1); */
/*     int s = *((int*)elem2); */
/*     if (f > s) return  1; */
/*     if (f < s) return -1; */
/*     return 0; */
/* } */

int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort (nums, numsSize, sizeof(int), comp);
    int min_diff = 0;
    int t = 0;
    for(int i = 0; i < numsSize - 2; i ++)
    {
        int s = i + 1;
        int e = numsSize - 1;
        while(s < e)
        {
            int diff = nums[i] + nums[s] + nums[e] - target;

            if (diff == 0)
                return target;

            if (!min_diff || abs(diff) < min_diff)
            {
                min_diff = abs(diff);
                t = diff + target;
            }

            if (diff < 0)
            {
                s ++;
            }
            else if (diff > 0)
            {
                e --;
            }

        }
    }
    return t;
}
