// corner case
// "" "" are true
// "ab" "aa" are false as it's not bijection !!!
bool wpm(char* p, int ps, int pe, char* s, int ss, int se, long* m, int* f)
{
    if (pe - ps > se - ss)
        return false;

    if (ps == pe && ss == se)
        return true;

    if (ps >= pe || ss >= se)
        return false;

    char c = p[ps] - 'a';

    if (m[c])
    {
        int ns = m[c] >> 32;
        int nn = m[c] & 0xFFFFFFFF;

        if (se - ss < nn)
            return false;

        for (int i = 0; i < nn; i ++)
            if (s[ns + i] != s[ss + i])
                return false;
        return wpm(p, ps + 1, pe, s, ss + nn, se, m, f);
    }
    else
    {
        if (ps + 1 == pe)
        {
            int fx = 0;
            int fa = 0;

            for (int i = ss; i < se; i ++)
            {
                fx ^= s[i];
                fa += s[i];
            }

            f[c] = fa << 16 | fx << 8 | ((se - ss) % 256);

            bool has = false;

            for (int j = 0; j < 26; j ++)
            {
                if (j == c || !m[j])
                    continue;

                if (f[c] == f[j])
                {
                    int ns = m[j] >> 32;
                    int nn = m[j] & 0xFFFFFFFF;

                    if (nn == (se - ss) && !strncmp(s + ss, s + ns, nn))
                    {
                        has = true;
                        break;
                    }
                }
            }

            f[c] = m[c] = 0;

            return !has;
        }

        int l = pe - ps - 1;

        int fx = 0;
        int fa = 0;

        for (int i = 0; i < se - l; i ++)
        {
            m[c] = (((long) ss) << 32) | (i + 1);

            fx ^= s[ss + i];
            fa += s[ss + i];
            f[c] = fa << 16 | fx << 8 | ((i + 1) % 256);

            bool has = false;

            for (int j = 0; j < 26; j ++)
            {
                if (j == c || !m[j])
                    continue;

                if (f[c] == f[j])
                {
                    int ns = m[j] >> 32;
                    int nn = m[j] & 0xFFFFFFFF;

                    if (nn == i + 1 && !strncmp(s + ss, s + ns, nn))
                    {
                        has = true;
                        break;
                    }
                }
            }

            if (has)
                continue;

            if (wpm(p, ps + 1, pe, s, ss + i + 1, se, m, f))
                return true;
        }

        f[c] = 0;
        m[c] = 0;
    }

    return false;
}

bool wordPatternMatch(char* pattern, char* str)
{
    if (!pattern || !str)
        return false;

    int f[26] = {0};
    long match[26] = {0l};
    int sl = strlen(str);
    int pl = strlen(pattern);

    // "" "" is true
    if (!pl)
        return !sl;

    if (pl > sl)
        return false;

    if (pl == 1)
        return true;
    return wpm(pattern, 0, pl, str, 0, sl, match, f);
}
