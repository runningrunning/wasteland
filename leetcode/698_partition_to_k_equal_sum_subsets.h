// wrong algorithm
// better solution !
// TODO !!!!! DO IT AGAIN
// recursion to handle all of cases

void cpks_sort(int* n, int s, int e)
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

    for (int i = s; i <= e; i ++)
    {
        while(n[i] < n[s]) i ++;
        while(n[e] > n[s]) e --;

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

    cpks_sort(n, cs, e - 1);
    cpks_sort(n, e + 1, ce);
}

bool _can(int* n, int s, int e, int c, int k, int m)
{
    if (c == k)
        return true;

    while (e >= s && n[e] < 0)
        e --;

    if (s > e)
        return false;

    if (n[e] == m)
        return _can(n, s, e - 1, c + 1, k, m);

    int ii = 0;
    int ix[16] = {0};
    ix[ii ++] = e;

    int x = n[e];
    int st = e - 1;
    while (true)
    {
        if (st >= s && n[st] >= 0 && x + n[st] <= m)
        {
            ix[ii ++] = st;
            x += n[st];
            n[st] = - n[st];
            if (x == m)
            {
                if (_can(n, s, e - 1, c + 1, k, m))
                    return true;
                x += n[st];
                n[st] = - n[st];
            }
        }

        st --;

        if (st < s)
        {
            if (ii <= 1)
                return false;
            st = ix[-- ii];
            x += n[st];
            n[st] = -n[st];
            st --;
        }
    }

    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k)
{
    if (k == 1)
        return true;

    if (!nums || !numsSize)
        return false;

    int s = 0;
    int e = numsSize - 1;

    cpks_sort(nums, s, e);

    if (nums[s] == nums[e])
        return !(numsSize % k);

    int need = 0;
    for (int i = 0; i < numsSize; i ++)
        need += nums[i];

    if (need % k)
        return false;
    need /= k;

    if (nums[e] > need)
        return false;

    int* c = calloc(sizeof(int), k);
    return _can(nums, 0, numsSize - 1, 0, k, need);
}

/* bool _can(int* n, int s, int e, int* c, int k, int m) */
/* { */
/*     if (s > e) */
/*     { */
/*         for (int i = 0; i < k; i ++) */
/*             if (c[i] != m) */
/*                 return false; */
/*         return true; */
/*     } */

/*     for (int i = 0; i < k; i ++) */
/*     { */
/*         if (c[i] + n[s] <= m) */
/*         { */
/*             c[i] += n[s]; */

/*             if (_can(n, s + 1, e, c, k, m)) */
/*                 return true; */

/*             c[i] -= n[s]; */
/*         } */
/*     } */
/*     return false; */
/* } */

/* bool canPartitionKSubsets(int* nums, int numsSize, int k) */
/* { */
/*     if (k == 1) */
/*         return true; */

/*     if (!nums || !numsSize) */
/*         return false; */

/*     int s = 0; */
/*     int e = numsSize - 1; */

/*     cpks_sort(nums, s, e); */

/*     if (nums[s] == nums[e]) */
/*         return !(numsSize % k); */

/*     int need = 0; */
/*     for (int i = 0; i < numsSize; i ++) */
/*         need += nums[i]; */

/*     if (need % k) */
/*         return false; */
/*     need /= k; */

/*     int _s = 0; */
/*     int _e = numsSize - 1; */

/*     if (nums[_e] > need) */
/*         return false; */

/*     while (nums[_e] == need || (nums[_e] + nums[_s] == need)) */
/*     { */
/*         k --; */
/*         if (nums[_e] < need) */
/*             _s ++; */
/*         _e --; */
/*     } */

/*     int* c = calloc(sizeof(int), k); */
/*     return _can(nums, _s, _e, c, k, need); */
/* } */

/* bool canPartitionKSubsets(int* nums, int numsSize, int k) */
/* { */
/*     if (k == 1) */
/*         return true; */

/*     if (!nums || !numsSize) */
/*         return false; */

/*     int s = 0; */
/*     int e = numsSize - 1; */

/*     cpks_sort(nums, s, e); */

/*     if (nums[s] == nums[e]) */
/*         return !(numsSize % k); */

/*     int need = 0; */
/*     for (int i = 0; i < numsSize; i ++) */
/*         need += nums[i]; */

/*     if (need % k) */
/*         return false; */

/*     need /= k; */

/*     if (nums[e] > need) */
/*         return false; */

/*     while(s <= e) */
/*     { */
/*         int x = nums[e --]; */
/*         while (x < need && s <= e) */
/*             x += nums[s ++]; */

/*         if (x != need) */
/*             return false; */
/*     } */
/*     return true; */
/* } */
