// just write code, any better solution ???
// just one turn
int maxSumTwoNoOverlap(int* A, int ASize, int L, int M)
{
    if (L + M > ASize)
        return 0;

    int* ll = calloc(sizeof(int), ASize);
    int* lm = calloc(sizeof(int), ASize);

    int* rl = calloc(sizeof(int), ASize);
    int* rm = calloc(sizeof(int), ASize);


    int lml = 0;
    int lmm = 0;
    int cll = 0;
    int clm = 0;

    int rml = 0;
    int rmm = 0;
    int crl = 0;
    int crm = 0;

    for (int i = 0; i < ASize; i ++)
    {
        cll += A[i];
        clm += A[i];

        crl += A[ASize - i - 1];
        crm += A[ASize - i - 1];

        if (i >= M - 1)
        {
            if (i >= M)
            {
                clm -= A[i - M];
                crm -= A[ASize - i - 1 + M];
            }

            if (lmm < clm)
                lmm = clm;

            if (rmm < crm)
                rmm = crm;
        }

        if (i >= L - 1)
        {
            if (i >= L)
            {
                cll -= A[i - L];
                crl -= A[ASize - i - 1 + L];
            }

            if (lml < cll)
                lml = cll;

            if (rml < crl)
                rml = crl;
        }

        ll[i] = lml;
        lm[i] = lmm;
        rl[ASize - i - 1] = rml;
        rm[ASize - i - 1] = rmm;
    }

    int max = 0;
    for (int i = 0; i < ASize - 1; i ++)
    {
        int clm = ll[i] + rm[i + 1];
        int cml = lm[i] + rl[i + 1];

        if (max < clm)
            max = clm;
        if (max < cml)
            max = cml;
    }

    if (L == 0 || M == 0)
    {
        if (max < ll[ASize - 1])
            max = ll[ASize - 1];
        if (max < lm[ASize - 1])
            max = lm[ASize - 1];
    }
    return max;
}
