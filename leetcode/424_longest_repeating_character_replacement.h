void cr_sort(int* n, int s, int e, int* m)
{
    if (s >= e)
        return;

    int t;

    if (n[s] < n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
        t = m[s];
        m[s] = m[e];
        m[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] > n[s]) i ++;
        while (n[e] < n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
            t = m[s];
            m[s] = m[e];
            m[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
            t = m[i];
            m[i] = m[e];
            m[e] = t;
        }
    }
    cr_sort(n, cs, e - 1, m);
    cr_sort(n, e + 1, ce, m);
}

int characterReplacement(char* s, int k)
{
    int a[26] = {0};
    int m[26] = {0};

    int i = 0;
    int c = s[i ++];

    while (c)
    {
        a[c - 'A'] ++;
        c = s[i ++];
    }

    int l = i - 1;

    int max = INT_MIN;
    for (i = 0; i < 26; i ++)
    {
        m[i] = i;

        if (max < a[i])
            max = a[i];
    }

    if (l - max <= k)
        return l;

    cr_sort(a, 0, 25, m);

    max = k;

    for (i = 0; i < 26; i ++)
    {
        if (a[i] + k <= max)
            return max;
        int c = 'A' + m[i];

        int j = 0;
        int t = k;
        while (t)
        {
            if (s[j] != c)
                t --;
            j ++;
        }

        int st = 0;
        int en = j - 1;
        int tmax = j;

        for (;j < l; j ++)
        {
            en ++;
            if (s[j] != c)
            {
                while (s[st] == c)
                    st ++;
                st ++;
            }

            if (tmax < en - st + 1)
                tmax = en - st + 1;
        }

        if (max < tmax)
            max = tmax;
    }
    return max;
}
