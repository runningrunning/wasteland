// math !!
// recursion
// it equal X(n - 1) * (n - 1) + (n - 1) * X(n - 2)
// eg. 3 is 312 231
// 4 is 312 and 231 replace one with 4 +
// 132 and 321 and 213 replace 1, 2, 3 with 4 !!
int findDerangement(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    long p2 = 0;
    long p1 = 1;

    for (long i = 3; i <= n; i ++)
    {
        long p = ((i - 1) * (p2 + p1)) % 1000000007;
        p2 = p1;
        p1 = p;
    }
    return p1;
    // return findDerangement(n - 1) * (n - 1) + (n - 1) * findDerangement(n - 2);
}
