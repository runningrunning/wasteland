// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int isB(int a, int b)
{
    if (a >= b)
        return a;
    int t = a + ((b - a) >> 1);
    if (isBadVersion(t))
        return isB(a, t);
    return isB(t + 1, b);
}

int firstBadVersion(int n) {
    if (isBadVersion(1))
        return 1;
    if (!isBadVersion(n))
        return 0;

    return isB(2, n);
}
