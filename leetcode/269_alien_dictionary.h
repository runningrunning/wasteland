// TODO do it again and more careful !!!!
// it's my way to do the graph
// can do a little optimization
// be careful, stupid mistake !!!!!!!
// stupid mistake, only need to compare the previous !!!
// failed toooooo much !!!
bool _has(char** ns, int x, int y)
{
    if (!ns[x])
        return false;

    for (int i = 1; i < ns[x][0]; i ++)
        if (ns[x][i] == y)
            return true;
    for (int i = 1; i < ns[x][0]; i ++)
        if (_has(ns, ns[x][i], y))
            return true;
    return false;
}

char* alienOrder(char** words, int wordsSize)
{
    if (!words || !wordsSize)
        return strdup("");

    if (wordsSize == 1)
        return strdup(words[0]);

    int f = 0;
    int hi = 0;
    char hs[26] = {0};
    char* ns[26];
    memset(ns, 0, sizeof(char*) * 26);

    for (int i = 1; i < wordsSize; i ++)
    {
        char* p = words[i - 1];
        int cc, oc;
        char* c = words[i];
        int e = -1;

        while (c[e + 1] && c[e + 1] == p[e + 1])
        {
            cc = c[e + 1] - 'a';
            if (!(f & (1 << cc)))
            {
                f |= 1 << cc;
                hs[hi ++] = cc;
            }
            e ++;
        }

        if (c[e + 1])
        {
            int x = e + 1;
            cc = c[x ++];
            while (cc)
            {
                cc -= 'a';
                if (!(f & (1 << cc)))
                {
                    f |= 1 << cc;
                    hs[hi ++] = cc;
                }
                cc = c[x ++];
            }
        }

        if (p[e + 1])
        {
            int x = e + 1;
            cc = p[x ++];
            while (cc)
            {
                cc -= 'a';
                if (!(f & (1 << cc)))
                {
                    f |= 1 << cc;
                    hs[hi ++] = cc;
                }
                cc = p[x ++];
            }
        }

        if (c[e + 1] && p[e + 1])
        {
            cc = c[e + 1];
            oc = p[e + 1];

            cc -= 'a';
            oc -= 'a';

            if (_has(ns, oc, cc))
                return strdup("");

            if (!ns[cc])
            {
                ns[cc] = malloc(2);
                ns[cc][0] = 2;
                ns[cc][1] = oc;
            }
            else
            {
                bool found = false;
                int l = ns[cc][0];
                for (int j = 1; j < l ; j ++)
                    if (ns[cc][j] == oc)
                    {
                        found = true;
                        break;
                    }

                if (!found)
                {
                    ns[cc] = realloc(ns[cc], l + 1);
                    ns[cc][l] = oc;
                    ns[cc][0] = l + 1;
                }
            }
        }
    }

    int ri = 0;
    char* ret = malloc(27);

    int nhi = 0;
    for (int i = 0; i < hi; i ++)
        if (!ns[hs[i]])
            ret[ri ++] = hs[i] + 'a';
        else
            hs[nhi ++] = hs[i];

    ret[ri] = 0;
    hi = nhi;
    while (hi)
    {
        nhi = 0;
        for (int i = 0; i < hi; i ++)
        {
            bool found = false;
            for (int j = 1; j < ns[hs[i]][0]; j ++)
            {
                if (ns[ns[hs[i]][j]])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                free(ns[hs[i]]);
                ns[hs[i]] = NULL;
                ret[ri ++] = hs[i] + 'a';
            }
            else
            {
                hs[nhi ++] = hs[i];
            }
        }
        hi = nhi;
    }
    ret[ri] = 0;
    return ret;
}
