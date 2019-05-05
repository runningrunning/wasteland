char* strWithout3a3b(int A, int B)
{
    int all[256] = {0};

    int max_n = A;
    int min_n = B;
    char max_c = 'a';
    char min_c = 'b';

    if (B > A)
    {
        max_n = B;
        max_c = 'b';
        min_n = A;
        min_c = 'a';
    }

    int max_l = max_n;
    int min_l = min_n;

    for (int i = 0; i < 256; i ++)
    {
        if (i & 1)
        {
            if (!min_l)
                break;
            all[i] = 1;
            min_l --;
        }
        else
        {
            if (!max_l)
                break;
            all[i] = 1;
            max_l --;
        }
    }

    for (int i = 0; i < 256; i ++)
    {
        if (i & 1)
        {
            if (min_l)
            {
                all[i] += 1;
                min_l --;
            }
        }
        else
        {
            if (max_l)
            {
                all[i] += 1;
                max_l --;
            }
        }
    }

    int ri = 0;
    char* r = malloc(sizeof(char) * (A + B + 1));
    r[A + B] = 0;

    for (int i = 0; i < 256; i ++)
    {
        if (!all[i])
            break;

        char c = (i & 1) ? min_c : max_c;
        r[ri ++] = c;

        if (all[i] == 2)
            r[ri ++] = c;
    }
    return r;
}


bool _str_verify(char* s)
{
    int i = 0;
    int an = 0;
    int bn = 0;

    while (s[i])
    {
        if (s[i] == 'a')
            an ++;
        else
            bn ++;
        i ++;
    }

    printf("a %d, b %d.\n", an, bn);
}
