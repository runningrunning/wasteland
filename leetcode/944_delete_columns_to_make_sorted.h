int minDeletionSize(char** A, int ASize)
{
    if (!A || ASize < 2)
        return 0;
    int l = strlen(A[0]);
    if (!l)
        return 0;

    int* a = calloc(sizeof(int), l);

    for (int i = 1; i < ASize; i ++)
    {
        char* c = A[i];
        char* p = A[i - 1];

        for (int j = 0; j < l; j ++)
            a[j] += (c[j] >= p[j]) ? 1 : 0;
    }

    int n = 0;
    for (int i = 0; i < l; i ++)
        if (a[i] != ASize - 1)
            n ++;
    return n;
}
