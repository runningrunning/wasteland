char* getHint(char* secret, char* guess)
{
    if (!secret || !guess)
        return NULL;

    int as = 0;
    int bs = 0;
    int ss[10] = {0};
    int gg[10] = {0};

    int si = 0;
    while(secret[si])
    {
        char s = secret[si] - '0';
        char g = guess[si] - '0';

        if (s == g)
            as ++;
        else
        {
            ss[s] ++;
            gg[g] ++;
        }
        si ++;
    }

    for (int i = 0; i < 10; i ++)
        bs += ss[i] < gg[i] ? ss[i] : gg[i];

    char* ret = malloc(64);
    int x = sprintf(ret, "%dA%dB", as, bs);
    ret[x] = 0;
    return ret;
}
