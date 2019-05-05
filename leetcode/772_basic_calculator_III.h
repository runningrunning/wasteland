// INT_MAX + 1 : (
// INT_MAX + 2 : +
// INT_MAX + 3 : -
// INT_MAX + 4 : *
// INT_MAX + 5 : /
int calculate(char* s)
{
    if (!s)
        return 0;
    int si = 0;
    int l = strlen(s);
    int sti = 0;
    long* st = malloc(sizeof(long) * l);

    long r = 0;

    while (s[si])
    {
        while (s[si] && s[si] == ' ')
            si ++;

        if (s[si])
        {
            bool do_cal = false;
            if (s[si] == '(')
            {
                st[sti ++] = INT_MAX + 1;
                si ++;
            }
            else if (s[si] == ')')
            {
                sti --;
                int end = sti;
                while (st[sti] != INT_MAX + 1)
                    sti --;

                r = st[sti + 1];
                for (int i = sti + 2; i <= end; i += 2)
                    r = (st[i] == (INT_MAX + 2)) ? (r  + st[i + 1]) : (r - st[i + 1]);
                st[sti ++] = r;
                do_cal = true;
                si ++;
            }
            else if (s[si] == '+' || s[si] == '-')
            {
                st[sti ++] = s[si] == '+' ? (INT_MAX + 2) : (INT_MAX + 3);
                si ++;
            }
            else if (s[si] == '*' || s[si] == '/')
            {
                st[sti ++] = s[si] == '*' ? (INT_MAX + 4) : (INT_MAX + 5);
                si ++;
            }
            else
            {
                int x = 0;
                while (s[si] && s[si] >= '0' && s[si] <= '9')
                    x = x * 10 + s[si ++] - '0';
                st[sti ++] = x;
                do_cal = true;
            }

            if (do_cal)
            {
                while (sti > 2)
                {
                    int last = sti - 1;
                    int op = last - 1;
                    if (st[op] != (INT_MAX + 4) && st[op] != (INT_MAX + 5))
                        break;
                    sti = op;
                    st[op - 1] = st[op] == (INT_MAX + 4) ?
                        (st[op - 1] * st[last]) : (st[op - 1] / st[last]);
                }
            }
        }
    }
    r = st[0];
    if (sti != 1)
    {
        for (int i = 1; i < sti; i += 2)
            r = (st[i] == (INT_MAX + 2)) ? (r  + st[i + 1]) : (r - st[i + 1]);
    }
    return r;
}
