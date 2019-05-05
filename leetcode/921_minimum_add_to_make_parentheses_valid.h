// that simple ????
// just do times?
// similar questions?
// minimum delete to make it valid ?
// from left and from the right do two times
// stupid wrong
int minAddToMakeValid(char* S)
{
    int i = 0;
    int c = S[i ++];

    int n = 0;

    int r_l = 0;

    while (c)
    {
        if (c == ')')
        {
            if (r_l)
                r_l --;
            else
                n ++;
        }
        else
            r_l ++;

        c = S[i ++];
    }

    int r_r = 0;

    i -= 1;
    c = S[ -- i];

    while (i >= 0)
    {
        if (c == '(')
        {
            if (r_r)
                r_r --;
            else
                n ++;
        }
        else
            r_r ++;

        c = S[-- i];
    }

    return n;
}
