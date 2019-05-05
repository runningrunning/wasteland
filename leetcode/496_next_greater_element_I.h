void nge_sort(int* nums, int s, int e, int* ids)
{
    if (s >= e)
        return;

    int t;

    if (nums[s] > nums[e])
    {
        t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;

        t = ids[s];
        ids[s] = ids[e];
        ids[e] = t;
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
            t = nums[s];
            nums[s] = nums[e];
            nums[e] = t;

            t = ids[s];
            ids[s] = ids[e];
            ids[e] = t;
        }
        else
        {
            t = nums[i];
            nums[i] = nums[e];
            nums[e] = t;

            t = ids[i];
            ids[i] = ids[e];
            ids[e] = t;
        }
    }

    nge_sort(nums, cs, e - 1, ids);
    nge_sort(nums, e + 1, ce, ids);
}

int nge_search(int* nums, int s, int e, int x)
{
    if (s >= e)
        return nums[s] == x ? (s + 1) : 0;

    int m = s + (e - s) / 2;

    if (nums[m] == x)
        return m + 1;

    if (nums[m] > x)
        return nge_search(nums, s, m - 1, x);
    return nge_search(nums, m + 1, e, x);
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
    int i = 0;
    int t[1001] = {0};
    for (i = 0; i < findNumsSize; i++)
        t[i] = i;

    nge_sort(findNums, 0, findNumsSize - 1, t);

    int* ret = malloc(sizeof(int) * findNumsSize);

    int c = 0;
    int ci = 0;

    int si = 0;
    int st[1001] = {0};
    int sc[1001] = {0};

    for (i = 0; i < numsSize; i ++)
    {
        if (!si)
        {
            c = nums[i];
            ci = nge_search(findNums, 0, findNumsSize - 1, c);

            if (ci)
            {
                ret[t[ci - 1]] = -1;
                st[si] = ci;
                sc[si] = c;
                si ++;
            }
        }
        else
        {
            int tc = nums[i];

            while (tc > c)
            {
                ret[t[ci - 1]] = tc;
                si --;

                if (!si)
                    break;

                c = sc[si - 1];
                ci = st[si - 1];
            }

            int ti = nge_search(findNums, 0, findNumsSize - 1, tc);
            if (ti)
            {
                ret[t[ti - 1]] = -1;
                c = tc;
                ci = ti;
                st[si] = ci;
                sc[si] = c;
                si ++;
            }
        }
    }
    *returnSize = findNumsSize;
    return ret;
}
