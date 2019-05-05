/* void aHeap(long* h, int hi, long v) */
/* { */
/* } */

/* void rHeap(long* h, int hi) */
/* { */
/* } */

double findMaxAverage(int* n, int numsSize, int k)
{
    if (k > numsSize)
        return 0.0;

    int* nums = malloc(sizeof(int) * (numsSize + 1));
    nums[0] = 0;

    for (int i = 0; i < numsSize; i ++)
        nums[i + 1] = nums[i] + n[i];

    numsSize ++;

    double cur = ((double) nums[k]) / ((double) k);
    double max = cur;

    /* int hi = 0; */
    /* long* heap = malloc(sizeof(long) * (numsSize - k + 1)); */
    /* aHeap(heap, hi ++, ((long) nums[0]) << 32) | (numsSize - 0); */

    /* out(nums, numsSize); */
    /* printf("%lf %lf %d.\n", max, cur, nums[k]); */

    int p = 0;
    int s = 0;

    for (int i = k; i < numsSize; i ++)
    {
        double d;

        if (i - k != s)
        {
            d = ((double) (nums[i - k] - nums[s])) / (double) (i - k - s);
            if (d <= max)
            {
                p = nums[i - k];
                s = i - k;
            }
        }

        d = max * (i - s) + nums[s];

        if (d <= nums[i])
        {
            int t = s;
            for (int j = s; j <= i - k; j ++)
            {
                d = ((double) (nums[i] - nums[j])) / ((double) (i - j));
                if (d >= max)
                {
                    max = d;
                    t = j;
                }
            }
            p = nums[t];
            s = t;
        }
    }
    return max;
}

/* double findMaxAverage(int* nums, int numsSize, int k) */
/* { */
/*     for (int i = 1; i < numsSize; i ++) */
/*         nums[i] += nums[i - 1]; */
/*     double max = ((double) nums[k - 1]) / (double) k; */
/*     for (int i = k; i < numsSize; i ++) */
/*     { */
/*         for (int j = 0; j <= i - k; j ++) */
/*         { */
/*             double t = ((double) (nums[i] - nums[j])) / ((double) (i - j)); */
/*             { */
/*                 if (t > max) */
/*                 { */
/*                     printf("i %d. j %d.\n", i, j); */
/*                     max = t; */
/*                 } */
/*             } */
/*         } */
/*     } */
/*     return max; */
/* } */

/*
double findMaxAverage(int* nums, int numsSize, int k)
{
    if (k > numsSize)
        return 0.0;

    double cur = 0.0;
    double max = 0.0;
    for (int i = 0; i < k; i         cur += nums[i];
    max = cur / k;

    double t;
    int k_start = 0;

    int k_pre = 0;
    double pre = 0.0;
    for (int i = k; i < numsSize; i ++)
    {
        pre += nums[k_start];
        cur += nums[i] - nums[k_start];
        if (nums[i] > nums[k_start])
        {
            t = cur / k;
            if (max < t)
                max = t;
        }
        k_start ++;

        while(k_pre < k_start)
        {
            t = pree ++;
        }
    }
    return max;
}
*/
