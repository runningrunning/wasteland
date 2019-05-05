int numJewelsInStones(char* J, char* S)
{
    if (!J || !S || !J[0] || !S[0])
        return 0;
    int i = 0;
    long sf = 0;
    char c = J[i ++];

    while (c)
    {
        sf |= (long) (1L << c);
        c = J[i ++];
    }

    i = 0;
    c = S[i ++];

    int num = 0;
    while (c)
    {
        if (sf & (long) (1L << c))
            num ++;
        c = S[i ++];
    }

    return num;
}
