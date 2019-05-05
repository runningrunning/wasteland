bool isMonotonic(int* A, int ASize)
{
    if (ASize <= 2)
        return true;

    int i = 0;

    for (i = 1; i < ASize; i ++)
        if (A[i] != A[0])
            break;

    if (i == ASize)
        return true;
    bool larger = A[i] > A[0];

    for (; i < ASize; i ++)
        if (A[i] != A[i - 1] && (A[i] > A[i - 1]) != larger)
            return false;
    return true;
}
