/* 96 ms */
int* twoSum(int* num, int numSize, int target)
{
    int i, j;
    int *ret = malloc(sizeof(int) * 2);
    for (i = 0; i < numSize - 1; i ++)
    {
        for (j = i + 1; j < numSize; j ++)
        {
            if (num[i] + num[j] == target)
            {
                ret[0] = i;
                ret[1] = j;
                return ret;
            }
        }
    }
    return 0;
}
