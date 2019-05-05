// better solution ???
// length is even !
int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

bool canReorderDoubled(int* A, int ASize)
{
    long a = 0;
    int ne = 0;

    for (int i = 0; i < ASize; i ++)
    {
        long x = A[i];
        a += x;
        if (x < 0)
            x = - x;

        if (!(x & 1))
            ne ++;
    }

    if ((a % 3) || ne < ASize / 2)
        return false;

    qsort(A, ASize, sizeof(int), comp);

    int s = 1;

    for (int i = 0; i < ASize - 1; i ++)
    {
        if (A[i] != 0xFFFFFFFF)
        {
            int x = 0;
            if (A[i] > 0)
                x = A[i] * 2;
            else
            {
                x = - A[i];
                if (x & 1)
                    return false;
                x = A[i] / 2;
            }

            for (; s < ASize; s ++)
                if (A[s] == x)
                {
                    A[s] = 0xFFFFFFFF;
                    break;
                }

            if (s == ASize)
                return false;
            s ++;
        }
    }

    return true;
}
