int bits(int x)
{
    int bs[] = {8, 0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,7,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,6,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,5,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0,4,0,1,0,2,0,1,0,3,0,1,0,2,0,1,0};

    int b8 = x & 0xff;
    if (b8)
        return bs[b8];
    b8 = (x >> 8) & 0xff;
    return 8 + bs[b8];
}

/* Careful ~!!!!!!!!!! */
char* findContestMatch(int n)
{
    int b[8192];
    int a[8192] = {0};

    int o = n;
    for (int i = 0; i < n; i ++)
        a[i] = i + 1;

    int x = 1;

    int* tmp;
    int* f = a;
    int* t = b;
    int* need;
    /* generate matches */
    while(n)
    {
        int t_off = 0;
        int b_off = 0;
        int a_off = (n - 1) * x;
        int size = x * sizeof(int);

        for (int i = 0; i < n; i ++)
        {
            memcpy(t + t_off, f + b_off, size);
            t_off += x;
            memcpy(t + t_off, f + a_off, size);
            t_off += x;
            b_off += x;
            a_off -= x;
        }

        x *= 2;
        n /= 2;
        need = t;
        if (n <= 2)
            break;
        tmp = f;
        f = t;
        t = tmp;
    }

    /* generate strings */
    /* it's difficult to append it into string :( */
    int ni = 0;
    int num[10] = {0};
    int ri = 0;
    char* ret = malloc(o * 6 + 1);
    ret[o * 6] = 0;

    for (int i = 0; i < o; i ++)
    {
        ni = 0;
        n = need[i];
        while (n)
        {
            num[ni ++] = n % 10;
            n /= 10;
        }

        if (i & 1)
        {
            x = i + 1;
            int b = bits(x);

            for (int k = -- ni ; k >= 0; k --)
                ret[ri ++] = num[k] + '0';

            while (b --)
                ret[ri ++] = ')';
        }
        else
        {
            x = o - i;
            int b = bits(x);
            while (b --)
                ret[ri ++] = '(';

            for (int k = -- ni ; k >= 0; k --)
                ret[ri ++] = num[k] + '0';
        }

        ret[ri ++] = ',';
    }
    /* remove the last ',' */
    ret[ri - 1] = 0;
    return ret;
}
