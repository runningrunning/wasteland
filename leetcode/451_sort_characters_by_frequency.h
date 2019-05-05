/* ERROR, there is error while using ^ under e == s */
/* Carefully, too much stupid memory overflow */
void fs_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    if (n[s] < n[e])
    {
        n[s] ^= n[e];
        n[e] ^= n[s];
        n[s] ^= n[e];
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(n[i] > n[s]) i ++;
        while(n[e] < n[s]) e --;

        if (i >= e)
        {
            if (s != e)         /* VIP ! */
            {
                n[s] ^= n[e];
                n[e] ^= n[s];
                n[s] ^= n[e];
            }
        }
        else
        {
            n[i] ^= n[e];
            n[e] ^= n[i];
            n[i] ^= n[e];
        }
    }

    fs_sort(n, cs, e - 1);
    fs_sort(n, e + 1, ce);
}

char* frequencySort(char* s)
{
    int all[256] = {0};
    int l = 0;
    while(s[l])
        all[s[l++]] ++;

    if (!l)
        return s;

    int si = 0;
    int i = 0;
    for (i = 0; i < 256; i ++)
    {
        if (all[i])
            all[si ++] = (all[i] << 8) | i;
    }

    fs_sort(all, 0, si - 1);

    int ii = 0;

    for (i = 0; i < si; i ++)
    {
        {
            char c = all[i] & 0xFF;
            int num = all[i] >> 8;
            while(num --)
                s[ii ++] = c;
        }
    }
    return s;
}
