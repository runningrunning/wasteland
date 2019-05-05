// stupid, forget to reduce it
char* fractionAddition(char* expression)
{
    int i = 0;
    char* e = expression;
    char c = e[i ++];

    bool minus = false;

    int fn = 0;
    int fd = 1;

    int cn = 0;
    int cd = 0;

    while (c)
    {
        if (c == '-' || c == '+')
            minus = c == '-';
        else
        {
            cn = 0;
            cd = 0;

            int ni = i;
            int *n = &cn;
            (*n) = c - '0';

            int nc = e[ni ++];

            while (nc && nc != '-' && nc != '+')
            {
                if (nc == '/')
                    n = &cd;
                else
                    (*n) = (*n) * 10 + nc - '0';

                nc = e[ni ++];
            }

            cn = minus ? - cn : cn;

            fn = fn * cd + cn * fd;
            fd = fd * cd;

            if (fn == 0)
                fd = 1;
            else if (!(fn % fd))
            {
                fn /= fd;
                fd = 1;
            }

            c = nc;
            i = ni;
            continue;
        }
        c = e[i ++];
    }

    char* r = malloc(16);

    if (fn == 0)
        fd = 1;

    // find common divider
    if (fd != 1)
    {
        if (fn < 0)
        {
            minus = true;
            fn = - fn;
        }
        else
            minus = false;

        int t1 = fn > fd ? fn : fd;
        int t2 = fn > fd ? fd : fn;

        while (t1 % t2)
        {
            t1 %= t2;

            t1 ^= t2;
            t2 ^= t1;
            t1 ^= t2;
        }

        fn /= t2;
        fd /= t2;

        fn = minus ? - fn : fn;
    }


    sprintf(r, "%d/%d", fn, fd);
    return r;
}
