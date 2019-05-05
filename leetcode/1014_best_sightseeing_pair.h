// TODO
// array ?
// complicated !
// FIND BETTER SOLUTION !!!!!!!
// NB DIFFERENT SOLUTION !!!
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxScoreSightseeingPair(int* A, int ASize) {
    int best = 0; int result = 0;
    for (int i = 0; i < ASize; i ++)
    {
        result = MAX(result, best + A[i]);
        best = MAX(best, A[i]) - 1;
    }

    return result;

    int max = A[0] + A[1] - 1;
    if (ASize == 2)
        return max;
    for (int i = 0; i < ASize;)
    {
        int j = i + 1;
        for (; j < i + A[i] && j < ASize; j ++)
        {
            max = max < (A[i] + A[j] - j + i) ? (A[i] + A[j] - j + i) : max;
            if (i + A[i] < j + A[j])
                break;
        }
        i = j;
    }

    return max;

    int ps = 0;
    int pe = -1;
    for (int i = 0; i < ASize; i ++)
    {
        if (pe == -1)
        {
            for (int j = i + 1; j < i + A[i] && j < ASize; j ++)
            {
                if (A[i] + A[j] - j + i > max)
                {
                    max = A[i] + A[j] - j + i;
                    pe = j;
                }
                if (i + A[i] < j + A[j])
                    break;
            }
        }
        else
        {
            if (i + A[i] > ps + A[ps])
            {
                ps = i;
                for (int j = pe > i ? pe : (i + 1); j < i + A[i] && j < ASize; j ++)
                {
                    if (A[i] + A[j] - j + i > max)
                    {
                        max = A[i] + A[j] - j + i;
                        pe = j;
                    }
                    if (i + A[i] < j + A[j])
                        break;
                }
            }

            /* if (A[i] <= A[ps] - (i - ps)) */
            /*     continue; */
            /* ps = i; */
            /* max = max < (A[i] + A[pe] - pe + i) ? (A[i] + A[pe] - pe + i) : max; */
            /* for (int j = pe + 1; j < i + A[i] && j < ASize; j ++) */
            /* { */
            /*     if (A[i] + A[j] - j + i > max) */
            /*     { */
            /*         max = A[i] + A[j] - j + i; */
            /*         pe = j; */
            /*     } */
            /* } */
        }
    }
    return max;
}
