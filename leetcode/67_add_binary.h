/* remember to add 0 at the end of the string.  */
char* addBinary(char* a, char* b)
{
    int la = strlen(a);
    int lb = strlen(b);
    if (la == 0 || lb == 0)
        return la == 0 ? b : a;

    int sl, ll;
    char* lo;
    char* so;

    if (la > lb)
    {
        ll = la;
        lo = a;
        sl = lb;
        so = b;
    }
    else
    {
        ll = lb;
        lo = b;
        sl = la;
        so = a;
    }

    int u = 0;
    for(int i = 1; i <= sl; i ++)
    {
        switch(lo[ll - i] + so[sl - i])
        {
        case 96:
            if (u)
                lo[ll - i] = '1';
            u = 0;
            break;
        case 97:
            if (u)
                lo[ll - i] = '0';
            else
                lo[ll - i] = '1';
            break;
        case 98:
            if (!u)
                lo[ll - i] = '0';
            u = 1;
            break;
        default:
            break;
        }
    }

    for(int i = 0; i < ll - sl; i ++)
    {
        if (lo[ll - sl - 1 - i] == '1')
        {
            if (u)
                lo[ll - sl - 1 - i] = '0';
        }
        else
        {
            if (u)
            {
                lo[ll - sl - 1 - i] = '1';
                u = 0;
            }
        }
    }

    if (u == 0)
        return lo;

    char* r = malloc(sizeof(char) * (ll + 2));
    r[0] = '1';
    memcpy(r + 1, lo, ll);
    r[ll + 1] = 0;
    return r;
}
