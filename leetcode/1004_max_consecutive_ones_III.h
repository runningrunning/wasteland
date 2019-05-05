// COMPLICATED, DO MORE PRACTICE
// REALLY STUPID !!
// DP again ?
// STUPID ME, NOT DP
// PEEK HINT
// Same as 340 longest substring with at mort k distinct characters
int longestOnes(int* A, int ASize, int K)
{
    int s = 0;
    int e = 0;
    int n = 0;

    /* while (n < K && e < ASize) */
    /* { */
    /*     if (!A[e ++]) */
    /*         n ++; */
    /* } */
    /* while(e < ASize && A[e]) */
    /*     e ++; */

    /* if (e == ASize) */
    /*     return ASize; */

    /* int max = e - s; */
    /* while (e < ASize) */
    /* { */
    /*     if (!A[s ++]) */
    /*         e ++; */
    /*     while(e < ASize && A[e]) */
    /*         e ++; */
    /*     max = max < (e - s) ? (e - s) : max; */
    /* } */
    for (e = 0; e < ASize; e ++)
    {
        if (!A[e])
            K --;
        if (K < 0 && !A[s ++])
            K ++;
    }
    return e - s;
}
