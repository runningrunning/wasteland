int partitionDisjoint(int* A, int ASize)
{
    int* b = malloc(sizeof(int) * ASize);

    int _min = A[ASize - 1];
    b[ASize - 1] = _min;
    for (int i = ASize - 1; i >= 0; i --)
    {
        b[i] = _min;

        if (A[i] < _min)
            _min = A[i];
    }

    int _max = A[0];
    for (int i = 0; i < ASize; i ++)
    {
        if (A[i] > _max)
            _max = A[i];

        if (_max <= b[i])
            return i + 1;
    }
    return 0;
}
