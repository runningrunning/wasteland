char* customSortString(char* S, char* T)
{
    if (!T)
        return NULL;

    int si[256] = {0};
    int tl = strlen(T);

    char* r = malloc(tl + 1);
    r[tl] = 0;

    int i = 0;
    int c = S[i ++];

    while (c)
    {
        si[c] = 1;
        c = S[i ++];
    }

    int ri = 0;
    for (i = 0; i < tl; i ++)
    {
        c = T[i];
        if (si[c])
            si[c] ++;
        else
            r[ri ++] = c;
    }

    i = 0;
    c = S[i ++];

    while (c)
    {
        si[c] -= 1;
        int n = si[c];
        while (n --)
            r[ri ++] = c;
        c = S[i ++];
    }
    return r;
}
