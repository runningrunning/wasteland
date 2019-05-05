/* Careful !!!! */
int _in(char* r, int i, int x)
{
    char s[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    if (i || (x & 0xF0))
    {
        r[i] = s[(x >> 4) & 0xF];
        r[i + 1] = s[x & 0xF];
        return 2;
    }
    r[i] = s[x & 0xF];
    return 1;
}

char* toHex(int num)
{
    char* ret = malloc(8 + 1);
    ret[8] = 0;

    char s[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    if (num >= 0 && num < 16)
    {
        ret[0] = s[num];
        ret[1] = 0;
        return ret;
    }

    int x;
    int i = 0;
    int ob = 24;
    int of = 0xFF000000;

    int t = 4;
    while(t --)
    {
        x = num & of;
        if (x || i)
            i += _in(ret, i, x >> ob);

        of >>= 8;
        ob -= 8;
    }

    ret[i] = 0;
    return ret;
}
