// just do array ??
// stupid wrong algorithm, find the better solution !!!
// overflow again !
int comp(const void* e1, const  void* e2)
{
    /* unsigned int i1 = *((unsigned int*)e1); */
    /* unsigned int i2 = *((unsigned int*)e2); */

    /* if (i1 == i2) */
    /*     return 0; */
    /* return i1 > i2 ? 1 : -1; */
    long x = *((long*)e1) - *((long*)e2);
    if (x == 0)
        return 0;
    return x > 0 ? 1 : -1;
}

int maxWidthRamp(int* _A, int ASize)
{
    long* A = malloc(sizeof(long) * ASize);

    for (int i = 0;  i < ASize; i ++)
        A[i] = ((long) _A[i]) << 32 | i;

    qsort(A, ASize, sizeof(long), comp);

    int ramp = 0;
    int min = A[0] & 0xFFFF;
    for (int i = 1; i < ASize; i ++)
    {
        int cur = A[i] & 0xFFFF;
        if (cur < min)
            min = cur;
        else if (cur - min > ramp)
            ramp = cur - min;
    }
    return ramp;
}

int maxWidthRamp_1(int* A, int ASize)
{
    int ramp = 0;
    int st = 0;

    int pre_x = INT_MAX;
    while (ASize - st > ramp)
    {
        int x = A[st];
        if (x <= pre_x)
        {
            pre_x = x;

            for (int i = ASize - 1; i > st + ramp; i --)
                if (A[i] >= x)
                {
                    ramp = i - st;
                    break;
                }
        }
        st ++;
    }
    return ramp;
}
