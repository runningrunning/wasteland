// TODO FIND BETTER SOLUTION !!!!!!!!!!
// REWORK Better solutions ??? !!!
int comp(const void* a1, const void* a2)
{
    return *((int*)a1) - *((int*)a2);
}

// heap
// optimize, just do re-balance
int smallestDistancePair(int* nums, int numsSize, int k)
{
    if (!nums || numsSize < 2)
        return 0;
    int l = numsSize * (numsSize - 1) / 2;
    if (k == l)
        return nums[numsSize - 1] - nums[0];

    int* next = calloc(sizeof(int), numsSize);

    int a = 0;
    int s = 0;
    int e = nums[numsSize - 1] - nums[0];

    while (s < e)
    {
        a = 0;
        int m = s + (e - s) / 2;

        for (int i = 0; i < numsSize - 1; i ++)
        {
            int _s = i;
            int _e = numsSize - 1;
            if (nums[_e] - nums[_s] <= m)
            {
                // a += _e - i;
                a += (_e - i) * (_e - i + 1) / 2;
                break;
            }
            else
            {
                int _m = nums[i] + m + 1;

                if (next[i])
                {
                    if (nums[next[i]] < _m)
                    {
                        _s = next[i];
                        while (nums[_s] < _m && _s != numsSize - 1)
                            _s ++;
                    }
                    else
                    {
                        _s = next[i];
                        while (nums[_s - 1] >= _m)
                            _s --;
                    }
                    next[i] = _s - 1;
                }
                else
                {
                    while (_s < _e)
                    {
                        int _mid = _s + (_e - _s) / 2;
                        if (nums[_mid] < _m)
                            _s = _mid + 1;
                        else
                            _e = _mid;

                        next[i] = _s - 1;
                    }
                }
                a += _s - 1 - i;
            }
        }

        if (a < k)
            s = m + 1;
        else
            e = m;
    }

    return s;
}
