char* removeOuterParentheses(char* S)
{
    int ri = 0;
    int l = strlen(S);
    char* r = malloc(sizeof(char) * (l + 1));
    int lv = 0;

    for (int i = 0; i < l; i ++)
    {
        if (S[i] == ')')
            lv --;
        if (lv)
            r[ri ++] = S[i];
        if (S[i] == '(')
            lv ++;
    }
    r[ri] = 0;
    return r;
}
