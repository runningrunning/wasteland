// be careful !!!
// Pratice MORE 
int comp(const void* a, const void* b)
{
    return *((const int*) a) - *((const int*) b);
}

int twoSumLessThanK(int* A, int ASize, int K)
{
    if (ASize < 2)
        return -1;

    if (ASize == 2)
        return (A[0] + A[1]) < K ? (A[0] + A[1]) : -1;

    qsort(A, ASize, sizeof(int), comp);

    // out(A, ASize);

    if (A[0] + A[1] >= K)
        return -1;

    int c = 0;
    int s = 0;
    int t = 0;
    int e = ASize - 1;

    while (s < e)
    {
        t = A[s] + A[e];
        if (t >= K)
            e --;
        else
        {
            while (t < K)
            {
                c = t > c ? t : c;

                if (e == ASize - 1)
                    break;

                t = A[s] + A[++ e];
            }
            s ++;
        }
    }

    /* binary search is hard to correct, find the one before the max
    for (int i = 0; i < ASize - 1; i ++)
    {
        int left = K - A[i];

        if (left <= A[0])
            break;

        int s = i + 1;
        int e = le;

        while (s < e)
        {
            int m = (s + e) / 2;
            if (A[m] < left)
                s = m + 1;
            else
                e = m;
        }

        le = s;

        if (le - 1 != i && (A[i] + A[le - 1] < K))
            c = (A[i] + A[le - 1]) < c ? c : (A[i] + A[le - 1]);
    }
    */
    return c;
}

