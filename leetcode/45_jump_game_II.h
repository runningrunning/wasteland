int jump(int* nums, int numsSize)
{
    if (numsSize < 2)
        return 0;

    if (numsSize == 2)
        return 1;

    int sc = 0;
    int* step = malloc(sizeof(int) * numsSize);
    step[sc] = numsSize - 1;
    step[++ sc] = numsSize - 2;
    nums[numsSize - 2] = 1;
    nums[numsSize - 1] = 0x7FFFFFF - 1 - numsSize;

    for(int i = 2; i < numsSize; i ++)
    {
        int ti = numsSize - i - 1;
        int c = ti  + nums[ti];

        while(c >= step[sc])
        {
            if (c >= step[sc] + nums[step[sc]])
            {
                nums[ti] = step[sc] + nums[step[sc]] - ti;
                step[sc --] = ti;
            }
            else
            {
                nums[ti] = step[sc] - ti;
                step[++ sc] = ti;
                break;
            }
        }
    }
    return sc;
}
