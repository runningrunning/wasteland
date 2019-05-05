// try with DP solution !!!!!
// STUPID TYPO ERROR !!!! How CAN NOT I FIND IT !!!!
double _kp(int N, int K, int r, int c, double p)
{
    if (K == 0)
        return p;

    int d = 8;
    int xd[] = {-1, -2, -2, -1, 1, 2,  2,  1};
    int yd[] = {-2, -1,  1,  2, 2, 1, -1, -2};

    double pn = 0.0;
    for (int k = 0; k < d; k ++)
    {
        int x = r + xd[k];
        int y = c + yd[k];
        if (x >= 0 && x < N && y >= 0 && y < N)
        {
            pn += _kp(N, K - 1, x, y, p / 8.0);
        }
    }
    return pn;
}

double knightProbability_1(int N, int K, int r, int c)
{
    return _kp(N, K, r, c, 1.0);
}

double knightProbability(int N, int K, int r, int c)
{
    if (K == 0)
        return 1.0;

    double p1[625] = {0.0};
    double p2[625] = {0.0};

    int d = 8;
    int xd[] = {-1, -2, -2, -1, 1, 2,  2,  1};
    int yd[] = {-2, -1,  1,  2, 2, 1, -1, -2};

    for (int i = 0; i < N * N; i ++)
    {
        p1[i] = 1.0;
        p2[i] = 1.0;
    }

    double* pk = p1;
    double* pp = p2;
    double per = 1.0 / 8.0;

    for (int n = 0; n < K; n ++)
    {
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < N; j ++)
            {
                double pn = 0.0;
                for (int k = 0; k < d; k ++)
                {
                    int x = i + xd[k];
                    int y = j + yd[k];

                    if (x >= 0 && x < N && y >= 0 && y < N)
                    {
                        pn += pk[x * N + y];
                    }

                }
                pp[i * N + j] = pn * per;
            }

        double* pt = pk;
        pk = pp;
        pp = pt;
    }

    for (int i = 0; i < N * N; i ++)
        printf("i %d: %lf %lf \n",i, p1[i], p2[i]);
    double* pt = K & 1 ? p2 : p1;
    return pt[r * N + c];
}
