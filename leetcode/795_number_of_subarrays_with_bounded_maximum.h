int numSubarrayBoundedMax(int* A, int ASize, int L, int R)
{
    int a = 0;
    int p = 0;
    int s = -1;
    int m = -1;

    for (int i = 0; i < ASize; i ++)
    {
        if (A[i] <= R)
        {
            if (s == -1)
                s = i;

            if (A[i] < L)
            {
                if (m != -1)
                    a += p;
            }
            else
            {
                p = (s == -1 ? 0 : i - s) + 1;
                m = i;
                a += p;
            }
        }
        else
        {
            p = 0;
            s = -1;
            m = -1;
        }
    }
    return a;
}
