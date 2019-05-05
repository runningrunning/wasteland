// what happened when hash value is 0, e.g. stol return, we need flags to tell 0 is valid value.
// that's why we need V_MASK and H_MASK
long stol(char* s, int* n)
{
    int i = 0;
    int c = s[i ++];

    while(c && (c < 'A' || (c > 'Z' && c < 'a') || c > 'z'))
        c = s[i ++];

    if (!c)
        return -1;

    long t = 0;
    while (c && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
    {
        if (c >= 'a' && c <= 'z')
            c -= 'a';
        else
            c -= 'A';
        t = (t << 5) | (c + 1);
        c = s[i ++];
    }

    *n = i - 1;
    return t;
}

#define F_MASK  (1L << 63)
#define V_MASK  (~(1L << 63))
char* mostCommonWord(char* paragraph, char** banned, int bannedSize)
{
    if (!paragraph)
        return NULL;

    int pdp = 2053;
    int bdp = 257;
    int* phn = calloc(pdp, sizeof(int));
    long* ph = calloc(pdp, sizeof(long));
    long* bh = calloc(bdp, sizeof(long));

    for (int i = 0; i < bannedSize; i ++)
    {
        int n = 0;

        long t = stol(banned[i], &n);
        int x = t % bdp;
        while ((bh[x] & F_MASK) && (bh[x] & V_MASK) != t)
            x = (x + 1) % bdp;

        if (!(bh[x] & F_MASK))
            bh[x] = F_MASK | t;
    }

    int m = 0;
    long mv = 0;
    int n = 0;
    while(paragraph[n])
    {
        int next = 0;
        long t = stol(paragraph + n, &next);

        if (t == -1)
            break;

        n += next;

        int x = t % bdp;

        while ((bh[x] & F_MASK) && (bh[x] & V_MASK) != t)
            x = (x + 1) % bdp;

        if (bh[x] & F_MASK)
            continue;

        x = t % pdp;
        while ((ph[x] & F_MASK) && (ph[x] & V_MASK) != t)
            x = (x + 1) % pdp;

        if (!(ph[x] & F_MASK))
            ph[x] = F_MASK | t;
        phn[x] ++;

        if (phn[x] > m)
        {
            m = phn[x];
            mv = ph[x];
        }
    }

    char* r = malloc(11);
    r[10] = 0;

    int shift = 50;
    long mask = 0x1FL << shift;

    while (!(mask & mv))
    {
        shift -= 5;
        mask >>= 5;
    }

    int ri = 0;
    while (mask & mv)
    {
        r[ri ++] = ((mask & mv) >> shift) + 'a' - 1;
        mask >>= 5;
        shift -= 5;
    }

    r[ri] = 0;
    return r;
}
