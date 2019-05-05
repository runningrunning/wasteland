int calPoints(char** ops, int opsSize)
{
    int ns[1000] = {0};
    int c = 0;
    int all = 0;

    int num;

    for (int i = 0; i < opsSize; i ++)
    {
        char* s = ops[i];
        if (s[0] == '+')
            num = ns[c - 1] + ns[c - 2];
        else if (s[0] == 'C')
        {
            all -= ns[c - 1];
            c --;
            continue;
        }
        else if (s[0] == 'D')
            num = ns[c - 1] * 2;
        else
            num = atoi(s);

        ns[c ++] = num;
        all += num;
    }
    return all;
}
