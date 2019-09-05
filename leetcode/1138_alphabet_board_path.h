// corner case for Z
char* alphabetBoardPath(char* target)
{
    int p[26] = {0};
    char* b[] = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};

    for (int c = 0; c < 26; c ++)
    {
        char a = c + 'a';
        for (int i = 0; i < sizeof(b)/sizeof(b[0]); i ++)
        {
            int si = 0;
            char* s = b[i];

            while (s[si])
                if (s[si] == a)
                {
                    p[c] = i << 8 | si;
                    break;
                }
                else
                    si ++;
        }
    }

    int l = strlen(target);
    int ri = 0;

    char* r = malloc(sizeof(char) * (10 * l + 1));

    int x = 0;
    int y = 0;

    int xz = p[25] >> 8;
    int yz = p[25] & 0xFF;

    for (int i = 0; i < l; i ++)
    {
        char a = target[i] - 'a';

        if (x == xz && y == yz && a != 25)
        {
            r[ri ++] = 'U';
            x -= 1;
        }

        int xt = p[a] >> 8;
        int yt = p[a] & 0xFF;

        char c = y > yt ? 'L' : 'R';
        int d = abs(y - yt);
        while (d --)
            r[ri ++] = c;
        c = x > xt ? 'U' : 'D';
        d = abs(x - xt);

        while (d --)
            r[ri ++] = c;

        r[ri ++] = '!';
        x = xt;
        y = yt;
    }

    r[ri] = 0;
    return r;
}
