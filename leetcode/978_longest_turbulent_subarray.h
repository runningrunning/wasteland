int maxTurbulenceSize(int* A, int ASize)
{
    int max_1 = 1;
    int max_2 = 1;
    int max = 1;
    for (int i = 1; i < ASize; i ++)
    {
        if (A[i] == A[i - 1])
        {
            max_1 = 1;
            max_2 = 1;
        }
        else if (A[i] > A[i - 1])
        {
            if (i & 1)
            {
                max_1 ++;
                max_2 = 1;

                if (max_1 > max)
                    max = max_1;
            }
            else
            {
                max_2 ++;
                max_1 = 1;
                if (max_2 > max)
                    max = max_2;
            }
        }
        else
        {
            if (i & 1)
            {
                max_2 ++;
                max_1 = 1;
                if (max_2 > max)
                    max = max_2;
            }
            else
            {
                max_1 ++;
                max_2 = 1;
                if (max_1 > max)
                    max = max_1;
            }
        }
    }

    return max;
}
