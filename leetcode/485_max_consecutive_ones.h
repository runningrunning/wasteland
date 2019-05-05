int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int a = 0;
    int c = 0;

    printf("%d.\n", numsSize);
    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i])
            a ++;
        else
        {
            if (a > c)
                c = a;
            a = 0;
        }
    }
    return a > c ? a : c;
}
