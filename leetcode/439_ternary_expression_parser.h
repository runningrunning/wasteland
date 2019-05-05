// find simple and easy solution
// really do we need to stack !
char pt(char* r, int s, int e)
{
    if (s == e || r[s + 1] == ':')
        return r[s];

    if (r[s] == 'T')
        return pt(r, s + 2, e);

    // False, need to go through it
    int l = 1;
    int st = s + 2;
    while (l)
    {
        if (r[st] == ':')
            l --;
        else if (r[st] == '?')
            l ++;
        st ++;
    }
    return pt(r, st, e);
}


char* parseTernary(char* expression)
{
    char* r = malloc(2);
    r[1] = 0;
    r[0] = pt(expression, 0, strlen(expression) - 1);
    return r;
}

/*
// it's not that stupid !, stupid wrong algorithm
char pt(char* r, int s, int e)
{
    if (s == e)
        return r[s];

    int l = e;
    // find last ":"
    while (r[l] != ':')
        l --;

    if (r[s] == 'T')
        return pt(r, s + 2, l - 1);
    return pt(r, l + 1, e);
}

char* parseTernary(char* expression)
{
    char* r = malloc(2);
    r[1] = 0;
    r[0] = pt(expression, 0, strlen(expression) - 1);
    return r;
}

*/
