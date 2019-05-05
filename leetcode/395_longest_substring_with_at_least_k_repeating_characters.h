// can not handle "bbaaacbd", 3

int lss(char* c, int s, int e, int k)
{
    int a[26] = {0};
    for (int i = s; i <= e; i ++)
        a[c[i] - 'a'] ++;

    int f = 0;
    for (int i = 0; i < 26; i ++)
        if (a[i] && a[i] < k)
            f |= 1 << i;

    if (!f)
        return e - s + 1;

    int max = 0;
    int st = -1;
    int en = -1;
    for (int i = s; i <= e; i ++)
    {
        int n = c[i] - 'a';
        if (f & (1 << n))
        {
            if (st != -1 && en != -1 && max < (en - st + 1))
            {
                int tmp = lss(c, st, en, k);
                if (tmp > max)
                    max = tmp;
            }
            st = -1;
            en = -1;
            continue;
        }

        if (st == -1)
            st = i;
        else
            en = i;
    }

    if (st != -1 && en != -1 && max < (en - st + 1))
    {
        int tmp = lss(c, st, en, k);
        if (tmp > max)
            max = tmp;
    }
    return max;
}

int longestSubstring(char* s, int k)
{
    if (!s)
        return 0;

    int l = strlen(s);

    if (k <= 1)
        return l;

    if (l < k)
        return 0;
    return lss(s, 0, l - 1, k);
}

// int longestSubstring(char* s, int k)
// {
//     if (!s || !s[0])
//         return 0;

//     if (k <= 1)
//         return strlen(s);

//     int n[26] = {0};
//     int fp = 0;

//     int i = 0;
//     int c = s[i ++];
// }

// int longestSubstring(char* s, int k)
// {
//     if (!s || !s[0])
//         return 0;

//     if (k <= 1)
//         return strlen(s);

//     int f = 0xFFFFFFFF;

//     int n[26] = {0};

//     int i = 0;
//     int c = s[i ++];

//     while(c)
//     {
//         c -= 'a';
//         n[c] ++;
//         if (n[c] >= k)
//             f &= ~(1 << c);
//         c = s[i ++];
//     }

//     i -= 1;

//     int x = 0;
//     int y = 0;
//     int fx = 0;
//     int m = 0;

//     for (int j = 0; j < i; j ++)
//     {
//         c = s[j] - 'a';
//         int fc = 1 << c;

//         if (f & fc)
//         {
//             fx = 0;
//             x = 0;
//             y = 0;
//         }
//         else
//         {
//             x ++;

//             if (fx & fc)
//             {
//                 n[c] ++;
//                 if (n[c] == k)
//                     y --;
//             }
//             else
//             {
//                 fx |= fc;
//                 n[c] = 1;
//                 y ++;
//             }

//             if (!y && x > m)
//                 m = x;
//         }
//     }
//     return m;
// }
