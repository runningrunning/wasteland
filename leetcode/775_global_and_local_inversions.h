bool isIdealPermutation(int* A, int ASize)
{
    if (ASize <= 2)
        return true;

    for (int i = 0; i < ASize - 1; i ++)
    {
        if (A[i] > A[i + 1])
        {
            if (A[i] != i + 1 || A[i + 1] != i)
                return false;

            A[i] = i;
            A[i + 1] = i + 1;
        }
    }
    return true;
}
