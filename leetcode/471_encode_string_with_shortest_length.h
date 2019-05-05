// DP is the easiest version to write, and the only correct version !
// just brute force ??? WRONG
// CHECKING THE SOLUTION !!!
// actually, it's similar with 312 burst_ballons.h !!!!!, find the shortest length in i to j

// how to write clear and clean code for this question !

// stupid wrong algorithm ? DP ??
// peek solution !!

// GREED + DP SOLUTIO
// JUST BE CAREFUL !!!

// "renereneabcedfreneabcedfreneabcedf" ? how to handle this?
// how to find the smallest
// "2[rene]abcedfreneabcedf"
// "rene2[reneabcedf]"

int _en(char* str, int s, int e, int** dp)
{
    if (e - s <= 3)
    {
        dp[s][e] = e - s + 1;
        return e - s + 1;
    }

    if (dp[s][e])
        return dp[s][e] & 0xFF;

    int dl = e - s + 1;
    int m = dl / 2;

    bool check_even = !(dl & 1);

    if (check_even)
    {
        for (int i = 0; i < m; i ++)
            if (str[s + i] != str[s + m + i])
            {
                check_even = false;
                break;
            }
    }

    bool same = false;

    for (int i = 1; i <= m; i ++)
    {
        if (!(dl % i))
        {
            int num = dl / i;

            if (!(num & 1) && !check_even)
                continue;

            same = true;

            for (int j = 1; j < num; j ++)
            {
                int start = s + j * i;
                for (int k = 0; k < i; k ++)
                    if (str[s + k] != str[start + k])
                    {
                        same = false;
                        break;
                    }

                if (!same)
                    break;
            }

            if (same)
            {
                int x = _en(str, s, s + i - 1, dp);
                int nl = (num >= 100 ? 3 : (num >= 10 ? 2 : 1)) + 2;
                if (x + nl < dl)
                {
                    dp[s][e] = (i << 16) | (nl + x);
                    break;
                }
                same = false;
            }
        }
    }

    if (same)
        return dp[s][e] & 0xFF;

    int di = 0;

    for (int i = s + 1; i < e; i ++)
    {
        int da = _en(str, s, i, dp);
        int db = _en(str, i + 1, e, dp);
        int dx = da + db;

        if (dx <= dl)
        {
            dl = dx;
            di = i;
            dp[s][e] = (di << 8) | dl;
        }
    }

    if (!dp[s][e])
        dp[s][e] = e - s + 1;

    return dp[s][e] & 0xFF;
}

void _str(char* o, char* r, int** dp, int s, int e)
{
    int ri = 0;
    int x = dp[s][e];

    if (x >> 16)
    {
        int num = (e - s + 1) / (x >> 16);

        if (num >= 100)
        {
            r[ri ++] = (num / 100) + '0';
            num %= 100;
            r[ri ++] = (num / 10) + '0';
            num %= 10;
        }
        else if (num >= 10)
        {
            r[ri ++] = (num / 10) + '0';
            num %= 10;
        }

        r[ri ++] = (num) + '0';

        r[ri ++] = '[';

        _str(o, r + ri, dp, s, s + (x >> 16) - 1);

        r[(x & 0xFF) - 1] = ']';
    }
    else if (x >> 8)
    {
        _str(o, r, dp, s, x >> 8);
        r += dp[s][x >> 8] & 0xFF;
        _str(o, r, dp, (x >> 8) + 1, e);
    }
    else
    {
        for (int i = s; i <= e; i ++)
            r[ri ++] = o[i];
    }
}

char* encode(char* s)
{
    int l = strlen(s);
    if (l <= 4)
        return strdup(s);

    int** dp = malloc(sizeof(int*) * 256);
    for (int i = 0; i < l; i ++)
        dp[i] = calloc(sizeof(int), l + 1);

    int dl = _en(s, 0, l - 1, dp);
    char* r = malloc(dl + 1);
    _str(s, r, dp, 0, l - 1);
    r[dl] = 0;
    return r;
}


// GREEDY is not correct,
// GREEDY + DP is better solutions here !
// printf("%s.\n", encode("aaaaaaaaaabbbaaaaabbb"));
// printf("%s.\n", encode("abcdefabcdefffffffffffffedcbafedcba"));
/*
char* _en(char* str, int s, int e, char* c)
{
    if (e - s + 1 <= 4)
        return NULL;

    int cn[26] = {0};

    for (int i = s; i <= e; i ++)
    {
        int ca = str[i] - 'a';
        c[ca * 256 + cn[ca]] = i;
        cn[ca] ++;
    }

    int mx = 0;
    int ms = 0;
    int mn = 0;
    int ml = 0;

    for (int i = s + 1; i <= e; i ++)
    {
        int ca = str[i] - 'a';

        int n = 0;
        int nl = 0;

        for (int j = 0; j < cn[ca]; j ++)
        {
            bool same = true;
            int ss = c[ca * 256 + j];

            if (ss >= i)
                break;

            int se = i - 1 - ss + 1;
            int ae = e - i + 1;

            if (ae < se)
                continue;

            int as = i;

            for (int k = 0; k < se; k ++)
                if (str[ss + k] != str[i + k])
                {
                    same = false;
                    break;
                }

            // find more
            if (same)
            {
                n = ss;
                nl = 2;

                ss = i;

                int sn = ss + se;

                while (e - sn + 1 >= se)
                {
                    same = true;
                    for (int k = 0; k < se; k ++)
                    {
                        if (str[ss + k] != str[sn + k])
                        {
                            same = false;
                            break;
                        }
                    }

                    if (!same)
                        break;

                    nl ++;
                    sn += se;
                }

                int save = nl * se - se - 2 - (nl >= 100 ? 3 : (nl >= 10 ? 2 : 1));
                // printf("save is %d for nl %d n %d %d.\n", save, nl, n, se);

                if (save >= mx)
                {
                    mx = save;
                    ms = n;
                    mn = nl;
                    ml = se;
                    // printf("mx %d, ms %d mn %d ml %d.\n", mx, ms, mn, ml);
                }
            }
        }
    }

    if (!mx)
        return NULL;

    char* r = strdup(str + s);

    char* rf = _en(str, s, ms - 1, c);
    int sl = ms - s;

    if (rf)
    {
        strcpy(r, rf);
        sl = strlen(rf);
        free(rf);
    }

    int omn = mn;
    if (mn >= 100)
    {
        r[sl ++] = (mn / 100) + '0';
        mn %= 100;
        r[sl ++] = (mn / 10) + '0';
        mn %= 10;
        r[sl ++] = (mn) + '0';
    }
    else if (mn >= 10)
    {
        r[sl ++] = (mn / 10) + '0';
        mn %= 10;
        r[sl ++] = (mn) + '0';
    }
    else
    {
        r[sl ++] = (mn) + '0';
    }

    r[sl ++]= '[';

    rf = _en(str, ms, ms + ml - 1, c);

    if (rf)
    {
        r[sl] = 0;
        strcat(r, rf);
        free(rf);
        sl = strlen(r);
    }
    else
    {
        for (int i = 0; i < ml; i++)
            r[sl ++] = str[ms + i];
    }

    r[sl ++] = ']';
    ms += omn * ml;

    rf = _en(str, ms, e, c);

    if (rf)
    {
        r[sl] = 0;
        strcat(r, rf);
        free(rf);
    }
    else
    {
        for (int i = ms; i <= e; i ++)
            r[sl ++] = str[i];
        r[sl] = 0;
    }
    return r;
}

char* encode(char* s)
{
    int l = strlen(s);

    if (l <= 4)
        return strdup(s);

    char cache[26 * 256];
    char* r = _en(s, 0, l - 1, cache);
    return r ? r : strdup(s);
}
*/
