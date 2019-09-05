// just simple binary search
int validSubarrays(int* nums, int numsSize)
{
    int i = 0;
    int all = 1;
    int top = 0;

    for (int i = 1; i < numsSize; i ++)
    {
        all ++;
        if (nums[i] < nums[top])
        {
            int s = 0;
            int e = top;
            while (s < e)
            {
                int m = (s + e) / 2;
                if (nums[m] <= nums[i])
                    s = m + 1;
                else
                    e = m;
            }
            top = s;
            nums[top] = nums[i];
        }
        else
        {
            nums[++ top] = nums[i];
        }
        all += top;
    }
    return all;
}
