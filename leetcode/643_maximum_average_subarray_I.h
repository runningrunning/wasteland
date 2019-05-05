double findMaxAverage(int* nums, int numsSize, int k)
{
    if (k > numsSize)
        return 0.0;

    double max = 0.0;
    double cur = 0.0;
    for (int i = 0; i < k; i ++)
        cur += nums[i];
    max = cur / k;

    int pre = 0;
    for (int i = k; i < numsSize; i ++)
    {
        cur += nums[i] - nums[pre];
        if (nums[i] > nums[pre])
        {
            double t = cur / k;
            if (max < t)
                max = t;
        }
        pre ++;
    }

    return max;
}
