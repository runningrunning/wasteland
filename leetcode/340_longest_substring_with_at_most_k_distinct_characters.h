// careful !!!,no mention it's lower case only !!!
int lengthOfLongestSubstringKDistinct(char* s, int k)
{
    if (k == 0)
        return 0;

    int i = 0;
    int c = s[i ++];
    int n[256] = {0};

    int t = 0;
    int st = 0;

    while (c && t <= k)
    {
        if (!n[c])
        {
            if (t == k)
                break;
            t ++;
        }

        n[c] ++;
        c = s[i ++];
    }

    int max = i - 1; // n[end] should not be included

    if (t <= k && !c) // only return when c is 0
        return max;

    while (c)
    {
        if (!n[c])
        {
            while (true)
            {
                t = s[st ++];
                n[t] --;
                if (!n[t])
                    break;
            }
        }

        n[c] ++;

        if (max < i - st) // end should not be included, i is the next
            max = i - st;

        c = s[i ++];
    }

    return max;
}

/* // careful !!!,no mention it's lower case only !!! */
/* int lengthOfLongestSubstringKDistinct(char* s, int k) */
/* { */
/*     if (k == 0) */
/*         return 0; */

/*     int i = 0; */
/*     int c = s[i ++]; */
/*     int n[256] = {0}; */

/*     int t = 0; */
/*     int st = 0; */

/*     while (c && t <= k) */
/*     { */
/*         if (!n[c]) */
/*         { */
/*             if (t == k) */
/*                 break; */
/*             t ++; */
/*         } */

/*         n[c] ++; */
/*         c = s[i ++]; */
/*     } */

/*     int en = i - 1; */
/*     int max = en; // n[en] should not be included */

/*     if (t <= k && !c) // only return when c is 0 */
/*         return en; */

/*     while (c) */
/*     { */
/*         en ++; */

/*         if (!n[c]) */
/*         { */
/*             while (true) */
/*             { */
/*                 t = s[st ++]; */
/*                 n[t] --; */
/*                 if (!n[t]) */
/*                     break; */
/*             } */
/*         } */

/*         n[c] ++; */

/*         printf("%d %d %d.\n", st, en, i); */
/*         if (max < en - st) // en should not be included */
/*             max = en - st; */

/*         c = s[i ++]; */
/*     } */

/*     return max; */
/* } */
