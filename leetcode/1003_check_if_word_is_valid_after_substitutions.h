// brute force ????
bool _iv(char* s, int l)
{
    if (!l)
        return true;

    int in = 0;
    for (int i = 0; i < l; i ++)
    {
        if (i < l - 2)
        {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
            {
                i += 2;
                continue;
            }
        }
        s[in ++] = s[i];
    }

    if (in == l)
        return false;
    return _iv(s, in);
}

bool isValid(char* S)
{
    int l = strlen(S);
    if (l < 3)
        return false;
    return _iv(S, l);
}
