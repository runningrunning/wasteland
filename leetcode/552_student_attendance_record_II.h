// better solution ???
// simple DP

// with A
/* A  = '(withoutA) */
/* P  = 'A + 'P + '1C + '2C */
/* 1C = 'A + 'P */
/* 2C = '1C */
// without A
/* P = 'P + '1C + '2C */
/* 1C = 'P */
/* 2C = '1C */

#define MOD 1000000007

int checkRecord(int n)
{
    long a_a = 1;
    long a_p = 0;
    long a_c = 0;
    long a_2c = 0;

    long na_p = 1;
    long na_c = 1;
    long na_2c = 0;

    long ta, tp, tc;
    for (int i = 1; i < n; i ++)
    {
        ta = (na_p + na_c + na_2c) % MOD;
        tp = (a_a + a_p + a_c + a_2c) % MOD;
        tc = (a_a + a_p) % MOD;
        a_2c = a_c;
        a_a = ta;
        a_p = tp;
        a_c = tc;

        tp = (na_p + na_c + na_2c) % MOD;
        na_2c = na_c;
        na_c = na_p;
        na_p = tp;
    }

    return (a_a + a_p + a_c + a_2c + na_p + na_c + na_2c) % MOD;
}
