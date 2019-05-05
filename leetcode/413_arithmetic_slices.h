int numberOfArithmeticSlices(int* A, int ASize)
{
    if (ASize < 3)
        return 0;

    int all = 0;
    int num = 0;
    int cur = A[1] - A[0] - 1;
    for (int i = 1; i < ASize - 1; i ++)
    {
        if (A[i] - A[i - 1] == A[i + 1] - A[i])
        {
            if (cur != A[i] - A[i - 1])
                num = 1;
            else
                num ++;
        }
        else if (num)
        {
            all += ((num + 1) * num) / 2;
            num = 0;
        }
        cur = A[i] - A[i - 1];
    }
    if (num)
        all += ((num + 1) * num) / 2;
    return all;
}
