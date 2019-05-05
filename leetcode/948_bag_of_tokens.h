// DP ??? or greedy ????
// peek hint, greedy

int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int bagOfTokensScore(int* tokens, int tokensSize, int P)
{
    if (!tokens || !tokensSize)
        return 0;

    qsort(tokens, tokensSize, sizeof(int), comp);

    int s = 0;
    int e = tokensSize - 1;
    int m = 0;
    int p = 0;

    while (s <= e)
    {
        if (P >= tokens[s])
        {
            P -= tokens[s ++];
            p ++;
            if (p > m)
                m = p;
        }
        else if (p > 0)
        {
            P += tokens[e --];
            p --;
        }
        else
            break;
    }
    return m;
}
