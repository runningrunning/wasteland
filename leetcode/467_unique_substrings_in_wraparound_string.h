/* STUPID WRONG ALGORITHM */
/* CHOOSE THE END STRING AND EVERY SUBSTRING END WITH SAME CHAR IS UNIQUE */
/* DO MORE !!! */

int findSubstringInWraproundString(char* p)
{
    int a[26] = {0};

    int i = 0;
    char pre = p[i ++];
    char c = p[i ++];

    if (!pre)
        return 0;

    a[pre -  'a'] = 1;

    int sn = 1;
    while(c)
    {
        if (pre + 1 == c || (pre == 'z' && c == 'a'))
            sn ++;
        else
            sn = 1;

        if (a[c - 'a'] < sn)
            a[c - 'a'] = sn;

        pre = c;
        c = p[i ++];
    }

    int all = 0;
    for (int i = 0; i < 26; i ++)
        all += a[i];
    return all;
}

int numsof(int x)
{
    /* int nums[27] = {0}; */
    /* for (int i = 1; i <= 26; i ++) */
    /* { */
    /*     int x = 0; */
    /*     for (int j = 1; j <= i; j ++) */
    /*         x += (i + 1 - j); */
    /*     nums[i] = x; */
    /* } */
    /* out(nums, 27); */

    int ns[27] = {
        0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91,
        105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351 };
    return x < 27 ? ns[x] : (((x - 26) * 26) + 351);
}

// Line 70: index 1300 out of bounds for type 'int [27]'
// corner case, can be larger than 26 !!!
int findSubstringInWraproundString_1(char* p)
{
    int a[26] = {0};
    // 0 ~ 26

    int i = 0;
    int sn = 1;
    char pre = p[i ++];
    char st = pre - 'a';
    char c = p[i ++];

    if (!pre)
        return 0;

    while(c)
    {
        if (pre == 'z' && c == 'a')
            sn ++;
        else if (pre + 1 == c)
            sn ++;
        else
        {
            if (a[st] < sn)
                a[st] = sn;

            sn = 1;
            st = c - 'a';
        }

        pre = c;
        c = p[i ++];
    }

    if (a[st] < sn)
        a[st] = sn;

    // out(a, 26);

    for (int i = 0; i < 26; i ++)
    {
        if (a[i] > 1)
        {
            int x = a[i];
            int d = x < 26 ? x : 26;

            for (int j = 1; j < d; j ++)
            {
                int n = (i + j) % 26;
                if (a[n] <= x - j)
                    a[n] = 0;
            }
        }
    }

    // out(a, 26);

    int l = 0;
    int all = 0;
    bool got;
    while (true)
    {
        got = false;
        for (int i = 0; i < 26; i ++)
        {
            int x = a[i] - l;
            if (x > 0)
            {
                /* can not remove directly !!, it could be multiple overlapped !! */
                all += numsof(x);
                // printf("+ %d is %d.\n", x, numsof(x));
                if (x > 1)
                {
                    int d = x < 26 ? x : 26;
                    for (int j = 1; j < d; j ++)
                    {
                        int n = (i + j) % 26;
                        if (a[n] - l > x - j)
                        {
                            got = true;
                            // printf("%d is %d.\n", x - j, numsof(x - j));
                            all -= numsof(x - j);
                            break;
                        }
                    }
                }
            }
        }

        l += 26;
        if (!got)
            break;
    }
    return all;
}
