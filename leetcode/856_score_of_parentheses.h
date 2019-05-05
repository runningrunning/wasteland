// try to use recursion
int scoreOfParentheses(char* S)
{
    int si = 0;
    int st[128] = {0};

    int i = 0;
    int c = S[i ++];
    int x = 0;
    int pre = 0;

    while (c)
    {
        if (c == '(')
        {
            if (si == 0)
                st[si] = 1;
            else
                st[si] = 2 * st[si - 1];
            si ++;
        }
        else
        {
            si --;
            if (pre == '(')
                x += st[si];
        }

        pre = c;
        c = S[i ++];
    }
    return x;
}
