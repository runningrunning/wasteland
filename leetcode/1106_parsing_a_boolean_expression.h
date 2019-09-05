// stack no need, just be careful
char* pbe(char* e, bool* r)
{
    if (!e[0])
        return false;
    char c = e[0];

    bool x = false;

    if (c == 't' || c == 'f')
        *r = c == 't';
    else if (c == '!')
    {
        // should only have one level
        e = pbe(e + 2, &x);
        *r = !x;
    }
    else
    {
        bool and = c == '&';
        e = e + 1;
        x = and ? true : false;
        do
        {
            e += 1;
            bool n = false;
            e = pbe(e, &n);

            // do skip here ?
            if (and)
                x = x && n;
            else
                x = x || n;
        } while (e[0] != ')');

        *r = x;
    }
    return e + 1;
}

bool parseBoolExpr(char * expression)
{
    bool r = false;
    pbe(expression, &r);
    return r;
}

