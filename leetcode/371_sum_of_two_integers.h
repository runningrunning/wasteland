int getSum(int a, int b)
{
    while(a)
    {
        int x = a ^ b;
        a = (a & b) << 1;
        b = x;
    }
    return b;
}
