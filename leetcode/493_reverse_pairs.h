// try with segment tree method
// over flow !!!!!!! INT_MAX, INT_MIN again !!!
// clear mind !!!
int reversePairs(int* _nums, int numsSize)
{
    long* nums = malloc(sizeof(long) * numsSize);
    long* t = malloc(sizeof(long) * numsSize);

    for (int i = 0; i < numsSize; i ++)
        nums[i] = _nums[i];

    long* _n = nums;
    long* _t = t;

    int x = 1;
    int r = 0;

    while (x < numsSize)
    {
        for (int i = 0; i < numsSize; i += 2 * x)
        {
            if (i + x >= numsSize)
            {
                for (int j = i; j < numsSize; j ++)
                    _t[j] = _n[j];
            }
            else
            {
                int j1 = i;
                int e1 = i + x;
                int j2 = i + x;
                int e2 = i + 2 * x;
                e2 = e2 > numsSize ? numsSize : e2;

                for (int j = i; j < i + x; j ++)
                {
                    while (j2 < e2 && _n[j] > 2 * _n[j2])
                        j2 ++;
                    r += j2 - i - x;
                }

                j2 = i + x;

                int ti = i;
                while (j1 < e1 && j2 < e2)
                {
                    if (_n[j1] < _n[j2])
                        _t[ti ++] = _n[j1 ++];
                    else
                        _t[ti ++] = _n[j2 ++];
                }

                while (j1 < e1)
                    _t[ti ++] = _n[j1 ++];

                while (j2 < e2)
                    _t[ti ++] = _n[j2 ++];

            }
        }

        _n = _n == nums ? t : nums;
        _t = _t == t ? nums : t;
        x *= 2;
    }

    return r;
}
