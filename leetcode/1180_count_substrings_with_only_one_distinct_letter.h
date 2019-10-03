int countLetters(char * S)
{
    int p = 0;
    int i = 0;
    int n = 0;
    int s = 0;

    while(S[i])
    {
        int c = S[i ++];
        if (c != p)
            s = 0;
        p = c;
        n += ++s;
    }

    return n;
}

