/* bsearch variant  */
int findUnsortedSubarray(int* nums, int numsSize)
{
    if (!nums || numsSize < 2)
        return 0;

    if (nums[0] > nums[numsSize - 1])
        return numsSize;

    if (numsSize == 2)
        return 0;

    int st = 1;
    while (st < numsSize)
    {
        if (nums[st] < nums[st - 1])
            break;
        st ++;
    }

    if (st == numsSize)
        return 0;

    int en = numsSize - 2;

    while (en >= 0)
    {
        if (nums[en] > nums[en + 1])
            break;
        en --;
    }

    while (nums[st - 1] > nums[en + 1])
    {
        st --;
        en ++;

        if (!st || en == numsSize - 1)
            break;
    }

    if (!st && en == numsSize -1)
        return numsSize;

    // 0 ~ st - 1 and en + 1 ~ numsSize - 1 is sorted;

    int ns = st ? nums[st - 1] : 0;
    int ne = (en != numsSize - 1) ? nums[en + 1] : 0;

    int end = en;

    for (int i = st; i <= end; i ++)
    {
        int n = nums[i];
        if (st)
        {
            if (n < ns)
            {
                int s = 0;
                int e = st - 1;

                while (s < e)
                {
                    int m = s + (e - s) / 2;
                    if (nums[m] > n)
                        e = m;
                    else
                        s = m + 1;
                }
                st = s;

                if (st)
                    ns = nums[st - 1];
            }
        }

        if (en != numsSize - 1)
        {
            if (n > ne)
            {
                int s = en + 1;
                int e = numsSize - 1;

                while (s < e)
                {
                    int m = e - (e - s) / 2;
                    if (nums[m] < n)
                        s = m;
                    else
                        e = m - 1;
                }
                en = s;

                if (en != numsSize - 1)
                    ne = nums[en + 1];
            }
        }

        if (!st && en == numsSize -1)
            return numsSize;
    }
    return en - st + 1;
}
