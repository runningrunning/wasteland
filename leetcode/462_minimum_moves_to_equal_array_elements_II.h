void mm2_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i++;
        while (n[e] > n[s]) e--;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    mm2_sort(n, cs, e - 1);
    mm2_sort(n, e + 1, ce);
}

int minMoves2(int* nums, int numsSize)
{
    if (numsSize < 2)
        return 0;

    mm2_sort(nums, 0, numsSize - 1);

    int* left = malloc(sizeof(int) * numsSize);
    int* right = malloc(sizeof(int) * numsSize);

    int e = numsSize - 1;

    left[0] = 0;
    right[e] = 0;

    for (int i = 1; i < numsSize; i++)
    {
        left[i] = left[i - 1] + nums[i - 1];
        right[e - i] = right[e - i + 1] + nums[e - i + 1];
    }

    int s;

    long min = LONG_MAX;
    long t;

    for (int i = 0; i < numsSize;)
    {
        s = i;
        while (i < numsSize && nums[i] == nums[s])
            i ++;
        e = i - 1;

        t = 0;

        t += (long) nums[s] * s - left[s];
        t += right[e] - (long) nums[e] * (numsSize - 1 - e);

        if (t < min)
            min = t;
    }
    return min;
}
