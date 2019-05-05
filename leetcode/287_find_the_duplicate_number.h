
int findDuplicate(int* nums, int numsSize)
{
#define COUNT 512

    int a[COUNT] = {0};
    a[numsSize % COUNT] ++;

    for (int i = 0; i < numsSize; i ++)
    {
        a[(i + 1) % COUNT] --;
        a[nums[i] % COUNT] ++;
    }


    int c_max = 0;
    int max = INT_MIN;

    for (int i = 0; i < COUNT; i ++)
    {
        if (max < a[i])
        {
            max = a[i];
            c_max = i;
        }
    }

    int s = c_max;
    while(s < numsSize)
    {
        int count = 0;
        for (int i = 0; i < numsSize; i ++)
        {
            if (nums[i] == s)
                count ++;
            if (count > 1)
                return s;
        }
        s += COUNT;
    }

    return -1;
}

