// corner case !!!
// all zero, missing 1
// int m[] = {0, 0, 0, 0, 1}; int s = 2;
// int m[] = {0, 0, 0, 0, 0}; int s = 0;
int numSubarraysWithSum(int* A, int ASize, int S)
{
    int all = 0;

    if (!S)
    {
        int pi = 0;
        for (int i = 0; i < ASize; i ++)
        {
            if (A[i] == 1)
            {
                all += (pi + 1) * pi / 2;
                pi = 0;
            }
            else
                pi ++;
        }

        if (!A[ASize - 1])
            all += (pi + 1) * pi / 2;
    }
    else
    {
        int zi = 0;
        int* zeros = malloc(sizeof(int) * S);

        int pi = 0;
        int ones = 0;

        for (int i = 0; i < ASize; i ++)
        {
            if (A[i] == 1)
            {
                zeros[zi ++] = pi;
                if (zi == S)
                {
                    ones = i + 1;
                    break;
                }
                pi = 0;
            }
            else
                pi ++;
        }

        if (zi < S)
            return 0;

        int oi;
        for (int i = ones; i < ASize; i ++)
        {
            zi = zi % S;
            int czi = zeros[zi];
            oi = i;
            while (i < ASize && !A[i])
                i ++;
            zeros[zi] = i - oi;
            all += (czi + 1) * (i - oi +  1);
            zi ++;
        }

        if (A[ASize - 1])
        {
            zi %= S;
            all += (zeros[zi] + 1);
        }
    }
    return all;
}
