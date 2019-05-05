// find simple solution ~!
int compare(char* a, char* b, int l)
{
    for (int i = 0; i < l; i ++)
        if (a[i] != b[i])
            return a[i] > b[i] ? 1 : - 1;
    return 0;
}

bool big_than(char* a, char* b, int l)
{
    return compare(a, b, l) == 1;
}

void bw_sort(int* n, int s, int e, char** w)
{
    if (s >= e)
        return;
    int t;
    char* tc;

    if (n[s] > n[e] || (n[s] == n[e] && big_than(w[s], w[e], n[s])))
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        tc = w[s];
        w[s] = w[e];
        w[e] = tc;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i= s + 1; i <= e; i ++)
    {
        while (n[i] < n[s] || (n[i] == n[s] && !big_than(w[i], w[s], n[s]))) i ++;
        while (n[e] > n[s] || (n[e] == n[s] &&  big_than(w[e], w[s], n[s]))) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            tc = w[s];
            w[s] = w[e];
            w[e] = tc;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;

            tc = w[e];
            w[e] = w[i];
            w[i] = tc;
        }
    }

    bw_sort(n, cs, e - 1, w);
    bw_sort(n, e + 1, ce, w);
}

char* addBoldTag(char* S, char** words, int wordsSize)
{
    if (!words || !wordsSize)
        return S;

    int wl[256] = {0};

    int dl = 0;
    int si[256] = {0};
    int nl[256] = {0};
    int fl[256] = {0};
    int stfl[256] = {0};
    int asfl = 0;

    // compare strings
    for (int i = 0; i < wordsSize; i ++)
        wl[i] = strlen(words[i]);
    bw_sort(wl, 0, wordsSize - 1, words);

    int pre_l = 0;
    for (int i = 0; i < wordsSize; i ++)
    {
        if (pre_l != wl[i])
        {
            dl ++;
            pre_l = wl[i];
        }

        int l = dl - 1;

        wl[l] = wl[i];

        if (!si[l])
            si[l] = i + 1;
        nl[l] ++;

        char* w = words[i];

        for (int k = 0; k < wl[i]; k ++)
            fl[l] |= 1 << (w[k] - 'a');

        stfl[l] |= 1 << (w[0] - 'a');
        asfl |= 1 << (w[0] - 'a');
    }

    int i = 0;
    char c = S[i ++];
    int sl = strlen(S);

    int ri = 0;
    char* r = malloc(sl * 8);

    int start = -1;
    int end = -1;
    for (int i = 0; i < sl; i ++)
    {
        int sf = 1 << (S[i] - 'a');

        if (sf & asfl)
        {
            int sa = sf;

            for (int j = dl - 1; j >= 0; j --)
            {
                int l = wl[j] - 1;

                if (i + l >= sl)
                    continue;

                if (i + l < end)
                    break;

                if (!(stfl[j] & sf))
                    continue;

                bool match = false;
                for (int k = 0; k < nl[j]; k ++)
                {
                    if (!strncmp(words[si[j] - 1 + k], &S[i], l + 1))
                    {
                        match = true;
                        break;
                    }
                }

                if (match)
                {
                    if (start == -1)
                        start = i;

                    if (end < i + l)
                        end = i + l;
                    break;
                }
            }

            if (i == start)
            {
                r[ri ++] = '<';
                r[ri ++] = 'b';
                r[ri ++] = '>';
                r[ri ++] = S[i];
                continue;
            }
        }
        if (end != -1 && i - 1 == end)
        {
            r[ri ++] = '<';
            r[ri ++] = '/';
            r[ri ++] = 'b';
            r[ri ++] = '>';
            r[ri ++] = S[i];

            start = -1;
            end = -1;
        }
        else
        {
            r[ri ++] = S[i];
        }
    }

    if (end != -1 && sl - 1 == end)
    {
            r[ri ++] = '<';
            r[ri ++] = '/';
            r[ri ++] = 'b';
            r[ri ++] = '>';
    }
    r[ri] = 0;
    return r;
}
