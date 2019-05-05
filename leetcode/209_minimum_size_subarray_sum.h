// DONOT need to use any binary search !!!!! :(
// how stupid I am !!!!!
// STUPID WRONG ALGORITHM
int minSubArrayLen(int s, int* nums, int numsSize)
{
    int st = 0;
    int sum = 0;
    int min = INT_MAX;
    for (int i = 0; i < numsSize; i ++)
    {
        sum += nums[i];

        if (sum < s)
            continue;

        while (sum >= s)
        {
            min = i - st + 1 < min ? i - st + 1 : min;
            sum -= nums[st ++];
        }
    }
    return min == INT_MAX ? 0 : min;
}
/*
int minSubArrayLen(int s, int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    if (nums[0] >= s)
        return 1;

    if (numsSize == 1)
        return 0;

    int pre_i = 0;
    int min = INT_MAX;

    for (int i = 1; i < numsSize; i ++)
    {
        if (nums[i] >= s)
            return 1;

        nums[i] += nums[i - 1];

        if (nums[i] < s)
            continue;
        else if (nums[i] == s)
        {
            if (min > i - pre_i + 1)
                min = i - pre_i + 1;
        }
        else
        {
            int x = nums[i] - s;
            int st = pre_i;
            int ed = i - 1;

            // stupid error here
            while (st < ed)
            {
                int m = ed - (ed - st) / 2;
                if (nums[m] > x)
                    ed = m - 1;
                else
                    st = m;
            }

            if (min > i - st)
                min = i - st;
            pre_i = st + 1;
        }
    }
    return min == INT_MAX ? 0 : min;
}
*/
/*
int check(int s, int* ns, int m, int n, int seq)
{
    int a = 0;
    if (seq >= 0)
    {
        for(int i = 0; i < n; i ++)
        {
            a += ns[m - i];
            if (a >= s)
                return i + 1;
        }
    }
    else
    {
        m = m - n + 1;
        for(int i = 0; i < n; i ++)
        {
            a += ns[m + i];
            if (a >= s)
                return i + 1;
        }
    }
    return 0;
}

int minSubArrayLen(int s, int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int n = 1;
    int seq = 0;
    int pc = INT_MAX;

    for(int i = 1; i < numsSize; i ++)
    {
        int nseq = nums[i] - nums[i - 1];

        if (!nseq)
            n ++;
        else
        {
            nseq = nseq > 0 ? 1 : -1;
            if (!seq)
            {
                seq = nseq;
                n ++;
            }
            else
            {
                if (nseq == seq)
                    n ++;
                else
                {
                    int c = check(s, nums, i - 1, n, seq);
                    if (c && c < pc)
                        pc = c;
                    n = 2;
                    seq = nseq;
                }
            }
        }
    }

    int c = check(s, nums, numsSize - 1, n, seq);
    if (c && c < pc)
        pc = c;

    return pc == INT_MAX ? 0 : pc;
}
*/
