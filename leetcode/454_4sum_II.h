void fs_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(n[i] < n[s]) i ++;
        while(n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    fs_sort(n, cs, e - 1);
    fs_sort(n, e + 1, ce);
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
    if (!A || !ASize || !B || !BSize || !C || !CSize || !D || !DSize)
        return 0;

    fs_sort(A, 0, ASize - 1);
    fs_sort(B, 0, BSize - 1);
    fs_sort(C, 0, CSize - 1);
    fs_sort(D, 0, DSize - 1);

    int all = 0;
    int dupA;
    int dupB;

    int minCD = C[0] + D[0];
    int maxCD = C[CSize - 1] + D[DSize -1];
    int minBCD = B[0] + minCD;
    int maxBCD = B[BSize - 1] + maxCD;

    if (A[0] + minBCD > 0 || A[ASize - 1] + maxBCD < 0)
        return 0;

    for (int i = 0; i < ASize; i ++)
    {
        if (A[i] + minBCD > 0)
            break;

        if (A[i] + maxBCD < 0)
            continue;

        if (i && A[i] == A[i - 1])
        {
            all += dupA;
            continue;
        }

        dupA = 0;

        for (int j = 0; j < BSize; j ++)
        {
            int x = A[i] + B[j];

            if (x + minCD > 0)
                break;

            if (x + maxCD < 0)
                continue;

            if (j && B[j] == B[j - 1])
            {
                dupA += dupB;
                continue;
            }

            dupB = 0;

            int c = 0;
            int d = DSize - 1;
            int y = 0;
            x = -x;

            while(c < CSize && d >= 0)
            {
                if (C[c] + D[0] > x || C[CSize - 1] + D[d] < x)
                    break;

                y = C[c] + D[d];

                while(y > x && d)
                {
                    d --;
                    y = C[c] + D[d];
                }

                while(y < x && c < CSize - 1)
                {
                    c ++;
                    y = C[c] + D[d];
                }

                if (y == x)
                {
                    int dupC = 1;
                    int t = C[c ++];
                    while(c < CSize && t == C[c])
                    {
                        dupC ++;
                        c ++;
                    }

                    int dupD = 1;
                    t = D[d --];
                    while(d >= 0 && t == D[d])
                    {
                        dupD ++;
                        d --;
                    }

                    dupB += dupC * dupD;
                }
            }
            dupA += dupB;
        }
        all += dupA;
    }
    return all;
}
