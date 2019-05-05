int maximumProduct(int* nums, int numsSize)
{
    if (numsSize == 3)
        return nums[0] * nums[1] * nums[2];


    int max_1 = INT_MIN;
    int max_2 = INT_MIN;
    int max_3 = INT_MIN;

    int min_1 = INT_MAX;
    int min_2 = INT_MAX;

    for (int i = 0; i < numsSize; i ++)
    {
        int n = nums[i];
        if (n >= max_1)
        {
            max_3 = max_2;
            max_2 = max_1;
            max_1 = n;
        }
        else if (n >= max_2)
        {
            max_3 = max_2;
            max_2 = n;
        }
        else if (n >= max_3)
            max_3 = n;

        if (n <= min_1)
        {
            min_2 = min_1;
            min_1 = n;
        }
        else if (n <= min_2)
        {
            min_2 = n;
        }
    }

    int px = max_1 * max_2 * max_3;
    int pl = max_1 * min_1 * min_2;
    return px > pl ? px : pl;
}

/* TODO Think TOO MUCH !!!! */
/* int maximumProduct(int* nums, int numsSize)
{
    if (numsSize == 3)
        return nums[0] * nums[1] * nums[2];

    int n = 0;
    int all[2001] = {0};

    int l0_max_i = 1000;
    int l0_min_i = 2000;
    int m0_max_i = 0;
    int m0_min_i = 1000;

    int l0 = 0;
    int m0 = 0;

    bool has0 = false;
    for (int i = 0; i < numsSize; i ++)
    {
        if (!nums[i])
        {
            has0 = true;
            continue;
        }

        n = nums[i] + 1000;

        if (n > 1000)
        {
            l0 ++;

            if (n > l0_max_i)
                l0_max_i = n;

            if (n < l0_min_i)
                l0_min_i = n;
        }
        else
        {
            m0 ++;

            if (n < m0_min_i)
                m0_min_i = n;

            if (n > m0_max_i)
                m0_max_i = n;
        }
        all[n] ++;
    }

    if (l0 >= 3)
    {
        if (m0 > 1)
        {
            int p_min = 0;
            if (all[m0_min_i] > 1)
                p_min = (m0_min_i - 1000) * (m0_min_i - 1000) * (l0_max_i - 1000);
            else
            {
                for (int i = m0_min_i + 1; i < 1000; i ++)
                    if (all[i])
                    {
                        p_min =  (l0_max_i - 1000) * (m0_min_i - 1000) * (i - 1000);
                        break;
                    }
            }

            int p_max = 0;

            if (all[l0_max_i] > 1)
            {
                if (all[l0_max_i] > 2)
                {
                    p_max = (l0_max_i - 1000) * (l0_max_i - 1000) * (l0_max_i - 1000);
                    return p_max > p_min ? p_max : p_min;
                }

                for (int i = l0_max_i - 1; i > 1000; i --)
                    if (all[i])
                    {
                        p_max = (l0_max_i - 1000) * (l0_max_i - 1000) * (i - 1000);
                        return p_max > p_min ? p_max : p_min;
                    }
            }
            else
            {
                for (int i = l0_max_i - 1; i > 1000; i --)
                    if (all[i])
                    {
                        if (all[i] > 1)
                        {
                            p_max = (l0_max_i - 1000) * (i - 1000) * (i - 1000);
                            return p_max > p_min ? p_max : p_min;
                        }
                        else
                        {
                            for (int j = i - 1; j > 1000; j --)
                                if (all[j])
                                {
                                    p_max = (l0_max_i - 1000) * (i - 1000) * (j - 1000);
                                    return p_max > p_min ? p_max : p_min;
                                }
                        }
                    }
            }
        }
        else
        {
            if (all[l0_max_i] > 1)
            {
                if (all[l0_max_i] > 2)
                    return (l0_max_i - 1000) * (l0_max_i - 1000) * (l0_max_i - 1000);

                for (int i = l0_max_i - 1; i > 1000; i --)
                    if (all[i])
                        return (l0_max_i - 1000) * (l0_max_i - 1000) * (i - 1000);
            }
            else
            {
                for (int i = l0_max_i - 1; i > 1000; i --)
                    if (all[i])
                    {
                        if (all[i] > 1)
                            return (l0_max_i - 1000) * (i - 1000) * (i - 1000);

                        for (int j = i - 1; j > 1000; j --)
                            if (all[j])
                                return (l0_max_i - 1000) * (i - 1000) * (j - 1000);
                    }
            }
        }
    }
    else
    {
        if (!l0)
        {
            if (has0)
                return 0;
            else
            {
                if (all[m0_max_i] > 1)
                {
                    for (int i = m0_min_i - 1; i >= 0; i --)
                        if (all[i])
                            return (m0_max_i - 1000) * (m0_max_i - 1000) * (i - 1000);
                }
                else
                {
                    for (int i = m0_min_i - 1; i >= 0; i --)
                        if (all[i])
                        {
                            if (all[i] > 1)
                                return (m0_max_i - 1000) * (i - 1000) * (i - 1000);

                            for (int j = i - 1; j >= 0; j --)
                                if (all[j])
                                    return (m0_max_i - 1000) * (i - 1000) * (j - 1000);
                        }
                }
            }
        }

        if (all[m0_min_i] > 1)
            return (l0_max_i - 1000) * (m0_min_i - 1000) * (m0_min_i - 1000);

        for (int i = m0_min_i + 1; i < 1000; i ++)
            if (all[i])
                return (l0_max_i - 1000) * (m0_min_i - 1000) * (i - 1000);
    }

    return 0;
}
*/

