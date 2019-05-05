int newInteger(int n)
{
    int x = 0;
    int b = 1;
    while(n)
    {
        x = (n % 9) * b;
        b *= 10;
        n /= 9;
    }
    return x;
}
