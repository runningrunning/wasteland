char* multiply(char* num1, char* num2)
{
    if (!num1 || !num2)
        return NULL;

    int l1 = strlen(num1);
    int l2 = strlen(num2);

    if (l1 == 1 && num1[0] == '0')
        return "0";

    if (l2 == 1 && num2[0] == '0')
        return "0";

    int tl = l1;
    char* t = num1;

    if (l2 > l1)
    {
        l1 = l2;
        num1 = num2;
        num2 = t;
        l2 = tl;
    }

    char* r = malloc(l1 + l2 + 1);
    r[l1 + l2] = 0;
    memset(r, '0', l1 + l2);

    t = malloc(l1 + 2);
    t[0] = '0';
    t[l1 + 1] = 0;
    strncpy(t + 1, num1, l1);


    int o = 0;
    for(int i = 1; i < 10; i ++)
    {
        o = 0;
        for (int j = l2 - 1; j >= 0; j --)
        {
            if (num2[j] == i + '0')
            {
                int ext = 0;
                int of = l1 + l2 - 1 - o;
                for (int k = l1; k >= 0; k --)
                {
                    ext += t[k] + r[of] - ('0' << 1);
                    r[of] = '0' + (ext % 10);
                    ext /= 10;
                    of --;
                }

                while (ext)
                {
                    ext += r[of] - '0';
                    r[of] = '0' +(ext % 10);
                    ext /= 10;
                    of --;
                }
            }
            o ++;
        }

        if (i != 9)
        {
            int ext = 0;
            for (int j = l1 - 1; j >= 0; j --)
            {
                ext += t[j + 1] + num1[j] - ('0' << 1);
                t[j + 1] = '0' + (ext % 10);
                ext /= 10;
            }
            t[0] += (ext % 10);
        }
    }

    o = 0;
    int i = 0;

    while(r[i] == '0')
        i ++;

    while(r[i])
        r[o ++] = r[i ++];
    r[o] = 0;

    return r;
}
