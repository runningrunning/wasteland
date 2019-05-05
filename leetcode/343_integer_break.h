int integerBreak(int n) {
    if (!n)
        return n;

    if (n <= 3)
        return n - 1;

    int last = n % 3;
    if (last == 1)
        last = 4;
    int x = (n - last) / 3;

    int r = 1;
    while(x --)
        r *= 3;
    return last ? r * last : r;
}
