char* originalDigits(char* s)
{
    char c;
    int i = 0;

    int num[10] = {0};
    int all[256] = {0};

    while(c = s[i ++])
        all[c] ++;

    int a = 0;
    int tmp;

    if (tmp = all['g'])
    {
        a += tmp;
        num[8] = tmp;
        /* all['e'] -= tmp; */
        /* all['i'] -= tmp; */
        /* all['g'] -= tmp; */
        /* all['h'] -= tmp; */
        /* all['t'] -= tmp; */
    }

    if (tmp = all['z'])
    {
        a += tmp;
        num[0] = tmp;
        /* all['z'] -= tmp; */
        /* all['e'] -= tmp; */
        all['r'] -= tmp;
        all['o'] -= tmp;
    }

    if (tmp = all['w'])
    {
        a += tmp;
        num[2] = tmp;
        /* all['t'] -= tmp; */
        /* all['w'] -= tmp; */
        all['o'] -= tmp;
    }

    if (tmp = all['u'])
    {
        a += tmp;
        num[4] = tmp;
        all['f'] -= tmp;
        all['o'] -= tmp;
        /* all['u'] -= tmp; */
        all['r'] -= tmp;
    }

    if (tmp = all['o'])
    {
        a += tmp;
        num[1] = tmp;
        all['o'] -= tmp;
        all['n'] -= tmp;
        /* all['e'] -= tmp; */
    }

    if (tmp = all['f'])
    {
        a += tmp;
        num[5] = tmp;
        /* all['f'] -= tmp; */
        /* all['i'] -= tmp; */
        /* all['v'] -= tmp; */
        /* all['e'] -= tmp; */
    }

    if (tmp = all['x'])
    {
        a += tmp;
        num[6] = tmp;
        all['s'] -= tmp;
        /* all['i'] -= tmp; */
        /* all['x'] -= tmp; */
    }

    if (tmp = all['s'])
    {
        a += tmp;
        num[7] = tmp;
        all['s'] -= tmp;
        /* all['e'] -= tmp; */
        /* all['v'] -= tmp; */
        /* all['e'] -= tmp; */
        all['n'] -= tmp;
    }

    if (tmp = all['r'])
    {
        a += tmp;
        num[3] = tmp;
        /* all['t'] -= tmp; */
        /* all['h'] -= tmp; */
        /* all['r'] -= tmp; */
        /* all['e'] -= tmp; */
        /* all['e'] -= tmp; */
    }

    if (tmp = all['n'])
    {
        tmp /= 2;
        a += tmp;
        num[9] = tmp;
    }

    char* ret = malloc(a + 1);
    ret[a] = 0;

    int in = 0;
    for (int i = 0; i < 10; i ++)
    {
        int j = num[i];
        while(j --)
            ret[in ++] = i + '0';
    }
    return ret;
}
