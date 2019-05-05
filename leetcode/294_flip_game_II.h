bool cw(char* s, int l)
{
    for (int i = 0; i < l - 1; i ++)
    {
        if (s[i] == '+' && s[i + 1] == '+')
        {
            s[i] = '-';
            s[i + 1] = '-';
            if (!cw(s, l))
            {
                s[i] = '+';
                s[i + 1] = '+';
                return true;
            }
            s[i] = '+';
            s[i + 1] = '+';
        }
    }
    return false;
}

bool canWin(char* s)
{
    int l = strlen(s);
    return cw(s, l);
}
