// TODO MUST DO IT AGAIN !!!! // better method to do merge sort !!!
// STUPID ! more practice !!!
// clear mind !!!
int _crs(long* nums, int l, int s, long low, long up, long* t)
{
    int n = 0;
    for (int i = 0; i < s; i += 2 * l)
    {
        int s1 = i;

        if (s1 + l >= s)
            memcpy(t + i, nums + i, sizeof(long) * (s - s1));
        else
        {
            int e1 = i + l;
            int s2 = i + l;
            int e2 = i + 2 * l;
            e2 = e2 > s ? s : e2;

            // from s1 -> e1
            int ps = s1;
            int pe = s1;

            if (nums[e2 - 1] - nums[ps] >= low && nums[s2] - nums[e1 - 1] <= up)
            {
                for (int j = s2; j < e2; j ++)
                {
                    // how many stuff > up
                    while (ps < e1 && nums[j] - nums[ps] > up) ps ++;
                    // how many stuff >= low
                    while (pe < e1 && nums[j] - nums[pe] >= low) pe ++;

                    if (ps == e1)
                        break;

                    n += pe - ps;
                    // don't need to be this, just use pe - ps is enough
                    /* if (pe > s1 && (nums[j] - nums[pe - 1] >= low || pe == e1)) */
                    /* { */
                    /*     pe --; */
                    /*     n += pe - ps + 1; */
                    /* } */
                }
            }

            int ti = i;
            int i1 = s1;
            int i2 = s2;
            while (i1 < e1 && i2 < e2)
            {
                if (nums[i1] > nums[i2])
                    t[ti ++] = nums[i2 ++];
                else
                    t[ti ++] = nums[i1 ++];
            }

            while (i1 < e1)
                t[ti ++] = nums[i1 ++];

            while (i2 < e2)
                t[ti ++] = nums[i2 ++];
        }
    }

    return n;
}

int countRangeSum(int* nums, int numsSize, int low, int up)
{
    long lower = low;
    long upper = up;

    long* lnums = malloc(sizeof(long) * (numsSize + 1));
    long* tmp = malloc(sizeof(long) * (numsSize + 1));

    // insert 1 extra as 0, then it will calculate every sum also.
    lnums[0] = 0;
    for (int i = 0; i < numsSize; i ++)
        lnums[i + 1] = lnums[i] + nums[i];
    numsSize ++;

    int r = 0;
    int x = 1;

    long* _nums = lnums;
    while (x < numsSize)
    {
        // outl(_nums, numsSize);
        r += _crs(_nums, x, numsSize, lower, upper, _nums == lnums ? tmp : lnums);
        _nums = _nums == lnums ? tmp : lnums;
        x *= 2;
    }
    // outl(_nums, numsSize);
    return r;
}

/*
// stupid wrong algorithm !!!!, it's not this way!
// same with 315 count of smaller number after self
// how can I solve this through binary search tree ?
void _crs_sort(long* n, int s, int e)
{
    if (s > e)
        return;
    long t;
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
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

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

    _crs_sort(n, cs, e - 1);
    _crs_sort(n, e + 1, ce);
}

void _crs(int* tree, int x, int l, int s, int start, long v, long* a, int* r, bool in)
{
    if (x > s)
        return;

    int ox = x + 1;
    int st = (ox << l) - 1;

    if (st > s)
        return;

    int ed = st + (1 << l) - 1;
    ed = ed > s ? s : ed;

    st -= start;
    ed -= start;

    long vst = a[st];
    long ved = a[ed];

    if (v < vst)
        return;

    if (in && v >= vst && v <= ved)
        tree[x] ++;

    if (v > ved)
    {
        (*r) += tree[x];
        return;
    }

    if (l)
    {
        _crs(tree, x * 2 + 1, l - 1, s, start, v, a, r, in);
        _crs(tree, x * 2 + 2, l - 1, s, start, v, a, r, in);
    }
}

int countRangeSum(int* nums, int numsSize, int low, int up)
{
    long lower = low;
    long upper = up;

    long* sum = malloc(sizeof(long) * numsSize);
    for (int i = 0; i < numsSize; i ++)
        sum[i] = nums[i];

    for (int i = 1; i < numsSize; i ++)
        sum[i] += sum[i - 1];

    long* copy = malloc(sizeof(long) * numsSize);
    memcpy(copy, sum, sizeof(long) * numsSize);
    _crs_sort(copy, 0, numsSize - 1);

    int size = 1;

    for (int i = 1; i < numsSize; i ++)
        if (copy[i] != copy[i - 1])
            copy[size ++] = copy[i];

    int l = 0;
    int x = 1;

    while (x < size)
    {
        x <<= 1;
        l ++;
    }

    int start = x - 1;
    int* tree = calloc(sizeof(int), start + size);

    int r = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        int x = 0;
        _crs(tree, 0, l, start + size - 1, start, sum[i] - upper, copy, &x, false);
        // printf("v %d x %d.\n", sum[i] - upper, x);
        int y = 0;
        _crs(tree, 0, l, start + size - 1, start, sum[i] - lower + 1, copy, &y, false);
        // printf("v %d y %d.\n", sum[i] - lower, y);
        r += y - x;
        x = 0;
        _crs(tree, 0, l, start + size - 1, start, sum[i], copy, &x, true);

        if (sum[i] <= upper && sum[i] >= lower)
            r ++;
    }
    return r;
}
*/

// seems segment trees
// it can be just have one child, we should not count them in
/* void _crs(int* t, int x, int s, int l, int low, int up, int* r) */
/* { */
/*     if (x > s) */
/*         return; */

/*     if (l) */
/*     { */
/*         int lc = x * 2 + 1; */
/*         if (lc > s) */
/*             return; */
/*         int olc = lc + 1; */
/*         int st = (olc << (l - 1)) - 1; */
/*         int se = st + (1 << (l - 1)) - 1; */
/*         if (st <= s) */
/*             _crs(t, x * 2 + 1, s, l - 1, low, up, r); */
/*         if (se < s) */
/*         { */
/*             printf("%d se %d s %d l %d st %d. t[x] %d  %d\n", x, se, s, l, st, t[x], olc); */
/*             if (t[x] <= up && t[x] >= low) */
/*                 (*r) ++; */
/*             _crs(t, x * 2 + 2, s, l - 1, low, up, r); */
/*         } */
/*     } */
/*     else */
/*     { */
/*         if (t[x] <= up && t[x] >= low) */
/*             (*r) ++; */
/*     } */
/* } */
/* int countRangeSum(int* nums, int numsSize, int lower, int upper) */
/* { */
/*     int l = 0; */
/*     int x = 1; */

/*     while (x < numsSize) */
/*     { */
/*         x <<= 1; */
/*         l ++; */
/*     } */

/*     int start = x - 1; */
/*     int* tree = calloc(sizeof(int), start + numsSize); */

/*     for (int i = 0; i < numsSize; i ++) */
/*     { */
/*         x = i + start; */
/*         tree[x] = nums[i]; */

/*         while (x) */
/*         { */
/*             int p = (x - 1) / 2; */
/*             tree[p] += nums[i]; */
/*             x = p; */
/*         } */
/*     } */
/*     out(tree, start + numsSize); */
/*     int r = 0; */
/*     _crs(tree, 0, start + numsSize - 1, l, lower, upper, &r); */
/*     return r; */
/* } */
