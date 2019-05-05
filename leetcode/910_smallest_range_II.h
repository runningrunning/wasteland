// TODO MUST FIGURE IT WHY !!!
// CHEATING READING THE ANSWER !!
// STUPID WRONG ALGORITHM !!
// just setup the correct model !!
// THINK TOO MUCH !!!!,simple is faster !
// why it works !
// how to calculate this ?
// try all the possible ways ???
// how to prove it works ?
// it's simple !!!
int comp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

int smallestRangeII(int* A, int ASize, int K)
{
    if (!A || ASize < 2)
        return 0;

    qsort(A, ASize, sizeof(int), comp);

    int _min = A[ASize - 1] - A[0];

    if (_min <= K || !K)
        return _min;

    int _low = A[0] + K;
    int _high = A[ASize - 1] - K;

    for (int i = 0; i < ASize - 1; i ++)
    {
        int a = A[i] + K;
        int b = A[i + 1] - K;

        int high = _high > a ? _high : a;
        int low = _low < b ? _low : b;

        _min = _min < (high - low) ? _min : (high - low);
    }
    return _min;
}
