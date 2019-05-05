char* countAndSay(int n)
{
    if (n == 0)
        return "";

    int lsize = 1024;
    char* t1 = malloc(sizeof(char) * lsize);
    char* t2 = malloc(sizeof(char) * lsize);
    memset(t1, 0, sizeof(char) * lsize);
    memset(t2, 0, sizeof(char) * lsize);

    strcpy(t1, "1");

    if (n == 1)
        return t1;

    char* lt;
    for(int i = 2; i <= n; i ++)
    {
        char* t = !(i % 2) ? t2 : t1;
        char* r = !(i % 2) ? t1 : t2;

        int s = 1;
        int c = 1;
        int w = 0;
        char pre = r[0];
        while(r[s])
        {
            if (pre == r[s])
                c ++;
            else
            {
                t[w ++] = c + '0';
                t[w ++] = pre;
                pre = r[s];
                c = 1;
            }
            s ++;
        }
        t[w] = c + '0';
        t[w + 1] = pre;
        t[w + 2] = 0;
        lt = t;

        if (w > lsize / 2)
        {
            lsize *= 8;
            t1 = realloc(t1, lsize);
            t2 = realloc(t2, lsize);
            lt = !(i % 2) ? t2 : t1;
        }
    }
    return lt;
}
