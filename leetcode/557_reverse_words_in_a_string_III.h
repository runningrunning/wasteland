void swap(char* c, int s, int e)
{
    if (s >= e)
        return;
    char t;

    while(s < e)
    {
        t = c[s];
        c[s] = c[e];
        c[e] = t;
        s ++;
        e --;
    }
}

char* reverseWords(char* s)
{
    bool in = false;

    int i = 0;
    int si = 0;

    while(s[i])
    {
        if (s[i] == ' ')
        {
            if (in)
                swap(s, si, i - 1);

            in = false;
        }
        else if (!in)
        {
            in = true;
            si = i;
        }

        i ++;
    }

    if (in)
        swap(s, si, i - 1);
    return s;
}
