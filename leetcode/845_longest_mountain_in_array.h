// be careful
// read the questions
// int m[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; is 0 !
int longestMountain(int* A, int ASize)
{
    if (ASize < 3)
        return 0;

    short* a = malloc(sizeof(short) * ASize);
    short* b = malloc(sizeof(short) * ASize);

    a[0] = 0;
    b[ASize - 1] = 0;
    int last = ASize - 2;

    for (int i = 1; i < ASize; i ++)
    {
        if (A[i] > A[i - 1])
            a[i] = a[i - 1] + 1;
        else
            a[i] = 0;

        if (A[last] > A[last + 1])
            b[last] = b[last + 1] + 1;
        else
            b[last] = 0;
        last --;
    }

    int max = INT_MIN;
    for (int i = 0; i < ASize; i ++)
        if (a[i] && b[i] && max < a[i] + b[i] + 1)
            max = a[i] + b[i] + 1;
    return max > 2 ? max : 0;
}
