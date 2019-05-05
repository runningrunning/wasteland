int ptw(int* n, int s, int e, int p1, int p2, int c, int* t)
{
    if (t[s * c + e] != INT_MIN)
        return p1 + t[s * c + e] - p2;

    if (s == e)
    {
        t[s * c + e] = n[s];
        return p1 + n[s] - p2;
    }

    if (e - s == 1)
    {
        int max = n[s] > n[e] ? n[s] : n[e];
        int min = n[s] > n[e] ? n[e] : n[s];
        t[s * c + e] = max - min;
        return p1 + t[s * c + e] - p2;
    }

    // p1 left p2 end
    int ple = ptw(n, s + 1, e - 1, n[s], n[e], c, t);
    int pll = ptw(n, s + 2, e, n[s], n[s + 1], c, t);

    int min = ple < pll ? ple : pll;
    ple = ple + 2 * (n[e] - n[s]);
    int pee = ptw(n, s, e - 2, n[e], n[e - 1], c, t);
    int min_2 = ple < pee ? ple : pee;

    t[s * c + e] = min < min_2 ? min_2 : min;
    return p1 + t[s * c + e] - p2;
}

bool PredictTheWinner(int* nums, int numsSize)
{
    if (!nums || numsSize <= 2)
        return true;

    int t[512] = {0};
    for (int i = 0; i < 512; i ++)
        t[i] = INT_MIN;
    return  ptw(nums, 0, numsSize - 1, 0, 0, numsSize, t) >= 0;
}

// WHY DP result is not same with me ????
// int m[] = {9337301,0,2,2245036,4,1997658,5,2192224,960000,1261120,8824737,1,1161367,9479977,7,2356738,5,4,9};
/*
void max_diff(int* nums, int s, int e, int odd, int even, int* p1, int* p2)
{
    out(nums + s, e - s + 1);
    printf("odd %d even %d.\n", odd, even);
    if (s + 1 == e)
    {
        if (nums[s] > nums[e])
        {
            *p1 += nums[s];
            *p2 += nums[e];
            printf("p1 %d p2 %d.\n", nums[s], nums[e]);
        }
        else
        {
            *p1 += nums[e];
            *p2 += nums[s];
            printf("p1 %d p2 %d.\n", nums[e], nums[s]);
        }
    }
    else
    {
        if (odd == even)
        {
            if (nums[s] > nums[e])
            {
                odd -= nums[s];
                *p1 += nums[s];
                if (nums[s + 1] > nums[e])
                {
                    even -= nums[s + 1];
                    *p2 += nums[s + 1];
                    printf("p1 %d p2 %d.\n", nums[s], nums[s + 1]);
                    max_diff(nums, s + 2, e, odd, even, p1, p2);
                }
                else
                {
                    even -= nums[e];
                    *p2 += nums[e];
                    printf("p1 %d p2 %d.\n", nums[s], nums[e]);
                    max_diff(nums, s + 1, e - 1, even, odd, p1, p2);
                }
            }
            else
            {
                even -= nums[e];
                *p1 += nums[e];
                if (nums[s] > nums[e - 1])
                {
                    odd -= nums[s];
                    *p2 += nums[s];
                    printf("p1 %d p2 %d.\n", nums[e], nums[s]);
                    max_diff(nums, s + 1, e - 1, even, odd, p1, p2);
                }
                else
                {
                    odd -= nums[e - 1];
                    *p2 += nums[e - 1];
                    printf("p1 %d p2 %d.\n", nums[e], nums[e - 1]);
                    max_diff(nums, s, e - 2, odd, even, p1, p2);
                }
            }
        }
        else
        {
            if (odd > even)
            {
                odd -= nums[s];
                *p1 += nums[s];
                if (nums[s + 1] > nums[e])
                {
                    even -= nums[s + 1];
                    *p2 += nums[s + 1];
                    printf("p1 %d p2 %d.\n", nums[s], nums[s + 1]);
                    max_diff(nums, s + 2, e, odd, even, p1, p2);
                }
                else
                {
                    even -= nums[e];
                    *p2 += nums[e];
                    printf("p1 %d p2 %d.\n", nums[s], nums[e]);
                    max_diff(nums, s + 1, e - 1, even, odd, p1, p2);
                }
            }
            else
            {
                even -= nums[e];
                *p1 += nums[e];
                if (nums[s] > nums[e - 1])
                {
                    odd -= nums[s];
                    *p2 += nums[s];
                    printf("p1 %d p2 %d.\n", nums[e], nums[s]);
                    max_diff(nums, s + 1, e - 1, even, odd, p1, p2);
                }
                else
                {
                    odd -= nums[e - 1];
                    *p2 += nums[e - 1];
                    printf("p1 %d p2 %d.\n", nums[e], nums[e - 1]);
                    max_diff(nums, s, e - 2, odd, even, p1, p2);
                }
            }
        }
    }
}

// [2,4,55,6,8]
// [0, 0, 7, 6, 5, 6, 1]
bool PredictTheWinner(int* nums, int numsSize)
{
    if (!(numsSize & 1) || numsSize < 2)
        return true;

    int md;
    int t;

    int odd = 0;
    int even = 0;
    for (int i = 1; i <= numsSize; i ++)
    {
        if (i & 1)
            odd += nums[i - 1];
        else
            even += nums[i - 1];
    }

    printf("== %d %d.\n", odd, even);

    int p1 = 0;
    int p2 = 0;
    if (nums[0] > nums[numsSize - 1])
    {
        t = nums[0];
        odd -= t;
        max_diff(nums, 1, numsSize - 1, even, odd, &p1, &p2);
    }
    else
    {
        t = nums[numsSize - 1];
        odd -= t;
        max_diff(nums, 0, numsSize - 2, odd, even, &p1, &p2);
    }
    printf("%d %d %d %d.\n", t, p1 - p2, p1, p2);
    return t >= (p1 - p2);
}
*/
