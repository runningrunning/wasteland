char* maskPII(char* S)
{
    char e1 = S[0];
    char e2 = 0;

    int i = 0;
    int c = S[i ++];

    int pre = e1;

    int n = 0;

    while (c && c != '@')
    {
        if (c >= '0' && c <= '9')
            n ++;
        pre = c;
        c = S[i ++];
    }

    int l = i - 1;

    char* r = NULL;

    // phone
    if (!c)
    {
        char* tmp[] = {
            "***-***-****",
            "+*-***-***-****",
            "+**-***-***-****",
            "+***-***-***-****",
        };

        r = strdup(tmp[n - 10]);

        int t = 4;
        int ri = strlen(r) - 1;

        i -= 1;
        while (t)
        {
            if (S[i] >= '0' && S[i] <= '9')
            {
                r[ri --] = S[i];
                t --;
            }
            i --;
        }
    }
    else
    {
        l = strlen(S);

        e2 = pre;
        r = malloc(l - i + 2 + 8);
        r[0] = (e1 >= 'A' && e1 <= 'Z') ? (e1 - 'A' + 'a') : e1;
        r[1] = r[2] = r[3] = r[4] = r[5] = '*';
        r[6] = (e2 >= 'A' && e2 <= 'Z') ? (e2 - 'A' + 'a') : e2;
        int t = 7;
        while (c)
        {
            r[t ++] = (c >= 'A' && c <= 'Z') ? (c  - 'A' + 'a') : c;
            c = S[i ++];
        }
        r[t] = 0;
    }

    return r;
}
