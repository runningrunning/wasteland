/* sqrt means how many numbers will have odd dividor, and only odd dividor number will on */
int bulbSwitch(int n)
{
    return sqrt(n);
    /*
    int all = 0;

    for (int i = 1; i <= n; i ++)
    {
        int a = 0;
        int x = sqrt(i);
        a = x * x == i ? 1 : 2;

        for (int j = a - 1; j > 0; j --)
        {
            if (!(i % j))
                a += 2;
        }
        if (a & 1)
            all ++;
    }
    return all;
    */
}
