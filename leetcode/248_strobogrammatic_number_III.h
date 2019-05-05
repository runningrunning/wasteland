int down(char* s)
{
    /* down 0, 1, 6, 8, 9 */
    /*              0  1  2  3  4  5  6  7  8  9  */
    int sn_m[] =  {-1, -2, 1, 1, 1, 1,  1, 1, -3,  2 };
    int sn_o0[] = {-1, -1, 0, 0, 0, 0, -2, 1, -3, -4 };
    int sn_o1[] = {-1, -2, 1, 1, 1, 1, -3, 2, -4, -5 };

    int sc[] =    {0, 1, 0, 0, 0, 0, 9, 0, 8, 6};
    int n = strlen(s);

    int num = 1;
    int m = (n + 1) / 2;
    int* sample = malloc(sizeof(int) * n);
    memset(sample, 0, sizeof(int) * n);

    bool compare = true;
    for (int i = 0; i < m; i ++)
    {
        int sn;
        int c = s[i] - '0';

        if (i == n - 1 - i)
        {
            sn = sn_m[c];
            num *= 3;
        }
        else
        {
            if (i)
            {
                sn = sn_o1[c];
                num *= 5;
            }
            else
            {
                sn = sn_o0[c];
                num *= 4;
            }
        }

        if (sn < 0)
        {
            sample[i] = c;
            sample[n - 1 - i] = sc[c];
        }
        else
            compare = false;
    }

    int delta = 1;

    if (compare)
    {
        bool down = false;
        for(int i = m; i < n; i ++)
        {
            int c = s[i] - '0';
            if (c < sample[i])
            {
                down = true;
                break;
            }
        }
        if (down)
            delta = 0;
    }

    int index = 0;
    int a_num = num;
    bool max = false;
    for (int i = 0; i < m; i ++)
    {
        int sn;
        int c = s[i] - '0';
        if (max)
            c = 9;

        if (i == n - 1 - i)
        {
            sn = sn_m[c];
            num /= 3;
        }
        else
        {
            if (i)
            {
                sn = sn_o1[c];
                num /= 5;
            }
            else
            {
                sn = sn_o0[c];
                num /= 4;
            }
        }

        if (sn < 0)
            sn = -sn - 1;
        else
            max = true;
        index += sn * num;
    }
    return index + delta;
}

int len(int n)
{
    int num = 1;
    int m = (n + 1) / 2;

    for (int i = 0; i < m; i ++)
    {
        if (i == n - 1 - i)
            num *= 3;
        else
            num *= i ? 5 : 4;
    }
    return num;
}

bool isStrobogrammatic(char* num) {
    if (!num)
        return false;

    // 0 => 1, 1 => 2, 6 => 7, 8 => 9, 9 => 10
    int sg[11] = {0, 1, 2, 0, 0, 0, 0, 10, 0, 9, 7};
    int l = strlen(num);

    if (!l)
        return false;

    for (int i = 0; i < (l + 1) / 2; i ++)
    {
        int c = num[i] - '0' + 1;
        c = sg[c] - 1 + '0';

        if (c != num[l - 1 - i])
            return false;
    }
    return true;
}

int strobogrammaticInRange(char* low, char* high)
{
    if (!low || !high)
        return 0;

    bool low_i = isStrobogrammatic(low) ? 1 : 0;

    int ll = strlen(low);
    int lh = strlen(high);

    if (ll > lh)
        return 0;

    if (ll == lh)
        return down(high) - down(low) + low_i;

    int num = 0;

    for (int i = ll + 1; i <= lh - 1; i ++)
        num += len(i);

    num += len(ll) - down(low) + low_i;
    num += down(high);
    return num;
}
