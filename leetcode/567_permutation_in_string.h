/* Same as 438_find_all_anagrams_in_a_string */
/* In this case, substring include s1 itself !!! */
bool checkInclusion(char* p, char* s)
{
    int i = 0;
    int x = 0;
    int f = 0;
    int a = 0;

    while(p[i])
    {
        int v = p[i] - 'a';
        a += v;
        f |= 1 << v;
        x ^= v;
        i ++;
    }

    int l = strlen(s);
    if (l < i)
        return false;

    int sx = 0;
    int sf = 0;
    int sa = 0;

    int ac[26] = {0};

    for (int j = 0; j < i; j ++)
    {
        int sv = s[j] - 'a';
        sa += sv;
        sf |= 1 << sv;
        sx ^= sv;
        ac[sv] ++;
    }

    if (sa == a && sf == f && sx == x)
        return true;

    for (int j = i; j < l; j ++)
    {
        int sv = s[j] - 'a';
        int pv = s[j - i] - 'a';
        if (pv != sv)
        {
            ac[pv] --;
            ac[sv] ++;
            sa += sv - pv;
            if (!ac[pv]) // only when pv is 0, then remove it.
                sf &= ~(1 << pv);
            sf |= 1 << sv;
            sx ^= sv ^ pv;
        }
        if (sa == a && sf == f && sx == x)
            return true;
    }

    return false;
}
