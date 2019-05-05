// learn a lot !!! about the DP and how calculate it
// binary search, try to optimize codes
// similar with 300_longest_increasing_subsequence.h
// clear mind is most important
// try to study DP
void fnlis(int* n, int e, int* t, int* num, int* m, int* a)
{
    if (e == 0)
    {
        *m = 1;
        t[0] = 1;
        num[0] = 1;
        *a = 1;
        return;
    }

    fnlis(n, e - 1, t, num, m, a);

    int min = 1;
    int n_min = 0;
    int c = n[e];
    int x = 0;
    int y = -1;

    for (int i = 0; i <= e - 1; i ++)
    {
        if (c > n[i])
        {
            if (min < t[i] + 1)
            {
                min = t[i] + 1;
                y = t[i];
                x = num[i];
            }
            else if (y == t[i])
                x += num[i];

        }
    }

    t[e] = min;
    num[e] = x ? x : 1;
    if (min > *m)
    {
        *m = min;
        *a = num[e];
    }
    else if (min == *m)
    {
        *a += num[e];
    }
}

int findNumberOfLIS_1(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;
    int m;
    int* t = malloc(sizeof(int) * numsSize);
    int* n = malloc(sizeof(int) * numsSize);
    memset(n, 0, sizeof(int) * numsSize);
    int a;
    fnlis(nums, numsSize - 1, t, n, &m, &a);
    return a;
}

int findNumberOfLIS(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int* t = malloc(sizeof(int) * numsSize);
    int* ti = malloc(sizeof(int) * numsSize);
    // previous (index + 1) << 16 | how many number low than itself, include it self
    int* n = malloc(sizeof(int) * numsSize);

    int max = 0;
    int ts = 0;
    int te = 1;
    t[0] = nums[0];
    ti[0] = 0 + 1;
    n[0] = 1;

    for (int i = 1; i < numsSize; i ++)
    {
        int x = nums[i];

        if (t[0] > x)
        {
            n[i] = ti[0] << 20 | 1;
            t[0] = x;
            ti[0] = i + 1;
        }
        else if (t[te - 1] < x)
        {
            ti[te] = i + 1;
            t[te] = x;

            int d = 0;
            int y = ti[te - 1] - 1;
            while (y >= 0 && x > nums[y])
            {
                d += n[y] & 0xFFFFF;
                y = (n[y] >> 20) - 1;
            }
            n[i] = d;
            max = te ++;
        }
        else
        {
            // b_search, must use the size, not the last index !!
            int s = ts;
            int e = te;

            while (s < e)
            {
                int m = (s + e) / 2;
                if (t[m] < x)
                    s = m + 1;
                else
                    e = m;
            }

            int d = 0;
            int y = ti[s - 1] - 1;

            while (y >= 0 && x > nums[y])
            {
                d += n[y] & 0xFFFFF;
                y = (n[y] >> 20) - 1;
            }

            n[i] = (ti[s] << 20) | (d ? d : 1);
            t[s] = x;
            ti[s] = i + 1;
        }
    }

    int d = 0;
    int y = ti[max] - 1;
    while (y >= 0)
    {
        d += n[y] & 0xFFFFF;
        y = (n[y] >> 20) - 1;
    }
    return d;
}
