/* TODO, it's not that easy, it's DP */
/* how to setup dp endpoint ? NOT NEED FOR THIS CASE*/
/* be careful about all of valid inputs, e.g. all 0s. */
/* try better DP solutions !! */
/* USE ARRAY TO REMOVE DP */
/* no need for temporary array, as it's stored in itself */
/* WE DONOT NEED TO USE ARRAY AT ALL */
/* Need to understand code */

int rob(int* nums, int numsSize)
{
    if (numsSize <= 1)
        return numsSize == 1 ? nums[0] : 0;
    int e = numsSize - 1;

    /*
    // use array not recursive from back to front
    nums[e] = nums[e];
    nums[e - 1] = nums[e] > nums[e - 1] ? nums[e] : nums[e - 1];

    int s;
    int pre = nums[e - 1];

    for (int i = e - 2; i >= 0; i --)
    {
        s = nums[i] + nums[i + 2];
        pre = nums[i] = s > pre ? s : pre;
    }
    return nums[0];
    */

    // use array not recursive from front to end
    nums[1] = nums[1] > nums[0] ? nums[1] : nums[0];

    int s;
    int pre = nums[1];

    for (int i = 2; i < numsSize; i ++)
    {
        s = nums[i] + nums[i - 2];
        pre = nums[i] = s > pre ? s : pre;
    }
    return nums[numsSize - 1];
}

/* int rob_dp(int* nums, int s, int e, int* tmp) */
/* { */
/*     if (s > e) */
/*         return 0; */

/*     if (tmp[s] == -1) */
/*     { */
/*         int x1 = nums[s] + rob_dp(nums, s + 2, e, tmp); */
/*         int x2 = rob_dp(nums, s + 1, e, tmp); */
/*         tmp[s] = x1 > x2 ? x1 : x2; */
/*     } */
/*     return tmp[s]; */
/* } */

/* int rob(int* nums, int numsSize) */
/* { */
/*     int* tmp = malloc(sizeof(int) * numsSize); */
/*     for (int i = 0; i < numsSize; i ++) */
/*         tmp[i] = -1; */
/*     return rob_dp(nums, 0, numsSize - 1, tmp); */
/* } */

/*
int rob_dp(int cur, int* nums, int s, int e, int* max, int* tmp)
{
    if (s > e)
        return 0;

    if (tmp[s] >= 0)
        return tmp[s];

    int x1 = nums[s] + rob_dp(cur + nums[s], nums, s + 2, e, max, tmp);
    int x2 = rob_dp(cur, nums, s + 1, e, max, tmp);
    tmp[s] = x1 > x2 ? x1 : x2;
    return tmp[s];
}

int rob(int* nums, int numsSize)
{
    int pre = 0;
    int* max = malloc(sizeof(int) * numsSize);
    for (int i = numsSize - 1; i >= 0; i --)
    {
        max[i] = nums[i] + pre;
        pre += nums[i];
    }
    int* tmp = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i ++)
        tmp[i] = -1;

    return rob_dp(0, nums, 0, numsSize - 1, max, tmp);
}

int rob(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int m = nums[0];
    nums[0] = - nums[0];

    for(int i = 1; i < numsSize; i ++)
    {
        if (nums[i - 1] > 0)
        {
            m += nums[i];
            nums[i] = - nums[i];
        }
        else
        {
            int o1 = i > 1 ? nums[i - 2] : 0;
            int o2 = i > 2 ? nums[i - 3] : 0;

            if (o2 < 0)
                o1 = 0;

            if (o1 + nums[i] > - nums[i - 1])
            {
                m += nums[i - 1];
                m += o1 + nums[i];
                nums[i] = - nums[i];
                nums[i - 1] = - nums[i - 1];

                if (o1)
                    nums[i - 2] = - nums[i - 2];
            }
        }
    }

    return m;
}
*/
