// INT_MAX + 1 (
// INT_MAX + 2 +
// INT_MAX + 3 -
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
            if (s[si] == '(')
            {
                si ++;
                st[sti ++] = INT_MAX + 1;
            }
            else if (s[si] == ')')
            {
                si ++;
                sti --;
                int end = sti;
                while (st[sti] != (INT_MAX + 1))
                    sti --;

                r = st[sti + 1];
                for (int i = sti + 2; i <= end; i += 2)
                    r = (st[i] == (INT_MAX + 2)) ? (r  + st[i + 1]) : (r - st[i + 1]);
                st[sti ++] = r;
            }
            else if (s[si] == '+')
            {
                si ++;
                st[sti ++] = INT_MAX + 2;
            }
            else if (s[si] == '-')
            {
                si ++;
                st[sti ++] = INT_MAX + 3;
            }
            else
            {
                int x = 0;
                while (s[si] && s[si] >= '0' && s[si] <= '9')
                    x = x * 10 + (s[si ++] - '0');
                st[sti ++] = x;
            }
        }
    }
    r = st[0];
    if (sti != 1)
    {
        r = st[0];
        for (int i = 1; i < sti; i += 2)
            r = (st[i] == (INT_MAX + 2)) ? (r  + st[i + 1]) : (r - st[i + 1]);
    }
    return r;
}
