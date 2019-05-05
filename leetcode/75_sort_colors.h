/*void color_sort(int* nums, int s, int e)
{
    if (s >= e)
        return;

    int t = 0;

    int i = s + 1;
    int j = e;

    while(true)
    {
        while(nums[j] > nums[s])
            j --;

        while(i < j && nums[i] < nums[s])
            i ++;

        if (j > i)
        {
            if (nums[i] != nums[j])
            {
                t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
            }

            j --;
            i ++;
        }

        if (j <= i)
        {
            if (nums[j] < nums[s])
            {
                t = nums[j];
                nums[j] = nums[s];
                nums[s] = t;
            }

            break;
        }
    }

    color_sort(nums, s, j - 1);
    color_sort(nums, j + 1, e);
}
*/

void color_sort(int* nums, int s, int e)
{
    if (s >= e)
        return;

    int t = 0;

    if (nums[s] > nums[e])
    {
        t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;
    }

    int i = s + 1;
    int j = e;

    while(true)
    {
        while(nums[j] > nums[s])
            j --;

        while(nums[i] < nums[s])
            i ++;

        if (j > i)
        {
            t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
            j --;
            i ++;
        }
        else if (j <= i)
        {
            t = nums[j];
            nums[j] = nums[s];
            nums[s] = t;
            break;
        }
    }

    color_sort(nums, s, j - 1);
    color_sort(nums, j + 1, e);
}

void sortColors(int* nums, int numsSize)
{
    // color_sort(nums, 0, numsSize - 1);
    int zi = 0;
    int oi = 0;
    int ti = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        int n = nums[i];
        nums[ti] = 2;

        if (n < 2)
        {
            nums[oi] = 1;
            oi ++;

            if (!n)
            {
                nums[zi] = 0;
                zi ++;
            }
        }
        ti ++;
    }
    return;
}


