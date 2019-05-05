/* A SUBSEQUENCE is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string. */
/* TODO do it again !!!! */
// is_sub(ts, sl[j] & s_mask, itl, jsl))
/* STUPID ERROR */
/* must take account in  all of corner cases.*/
/* can not use & directly, e.g. 5 & 4 == 4 but not 5 != 4 */
// ["aabbcc", "aabbcc","cb","abc"] !!! IT'S 2, NOT 3
/* how to define substring, subsequence !!! */
/* try AGAIN */

bool is_sub(long x, long s, int xl, int sl)
{
    int j = 0;
    long c_mask = 0x1F;

    for (int i = 0; i < xl; i ++)
    {
        int t = x & c_mask;
        for (; j < sl; j ++)
        {
            int ts = s & c_mask;
            s >>= 5;

            if (ts == t)
                break;
        }

        if (j == sl)
            return false;

        x >>= 5;
    }
    return true;
}

void l_flus_sort(long* n, int s, int e, int* f)
{
    if (s > e)
        return;

    long t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;

        t = f[e];
        f[e] = f[s];
        f[s] = t;
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
            t = n[e];
            n[e] = n[s];
            n[s] = t;

            t = f[e];
            f[e] = f[s];
            f[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;

            t = f[e];
            f[e] = f[i];
            f[i] = t;
        }
    }

    l_flus_sort(n, cs, e - 1, f);
    l_flus_sort(n, e + 1, ce, f);
}

int findLUSlength(char** strs, int strsSize) {
    if (!strs || !strsSize)
        return -1;

    int ls[16] = {0};
    int max_l = INT_MIN;

    int sf[50] = { 0 };
    long sl[50] = { 0L };
    long sm[16] = { 0L };

    for (int i = 0; i < strsSize; i ++)
    {
        int f = 0;
        long t = 0;
        long si = 0;

        while (strs[i][si])
        {
            int cf = strs[i][si] - 'a';

            f |= 1 << cf;
            /* assuming it's alwasy 'a' ~ 'z' */
            t = (t << 5) | (cf + 1);
            si ++;
        }

        ls[si] ++;

        if (si > max_l)
            max_l = si;

        sl[i] = (si << 50) | t;
    }

    if (ls[max_l] == 1)
        return max_l;

    long m = 0;
    long c_mask = 0x1FL;

    for (int i = 0; i < 16; i ++)
    {
        sm[i] = m;
        m = (m << 5) | c_mask;
    }

    // l_flus_sort(ss, 0, strsSize - 1);
    l_flus_sort(sl, 0, strsSize - 1, sf);

    long l_mask = 0xFFL << 50;
    long s_mask = ~ l_mask;

    long pre = l_mask;
    for (int i = strsSize - 1; i >= 0; i --)
    {
        long tmp = sl[i];

        if (tmp == pre)
            continue;

        pre = tmp;

        if (i && (tmp == sl[i - 1]))
            continue;

        long tl = tmp & l_mask;
        long ts = tmp & s_mask;
        int itl = (tl >> 50);
        long tm = sm[itl];

        if (!tl || !ts)
            break;

        bool found = false;
        for (int j = strsSize - 1; j >= 0; j --)
        {
            if (i == j)
                continue;

            if (sl[i] == sl[j])
            {
                found = true;
                break;
            }

            if (sl[j] < tl)
                break;

            if ((sf[j] & sf[i]) != sf[i])
                continue;

            int jsl = (sl[j] & l_mask) >> 50;
            long ss = sl[j] & s_mask;

            int sf = jsl - itl;

            while (sf + 1)
            {
                if ((ss & tm) == ts)
                {
                    found = true;
                    break;
                }

                ss >>= 5;
                sf --;
            }

            if (found || (itl > 1 && is_sub(ts, sl[j] & s_mask, itl, jsl)))
            {
                found = true;
                break;
            }
        }

        if (!found)
            return tl >> 50;
    }
    return -1;
}
