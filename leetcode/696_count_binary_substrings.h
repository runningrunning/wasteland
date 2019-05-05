int countBinarySubstrings(char* s)
{
    int a = 0;
    int si = 0;
    int ps[] = {0, 0};

    int c;
    int p = 2;

    while(s[si])
    {
        c = s[si ++] - '0';
        if (c != p)
        {
            if (ps[0] && ps[1])
            {
                a += ps[0] < ps[1] ? ps[0] : ps[1];
                ps[c] = 0;
            }
        }
        p = c;
        ps[c] ++;
    }

    if (ps[0] && ps[1])
    {
        a += ps[0] < ps[1] ? ps[0] : ps[1];
        ps[c] = 0;
    }
    return a;
}
