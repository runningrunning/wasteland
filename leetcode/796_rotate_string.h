bool rotateString(char* A, char* B)
{
    if (!A || !B)
        return A == B;

    int la = strlen(A);
    int lb = strlen(B);

    if (la != lb)
        return false;

    int ci = 0;
    int cs[100];

    int xa = 0;
    int xb = 0;

    int sa = 0;
    int sb = 0;

    bool same = true;

    for (int i = 0; i < la; i ++)
    {
        sa += A[i];
        sb += B[i];

        xa ^= A[i];
        xb ^= B[i];

        if (B[i] == A[0])
            cs[ci ++] = i;

        if (same)
            same = A[i] == B[i];
    }

    if (sa != sb || xa != xb)
        return false;

    if (same)
        return true;

    for (int i = 0; i < ci; i ++)
    {
        int j = 0;
        int k = cs[i];

        char c = A[j ++];
        while (c)
        {
            if (c != B[(k ++) % lb])
                break;
            c = A[j ++];
        }

        if (!c)
            return true;
    }
    return false;
}
