int rangeBitwiseAnd(int m, int n) {
    int b = m & n;
    if (n - m <= 1 || !b)
        return b;
    if (n - m >= m)
        return 0;

    int d = n - m;
    int i = 1;
    while(i < d)
        i <<= 1;
    return b & ~(i - 1);
}
