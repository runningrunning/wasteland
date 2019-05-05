int comp (const void * elem1, const void * elem2)
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    int** ret = malloc(sizeof(int*) * 64);
    qsort (nums, numsSize, sizeof(int), comp);
    int num = 0;
    for(int i = 0; i < numsSize - 2; i ++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        if (nums[i] > 0)
            break;

        int s = i + 1;
        int e = numsSize - 1;
        int pre_s = nums[i + 1] - 1;
        while(s < e)
        {
            if (pre_s == nums[s])
            {
                s ++;
                continue;
            }
            int sum = nums[i] + nums[s] + nums[e];
            if (sum == 0)
            {
                ret[num] = malloc(sizeof(int) * 3);
                ret[num][0] = nums[i];
                ret[num][1] = nums[s];
                ret[num][2] = nums[e];
                num ++;
                if (!(num % 64))
                    ret = realloc(ret, sizeof(int*) * (num + 64));
                pre_s = nums[s];
                s ++;
                e --;
            }
            else if (sum < 0)
            {
                pre_s = nums[s];
                s ++;
            }
            else if (sum > 0)
            {
                e --;
            }

        }

        /* for(int j = i + 1; j < numsSize - 1; j++) */
        /* { */
        /*     if (j > i + 1 && nums[j] == nums[j - 1]) */
        /*         continue; */

        /*     if (nums[i] + nums[j] > 0) */
        /*         break; */
        /*     int k = -(nums[i] + nums[j]); */
        /*     int* b = bsearch(&k, &nums[j + 1], numsSize - j - 1, sizeof(int), comp); */
        /*     if (b) */
        /*     { */
        /*         ret[num] = malloc(sizeof(int) * 3); */
        /*         ret[num][0] = nums[i]; */
        /*         ret[num][1] = nums[j]; */
        /*         ret[num][2] = *b; */
        /*         num ++; */
        /*         if (!(num % 64)) */
        /*             ret = realloc(ret, sizeof(int*) * (num + 64)); */
        /*     } */
        /* } */
    }
    *returnSize = num;
    return ret;
}
