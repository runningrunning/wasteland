char* largestTimeFromDigits(int* A, int ASize)
{
    int less_2 = 0; // 1
    int less_5 = 0; // 2

    int alls = 0;
    int bits = 0;

    for (int i = 0; i < ASize; i ++)
    {
        if (A[i] <= 2)
        {
            less_2 ++;
            less_5 ++;
        }
        else if (A[i] <= 5)
        {
            less_5 ++;
        }

        bits |= 1 << A[i];
        alls += A[i];
    }

    if (less_2 < 1 || less_5 < 2)
        return strdup("");


    char* r = malloc(6);
    r[2] = ':';
    r[5] = 0;

    for (int i = 23 * 60 + 59; i >= 0; i --)
    {
        int m = i % 60;
        int h = i / 60;

        int xbits = (1 << (h % 10)) | (1 << (h / 10)) | (1 << (m % 10)) | (1 << (m / 10));
        int xalls = (h % 10) + h / 10 + m / 10 + (m % 10);

        if (xbits == bits && xalls == alls)
        {
            r[0] = (h / 10) + '0';
            r[1] = (h % 10) + '0';
            r[3] = (m / 10) + '0';
            r[4] = (m % 10) + '0';

            return r;
        }
    }
    return strdup("");
}
