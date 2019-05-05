// DP ? NOT
// 2  answer, circular
// not circular it the largest subarray ? // not LCS (longest subsequence problem)
// circular is the start_from_0 + end_at_last value
// about corner case !! c_max and v_max must be INT_MIN

// NB DIFFERENT SOLUTION (ONE PASS)
// FIND THE MAX FROM BEGIN AND MIN IN THE MIDDLE

int maxSubarraySumCircular(int* A, int ASize)
{
    if (!A)
        return 0;

    if (ASize == 1)
        return A[0];

    // current max
    /* int* a = malloc(sizeof(int) * ASize); */

    // c_max and v_max must INT_MIN
    // cmin must be 0
    int c_max = INT_MIN;
    int c_min = 0;
    int v_max = INT_MIN;
    int v_min = INT_MAX;
    int v_all = 0;

    for (int i = 0; i < ASize; i ++)
    {
        v_all += A[i];

        if (v_all - c_min > v_max)
            v_max = v_all - c_min;

        if (i)
        {
            if (v_all - c_max < v_min)
                v_min = v_all - c_max;
        }

        if (v_all < c_min)
            c_min = v_all;
        if (v_all > c_max)
            c_max = v_all;

        /* a[i] = c_max; */
    }

    /* v_all = A[ASize - 1]; */
    /* c_max = A[ASize - 1]; */

    /* for (int i = ASize - 2; i >= 0; i --) */
    /* { */
    /*     if (a[i] + c_max > v_max) */
    /*         v_max = a[i] + c_max; */

    /*     v_all += A[i]; */

    /*     if (v_all > c_max) */
    /*         c_max = v_all; */
    /* } */
    return v_max > (v_all - v_min) ? v_max : (v_all - v_min);
}
