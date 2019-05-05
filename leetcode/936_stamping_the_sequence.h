// TODO write simple code !
// failed too much, but it's fun to run crc or hash like this way !
// stupid wrong hash represent !!!
// too much corner case
// need recursive ????
// no need !
// just write code ???, a little bit complicated
// to make it clear more understand code
// no need to be the smallest one ?????
// same as 664 stranger printer ?
// just recursion ?
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void _mv(char* t, int s, int e, int lt, bool eat_s, bool eat_e, bool has_f, char* o, int ol, int* hh, int* ht, int dp,
         int* fc, int* sc, int *lc, int* nc, int* r, int* rs)
{
    if (s > e)
        return;

    if (e - s + 1 < ol)
        has_f = false;

    if ((*rs) && r[(*rs) - 1] == -1)
        return;

    r[*rs] = 0;

    if (has_f)
    {
        int p = 0;
        for (int i = s; i < s + ol - 1; i ++)
            p = ((p << 8) + t[i]) % dp;

        for (int i = s + ol - 1; i <= e; i ++)
        {
            p = ((p << 8) + t[i]) % dp;

            if (i - ol >= s)
                p = (p - (fc[t[i - ol] - 'a']) + dp) % dp;

            if (t[i] == o[ol - 1])
            {

                int k = p;
                int v = ol << 16 | p;
                while (hh[k] && hh[k] != v)
                    k = (k + 1) % dp;

                if (hh[k] && !strncmp(t + i - ol + 1, o, ol))
                {
                    r[*rs] = i - ol + 1;
                    (*rs) ++;
                    r[*rs] = 0;
                    _mv(t, s,  i - ol, lt, eat_s, 1, 0, o, ol, hh, ht, dp, fc, sc, lc, nc, r, rs);
                    _mv(t, i + 1, e, lt, 1, eat_e, 1, o, ol, hh, ht, dp, fc, sc, lc, nc, r, rs);
                    return;
                }
            }
        }
    }

    if (eat_s)
    {
        int p = 0;
        // find trick way to cal the ht, from the end
        for (int i = s; i <= e && i < s + ol - 1; i ++)
        {
            p = ((p << 8) + t[i]) % dp;

            if (t[i] == o[ol - 1] && i >= ol - 1)
            {
                int k = p;
                int v = ((i - s + 1) << 16) | p;
                while (ht[k] && ht[k] != v)
                    k = (k + 1) % dp;

                if (ht[k] && !strncmp(t + s, o + ol - (i - s + 1), i - s + 1))
                {
                    r[*rs] = i - ol + 1; // not i
                    (*rs) ++;
                    _mv(t, i + 1, e, lt, 1, eat_e, has_f, o, ol, hh, ht, dp, fc, sc, lc, nc, r, rs);
                    return;
                }
            }
        }
    }

    if (eat_e)
    {
        int fs = 1;
        int p = 0;
        for (int i = e; i >= s && (e - i + 1) < ol; i --)
        {
            p = (p + t[i] * fs) % dp;
            fs = (fs << 8) % dp;
            if (t[i] == o[0] && i + ol <= lt)
            {
                int k = p;
                int v = ((e - i + 1) << 16) | p;
                while (hh[k] && hh[k] != v)
                    k = (k + 1) % dp;

                if (hh[k] && !strncmp(t + i, o, e - i + 1))
                {
                    r[*rs] = i; // not i
                    (*rs) ++;
                    _mv(t, s,  i - 1, lt, eat_s, 1, 0, o, ol, hh, ht, dp, fc, sc, lc, nc, r, rs);
                    return;
                }
            }
        }
    }

    int l = e - s + 1;

    for (int i = 0; i <= ol - l - 1; i ++)
        if (!strncmp(t + s, o + i, l) && s >= i)
        {
            r[*rs] = s - i + ol <= lt ? (s - i) : -1;
            (*rs) ++;
            return;
        }

    r[*rs] = -1;
    (*rs) ++;
    return;
}

int* movesToStamp(char* stamp, char* target, int* returnSize)
{
    if (!stamp || !target || !stamp[0] || !target[0])
        return 0;

    int ls = strlen(stamp);
    int lt = strlen(target);

    int* r = malloc(sizeof(int) * (lt * 10));
    if (ls == 1)
    {
        *returnSize = lt;
        for (int i = 0; i < lt; i ++)
            r[i] = i;
        return r;
    }

    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 131;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 4 >= ls)
            break;
    }

    // head and tail hash
    int* hh = calloc(sizeof(int), dp);
    int* ht = calloc(sizeof(int), dp);

    int sc[26] = {0};
    int lc[26] = {0};
    int* ns = malloc(sizeof(int) * ls);

    int fs = 1;
    int fc[26] = {0};

    int ph = 0;
    int pt = 0;
    for (int i = 0; i < ls; i ++)
    {
        ph = ((ph << 8) + stamp[i]) % dp;
        pt = (pt + (stamp[ls - i - 1]) * fs) % dp;
        fs = (fs << 8) % dp;

        int c = stamp[i] - 'a';

        if (lc[c])
            ns[lc[c] - 1] = i;
        else
            sc[c] = i + 1;
        lc[c] = i + 1;

        int k = ph;
        int v = (i + 1) << 16 | ph;
        while (hh[k] && hh[k] != v)
            k = (k + 1) % dp;
        hh[k] = v;

        k = pt;
        v = (i + 1) << 16 | pt;
        while (ht[k] && ht[k] != v)
            k = (k + 1) % dp;
        ht[k] = v;
    }

    for (int i = 0; i < 26; i ++)
        fc[i] = (fs * ('a' + i)) % dp;


    int rs = 0;
    r[rs] = 0;
    _mv(target, 0, lt - 1, lt, 0, 0, 1, stamp, ls, hh, ht, dp, fc, sc, lc, ns, r, &rs);

    if (r[rs - 1] == -1)
    {
        *returnSize = 0;
        return r;
    }

    *returnSize = rs;

    int s = 0;
    int e = rs - 1;
    while (s < e)
    {
        r[s] ^= r[e];
        r[e] ^= r[s];
        r[s] ^= r[e];

        s ++;
        e --;
    }
    return r;
}
