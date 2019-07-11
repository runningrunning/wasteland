int sumOfDigits(int* A, int ASize)
{
    int min = 100;
    for (int i = 0; i < ASize; i ++)
    {
        if (A[i] == 1)
            return 0;

        if (A[i] < min)
            min = A[i];
    }

    if (min == 100)
        return 0;

    return !(((min / 10) + (min % 10)) % 2);
}

