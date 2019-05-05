int ln_comp(int* nums, int* hp, int a, int b)
{
    if (nums[a] == nums[b])
        return 0;

    int fa = hp[a] % 10;
    int fb = hp[b] % 10;

    if (fa != fb)
        return fa > fb ? 1 : -1;

    int la = hp[a] - fa;
    int lb = hp[b] - fb;

    if (la == lb)
        return nums[a] > nums[b] ? 1 : -1;

    la = !la ? 1 : la;
    lb = !lb ? 1 : lb;

    long pa = nums[a] * lb * 10 + nums[b];
    long pb = nums[b] * la * 10 + nums[a];

    if (pa == pb)
        return 0;

    return pa > pb ? 1 : -1;
}

void ln_sort(int* nums, int* hp, int s, int e)
{
    if (s >= e)
        return;

    int t = 0;
    int cs = s;
    int ce = e;

    if (ln_comp(nums, hp, s, e) == 1)
    {
        t = nums[e];
        nums[e] = nums[s];
        nums[s] = t;
        t = hp[e];
        hp[e] = hp[s];
        hp[s] = t;
    }

    if (s + 1 == e)
        return;

    for(int i = s + 1; i <= e; i ++)
    {
        while(ln_comp(nums, hp, i, s) == -1)
            i ++;
        while(ln_comp(nums, hp, e, s) == 1)
            e --;

        if (i >= e)
        {
            t = nums[e];
            nums[e] = nums[s];
            nums[s] = t;
            t = hp[e];
            hp[e] = hp[s];
            hp[s] = t;
        }
        else
        {
            t = nums[e];
            nums[e] = nums[i];
            nums[i] = t;
            t = hp[e];
            hp[e] = hp[i];
            hp[i] = t;
        }
    }

    ln_sort(nums, hp, cs, e - 1);
    ln_sort(nums, hp, e + 1, ce);
}

char* largestNumber(int* nums, int numsSize)
{
    int* hp = malloc(sizeof(int) * numsSize);

    int len = 0;
    for(int i = 0; i < numsSize; i ++)
    {
        int lv = 0;
        int n = nums[i];

        len ++;
        while(n >= 10)
        {
            if (!lv)
                lv = 10;
            else
                lv *= 10;
            len ++;
            n /= 10;
        }
        hp[i] = lv + n;
    }

    ln_sort(nums, hp, 0, numsSize - 1);

    char* ret = malloc(sizeof(char) * (len + 1));
    ret[len] = 0;
    len = 0;

    if (nums[numsSize - 1] == 0)
    {
        ret[0] = '0';
        ret[1] = 0;
        return ret;
    }

    for(int i = numsSize - 1; i >= 0; i --)
    {
        int n = nums[i];
        int l = hp[i];
        l -= l % 10;

        if (l)
        {
            while(l)
            {
                ret[len ++] = (n / l)  + '0';
                n %= l;
                l /= 10;
            }
        }
        else
            ret[len ++] = n + '0';
    }
    return ret;
}
