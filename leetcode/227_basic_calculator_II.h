void reduce(int* st, int* sc)
{
    int c = *sc;
    if (c >= 3)
    {
        int op = - st[c - 2];

        if (op == '*')
        {
            st[c - 3] *= st[c - 1];
            *sc = c - 2;
        }
        else if (op == '/')
        {
            st[c - 3] /= st[c - 1];
            *sc = c - 2;
        }
    }
}

int calculate(char* s)
{
    if (!s)
        return 0;
    int l = strlen(s);

    int sc = 0;
    int* st = malloc(sizeof(int) * l);
    int si = 0;

    int num = -1;

    while(s[si])
    {
        if (s[si] != ' ')
        {
            if (s[si] >= '0' && s[si] <= '9')
            {
                if (num == -1)
                    num = s[si] - '0';
                else
                    num = num * 10 + s[si] - '0';
            }
            else
            {
                if (num != -1)
                {
                    st[sc ++] = num;
                    reduce(st, &sc);
                    num = -1;
                }
                st[sc ++] = - s[si]; 
            }
        }
        else
        {
            if (num != -1)
            {
                st[sc ++] = num;
                reduce(st, &sc);
                num = -1;
            }
        }
        si ++;
    }

    if (num != -1)
    {
        st[sc ++] = num;
        reduce(st, &sc);
        num = -1;
    }

    for(int i = 1; i < sc; i += 2)
    {
        int op = - st[i];

        if (op == '+')
        {
            st[0] += st[i + 1];
        }
        else
        {
            st[0] -= st[i + 1];
        }
    }

    return st[0];
}
