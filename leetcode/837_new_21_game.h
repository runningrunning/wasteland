// why no DP version is faster then DP version
// as DP skip the sequence but non DP version just
// take the previous W values !!!
// learn a lot from the calculate the previous possibility !!!!
double new21Game(int N, int K, int W)
{
    if (K == 0)
        return 1.0;

    double p = 0.00000;
    double* t = malloc(sizeof(double) * N);

    for (int i = 0; i < N; i ++)
    {
        if (i < W)
            t[i] = (p + 1) * (1 / (double) W);
        else
        {
            t[i] = p * (1 / (double) W);
            p -= t[i - W];
        }

        if (i < K - 1)
            p += t[i];
    }

    p = 0.0;

    for (int i = K - 1; i < N; i ++)
        p += t[i];

    return p;
}

double _n21g_1(int N, int c, int K, int W, double* t, char* ti)
{
    if (c >= K)
        return c <= N ? 1.0 : 0.0;

    if (ti[c])
        return t[c];

    double x = 0.0;
    for (int i = 1; i <= W; i ++)
        x += _n21g_1(N, c + i, K, W, t, ti) / ((double) W);

    t[c] = x;
    ti[c] = 1;
    return x;
}

// DP version from 0 to K, it's slow because it's do calculate from the last
double new21Game_1(int N, int K, int W) {
    char* ti = malloc(K);
    bzero(ti, K);
    double* t = malloc(sizeof(double) * K);
    double y =  _n21g_1(N, 0, K, W, t, ti);
    return y;
}

double _n21g_2(int N, int c, int K, int W, double* t)
{
    if (fabs(t[c]) >= 10e-10) // be careful about checking 0
        return t[c];

    int l = c - W;
    l = l < 0 ? 0 : l;

    double x = 0.0;
    for (int i = c - 1; i >= l; i --)
    {
        x += _n21g_2(N, i, K, W, t) / ((double) W);
    }

    if (c < W)
        x += 1 / ((double) W);
    t[c] = x;
    return x;
}

double new21Game_2(int N, int K, int W) {
    double* t = malloc(sizeof(double) * N);
    for (int i = 0; i < N; i ++)
        t[i] = 0.00000;
    double y =  _n21g_2(N, N - 1, K, W, t);

    double p = 0.0;
    for (int i = K - 1; i < N; i ++)
        p += t[i];
    return p;
}

