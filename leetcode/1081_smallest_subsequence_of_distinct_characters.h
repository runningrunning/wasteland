char * smallestSubsequence(char * text)
{
    int ti = 0;
    int has[26] = {0};
    int all[26] = {0};

    char* ret = calloc(sizeof(char), 27);

    while (text[ti])
        all[text[ti ++] - 'a'] ++;

    if (ti == 0)
        return ret;

    ti = 0;

    int ri = -1;

    while (text[ti])
    {
        int c = text[ti ++];
        all[c - 'a'] --;
        if (has[c - 'a'])
            continue;

        for (int i = ri; i >= 0; i --)
        {
            if (c < ret[i] && all[ret[i] - 'a'])
            {
                ri = i - 1;
                has[ret[i] - 'a'] = 0;
            }
            else
                break;
        }
        ret[++ ri] = c;
        has[c - 'a'] = 1;
    }
    ret[ri + 1] = 0;
    return ret;
}

/*
// Try another solution with stack and monotonically increasing
char * smallestSubsequence(char * text)
{
    int m = 0;
    int l = strlen(text);

    char* ret = calloc(sizeof(char), 27);
    int* b = malloc(sizeof(int) * l);

    for (int i = l - 1; i >= 0; i --)
    {
        m |= 1 << (text[i] - 'a');
        b[i] = m;
    }

    int ts = 0;
    m = 0;

    int has[26] = {0};
    for (int i = 0; i <= 26; i ++)
    {
        if (ts >= l)
        {
            ret[i] = 0;
            break;
        }

        int te = ts;
        int bits = b[ts] & (~m);

        if (!bits)
            break;

        char c = 'z' + 1;

        for (; te < l; te ++)
            if (bits == (b[te] & (~m)))
            {
                if (c > text[te] && !has[text[te] - 'a'])
                    c = text[te];
            }
            else
                break;

        for (; ts < te; ts ++)
            if (text[ts] == c)
            {
                te = ts + 1;
                break;
            }

        ts = te;

        ret[i] = c;
        has[c - 'a'] = 1;
        m |= 1 << (c - 'a');
    }
    return ret;
}
*/

/* wrong, "cbaacabcaaccaacababa" will get acb, need to store all of results and compare them
   it's doable, just need to build monotonically increasing
char * smallestSubsequence(char * text)
{
    int ti = 0;a
    int has[26] = {0};
    int all[26] = {0};


    while (text[ti])
        all[text[ti ++] - 'a'] ++;

    if (ti == 0)
        return ret;

    // wrong
    int ri = 0;
    int ori = -1;
    ti = 0;
    while (text[ti])
    {
        int c = text[ti ++];
        for (int i = ri - 1; i > ori; i --)
        {
            if (c > ret[i])
                break;
            else
            {
                if (ret[i])
                    has[ret[i] - 'a'] = 0;
                ri = i;
            }
        }
        if (!has[c - 'a'])
        {
            has[c - 'a'] = 1;
            ret[ri ++] = c;
        }
        all[c - 'a'] --;
        if (!all[c - 'a'])
            ori = ri - 1;
    }

    ret[ri] = 0;
    return ret;
}
*/
