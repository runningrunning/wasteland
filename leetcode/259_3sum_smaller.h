// stupid wrong algorithm
// 2 points is O(n*n), as the inner points are only n
void tss_sort(int* nums, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (nums[s] > nums[e])
    {
        t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(nums[i] < nums[s]) i ++;
        while(nums[e] > nums[s]) e --;

        if (i >= e)
        {
            t = nums[s];
            nums[s] = nums[e];
            nums[e] = t;
        }
        else
        {
            t = nums[i];
            nums[i] = nums[e];
            nums[e] = t;
        }
    }

    tss_sort(nums, cs, e - 1);
    tss_sort(nums, e + 1, ce);
}

/* O(n * n) */
int threeSumSmaller(int* nums, int numsSize, int target)
{
    if (numsSize < 3)
        return 0;

    if (numsSize == 3)
        return nums[0] + nums[1] + nums[2] < target ? 1 : 0;

    int all = 0;
    tss_sort(nums, 0, numsSize - 1);

    if (nums[0] + nums[1] + nums[2] >= target)
        return 0;

    int t;
    int pre = nums[0] + nums[1];
    for (int i = numsSize - 1; i >= 2; i --)
    {
        t = target - nums[i];

        if (pre >= t)
            continue;

        if (nums[i - 1] + nums[i - 2] < t)
        {
            all += (i + 1) * i * (i - 1)/ 6;
            break;
        }

        int s = 0;
        int e = i - 1;

        // two points here
        while (s < e)
        {
            int o = nums[s] + nums[e];

            while(o >= t)
                o = nums[s] + nums[-- e];

            if (e > s)
                all += e - s;
            s ++;
        }

        /* while (e < i) */
        /* { */
        /*     int tt = t - nums[s]; */

        /*     if (nums[e] >= tt) */
        /*         break; */

        /*     while (nums[e + 1] < tt && e < i - 1) */
        /*         e ++; */
        /*     printf("e %d s %d.\n", e, s); */

        /*     all += e - s; */
        /*     s ++; */
        /*     e = s + 1; */
        /* } */
    }
    return all;
}
