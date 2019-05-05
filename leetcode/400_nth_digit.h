/* be careful about the overflow of int, use long or try something never overflow */
int findNthDigit(int n)
{
    long x = n;
    long i = 9;
    int b = 1;

    long o = i * b;
    while(x > o)
    {
        x -= o;
        i *= 10;
        b ++;
        o = i * b;
    }

    x -= 1;
    int f1 = x / b;
    int f2 = b - 1 - (x % b);

    f1 += i / 9;
    while(f2 --)
        f1 /= 10;
    return f1 % 10;
}
