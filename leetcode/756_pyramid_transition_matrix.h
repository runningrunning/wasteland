// try to not use recursion to finish this one
void pt_sort(int* n, int s, int e)
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

    pt_sort(n, cs, e - 1);
    pt_sort(n, e + 1, ce);
}

bool can_pt(int* n, int l, int* sf, int* a, int as)
{
    if (l == 1)
        return true;

    int cs[9];
    int si[9];
    int st[9] = {0};
    int i = 0;
    for (;i < l - 1 && i >= 0;)
    {
        if (!st[i])
        {
            int x = (n[i] * 8) +  n[i + 1];
            if (!sf[x])
                return false;
            // ai here is always 1 based !!
            int ai = sf[x];
            st[i] = ai;
            si[i] = x;
            cs[i] = a[ai - 1] & 0x7;
        }
        else
        {
            int ai = ++ st[i] - 1;
            if (ai == as || (a[ai] >> 3) != si[i])
            {
                st[i] = 0;
                i --;
                continue;
            }
            cs[i] = a[ai] & 0x7;
        }
        if (can_pt(cs, i + 1, sf, a, as))
            i ++;
    }
    return i == l - 1;
}

bool pyramidTransition(char* bottom, char** allowed, int allowedSize)
{
    int sf[64] = {0};
    int* as = malloc(sizeof(int) * allowedSize);
    for (int i = 0; i < allowedSize; i ++)
    {
        char* a = allowed[i];
        as[i] = ((a[0] - '@') << 6) | ((a[1] - '@') << 3) | ((a[2] - '@'));
    }

    pt_sort(as, 0, allowedSize - 1);

    int pre = -1;
    for (int i = 0; i < allowedSize; i ++)
    {
        int c = as[i] >> 3;
        if (c != pre)
            sf[c] = i + 1;
        pre = c;
    }

    int n[10] = {0};
    int i = 0;
    int c = bottom[i ++];
    while (c)
    {
        n[i - 1] = c - '@';
        c = bottom[i ++];
    }
    // be careful, i is length + 1
    return can_pt(n, i - 1, sf, as, allowedSize);
}
