int smallestRangeI(int* A, int ASize, int K)
{
    if (!A || ASize < 2)
        return 0;

    int _min = A[0];
    int _max = A[1];

    if (A[0] >= A[1])
    {
        _max = A[0];
        _min = A[1];
    }

    for (int i = 2; i < ASize; i ++)
    {
        if (A[i] < _min)
            _min = A[i];
        else if (A[i] > _max)
            _max = A[i];
    }

    if (_min + K >= _max - K)
        return 0;
    return _max - _min - K * 2;
}
