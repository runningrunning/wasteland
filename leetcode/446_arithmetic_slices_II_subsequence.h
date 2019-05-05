// COOL !!! combine hash and DP !!!
// CPP is better than C, only CPP can use mapping etc
// BETTER SOLUTION !!! combined hash + the my c DP could be an easiest solution !
// LEARN A LOT !!!

// DP is simple, but not that simple
// failed case {1, 3, 5, 7, 7, 9, 11}; how to handle the 7, 7 in the middle
// use delta as mapping point and DP index !!!
// it can be done with I, J DP, just need to find a way to do so !
// simple by combing with the hash method.
int numberOfArithmeticSlices(int* A, int ASize)
{
    int all = 0;
    int** dp = malloc(sizeof(int*) * ASize);

    for (int i = 0; i < ASize; i ++)
        dp[i] = calloc(sizeof(int), ASize);

    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int prime = 1031;

    for (int i = 0; i < pl; i ++)
    {
        prime = pri[i];
        if (prime / 4 > ASize)
            break;
    }

    int** hash = calloc(sizeof(int*), prime);

    for (int i = 0; i < ASize; i ++)
    {
        int x = A[i] % prime;
        if (x < 0)
            x += prime;

        while (hash[x] && A[hash[x][1]] != A[i])
            x = (x + 1) % prime;

        if (!hash[x])
        {
            hash[x] = malloc(sizeof(int) * 2);
            hash[x][0] = 1;
            hash[x][1] = i;
        }
        else
        {
            int l = hash[x][0];
            hash[x] = realloc(hash[x], sizeof(int) * (l + 2));
            hash[x][l + 1] = i;
            hash[x][0] = l + 1;
        }
    }

    for (int i = 1; i < ASize; i ++)
    {
        for (int j = 0; j < i; j ++)
        {
            long i_v = A[i];
            long j_v = A[j];
            long p = j_v - (i_v - j_v);

            int x = p % prime;
            if (x < 0)
                x += prime;

            while (hash[x] && A[hash[x][1]] != p)
                x = (x + 1) % prime;

            if (!hash[x])
                continue;

            int* ins = hash[x] + 1;
            for (int k = 0; k < hash[x][0]; k ++)
            {
                if (ins[k] >= j)
                    break;
                dp[j][i] += dp[ins[k]][j] + 1;
            }
            all += dp[j][i];
        }
    }
    return all;
}

// out of mind !!!!
// DP ?? Try to solve with DP ways ~ // dp is pretty easy ?
// DP is simple, not that simple
// failed case {1, 3, 5, 7, 7, 9, 11}; how to handle the 7, 7 in the middle
// use delta as mapping point and DP index !!!
// only suitable for CPP code

// peek hint !!!!
// How to solve this with DP, not math?
// Find better hash function, hash with int index
//
// must have better solution !!!!/
// find simple solutions ??
// better solution ?
// just brute force ~
// [0, 1, 2, 2, 2] ???!!!
// int m[] = {0,2000000000,-294967296}; wrong :(
// int m[] = {1, 1, 1, 1, 1} is 16 !

// hash ?
// just try hash ways?
// find better solutions ?
// the new find will never be in the middle

// stupid wrong algorithm !!,
// can not solve problems like 1, 3, 5, 7, 7, 9
// int m[] = {1, 3, 5, 7, 7, 9}; is 7
// int m[] = {1, 3, 5, 7,  9}; is 7 also

/* #include <vector> */
/* #include <unordered_map> */
/* using namespace std; */
/* class Solution { */
/* public: */
/*     int numberOfArithmeticSlices(vector<int>& A) { */
/*         int n = A.size(); */
/*         if (n < 3) { */
/*             return 0; */
/*         } */

/*         long res = 0; */
/*         unordered_map<long long, int> dp[n]; */

/*         for (int i = 1; i < n; i ++) */
/*             for (int j = 0; j < i; j ++) */
/*             { */
/*                 long long d = (long long) A[i] - (long long) A[j]; */
/*                 int num = 0; */
/*                 if (dp[j].find(d) != dp[j].end()) */
/*                     num = dp[j][d]; */
/*                 dp[i][d] = num + 1; */
/*                 res += num; */
/*             } */
/*         return res; */
/*     } */
/* }; */


/* // DP is simple, not that simple */
/* // failed case {1, 3, 5, 7, 7, 9, 11}; how to handle the 7, 7 in the middle */
/* // use delta as mapping point and DP index !!! */
/* // it can be done with I, J DP, just need to find a way to do so ! */
/* // simple by combing with the hash method */
/* int numberOfArithmeticSlices(int* A, int ASize) */
/* { */
/*     int all = 0; */
/*     int** dp = malloc(sizeof(int*) * ASize); */

/*     for (int i = 0; i < ASize; i ++) */
/*         dp[i] = calloc(sizeof(int), ASize); */

/*     for (int i = 2; i < ASize; i ++) */
/*     { */
/*         long i_v = A[i]; */
/*         for (int m = 0; m < i - 1; m ++) */
/*             for (int n = m + 1; n < i; n ++) */
/*             { */
/*                 long m_v = A[m]; */
/*                 long n_v = A[n]; */
/*                 long d = n_v - m_v; */

/*                 if (d == i_v - n_v) */
/*                 { */
/*                     dp[n][i] += dp[m][n] + 1; */
/*                 } */
/*                 all += dp[m][n]; */

/*                 /\* if (d == i_v - n_v) *\/ */
/*                 /\* { *\/ */
/*                 /\*     int num = dp[m][n] + 1; *\/ */
/*                 /\*     dp[m][i] = num; *\/ */

/*                 /\*     if (d) *\/ */
/*                 /\*     { *\/ */
/*                 /\*         if (num >= 1) *\/ */
/*                 /\*         { *\/ */
/*                 /\*             if (num & 1) *\/ */
/*                 /\*             { *\/ */
/*                 /\*                 for (int j = 0; j <= num / 2; j ++) *\/ */
/*                 /\*                 { *\/ */
/*                 /\*                     if (!((num + 1) % (j + 1))) *\/ */
/*                 /\*                         all ++; *\/ */
/*                 /\*                 } *\/ */
/*                 /\*             } *\/ */
/*                 /\*             else *\/ */
/*                 /\*             { *\/ */
/*                 /\*                 for (int j = 0; j < num / 2; j ++) *\/ */
/*                 /\*                 { *\/ */
/*                 /\*                     if (!((num - j) % (j + 1))) *\/ */
/*                 /\*                         all ++; *\/ */
/*                 /\*                 } *\/ */
/*                 /\*             } *\/ */
/*                 /\*             // printf("%d %d %d %d.\n", m + 1, i + 1, onum, all - oall); *\/ */
/*                 /\*         } *\/ */
/*                 /\*     } *\/ */
/*                 /\*     else if (n == i - 1) *\/ */
/*                 /\*     { *\/ */
/*                 /\*         long ps = 1; *\/ */
/*                 /\*         long ms = 1; *\/ */
/*                 /\*         int as = 1; *\/ */
/*                 /\*         for (int i = 1; i <= num; i ++) *\/ */
/*                 /\*         { *\/ */
/*                 /\*             as *= (num - i + 1); *\/ */
/*                 /\*             as /= i; *\/ */
/*                 /\*             all += as; *\/ */
/*                 /\*         } *\/ */
/*                 /\*     } *\/ */
/*                 /\* } *\/ */

/*             } */
/*     } */
/* } */

/*     return all; */
/* } */

/* /\* #define HASH_M(h, d, v) do {                    \ *\/ */
/* /\*         x = v % d;                              \ *\/ */
/* /\*         if (x < 0)                              \ *\/ */
/* /\*             x += d;                             \ *\/ */
/* /\*         while (h[x] && A[h[x] - 1] != v)        \ *\/ */
/* /\*             x = (x + 1) % d;                    \ *\/ */
/* /\*     } while(0) *\/ */

/* /\* /\\* long get_nums(int* nums, int n) *\\/ *\/ */
/* /\* /\\* { *\\/ *\/ */
/* /\* /\\*     if (nums[n]) *\\/ *\/ */
/* /\* /\\*         return nums[n] - 1; *\\/ *\/ */

/* /\* /\\*     long num = (n - 1) * (n - 2) / 2; *\\/ *\/ */

/* /\* /\\*     for (int i = 1; i < n / 2; i ++) *\\/ *\/ */
/* /\* /\\*     { *\\/ *\/ */
/* /\* /\\*         if (i * 2 + 3 > n) *\\/ *\/ */
/* /\* /\\*             break; *\\/ *\/ */

/* /\* /\\*         for (int j = 0; j <= i; j ++) *\\/ *\/ */
/* /\* /\\*         { *\\/ *\/ */
/* /\* /\\*             if (j + 3 + i * 2 > n) *\\/ *\/ */
/* /\* /\\*                 break; *\\/ *\/ */
/* /\* /\\*             num += get_nums(nums, (n + i) / (i + 1)); *\\/ *\/ */
/* /\* /\\*         } *\\/ *\/ */
/* /\* /\\*     } *\\/ *\/ */
/* /\* /\\*     nums[n] = num + 1; *\\/ *\/ */
/* /\* /\\*     return num; *\\/ *\/ */
/* /\* /\\* } *\\/ *\/ */

/* /\* int numberOfArithmeticSlices(int* A, int ASize) *\/ */
/* /\* { *\/ */
/* /\*     // 1 << i *\/ */
/* /\*     // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 *\/ */
/* /\*     // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok. *\/ */
/* /\*     int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617}; *\/ */
/* /\*     int pl = sizeof(pri)/sizeof(pri[0]); *\/ */
/* /\*     int dp = 1031; *\/ */

/* /\*     for (int i = 0; i < pl; i ++) *\/ */
/* /\*     { *\/ */
/* /\*         dp = pri[i]; *\/ */
/* /\*         if (dp / 4 > ASize) *\/ */
/* /\*             break; *\/ */
/* /\*     } *\/ */

/* /\*     int all = 0; *\/ */

/* /\*     int* seen = calloc(sizeof(int), dp); *\/ */
/* /\*     int* hash = calloc(sizeof(int), dp); *\/ */

/* /\*     for (int i = 0; i < ASize; i ++) *\/ */
/* /\*     { *\/ */
/* /\*         int x; *\/ */
/* /\*         HASH_M(hash, dp, A[i]); *\/ */
/* /\*         while (hash[x]) *\/ */
/* /\*             x = (x + 1) % dp; *\/ */
/* /\*         hash[x] = i + 1; *\/ */
/* /\*     } *\/ */

/* /\*     for (int i = 0; i < ASize - 2; i ++) *\/ */
/* /\*     { *\/ */
/* /\*         for (int j = i + 1; j < ASize - 1; j ++) *\/ */
/* /\*         { *\/ */
/* /\*             for (int k = j + 1; k < ASize; k ++) *\/ */
/* /\*             { *\/ */
/* /\*                 long f = A[i]; *\/ */
/* /\*                 long m = A[j]; *\/ */
/* /\*                 long p = A[k]; *\/ */

/* /\*                 if (m - f != p - m) *\/ */
/* /\*                     continue; *\/ */

/* /\*                 long d = m - f; *\/ */
/* /\*                 p = f - d; *\/ */

/* /\*                 int x; *\/ */

/* /\*                 HASH_M(seen, dp, p); *\/ */
/* /\*                 if (seen[x]) *\/ */
/* /\*                     continue; *\/ */
/*  */
/* /\*                 if (!d) *\/ */
/* /\*                 { *\/ */
/* /\*                     HASH_M(seen, dp, A[i]); *\/ */
/* /\*                     while (seen[x]) *\/ */
/* /\*                         x = (x + 1) % dp; *\/ */
/* /\*                     seen[x] = i + 1; *\/ */
/* /\*                 } *\/ */

/* /\*                 long num = 3; *\/ */
/* /\*                 int cur = k + 1; *\/ */
/* /\*                 long v = A[k] + d; *\/ */

/* /\*                 while (true) *\/ */
/* /\*                 { *\/ */
/* /\*                     HASH_M(hash, dp, v); *\/ */
/* /\*                     while (hash[x]) *\/ */
/* /\*                     { *\/ */
/* /\*                         if (A[hash[x] - 1] == v && hash[x] > cur) *\/ */
/* /\*                             break; *\/ */
/* /\*                         x = (x + 1) % dp; *\/ */
/* /\*                     } *\/ */

/* /\*                     if (!hash[x]) *\/ */
/* /\*                         break; *\/ */

/* /\*                     num ++; *\/ */
/* /\*                     cur = hash[x]; *\/ */
/* /\*                     v += d; *\/ */
/* /\*                 }; *\/ */

/* /\*                 if (d) *\/ */
/* /\*                     all += (num - 1) * (num - 2) / 2; // get_nums(nums, num); *\/ */
/* /\*                 else // corner case for same *\/ */
/* /\*                 { *\/ */
/* /\*                     long ms = 1 * 2; *\/ */
/* /\*                     long ps = num * (num - 1); *\/ */
/* /\*                     long rs = ps / ms; *\/ */
/* /\*                     for (int i = 0; i <= num - 3; i ++) *\/ */
/* /\*                     { *\/ */
/* /\*                         rs *= (num - 2 - i); *\/ */
/* /\*                         rs /= (3 + i); *\/ */
/* /\*                         all += rs; *\/ */
/* /\*                     } *\/ */
/* /\*                     printf("num is %d %d %d : %d %d.\n", A[i], j, k, num, all); *\/ */
/* /\*                 } *\/ */
/* /\*             } *\/ */
/* /\*         } *\/ */

/* /\*         int x; *\/ */
/* /\*         int c = A[i]; *\/ */
/* /\*         HASH_M(seen, dp, c); *\/ */
/* /\*         while (seen[x] && seen[x] != i + 1) *\/ */
/* /\*             x = (x + 1) % dp; *\/ */
/* /\*         seen[x] = i + 1; *\/ */
/* /\*     } *\/ */
/* /\*     return all; *\/ */
/* /\* } *\/ */
