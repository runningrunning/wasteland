/*
void _aps_sort(int* nums, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (nums[s] > nums[e])
    {
        t = nums[e];
        nums[e] = nums[s];
        nums[s] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;


    for (int i = s + 1; i <= e; i ++)
    {
        while(nums[i] < nums[s]) i ++;
        while(nums[e] > nums[s]) e --;

        if (i >= e)
        {
            t = nums[e];
            nums[e] = nums[s];
            nums[s] = t;
        }
        else
        {
            t = nums[e];
            nums[e] = nums[i];
            nums[i] =t;
        }
    }

    _aps_sort(nums, cs, e - 1);
    _aps_sort(nums, e + 1, ce);
}

int arrayPairSum(int* nums, int numsSize)
{
    _aps_sort(nums, 0, numsSize - 1);

    int total = 0;
    for (int i = 0; i < numsSize; i += 2)
        total += nums[i];

    return total;
}
*/

int arrayPairSum(int* nums, int numsSize)
{
    char fg[20002] = {0};

    int sum = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        int c = nums[i] + 10000;

        if (fg[c])
        {
            fg[c] = 0;
            sum += nums[i];
        }
        else
            fg[c] = 1;
    }

    bool use = true;
    for (int i = 0; i < 20002; i ++)
    {
        if (fg[i])
        {
            if (use)
            {
                use = false;
                sum += i - 10000;
            }
            else
                use = true;
        }
    }

    return sum;
}
