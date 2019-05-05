int repeatedNTimes(int* A, int ASize)
{
    char* b = calloc(sizeof(char), 10000);
    for (int i = 0; i < ASize; i ++)
        if (b[A[i]])
            return A[i];
        else
            b[A[i]] = 1;

    return 0;
}
