// write simple and understandable code ~~~~!!!!
// to fix offset 1, add too much stupid codes ~
// SIMPLE CODE IS THE EASIEST AND FAST AND BUG FREE
// NEVER COMMIT CODE NEVER UNDERSTAND
int lengthLongestPath(char* input)
{
    if (!input || !input[0])
        return 0;

    int i = 0;
    int st[100] = {0};
    int max = 0;
    char c = input[i];
    while(true)
    {
        bool file = false;
        int lv = 0;
        int oi = i;

        while (c && c != '\n')
        {
            if (c == '\t')
                lv ++;
            if (c == '.')
                file = true;
            c = input[++ i];
        }

        if (file)
        {
            int pl = i - oi - lv;
            if (lv)
                pl += st[lv - 1];

            if (pl > max)
                max = pl;
        }
        else
        {
            st[lv] = i - oi - lv + 1;

            if (lv)
                st[lv] += st[lv - 1];
        }

        if (!c)
            break;

        c = input[++ i];
    }
    return max;
}

/*
STUPID UNFIXABLE CODE ~!!!
int lengthLongestPath(char* input)
{
    if (!input || !input[0])
        return 0;

    int i = 0;
    int si = 1024;
    int* st = malloc(sizeof(int) * 1024);
    int max = 1;
    char c = input[i];

    while(true)
    {
        bool file = false;
        int lv = 0;
        int oi = i;

        while (c && c != '\n')
        {
            if (c == '\t')
                lv ++;
            if (c == '.')
                file = true;
            c = input[i ++];
        }

        if (file)
        {
            int pl = i - oi - lv;
            if (lv)
                pl += st[lv - 1];
            else
                pl += oi != 0 ? 1 : 0;
            printf("%d %d %d.\n", oi, i, lv);
            if (pl > max)
                max = pl;
        }
        else
        {
            if (lv > si)
            {
                si += 1024;
                st = realloc(st, sizeof(int) * si);
            }

            st[lv] = i - oi - lv + 1;

            if (lv)
                st[lv] += st[lv - 1];
        }

        if (!c)
            break;
        c = input[i ++];

        out(st, 10);
    }
    return max - 1;
}
*/

