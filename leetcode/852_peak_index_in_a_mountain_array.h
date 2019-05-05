int _pima(int* a, int s, int e)
{
    while (s < e)
    {
        if (s + 1 == e)
            return a[s] > a[e] ? s : e;
        int m = (s + e) / 2;

        if (a[m - 1] > a[m])
            e = m - 1;
        else
            s = m;
    }
    return s;
}

int peakIndexInMountainArray(int* A, int ASize)
{
    return _pima(A, 0, ASize - 1);
}
