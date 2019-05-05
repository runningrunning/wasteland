// how to solve this in DP way ?
int minFlipsMonoIncr(char* S)
{
    int n0 = 0;
    int n1 = 0;

    int i = 0;
    char c = S[i ++];

    while (c)
    {
        if (c == '0')
            n1 ++;
        else
        {
            if (n1 > n0)
                n1 = n0;
            n0 ++;
        }
        c = S[i ++];
    }
    return n0 < n1 ? n0 : n1;
}
