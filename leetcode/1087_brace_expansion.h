/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// no nested
void _expand(char* s, int si, char* t, int ti, char*** r, int* ri)
{
    if (!s[si])
    {
        int n = *ri;
        char* x = malloc(sizeof(char) * (ti + 1));
        memcpy(x, t, sizeof(char) * ti);
        x[ti] = 0;
        (*r)[n] = x;
        (*ri) = n + 1;
    }
    else
    {
        while (s[si] && s[si] != '{')
            t[ti ++] = s[si ++];
        if (!s[si])
            _expand(s, si, t, ti, r, ri);
        else
        {
            // skip {
            si ++;
            int c[26] = {0};
            while (s[si] && s[si] != '}')
            {
                if (s[si] != ',')
                    c[s[si] - 'a'] = 1;
                si ++;
            }
            // skip }
            si ++;

            for (int i = 0; i < 26; i ++)
                if (c[i])
                {
                    t[ti] = 'a' + i;
                    _expand(s, si, t, ti + 1, r, ri);
                }
        }
    }
}

char ** expand(char * S, int* returnSize)
{
    int num = 1;
    char si = 0;
    int pre = -1;

    while (S[si])
    {
        char c = S[si];
        if (c == '{')
            pre = si;
        else if (c == '}')
            num *= (si - pre) / 2;
        si ++;
    }

    int ri = 0;
    char** r = malloc(sizeof(char*) * num);
    *returnSize = num;

    if (num == 1 && pre == -1)
    {
        r[0] = malloc(sizeof(char) * (si + 1));
        memcpy(r[0], S, sizeof(char) * si);
        r[0][si] = 0;
        return r;
    }

    int ti = 0;
    char tmp[256];
    _expand(S, 0, tmp, ti, &r, &ri);
    return r;
}

