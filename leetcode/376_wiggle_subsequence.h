// corner case again !!!!, check NULL
int wiggleMaxLength(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int len = 1;

    bool large = true;
    int min = nums[0];
    int max = nums[0];

    // start large
    for (int i = 1; i < numsSize; i ++)
    {
        if (large)
        {
            if (nums[i] > min)
            {
                len ++;
                large = false;
                max = nums[i];
            }
            else
                min = nums[i];
        }
        else
        {
            if (nums[i] < max)
            {
                len ++;
                large = true;
                min = nums[i];
            }
            else
                max = nums[i];
        }
    }

    int t = len;

    len = 1;

    min = max = nums[0];

    large = false;
    // start small
    for (int i = 1; i < numsSize; i ++)
    {
        if (large)
        {
            if (nums[i] > min)
            {
                len ++;
                large = false;
                max = nums[i];
            }
            else
                min = nums[i];
        }
        else
        {
            if (nums[i] < max)
            {
                len ++;
                large = true;
                min = nums[i];
            }
            else
                max = nums[i];
        }
    }
    return len > t ? len : t;
}
