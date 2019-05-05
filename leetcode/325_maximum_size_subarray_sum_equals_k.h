// Use hashtable will be much faster than sort version !

/*
// C++ map version !
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sums({{0, 1}});
        int max = 0;
        for (auto i = 0, sum = 0; i < nums.size(); i++)
        {
            sum += nums[i++];
            if (!sums[sum])
                sums[sum] = i + 1;

            if (sums[sum - k])
            {
                if (max < i - sums[sum - k] + 1)
                    max = i - sums[sum - k] + 1;
            }
        }
        return max;

    }
};
*/

void msal_sort(int* n, int s, int e, int* i)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = i[s];
        i[s] = i[e];
        i[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int k = s + 1; k <= e; k ++)
    {
        while (n[k] < n[s]) k ++;
        while (n[e] > n[s]) e --;

        if (k >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = i[s];
            i[s] = i[e];
            i[e] = t;
        }
        else
        {
            t = n[k];
            n[k] = n[e];
            n[e] = t;

            t = i[k];
            i[k] = i[e];
            i[e] = t;
        }
    }
    msal_sort(n, cs, e - 1, i);
    msal_sort(n, e + 1, ce, i);
}

// similar with 523 Continuous Subarray Sum ?
// similar with subarray sum equals K
// continuous way
int maxSubArrayLen(int* nums, int numsSize, int ok)
{
    if (!nums || !numsSize)
        return 0;

    int* t = malloc(sizeof(int) * numsSize);
    int* i = malloc(sizeof(int) * numsSize);

    i[0] = 0;
    t[0] = nums[0];

    for (int k = 1; k < numsSize; k ++)
    {
        i[k] = k;
        t[k] = nums[k] + t[k - 1];
    }

    if (t[numsSize - 1] == ok)
        return numsSize;

    msal_sort(t, 0, numsSize - 1, i);

    int pre_i = 0;
    int pre = t[0];
    for (int k = 0; k < numsSize; k ++)
    {
        if (t[k] != pre)
        {
            msal_sort(i, pre_i, k - 1, t);
            pre_i = k;
            pre = t[k];
        }
    }
    msal_sort(i, pre_i, numsSize - 1, t);

    int os = 0;
    int sum = nums[os];
    int max = sum == ok ? 1 : 0;
    for (int k = 1; k < numsSize; k ++)
    {
        sum += nums[k];

        int s = 0;
        int e = numsSize - 1;
        int n = sum -  ok;

        while (s < e)
        {
            int m = (s + e) / 2;
            if (t[m] < n)
                s = m + 1;
            else
                e = m;
        }

        if (sum == ok)
        {
            if (max < k + 1)
                max = k + 1;
        }
        else if (t[s] == n)
        {
            if (max < k - i[s])
                max = k - i[s];
        }
    }
    return max;
}
