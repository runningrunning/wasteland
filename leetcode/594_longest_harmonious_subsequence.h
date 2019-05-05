/* TODO DO IT AGAIN !! */
/* do search while doing partition sort !!!, so no need to sort them all ? */
/* how to divide those into 2 parts ? */
/* qsort variant, not qsort, just select sort ?? */
void flhs_sort(int* n, int s, int e, int* ret)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;
    }

    if (s + 1 == e)
    {
        if (n[e] - n[s] == 1)
        {
            if (*ret < 2)
                *ret = 2;
        }
        return;
    }

    int cs = s;
    int ce = e;

    int min = n[s];
    int max = n[s];

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s])
        {
            if (min > n[i])
                min = n[i];
            i ++;
        }
        while (n[e] > n[s])
        {
            if (max < n[e])
                max = n[e];
            e --;
        }

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;
        }
    }

    if (max - min == 1)
        *ret = ce - cs + 1;
    else if (n[e] - min == 1)
    {
        if (*ret < e - cs + 1)
            *ret = e - cs + 1;
    }

    if (*ret < e - cs)
        flhs_sort(n, cs, e - 1, ret);
    if (*ret < ce - e)
        flhs_sort(n, e + 1, ce, ret);
}

int findLHS(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int max = 0;
    flhs_sort(nums, 0, numsSize - 1, &max);

    /*
    int max = 0;
    int pre = nums[0] - 2;
    int pre_num = 0;
    int cur = nums[0];
    int cur_num = 0;

    for (int i = 1; i < numsSize; i ++)
    {
        if (nums[i] != cur)
        {
            if (cur - pre == 1)
            {
                if (max < i - pre_num)
                    max = i - pre_num;
            }

            pre = cur;
            pre_num = cur_num;

            cur = nums[i];
            cur_num = i;
        }
    }

    if (cur - pre == 1)
    {
        if (max < numsSize - pre_num)
            max = numsSize - pre_num;
    }
    */
    return max;
}
