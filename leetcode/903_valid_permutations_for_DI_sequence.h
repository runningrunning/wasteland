// I'm STUPID !!!!!!!!!!!
// how to do this?
// DP: JUST TO FIND HOW TO USE DP !
// SEEMS DP AGAIN !!
// similar with 920 number of music playlists ?
// how to find the solution for this one?

// just DP, start from the beginning or ending
// every time, when a number is used, it will be no changing sequence by reducing
// every number after it which is bigger than current one 1 to get n - 1 problems
// it's same from the ending !!!!!!

// how to represent this?
// "DID"
// {1, 0, 3, 2} => {1, 0, 2, 1}
// {2, 0, 3, 1} => {2, 0, 2, 1}
// {2, 1, 3, 0} => {2, 1, 2 ,0}
// {3, 0, 2, 1} => {3, 0, 2, 1}
// {3, 1, 2, 0} => {3, 1, 2, 0}
// very important !!!

/* dp[i][j] means the number of possible permutations of first i + 1 digits, */
/* where the i + 1th digit is j + 1th smallest in the rest of digits. */

// JUST OUT OF MIND !
// I'M TOO STUPID !!!
// almost correct answer !!
// stupid WRONG ALGORITHM, but almost correct !
/* if (v == 'D') */
/* { */
/*     for (int j = 0; j < o - i; j ++) */
/*     { */
/*         if (i == 0) */
/*             dp[j] = j; */
/*         else */
/*         { */
/*             if (j == 0) */
/*                 dp[j] = 0; */
/*             else */
/*                 dp[j] = odp[j - 1] + dp[j - 1]; */
/*         } */
/*     } */
/* } */
/* else */
/* { */
/*     for (int j = l - i; j >= 0; j --) */
/*     { */
/*         if (i == 0) */
/*             dp[j] = l - i - j; */
/*         else */
/*         { */
/*             if (j == l - i) */
/*                 dp[j] = 0; */
/*             else */
/*                 dp[j] = odp[j + 1] + dp[j + 1]; */
/*         } */
/*     } */

int numPermsDISequence(char* S)
{
    int l = strlen(S);
    int o = l + 1;

    long* dp = malloc(sizeof(long) * o);
    for (int i = 0; i < o; i ++)
        dp[i] = 1;
    long* ndp = malloc(sizeof(long) * o);

    for (int i = 0; i < l; i ++)
    {
        char v = S[i];

        if (v == 'D')
        {
            ndp[o - i - 1] = 0;
            for (int j = l - i - 1; j >= 0; j --)
                ndp[j] = (ndp[j + 1] + dp[j + 1]) % MOD;
        }
        else
        {
            for (int j = 0; j <= l - i - 1; j ++)
                ndp[j] = ((j == 0 ? 0 : ndp[j - 1]) + dp[j]) % MOD;
        }

        long* t = ndp;

        ndp = dp;
        dp = t;
    }
    return dp[0];

    /* for (int i = 0; i < l; i ++) */
    /* { */
    /*     char v = S[i]; */

    /*     if (i == 0) */
    /*     { */
    /*         if (v == 'D') */
    /*         { */
    /*             dp[0][0] = 1; */
    /*             dp[0][1] = 0; */
    /*         } */
    /*         else */
    /*         { */
    /*             dp[0][0] = 0; */
    /*             dp[0][1] = 1; */
    /*         } */
    /*     } */
    /*     else */
    /*     { */
    /*         if (v == 'D') */
    /*         { */
    /*         } */
    /*         else */
    /*         { */
    /*         } */
    /*     } */

    // stupid WRONG ALGORITHM, but almost correct !
    /* if (v == 'D') */
    /* { */
    /*     for (int j = 0; j < o - i; j ++) */
    /*     { */
    /*         if (i == 0) */
    /*             dp[j] = j; */
    /*         else */
    /*         { */
    /*             if (j == 0) */
    /*                 dp[j] = 0; */
    /*             else */
    /*                 dp[j] = odp[j - 1] + dp[j - 1]; */
    /*         } */
    /*     } */
    /* } */
    /* else */
    /* { */
    /*     for (int j = l - i; j >= 0; j --) */
    /*     { */
    /*         if (i == 0) */
    /*             dp[j] = l - i - j; */
    /*         else */
    /*         { */
    /*             if (j == l - i) */
    /*                 dp[j] = 0; */
    /*             else */
    /*                 dp[j] = odp[j + 1] + dp[j + 1]; */
    /*         } */
    /*     } */

    /* } */

    /* outl(dp, o - i); */

    /* odp = odp == dp_0 ? dp_1 : dp_0; */
    /* dp = dp == dp_0 ? dp_1 : dp_0; */
    /* } */
}
