/* STUPID WRONG ALGORITHM */
/* TODO find another algorithm */
// can be 50% reduce in performance

int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    if (!nums || !numsSize || k < 2)
        return 0;

    int x = 1;
    int s = 0;
    int i = 0;
    int pi = -1;
    int num = 0;

    for (i = 0; i < numsSize; i ++)
    {
        x = x * nums[i];
        if (x >= k)
        {
            // s - i is needed
            num += (i - s + 1) * (i - s) / 2;

            // printf("x %d k %d pi %d s %d num is %d %d %d.\n", x, k, pi, s,  num, s, i);
            if (pi >= s)
                num -= (pi - s + 1) * (pi - s + 2)/ 2;

            pi = i - 1;
            while (x >= k)
                x /= nums[s ++];
        }
    }
    // printf("x %d k %d pi %d s %d num is %d %d %d.\n", x, k, pi, s,  num, s, i);
    num += (i - s + 1) * (i - s) / 2;
    if (pi >= s)
        num -= (pi - s + 1) * (pi - s + 2)/ 2;
    return num;
}


int numSubarrayProductLessThanK_3(int* nums, int numsSize, int k)
{
    if (!nums || !numsSize || k < 2)
        return 0;

    int x = 1;
    int s = 0;
    int num = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] == 1)
            num += (i + 1 - s);
        else if (nums[i] >= k)
        {
            x = 1;
            s = i + 1;
        }
        else
        {
            x *= nums[i];
            while (x >= k)
                x /= nums[s ++];
            if (x > 1)
            {
                // printf("- add %d.\n", i + 1 - s);
                num += (i + 1 - s);
            }
        }
    }
    return num;
}

/*
Can not, it will overflow at the most time
int numSubarrayProductLessThanK(int* nums, int numsSize, int _k)
{
    if (!nums || !numsSize || _k < 2)
        return 0;

    int ok = _k;

    long k = _k;
    long x = 1;
    int s = 0;
    int num = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        if (nums[i] == 1)
        {
            num += (i + 1 - s);

            if (i)
                nums[i] = nums[i - 1];
        }
        else if (nums[i] >= ok)
        {
            k = ok;
            x = 1;
            s = i + 1;
        }
        else
        {
            x *= nums[i];
            nums[i] = x;

            if (x >= k)
            {
                int st = s;
                int en = i;
                // printf("start %d %d. \n", s, i);
                while (st < en)
                {
                    int m = (st + en) / 2;
                    if ((x / nums[m]) >= ok)
                        st = m + 1;
                    else
                        en = m;
                }
                k = ok * nums[st];
                s = st + 1;
                // printf("%d %d %d %d add %d.\n", i, s, num, k, i + 1 - s);

                if (i + 1 - s > 0)
                    num += (i + 1 - s);

            }
            else
            {
                //printf(" = add %d.\n", i + 1 - s);
                num += (i + 1 - s);
            }
        }
    }
    return num;
}
*/


int numSubarrayProductLessThanK_2(int* nums, int numsSize, int k)
{
    int num = 0;
    for (int i = 0; i < numsSize; i ++)
    {
        int x = nums[i];
        if (x < k)
            num ++;

        for (int j = i + 1; j < numsSize; j ++)
        {
            x *= nums[j];
            if (x < k)
                num ++;
            else
                break;
        }
    }
    return num;
}
