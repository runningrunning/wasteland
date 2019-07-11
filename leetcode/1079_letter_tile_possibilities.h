// how to calculate the array ?
void ntp(char* c, int s, int e, int* a, int l, char* b, int* n)
{
    if (s == e)
    {
        int x = 0;
        for (int i = 0; i <= e; i ++)
        {
            x = x * l + (a[c[i] - 'A']);
            if (!b[x])
            {
                b[x] = 1;
                (*n) ++;
            }
        }
    }
    else
    {
        int pre = 0;
        int cs = c[s];
        for (int i = s; i <= e; i ++)
        {
            if (c[i] != pre)
            {
                pre = c[i];
                c[s] = c[i];
                c[i] = cs;
                ntp(c, s + 1, e, a, l, b, n);
                c[i] = c[s];
                c[s] = cs;
            }
        }
    }
}

int numTilePossibilities(char * tiles)
{
    int t = 0;
    int a[26] = {0};
    int i = 0;

    while (tiles[i])
    {
        int c = tiles[i ++] - 'A';
        if (!a[c])
        {
            a[c] = ++ t;
        }
    }

    t ++;

    if (i == 1)
        return 1;

    int n = 1;
    for (int j = 0; j < i; j ++)
        n *= t;

    char* b = calloc(sizeof(char), n);
    int num = 0;
    ntp(tiles, 0, i - 1, a, t, b, &num);
    return num;
}
