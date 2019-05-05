// be careful about the s ++, e --
char* reverseOnlyLetters(char* S)
{
    if (!S)
        return NULL;

    if (!S[0])
        return strdup(S);

    int s = 0;
    int e = strlen(S) - 1;

    char* c = strdup(S);

    while (s < e)
    {
        char _s = c[s];
        char _e = c[e];

        if (!((_s >= 'a' && _s <= 'z') || (_s >= 'A' && _s <= 'Z')))
            s ++;
        else if (!((_e >= 'a' && _e <= 'z') || (_e >= 'A' && _e <= 'Z')))
            e --;
        else
        {
            c[e --] = _s;
            c[s ++] = _e;
        }
    }
    return c;
}
