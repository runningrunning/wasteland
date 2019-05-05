bool validMountainArray(int* A, int ASize)
{
    if (ASize < 3 || A[0] >= A[1] || A[ASize - 1] >= A[ASize - 2])
        return false;

    int s = 1;
    while (A[s] > A[s - 1])
        s ++;
    int e = ASize - 1;
    while (A[e] < A[e - 1])
        e --;
    return s - 1 == e;
}
