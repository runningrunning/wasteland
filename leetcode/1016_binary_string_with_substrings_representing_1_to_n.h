bool queryString(char* S, int N)
{
    int l = strlen(S);
    if (N >= l * 32)
        return false;

    int x = 1;
    int n = 0;

    while (x < N)
    {
        x <<= 1;
        n ++;
    }

    x = n;
    n = 0;

    char* f = calloc(sizeof(char), (N + 1));
    for (int i = 0; i < l; i ++)
    {
        if (S[i] == '0')
            continue;
        int c = 1;

        if (!f[c])
        {
            n ++;
            f[c] = 1;
        }

        for (int j = 1; j <= x && (i + j < l); j ++)
        {
            c = (c << 1) + S[i + j] - '0';
            if (c > N)
                break;

            if (!f[c])
            {
                n ++;
                f[c] = 1;
            }
        }
    }
    return n == N;
}
