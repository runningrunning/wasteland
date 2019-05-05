// DP, 0 and 9 and **
// "*" can not be 0 !!!
// can be optimized from the previous pattern !!!
#define PRIMER 1000000007
#define FAST ('9' - '*' + 1) // must add 1 for extra one !!!

int _nd(char* s, int i, int e, int* t, int* f)
{
    if (!s[i])
        return 1;

    if (t[i])
        return t[i] - 1;

    if (s[i] == '0')
    {
        t[i] = 1;
        return 0;
    }

    if (i == e)
    {
        t[i] = (s[i] == '*' ? 9 : 1) + 1;
        return t[i] - 1;
    }

    long n1 = _nd(s, i + 1, e, t, f);

    if (s[i] > '2')
    {
        t[i] = n1 + 1;
        return t[i] - 1;
    }

    long n2 = _nd(s, i + 2, e, t, f);

    long x = 1;
    int nc = s[i + 1];

    int f1, f2;
    int fx = (s[i] - '*') * FAST + nc - '*';

    if (!f[fx])
    {
        bool ns = nc == '*';

        if (s[i] == '1')
        {
            f1 = 1;
            f2 = ns ? 9 : 1;
        }
        else if (s[i] == '2')
        {
            f1 = 1;
            f2 = ns ? 6 : (nc < '7' ? 1 : 0);
        }
        else
        {
            if (ns)
            {
                f1 = 9;
                f2 = 15;
            }
            else
            {
                f1 = 9;
                f2 = (nc < '7') ? 2 : 1;
            }
        }

        f[fx] = f1 << 16 | f2;
    }
    else
    {
        f1 = f[fx] >> 16;
        f2 = f[fx] & 0xFFFF;
    }
    x = f1 * n1 + f2 * n2;
    t[i] = x % PRIMER + 1;
    return t[i] - 1;
}

int numDecodings(char* s)
{
    int l = strlen(s);
    if (!l)
        return 0;
    int* t = calloc(sizeof(int), l);
    int* f = calloc(sizeof(int), 256);
    return _nd(s, 0, l - 1, t, f);
}

/*
long _nd(char* s, int i, int e, int* t)
{
    if (!s[i])
        return 1;

    if (t[i])
        return t[i];

    if (s[i] == '0')
        return 0;

    long x = 1;
    if (s[i] == '1')
    {
        if (i != e)
            x = ((s[i + 1] == '*') ? 9 : 1) * _nd(s, i + 2, e, t)
                + _nd(s, i + 1, e , t);
    }
    else if (s[i] == '2')
    {
        if (i != e)
            x = ((s[i + 1] == '*') ? 6 : ((s[i + 1] < '7') ? 1 : 0)) * _nd(s, i + 2, e, t)
                + _nd(s, i + 1, e, t);
    }
    else if (s[i] == '*')
    {
        if (i == e)
            x = 9;
        else
        {
            if (s[i + 1] == '*')
            {
                x = 15 * _nd(s, i + 2, e, t)
                    + 9 * _nd(s, i + 1, e, t);
            }
            else
            {
                if (s[i + 1] < '7')
                {
                    x = 2 * _nd(s, i + 2, e, t)
                        + 9 * _nd(s, i + 1, e, t);
                }
                else
                {
                    x = _nd(s, i + 2, e, t)
                        + 9 * _nd(s, i + 1, e, t);
                }
            }
        }
    }
    else
    {
        x = _nd(s, i + 1, e, t);
    }

    t[i] = x % 1000000007;
    return t[i];
}

int numDecodings(char* s)
{
    int l = strlen(s);
    if (!l)
        return 0;

    int* t = calloc(sizeof(int), l);
    return _nd(s, 0, l - 1, t);
}

int _nd(char* s, int i, int e, int* t)
{
    if (!s[i])
        return 1;

    if (t[i])
        return t[i];

    if (s[i] == '0')
        return 0;

    long x = 1;
    if (s[i] == '1')
    {
        if (i != e)
            x = ((s[i + 1] == '*') ? 10 : 1) * _nd(s, i + 2, e, t)
                + _nd(s, i + 1, e , t);
    }
    else if (s[i] == '2')
    {
        if (i != e)
            x = ((s[i + 1] == '*') ? 7 : ((s[i + 1] < '7') ? 1 : 0)) * _nd(s, i + 2, e, t)
                + _nd(s, i + 1, e, t);
    }
    else if (s[i] == '*')
    {
        if (i == e)
            x = 9;
        else
        {
            if (s[i + 1] == '*')
            {
                x = 16 * _nd(s, i + 2, e, t)
                    + 9 * _nd(s, i + 1, e, t);
            }
            else
            {
                if (s[i + 1] < '7')
                {
                    x = 2 * _nd(s, i + 2, e, t)
                        + 9 * _nd(s, i + 1, e, t);
                }
                else
                {
                    x = _nd(s, i + 2, e, t)
                        + 9 * _nd(s, i + 1, e, t);
                }
            }
        }
    }
    else
    {
        x = _nd(s, i + 1, e, t);
    }

    t[i] = x % 1000000007;
    return t[i];
}

int numDecodings(char* s)
{
    int l = strlen(s);
    if (!l)
        return 0;

    int* t = calloc(sizeof(int), l);
    return _nd(s, 0, l - 1, t);
}
*/
