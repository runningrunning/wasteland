bool buddyStrings(char* A, char* B)
{
    int i = 0;
    int c[26] = {0};
    bool over2 = false;

    int di = 0;
    int df[4] = {0};

    while (A[i] && B[i])
    {
        int a = A[i] - 'a';
        int b = B[i] - 'a';
        if (a != b)
        {
            df[di ++] = (a << 8) | b;
            if (di > 2)
                return false;
        }

        c[a] ++;
        if (c[a] > 1)
            over2 = true;

        i ++;
    }

    if (A[i] || B[i])
        return false;

    if (!di)
        return over2;

    if (di != 2)
        return false;

    return ((df[0] & 0xFF) == ((df[1] >> 8) & 0xFF))
        && ((df[1] & 0xFF) == ((df[0] >> 8) & 0xFF));
}
