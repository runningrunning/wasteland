char* convertToTitle(int n)
{
    if (n <= 0)
        return NULL;

    int cnt = 0;
    int ret[10] = {0};

    while(n)
    {
        int t = n % 26;
        if (t == 0)
            t = 26;
        n -= t;
        ret[cnt ++] = t;
        n /= 26;
    }

    char* r = malloc(sizeof(char) * (cnt + 1));
    r[cnt] = 0;

    n = 0;
    for(;cnt > 0; cnt --)
        r[n ++] = ret[cnt - 1] + 'A' - 1;

    return r;
}
