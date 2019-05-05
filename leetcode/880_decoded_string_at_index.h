char* decodeAtIndex(char* S, int K)
{
    int i = 0;
    char c = S[i ++];
    long n = 1;

    while(true)
    {
        if (c >= 'a' && c <= 'z')
        {
            if (n == K)
                break;
        }
        else
        {
            n --;

            long m = c - '0';
            if (n * m >= K)
                return decodeAtIndex(S, (K % n) ? (K % n) : n);
            n *= m;
        }

        n ++;
        c = S[i ++];
    }

    char* r = malloc(2);
    r[0] = c;
    r[1] = 0;
    return r;
}
