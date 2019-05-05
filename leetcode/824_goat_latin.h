char* toGoatLatin(char* S)
{
    int i = 0;
    int a = 1;
    char* r = NULL;

    int j = 0;
    int c = S[j ++];

    while (true)
    {
        while (c == ' ')
        {
            r = realloc(r, ++ i);
            r[i - 1] = c;
            c = S[j ++];
        }

        if (!c)
        {
            r = realloc(r, ++ i);
            r[i - 1] = 0;
            break;
        }

        int s = j - 1;
        while (c && c != ' ')
            c = S[j ++];
        int e = j - 1;


        int l = e - s + a + 2;
        char b = S[s];
        bool v = b == 'a' || b == 'A' || b == 'e' || b == 'E' || b == 'i' || b == 'I'
            || b == 'o' || b == 'O' || b == 'u' || b == 'U';

        r = realloc(r, i + l);

        for (int x = v ? 0 : 1; x < e - s; x ++)
            r[i ++] = S[x + s];

        if (!v)
            r[i ++] = b;

        r[i ++] = 'm';
        r[i ++] = 'a';

        for (int x = 0; x < a; x ++)
            r[i ++] = 'a';

        a ++;
    }
    return r;
}
