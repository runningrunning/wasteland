// learn a lot !!! about the DP and how calculate it
// binary search, try to optimize codes

int lengthOfLIS(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;
    int* t = malloc(sizeof(int) * numsSize);
    memset(t, 0, sizeof(int) * numsSize);

    int max = 1;
    int ts = 0;
    int te = 1;
    t[0] = nums[0];

    for (int i = 1; i < numsSize; i ++)
    {
        int x = nums[i];

        if (t[0] > x)
            t[0] = x;
        else if (t[te - 1] < x)
        {
            t[te ++] = x;
            max = te;
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

            t[s] = x;
        }
    }
    return max;
}

/*
void lolis_sort(int* n, int s, int e, int* m)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = m[s];
        m[s] = m[e];
        m[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = m[s];
            m[s] = m[e];
            m[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = m[i];
            m[i] = m[e];
            m[e] = t;
        }
    }

    lolis_sort(n, cs, e - 1, m);
    lolis_sort(n, e + 1, ce, m);
}

int lengthOfLIS_1(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int* t = malloc(sizeof(int) * numsSize);
    int* n = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i ++)
        n[i] = i;

    t[0] = 1;
    lolis_sort(nums, 0, numsSize - 1, n);

    int m = 1;
    for (int i = 1; i < numsSize; i ++)
    {
        int tx = 1;
        int x = n[i];
        int y = nums[i];
        int min = 1;
        for (int j = 0; j < i; j ++)
        {
            if (n[j] < x && nums[j] != y)
            {
                if (min < t[j] + 1)
                    min = t[j] + 1;
            }
        }

        t[i] = min;
        if (min > m)
            m = min;
    }
    return m;
}
*/
