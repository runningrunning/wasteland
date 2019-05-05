// TODO BETTER SOLUTION !!!
// REDO AGAIN
bool find132pattern(int* nums, int numsSize)
{
    if (numsSize < 3)
        return false;

    int a_max = 0;
    int a_min = 0;

    bool has_max = false;
    int max = nums[0];
    int min = nums[0];

    int mi = 0;

    for (int i = 1; i < numsSize; i ++)
    {
        int x = nums[i];
        if (mi && x < a_max && x > a_min)
        {
            for (int j = mi - 1; j >= 0; j -= 2)
            {
                if (x > nums[j - 1] && x < nums[j])
                    return true;
            }
        }

        if (x >= max)
        {
            has_max = true;
            max = x;
        }
        else if (x <= min)
        {
            if (has_max)
            {
                nums[mi ++] = min;
                nums[mi ++] = max;

                if (a_max < max)
                    a_max = max;

                if (a_min > min)
                    a_min = min;
            }
            min = x;
            max = x;
            has_max = false;
        }
        else
        {
            return true;
        }
    }
    return false;
}
