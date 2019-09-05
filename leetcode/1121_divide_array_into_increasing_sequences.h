// why hard ?
bool canDivideIntoSubsequences(int* nums, int numsSize, int K)
{
    int max = 0;
    int num = 1;
    int pre = nums[0];

    for (int i = 1; i < numsSize; i ++)
    {
        if (nums[i] == pre)
            num ++;
        else
        {
            if (num > max)
                max = num;

            if (max * K > numsSize)
                return false;

            num = 1;
            pre = nums[i];
        }
    }
    if (num > max)
        max = num;
    return max * K <= numsSize;
}

