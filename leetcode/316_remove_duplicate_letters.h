// two points and stacks !!!!
// practice more times !
void rdl_sort(int* n, int s, int e, int* id)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;

        t = id[e];
        id[e] = id[s];
        id[s] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;

            t = id[e];
            id[e] = id[s];
            id[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;

            t = id[e];
            id[e] = id[i];
            id[i] = t;
        }
    }

    rdl_sort(n, cs, e - 1, id);
    rdl_sort(n, e + 1, ce, id);
}

char* removeDuplicateLetters(char* s)
{
    int en[26] = {0};
    int eni[26];

    int i = 0;
    int c = s[i ++];
    int f = 0;
    while (c)
    {
        c -= 'a';
        f |= 1 << c;
        en[c] = i;
        c = s[i ++];
    }

    for (int i = 0; i < 26; i ++)
        eni[i] = i;
    rdl_sort(en, 0, 25, eni);

    int ri = 0;
    char* ret = malloc(27);
    ret[26] = 0;

    int ei = 0;
    int pri = 0;
    while (f)
    {
        while(!(f & (1 << eni[ei])))
            ei ++;

        int i = 0;
        for (i = 0; i < 26; i ++)
            if (f & (1 << i))
                break;

        int t = eni[ei] + 'a';
        bool found = false;

        if (i == eni[ei])
        {
            for (int j = pri; j < en[ei] - 1; j ++)
                if (t == s[j])
                {
                    found = true;
                    pri = j + 1;
                    break;
                }
        }
        else
        {
            i = t - 'a';

            for (int j = pri; j < en[ei] - 1; j ++)
            {
                int c = s[j] - 'a';
                if (f & (1 << c))
                {
                    if (i > c || (!found && i == c))
                    {
                        t = s[j];
                        i = t - 'a';
                        pri = j + 1;
                        found = true;
                    }
                }
            }
        }

        if (!found)
        {
            i = eni[ei];
            pri = en[ei];
        }

        ret[ri ++] = t;
        f &= ~(1 << i);
    }

    ret[ri] = 0;
    return ret;
}

// char* removeDuplicateLetters(char* s)
// {
//     int st[26] = {0};
//     int en[26] = {0};
//     int eni[26];

//     int i = 0;
//     int c = s[i ++];
//     int f = 0;
//     while (c)
//     {
//         c -= 'a';
//         if (!st[c])
//         {
//             f |= 1 << c;
//             st[c] = i;
//             en[c] = i;
//         }
//         else
//             en[c] = i;
//         c = s[i ++];
//     }

//     for (int i = 0; i < 26; i ++)
//         eni[i] = i;
//     rdl_sort(en, 0, 25, eni);

//     int ri = 0;
//     int r[26] = {0};
//     int ei = 0;

//     int pri = 0;
//     while (f)
//     {
//         while(!(f & (1 << eni[ei])))
//             ei ++;

//         int i = 0;
//         for (i = 0; i < 26; i ++)
//             if (f & (1 << i))
//                 break;

//         if (i == eni[ei])
//         {
//             r[ri ++] = i;
//             int j = pri;
//             bool found = false;
//             for (; j < en[ei] - 1; j ++)
//                 if (i + 'a' == s[j])
//                 {
//                     found = true;
//                     pri = j + 1;
//                     break;
//                 }

//             if (!found)
//                 pri = en[ei];

//             ei ++;
//         }
//         else
//         {
//             int t = eni[ei] + 'a';
//             bool found = false;

//             for (int j = pri; j < en[ei] - 1; j ++)
//             {
//                 if ((t > s[j] || (!found && t == s[j])) && (f & (1 << (s[j] - 'a'))))
//                 {
//                     t = s[j];
//                     i = t - 'a';
//                     pri = j + 1;
//                     found = true;
//                 }
//             }

//             if (!found)
//             {
//                 i = t - 'a';
//                 pri = en[ei];
//             }
//             r[ri ++] = i;
//         }
//         f &= ~(1 << i);
//     }

//     char* ret = malloc(ri + 1);
//     ret[ri] = 0;
//     for (int i = 0; i < ri; i ++)
//         ret[i] = r[i] + 'a';
//     return ret;
// }


// char* removeDuplicateLetters(char* s)
// {
//     if (!s)
//         return s;

//     int l = strlen(s);
//     if (l < 2)
//         return s;
//     int f = 0;

//     /* c => index */
//     int ai[26] = {0};

//     int ci = 26;
//     /* index => c */
//     int ia[26] = {0};

//     int c2i[26] = {0};

//     while(l)
//     {
//         l --;
//         int c = s[l] - 'a';
//         int fc = 1 << c;

//         if (f & fc)
//         {
//             if (ia[ci] >= c)
//             {
//                 int el = c2i[c];

//                 if (ia[ci] > c)
//                 {
//                     for (int i = ai[c] - 1; i >= ci; i --)
//                     {
//                         ia[i + 1] = ia[i];
//                         ai[ia[i]] = i + 1;
//                     }
//                     ia[ci] = c;
//                     ai[c] = ci;
//                 }

//                 c2i[c] = l;


//                 bool found = true;
//                 int t_l = l;
//                 int t_ci = ci + 1;

//                 int t_min, t_low;
//                 t_low = ia[ci];

//                 while(found && t_ci < 26)
//                 {
//                     t_min = ia[t_ci];
//                     int t_el = c2i[ia[t_ci]];
//                     printf("t_min is %c, l %d el is %d t_el %d.\n", t_min + 'a', l, el, t_el);

//                     found = false;

//                     for (int i = t_l + 1; i < el; i ++)
//                     {
//                         int t_c = s[i] - 'a';

//                         if ((t_c < t_min && t_c >= t_low)
//                             || (t_c == t_min && !found))
//                         {
//                             found = true;
//                             t_min = t_c;
//                             t_l = i;
//                         }
//                     }

//                     if (found)
//                     {
//                         if (t_min != ia[t_ci])
//                         {
//                             for (int i = ai[t_min] - 1; i >= t_ci; i --)
//                             {
//                                 ia[i + 1] = ia[i];
//                                 ai[ia[i]] = i + 1;
//                             }
//                             ia[t_ci] = t_min;
//                             ai[t_min] = t_ci;
//                         }
//                         c2i[t_min] = t_l;

//                         t_low = t_min;
//                         found = true;
//                         t_ci += 1;
//                         el = t_el;
//                     }
//                     else
//                     {
//                         t_ci ++;
//                     }
//                 };
//             }
//         }
//         else
//         {
//             -- ci;
//             f |= fc;
//             ia[ci] = c;
//             ai[c] = ci;
//             c2i[c] = l;
//         }
//     }

//     char* r = malloc(27 - ci);
//     r[26 - ci] = 0;

//     for(int i = 0; i < 26 - ci; i ++)
//         r[i] = ia[ci + i] + 'a';
//     return r;
// }
