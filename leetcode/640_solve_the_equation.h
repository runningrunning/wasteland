char* solveEquation(char* equation)
{
    char* e = equation;
    int i = 0;
    int c = e[i ++];

    int fn = 0;
    int fx = 0;

    int pn = 0;
    int px = 0;

    bool got = false;
    bool minus = false;

    int *in = &fn;
    int *ix = &fx;

    int n = 0;
    while (c)
    {
        if (c >= '0' && c <= '9')
        {
            got = true;
            n = n * 10 + c - '0';
        }
        else if (c == '-' || c == '+' || c == '=')
        {
            if (got)
                (*in) += minus ? - n : n;

            n = 0;
            got = false;

            if (c == '=')
            {
                in = &pn;
                ix = &px;
                minus = false;
            }
            else
                minus = c == '-';
        }
        else if (c == 'x')
        {
            if (!got)
                n = 1;

            (*ix) += minus ? -n : n;
            n = 0;
            minus = false;
            got = false;
        }

        c = e[i ++];
    }

    if (got)
        (*in) += minus ? - n : n;

    if (fx == px)
        return fn == pn ? strdup("Infinite solutions") : strdup("No solution");

    int dx = fx - px;
    int dn = pn - fn;

    if (!dn)
        return strdup("x=0");

    char* r = malloc(16);
    sprintf(r, "x=%d", dn / dx);
    return r;
}
