/* THINKING TOO MUCH */
/* need to know about function x = -b / 2a is the limit value of */
/* a * x * x + b * x + c */
/* the limit value is (4ac - b * b) / 4 * a */
/* NO NEED TO DO SO !!!! */

/* in C language -10 / 6 is -1, not -2 */
/* even (int)(-10.0/6.0) is -1 also */
/* in C language (int) float JUST REMOVE anything not INT, DONOT USE THIS !!! */

/* For this questions, there is no need to use bsearch or any math to do so, if we generate values at the first */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
int* sortTransformedArray(int* nums, int numsSize, int a, int b, int c, int* returnSize)
{
    if (!nums || !numsSize)
        return NULL;

    *returnSize = numsSize;
    int* ret = malloc(sizeof(int) * numsSize);

    if (a == 0)
    {
        if (b > 0)
        {
            for (int i = 0; i < numsSize; i ++)
                ret[i] = b * nums[i] + c;
        }
        else
        {
            for (int i = 0; i < numsSize; i ++)
                ret[numsSize - i - 1] = b * nums[i] + c;
        }
        return ret;
    }

    if (numsSize == 1)
    {
        ret[0] = a * nums[0] * nums[0] + b * nums[0] + c;
        return ret;
    }

    // must choose the floor or ceil depends on whether is >< 0
    double xx = (- b) / (a * 2.0);
    int x = (int)(xx > 0.0 ? (xx + 0.5) : (xx - 0.5));
    int s = 0;
    int e = numsSize - 1;

    while (s < e)
    {
        int m = s + (e - s) / 2;
        if (nums[m] > x)
            e = m;
        else
            s = m + 1;
    }

    int s1 = s - 1;
    int s2 = s;

    if (!s)
    {
        s1 = s;
        s2 = s + 1;
    }

    int sp_st, sp_end;
    int sm_st, sm_end;

    if (a > 0)
    {
        sp_st = s2;
        sp_end = numsSize - 1;

        sm_st = s1;
        sm_end = 0;
    }
    else
    {
        sp_st = 0;
        sp_end = s1;
        sm_st = numsSize - 1;
        sm_end = s2;
    }

    int i = 0;
    for (int i = 0; i < numsSize; i ++)
        nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;

    while (sm_st >= sm_end || sp_st <= sp_end)
    {
        if (sm_st >= sm_end)
        {
            while (sp_st > sp_end || nums[sm_st] <= nums[sp_st])
            {
                ret[i ++] = nums[sm_st --];
                if (sm_st < sm_end)
                    break;
            }
        }

        if (sp_st <= sp_end)
        {
            while (sm_st < sm_end || nums[sm_st] > nums[sp_st])
            {
                ret[i ++] = nums[sp_st ++];
                if (sp_st > sp_end)
                    break;
            }
        }
    }
    return ret;
}
*/

int* sortTransformedArray(int* nums, int numsSize, int a, int b, int c, int* returnSize)
{
    if (!nums || !numsSize)
        return NULL;

    *returnSize = numsSize;
    int* ret = malloc(sizeof(int) * numsSize);

    int min_i = -1;
    int max_i = -1;
    int min_v = INT_MAX;
    int max_v = INT_MIN;

    for (int i = 0; i < numsSize; i ++)
    {
        nums[i] = a * nums[i] * nums[i] + b * nums[i] + c;
        if (nums[i] > max_v)
        {
            max_i = i;
            max_v = nums[i];
        }

        if (nums[i] < min_v)
        {
            min_i = i;
            min_v = nums[i];
        }
    }

    if (a == 0)
    {
        if (b > 0)
            memcpy(ret, nums, sizeof(int) * numsSize);
        else
            for (int i = 0; i < numsSize; i ++)
                ret[i] = nums[numsSize - 1 - i];
        return ret;
    }

    /* if (a == 0) */
    /* { */
    /*     if (b > 0) */
    /*     { */
    /*         for (int i = 0; i < numsSize; i ++) */
    /*             ret[i] = b * nums[i] + c; */
    /*     } */
    /*     else */
    /*     { */
    /*         for (int i = 0; i < numsSize; i ++) */
    /*             ret[numsSize - i - 1] = b * nums[i] + c; */
    /*     } */
    /*     return ret; */
    /* } */

    /* if (numsSize == 1) */
    /* { */
    /*     ret[0] = a * nums[0] * nums[0] + b * nums[0] + c; */
    /*     return ret; */
    /* } */

    /* // must choose the floor or ceil depends on whether is >< 0 */
    /* double xx = (- b) / (a * 2.0); */
    /* int x = (int)(xx > 0.0 ? (xx + 0.5) : (xx - 0.5)); */
    /* int s = 0; */
    /* int e = numsSize - 1; */

    /* while (s < e) */
    /* { */
    /*     int m = s + (e - s) / 2; */
    /*     if (nums[m] > x) */
    /*         e = m; */
    /*     else */
    /*         s = m + 1; */
    /* } */

    /* int s1 = s - 1; */
    /* int s2 = s; */

    /* if (!s) */
    /* { */
    /*     s1 = s; */
    /*     s2 = s + 1; */
    /* } */

    int sp_st, sp_end;
    int sm_st, sm_end;

    if (a > 0)
    {
        sp_st = min_i;
        sp_end = numsSize - 1;

        sm_st = min_i - 1;
        sm_end = 0;
    }
    else
    {
        sp_st = 0;
        sp_end = max_i;
        sm_st = numsSize - 1;
        sm_end = max_i + 1;
    }

    int i = 0;

    while (sm_st >= sm_end || sp_st <= sp_end)
    {
        while (sm_st >= sm_end)
        {
            if (sp_st > sp_end || nums[sm_st] <= nums[sp_st])
                ret[i ++] = nums[sm_st --];
            else
                    break;
        }

        while (sp_st <= sp_end)
        {
            if (sm_st < sm_end || nums[sm_st] > nums[sp_st])
                ret[i ++] = nums[sp_st ++];
            else
                break;
        }
    }
    return ret;
}
