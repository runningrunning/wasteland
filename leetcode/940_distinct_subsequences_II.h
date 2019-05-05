// LEARN a lot, need to rework
// leetcode/730_count_different_palindromic_subsequences.h ??
// simple dp, but need to figure out why
#define MOD 1000000007
int distinctSubseqII(char* S)
{
    long sn[26] = {0};

    for (int i = 0; i < 26; i ++)
        sn[i] = -1;

    int i = 0;
    char c = S[i ++];

    long p = 0;

    while (c)
    {
        c -= 'a';

        long op = p;

        if (sn[c] == -1)
        {
            // not 'x' before, so just p + p'x' + 'x'
            p = p * 2 + 1;
        }
        else
        {
            // with 'x' before, so p + p'x' - previous number of sequence end with 'x'
            p = p * 2 - sn[c] + MOD;
        }

        // number of subsequences ends with 'x' this time
        sn[c] = op;
        p %= MOD;
        c = S[i ++];
    }
    return p % MOD;
}


/* // leetcode/730_count_different_palindromic_subsequences.h ?? */
/* // multiple dp here */
/* #define MOD 1000000007 */
/* int distinctSubseqII(char* S) */
/* { */
/*     long sn[26] = {0}; */

/*     for (int i = 0; i < 26; i ++) */
/*         sn[i] = -1; */

/*     int i = 0; */
/*     char c = S[i ++]; */

/*     long p = 0; */

/*     while (c) */
/*     { */
/*         c -= 'a'; */

/*         long op = p; */

/*         if (sn[c] == -1) */
/*         { */
/*             sn[c] = p; */
/*             p += sn[c] + 1; */
/*         } */
/*         else */
/*         { */
/*             p = p * 2 - sn[c] + MOD; */
/*             sn[c] = op; */
/*         } */

/*         // printf("sn[c] %d, p %d %d.\n", sn[c], p, i); */
/*         sn[c] %= MOD; */
/*         p %= MOD; */
/*         c = S[i ++]; */
/*     } */

/*     return p % MOD; */
/* } */
