char* _hs(char* S)
{
    int i = 0;
    int c = S[i ++];

    int ci = 0;
    while (c)
    {
        if (c == '#')
        {
            ci --;
            if (ci < 0)
                ci = 0;
        }
        else
            S[ci ++] = c;
        c = S[i ++];
    }
    S[ci] = 0;
    return S;
}

bool backspaceCompare(char* S, char* T)
{
    return !strcmp(_hs(S), _hs(T));
}
