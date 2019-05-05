int maxRotateFunction(int* A, int ASize)
{
    if (!A || !ASize)
        return 0;

    int all = 0;
    int result = 0;

    for (int i = 0; i < ASize; i ++)
    {
        all += A[i];
        result += i * A[i];
    }

    int delta = 0;
    int max = result;
    int pre = A[0];

    for (int i = 1; i < ASize; i ++)
    {
        delta = ASize * pre - all;
        /* int minus = all - pre; */
        /* int add = (ASize - 1) * pre; */
        result += delta;
        if (result > max)
            max = result;
        pre = A[i];
    }
    return max;
}
