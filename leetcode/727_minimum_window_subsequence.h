// HOW TO SOLVE THIS WITH DP ?
// clear mind !!!
// stupid corner case !!!
char* minWindow(char* S, char* T)
{
    int tl = strlen(T);
    int ti[101] = {0};
    int ts[26] = {0};
    int tn[102] = {0};

    int i = 0;
    int c = T[i ++];

    while (c)
    {
        c -= 'a';
        tn[i - 1] = ts[c];
        ts[c] = i;
        c = T[i ++];
    }

    i = 0;
    c = S[i ++];

    int st;
    int se;
    int min = INT_MAX;

    while (c)
    {
        c -= 'a';
        if (ts[c])
        {

            int t = ts[c];
            do {
                t -= 1;
                if (!t)
                    ti[t] = i;
                else if (ti[t - 1])
                    ti[t] = ti[t - 1];

                if (t == tl - 1 && ti[t] && i - ti[t] < min)
                {
                    min = i - ti[t];
                    st = ti[t];
                    se = i;
                }

            } while (t = tn[t]);
        }
        c = S[i ++];
    }

    if (min == INT_MAX)
        return "";

    char* r = malloc(se - st + 1 + 1);
    r[se - st + 1] = 0;

    for (int i = 0; i < se - st + 1; i ++)
        r[i] = S[st - 1 + i];

    return r;
}
