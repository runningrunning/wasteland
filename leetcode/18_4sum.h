void fs_sort(int* nums, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (nums[s] > nums[e])
    {
        t = nums[e];
        nums[e] = nums[s];
        nums[s] = t;
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
            t = nums[e];
            nums[e] = nums[s];
            nums[s] = t;
        }
        else
        {
            t = nums[e];
            nums[e] = nums[i];
            nums[i] = t;
        }
    }
    fs_sort(nums, cs, e - 1);
    fs_sort(nums, e + 1, ce);
}

int fs_search(int* nums, int s, int e, int t)
{
    if (s >= e)
        return s;

    int m = s + (e - s) / 2;

    if (nums[m] == t)
        return m;

    if (nums[m] > t)
        return fs_search(nums, s, m - 1, t);
    return fs_search(nums, m + 1, e, t);
}

void _nSum(int* nums, int numsSize, int target, int k, int all, int* cur, int*** ret, int* c)
{
    if (numsSize < k)
        return;

    if (k > 2)
    {
        int pre = nums[0] - 1;

        for(int i = 0; i <= numsSize - k; i ++)
        {
            if (nums[i] + nums[i + 1] * (k - 1)> target)
                return;

            if (nums[i] == pre)
                continue;

            cur[k - 1] = nums[i];
            _nSum(nums + i + 1, numsSize - i - 1, target - nums[i], k - 1, all, cur, ret, c);

            pre = nums[i];
        }
    }
    else
    {
        int s = 0;
        int e = numsSize - 1;
        int a = 0;
        int pre = nums[s] - 1;

        while(s < e)
        {
            if (pre == nums[s])
            {
                s ++;
                continue;
            }

            a = nums[s] + nums[e] - target;

            if (a > 0)
            {
                /* int ne = fs_search(nums, s + 1, e - 1, target - nums[s]); */

                /* if (e == ne) */
                /*     return; */

                /* e = ne; */
                e --;
            }
            else if (a < 0)
            {
                s ++;
                /* int ns = fs_search(nums, s + 1, e - 1, target - nums[e]); */
                /* if (s == ns) */
                /*     return; */
                /* s = ns; */
            }
            else
            {
                cur[0] = nums[s];
                cur[1] = nums[e];
                int n = *c;

                if (!((n + 1) % 256))
                {
                    *ret = realloc(*ret, sizeof(int*) * (n + 256 + 1));
                }
                (*ret)[n] = malloc(sizeof(int) * all);
                memcpy((*ret)[n], cur, sizeof(int) * all);
                (*c) ++;

                pre = nums[s];
                s ++;
                e --;
            }
        }
    }
}

int** nSum(int* nums, int numsSize, int target, int* returnSize, int k, int* r)
{
    if (!nums)
        return NULL;

    fs_sort(nums, 0, numsSize - 1);

    /* k should never be more than 64 */
    int cur[64] = {0};
    int** ret = malloc(sizeof(int*) * 256);

    int sum = 0;
    for(int i = 0; i < k - 1; i ++)
        sum += nums[i];

    int e = fs_search(nums, k, numsSize - 1, target - sum);

    _nSum(nums, e + 1, target, k, k, cur, &ret, r);
    return ret;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize)
{
    int n = 3;
    return nSum(nums, numsSize, target, returnSize, n, returnSize);
}
