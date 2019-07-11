int fixedPoint(int* A, int ASize)
{
    int s = 0;
    int e = ASize - 1;

    if (A[0] > 0)
        return -1;

    if (A[0] == 0)
        return 0;

    while (s < e)
    {
        int m = (s + e) / 2;

        if (A[m] < m)
            s = m + 1;
        else
            e = m;
    }

    int c = -1;
    while (A[s] == s && s)
        c = s --;
    return c;
}

