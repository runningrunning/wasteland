int maxDistToClosest(int* seats, int seatsSize)
{
    int f1 = -1;
    int l1 = -1;
    int m0 = 0;

    for (int i = 0; i < seatsSize; i ++)
    {
        if (seats[i])
        {
            if (f1 < 0)
                l1 = f1 = i;
            else
            {
                if (m0 < i - l1)
                    m0 = i - l1;
                l1 = i;
            }
        }
    }

    int m = m0 / 2;

    if (m < f1)
        m = f1;
    if (m < seatsSize - 1 - l1)
        m = seatsSize - 1 - l1;
    return m;
}
