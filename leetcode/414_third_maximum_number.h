int thirdMax(int* nums, int numsSize)
{
    int max_1 = INT_MIN;
    int max_2 = INT_MIN;
    int max_3 = INT_MIN;

    bool has_min = false;

    int t;
    for (int i = 0; i < numsSize; i ++)
    {
        int x = nums[i];

        if (x == INT_MIN)
        {
            has_min = true;
            continue;
        }

        if (x >= max_1)
        {
            if (x != max_1)
            {
                max_3 = max_2;
                max_2 = max_1;
                max_1 = x;
            }
        }
        else if (x >= max_2)
        {
            if (x != max_2)
            {
                max_3 = max_2;
                max_2 = x;
            }
        }
        else if (x > max_3)
        {
            max_3 = x;
        }
    }

    if (max_3 != INT_MIN)
        return max_3;

    if (max_2 != INT_MIN && has_min)
        return INT_MIN;
    return max_1;
}
