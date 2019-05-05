// learn how to optimize code to reduce it to 0 ms from 160 ms
bool isPalindrome(char* s, int o, int l)
{
    int st = o;
    int en = l;
    while (st <= en && s[st] == s[en])
    {
        st ++;
        en --;
    }
    return st > en;
}

int _ppmc(char* s, int st, int l, int i, int* mem)
{
    if (mem[st])
        return mem[st];

    if (isPalindrome(s, st, l - 1))
    {
        mem[st] = 1;
        return 1;
    }

    int _min = INT_MAX;
    for (int si = l - 2; si >= st; si --)
    {
        if (isPalindrome(s, st, si))
        {
            int _tmp = _ppmc(s, si + 1, l, i + 1, mem);
            if (_tmp < _min)
            {
                _min = _tmp;
                if (_min == 1) // WITHOUT THS LINE, IT WILL BE 160 MS !!!!!!
                    break;
            }
        }
    }
    mem[st] = _min + 1;
    return _min + 1;
}

int minCut(char* s)
{
    int l = strlen(s);
    if (l <= 1)
        return 0;

    int* mem = malloc(sizeof(int) * (l + 1));
    memset(mem, 0, sizeof(int) * (l + 1));
    _ppmc(s, 0, l, 0, mem);
    return mem[0] - 1;
}

/*
bool isPalindrome(char* s, int o, int l)
{
    int st = o;
    int en = l;

    while (st <= en && s[st] == s[en])
    {
        st ++;
        en --;
    }
    return st > en;
}

int _ppmc(char* s, int st, int l, int i, int* mem, int* min)
{
    if (mem[st])
        return mem[st];

    if (st == l)
    {
        *min = i;
        return 0;
    }

    int _min = INT_MAX;

    for (int si = l - 1; si >= st; si --)
    {
        if (isPalindrome(s, st, si))
        {
            int _tmp = _ppmc(s, si + 1, l, i + 1, mem, min);
            if (_tmp < _min)
                _min = _tmp;
            if (_tmp == 1)
                break;
        }
    }
    mem[st] = _min + 1;
    return _min + 1;
}

int minCut(char* s)
{
    int l = strlen(s);
    if (l <= 1)
        return 0;

    int min = INT_MAX;
    int* mem = malloc(sizeof(int) * (l + 1));
    memset(mem, 0, sizeof(int) * (l + 1));
    _ppmc(s, 0, l, 0, mem, &min);
    return mem[0] - 1;
}

bool _ppmc(char* s, int st, int l, int i, int* min, int* ms, int* xs, int* es)
{
    if (i - 1 >= *min)
        return false;


    if (st == l)
    {
        if (i - 1 < *min)
            *min = i - 1;
        return true;
    }

    if (es[st] && i + st > *min)
        return false;

    if (ms[st] < i)
        return false;

    ms[st] = i;

    int x = xs[st];
    for (int si = l - 1; si >= st; si --)
    {
        int ds = si - st;
        int mid = st + (ds >> 1);
        if ((ds & 1) ? !x : (x == s[mid]))
        {
            int ti = st;
            for (; ti <= mid; ti ++)
                if (s[ti] != s[si - (ti - st)])
                    break;
            if (ti > mid)
            {
                bool r = _ppmc(s, si + 1, l, i + 1, min, ms, xs, es);
                if (r)
                {
                    es[si] = *min - i;
                    for (int tmp = st + 1; tmp <= si; tmp ++)
                        ms[tmp] = i + 1;
                }
            }
        }
        x ^= s[si];
    }
    return false;
}

int minCut(char* s)
{
    int l = strlen(s);

    if (l <= 1)
        return 0;

    int min = INT_MAX;
    int x = 0;
    int* es = malloc(sizeof(int) * l);
    memset(es, 0, sizeof(int) * l);
    int* ms = malloc(sizeof(int) * l);
    int* xs = malloc(sizeof(int) * l);
    for (int i = 0; i < l; i ++)
    {
        x ^= s[l - 1 - i];
        xs[l - 1 - i] = x;
        ms[i] = i;
    }

    _ppmc(s, 0, l, 0, &min, ms, xs, es);
    return min;
}

// dp with memory status
void _ppmc(char* s, int st, int l, int i, int* min, int* t, int* m)
{
    if (i - 1 >= *min)
        return;

    if (st == l)
    {
        if (i - 1 < *min)
            *min = i - 1;
        return;
    }

    m[st] = i;
    int x = 0;
    int ei = st * l;
    for (int si = st; si < l; si ++)
    {
        int ds = si - st;
        int m = st + (ds >> 1);

        x ^= s[si];

        if ((ds & 1) ? !x : (x == s[m]))
        {
            int ti = st;
            for (; ti <= m; ti ++)
                if (s[ti] != s[si - (ti - st)])
                    break;
            if (ti > m)
                t[ei ++] = si;
        }
    }

    for (int ed = -- ei; ed >= st * l; ed --)
        _ppmc(s, t[ed] + 1, l, i + 1, min, t, m);
}

int minCut(char* s)
{
    int l = strlen(s);

    if (l <= 1)
        return 0;
    int* t = malloc(sizeof(int) * l * l);
    int min = INT_MAX;
    int* ms = malloc(sizeof(int) * l);

    for (int i = 0; i < l; i ++)
        ms[i] = i;

    _ppmc(s, 0, l, 0, &min, t, ms);

    return min;
}
*/
