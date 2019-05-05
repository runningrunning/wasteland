int maxA(int N)
{
    int all[51] = {0};

    all[0] = 0;
    all[1] = 1;
    all[2] = 2;
    all[3] = 3;
    all[4] = 4;
    all[5] = 5;

    int t1, t2;
    for (int i = 6; i <= N; i ++)
    {
        int n1 = all[i - 1] + 1;
        int n2 = all[i - 3] * 2;
        int n3 = all[i - 4] * 3;
        int n4 = all[i - 5] * 4;
        t1 = n1 > n2 ? n1 : n2;
        t2 = n3 > n4 ? n3 : n4;
        all[i] = t1 > t2 ? t1 : t2;
    }
    return all[N];
}

