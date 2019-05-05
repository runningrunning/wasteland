/* corner case of input of all of DASH */
char* licenseKeyFormatting(char* S, int K)
{
    int l = 0;
    int i = 0;
    char c = S[i];

    while(c)
    {
        if (c == '-')
            l ++;
        c = S[++ i];
    }

    int n = i - l;
    int d = n / K - 1;
    d += (n % K) ? 1 : 0;

    char* ret;

    if (!n)
    {
        ret = malloc(1);
        ret[0] = 0;
        return ret;
    }

    ret = malloc(n + d + 1);
    ret[n + d] = 0;

    i = 0;
    int j = 0;

    int left = n;
    int need = (n % K) ? (n % K) : K;

    while(1)
    {
        int copy = need;
        while(need)
        {
            while(S[j] == '-')
                j ++;

            ret[i ++] = (S[j] >= 'a') ? (S[j] - 'a' + 'A') : S[j];
            j ++;
            need --;
        }

        left -= copy;

        if (!left)
            break;

        ret[i ++] = '-';
        need = K;
    }

    return ret;
}
