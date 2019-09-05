int numKLenSubstrNoRepeats(char * S, int K)
{
    if (K > 26)
        return 0;

    int b[26] = {0};
    int nr = 0;
    int num = 0;

    for (int i = 0; i < K; i ++)
    {
        if (!S[i])
            return 0;

        int c = S[i] - 'a';
        if (b[c] == 1)
            nr ++;
        b[c] ++;
    }

    if (!nr)
        num ++;
    int i = K;

    while (S[i])
    {
        int c = S[i] - 'a';
        if (b[c] == 1)
            nr ++;
        b[c] ++;
        c = S[i - K] - 'a';
        if (b[c] == 2)
            nr --;
        b[c] --;
        if (!nr)
            num ++;
        i ++;
    }
    return num;
}

