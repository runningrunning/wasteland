char * removeDuplicates(char * S)
{
    int si = 0;
    int ss = 1;
    while (S[ss])
    {
        while(S[ss] && si >= 0 && S[ss] == S[si])
        {
            si --;
            ss ++;
        }

        if (!S[ss])
            break;
        S[++ si] = S[ss ++];
    }
    S[++ si] = 0;
    return S;
}

