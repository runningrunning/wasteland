// find better way to optimize this problem
bool increasingTriplet(int* nums, int numsSize)
{
    /* int min = INT_MAX; */
    /* int max; */
    /* bool got_max = false; */

    /* for (int i = 0; i < numsSize - 1; i ++) */
    /* { */
    /*     if (nums[i] < min) */
    /*         min = nums[i]; */

    /*     if (nums[i + 1] <= nums[i]) */
    /*     { */
    /*         if (got_max && nums[i] > max) */
    /*             return true; */
    /*     } */
    /*     else */
    /*     { */
    /*         if (nums[i] > min) */
    /*             return true; */

    /*         if (!got_max) */
    /*             max = nums[i + 1]; */
    /*         else */
    /*         { */
    /*             if (nums[i + 1] > max) */
    /*                 return true; */
    /*             max = nums[i + 1]; */
    /*         } */
    /*         got_max = true; */
    /*     } */
    /* } */
    /* return false; */

    int latest_min = INT_MAX;
    int m0 = INT_MAX - 1;
    int m1 = INT_MAX;

    for (int i = 0; i < numsSize; i ++)
    {
        int t = nums[i];

        if (t > m1)
            return true;

        if (t == m1 || t == m0)
            continue;

        if (t > m0)
            m1 = t;
        else
        {
            if (latest_min < m0)
            {
                if (t > latest_min)
                {
                    m0 = latest_min;
                    m1 = t;
                }
                else
                    latest_min = t;
            }
            else
                latest_min = t;
        }
    }

    return false;
}
