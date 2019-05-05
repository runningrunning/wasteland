// Stupid error, forget to set the array size
// LESSON Learned, simple function is easy to understand and also faster
// sort version is hard to write and also several errors in corner cases
// can contribute mote test cases
void nct_sort(int* n, int s, int e)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;
        }
    }

    nct_sort(n, cs, e - 1);
    nct_sort(n, e + 1, ce);
}

char* nextClosestTime(char* time)
{
    char* ret = malloc(6);
    ret[2] = ':';
    ret[5] = 0;

    // forget to set the array size, STUPID ERROR
    int ds[4] = {0};
    ds[0] = time[0] - '0';
    ds[1] = time[1] - '0';
    ds[2] = time[3] - '0';
    ds[3] = time[4] - '0';

    int ai = 0;

    int all[24] = {0};
    for (int i = 0; i < 4; i ++)
        for (int j = 0; j < 4; j ++)
            all[ai ++] = ds[i] * 10 + ds[j];

    // out(all, ai);
    nct_sort(all, 0, ai - 1);

    int ri = 1;
    int pre = all[0];
    for (int i = 1; i < ai; i ++)
    {
        if (all[i] >= 60)
            break;

        if (pre == all[i])
            continue;

        pre = all[i];
        all[ri ++] = all[i];
    }


    int s = 0;
    int e = ri - 1;
    int t = ds[2] * 10 + ds[3];

    if (t != all[ri - 1])
    {
        while (s < e)
        {
            int m = s + (e - s) / 2;

            if (all[m] <= t)
                s = m + 1;
            else
                e = m;
        }

        ret[0] = time[0];
        ret[1] = time[1];
        ret[3] = (all[s] / 10) + '0';
        ret[4] = (all[s] % 10) + '0';

        return ret;
    }

    ret[0] = (all[0] / 10) + '0';
    ret[1] = (all[0] % 10) + '0';
    ret[3] = (all[0] / 10) + '0';
    ret[4] = (all[0] % 10) + '0';
    t = ds[0] * 10 + ds[1];

    s = 0;
    e = ri - 1;

    while (s < e)
    {
        int m = s + (e - s) / 2;
        if (all[m] <= t)
            s = m + 1;
        else
            e = m;
    }

    // can not larger than 24 or itself as it doesn't contain minutes larger.
    if (all[s] >= 24 || all[s] == t)
        return ret;

    ret[0] = (all[s] / 10) + '0';
    ret[1] = (all[s] % 10) + '0';

    return ret;

}

char* nextClosestTime_2(char* time) {
    char* ret = malloc(6);
    ret[2] = ':';
    ret[5] = 0;

    // forget to set the array size, STUPID ERROR
    int ds[4] = {0};
    ds[0] = time[0] - '0';
    ds[1] = time[1] - '0';
    ds[2] = time[3] - '0';
    ds[3] = time[4] - '0';

    // another method is just put them together to find the next
    int flag = (1 << ds[0]) | (1 << ds[1]) | (1 << ds[2]) | (1 << ds[3]);
    int ms = ds[2] * 10 + ds[3];
    int hs = ds[0] * 10 + ds[1];

    for (int i = ms + 1; i < 60; i ++)
    {
        int f = (1 << (i % 10)) | (1 << (i / 10));

        if ((f & flag) == f)
        {
            ret[0] = time[0];
            ret[1] = time[1];
            ret[2] = time[2];
            ret[3] = (i / 10) + '0';
            ret[4] = (i % 10) + '0';
            return ret;
        }
    }

    int less;
    for (int i = 0; i < 60; i ++)
    {
        int f = (1 << (i % 10)) | (1 << (i / 10));

        if ((f & flag) == f)
        {
            less = i;
            ret[3] = (i / 10) + '0';
            ret[4] = (i % 10) + '0';
            break;
        }
    }

    for (int i = hs + 1; i < 24; i ++)
    {
        int f = (1 << (i % 10)) | (1 << (i / 10));

        if ((f & flag) == f)
        {
            ret[0] = (i / 10) + '0';
            ret[1] = (i % 10) + '0';
            return ret;
        }
    }
    ret[0] = (less / 10) + '0';
    ret[1] = (less % 10) + '0';
    return ret;
}
