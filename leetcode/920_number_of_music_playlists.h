// DP CHEATING !!!!!!!!!!!!!!!!!!!!!!!!!!!!
// CHEATING BY READING THE ANSWER !!!!!!!!!!!!!!!!!!!!!!!!!
// PEAK SOLUTION AND CHEATING !!!
// F(N,L,K) = F(N - 1, L - 1, K) * N + F(N, L - 1, K) * (N - K)
// WHY DP IS SO HARD !!!!
// NB DIFFERENT SOLUTION
// LEARN A LOT !


// math again !!!! NOT
// or DP ?
// just DP
// how to keep this condition works [every song must be played at least once] ?
// how to solve this in DP ???????

// NO RECURSION version ?

#define MOD 1000000007

int numMusicPlaylists(int N, int L, int K) {
    long** dp = malloc(sizeof(long*) * N);
    for (int i = 0; i < N; i ++)
        dp[i] = calloc(sizeof(long), L);

    for (int i = 0; i < N; i ++)
    {
        dp[i][i] = ((i == 0 ? 1 : dp[i - 1][i - 1]) * (i + 1)) % MOD;

        if (i < K)
            continue;

        for (int j = i + 1; j < L; j ++)
            dp[i][j] = ((i == 0 ? 0 : dp[i - 1][j - 1]) * (i + 1) + dp[i][j - 1] * (i + 1 - K)) % MOD;
    }
    return dp[N - 1][L - 1];
}

/* int numMusicPlaylists(int N, int L, int K) { */
/*     long** dp = malloc(sizeof(long*) * N); */
/*     for (int i = 0; i < N; i ++) */
/*         dp[i] = calloc(sizeof(long), L); */

/*     for (int i = 0; i < N; i ++) */
/*     { */
/*         dp[i][i] = ((i == 0 ? 1 : dp[i - 1][i - 1]) * (i + 1)) % MOD; */
/*         for (int j = i + 1; j < L; j ++) */
/*             dp[i][j] = ((i == 0 ? 0 : dp[i - 1][j - 1]) * (i + 1 > K ? (i + 1) : 0)) % MOD + (dp[i][j - 1] * (i + 1 > K ? (i + 1 - K) : 0)) % MOD; */
/*     } */
/*     return dp[N - 1][L - 1] % MOD; */
/* } */

// WRONG ALGORITHM !
/* long nmp(int i, int n, int l, int k) */
/* { */
/*     if (i >= l) */
/*         return 1; */

/*     if (i < k) */
/*         return ((n - i) * nmp(i + 1, n, l, k)) % MOD; */

/*     return ((n - k) * nmp(i + 1, n, l, k)) % MOD; */
/* } */

/* int numMusicPlaylists(int N, int L, int K) */
/* { */
/*     // remove the (L - N) */
/*     int x = nmp(0, N, L - N + K, K) % MOD; */
/*     // insert L - N back */

/*     printf("x %d.\n", x); */
/*     int l = L - N; */
/*     for (int i = 0; i < N - K; i ++) */
/*     { */
/*         x = (x * l) % MOD; */
/*         l ++; */
/*     } */
/*     return x; */
/* } */
