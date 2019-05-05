char* optimalDivision(int* nums, int numsSize)
{
    char* ret = malloc(256);
    memset(ret, 0, 256);
    if (numsSize == 1)
        sprintf(ret, "%d", nums[0]);
    else if (numsSize == 2)
        sprintf(ret, "%d/%d", nums[0], nums[1]);
    else
    {
        int i = sprintf(ret, "%d/(%d", nums[0], nums[1]);
        for (int x = 2; x < numsSize; x ++)
            i += sprintf(&ret[i], "/%d", nums[x]);
        sprintf(&ret[i], ")");
    }
    return ret;
}
