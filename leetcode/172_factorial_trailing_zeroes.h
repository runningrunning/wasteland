int trailingZeroes(int n) {
    int num = 0;
    while(n)
    {
        num += n / 5;
        n /= 5;
    }
    return num;
}
