int countSegments(char* s)
{
    if (!s)
        return 0;

    int i = 0;
    char c = s[i ++];
    int n = 0;

    while (c == ' ')
        c = s[i ++];

    while (c)
    {
        while(c && c != ' ')
            c = s[i ++];
        n ++;
        while (c == ' ')
            c = s[i ++];
    };
    return n;
}
