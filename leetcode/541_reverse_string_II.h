char* reverseStr(char* s, int k) {
    if (k == 1)
        return s;

    int t;
    int c = 0;
    int i = 0;
    bool reverse = true;

    while(s[i])
    {
        i ++;
        if (!(i % k))
        {
            if (reverse)
            {
                int e = i - 1;
                while(c < e)
                {
                    t = s[c];
                    s[c] = s[e];
                    s[e] = t;
                    c ++;
                    e --;
                }
            }
            c = i;
            reverse = !reverse;
        }
    }

    if (reverse)
    {
        int e = i - 1;
        while(c < e)
        {
            t = s[c];
            s[c] = s[e];
            s[e] = t;
            c ++;
            e --;
        }
    }
    return s;
}
