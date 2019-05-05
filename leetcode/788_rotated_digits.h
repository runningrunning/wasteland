// TODO find better solution !!!
bool is_good(int x)
{
    int gf = (1 << 2) | (1 << 5) | (1 << 6) | (1 << 9);
    int bf = (1 << 3) | (1 << 4) | (1 << 7);

    int g = 0;

    while (x)
    {
        int y = x % 10;
        if (bf & (1 << y))
            return false;
        g |= ((1 << y) & gf);
        x /= 10;
    }

    return g != ;0
}

/*
int rotatedDigits(int N)
{
    // in each digits, bl are digits can not use only
    // ul are digits can only used
    //            0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    int bl[10] = {1, 2, 2, 2, 2, 2, 2, 2, 3, 3};
    int ul[10] = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7};

    int a = 1;
    int n = 1;
    while (N)
    {
        int y = N % 10;
        a *= ul[y];
        n *= bl[y];
        N /= 10;
    }
    return a - n;
}
*/

int rotatedDigits(int N)
{

    int all = 0;
    for (int i = 1; i <= N; i ++)
        if (is_good(i))
            all ++;
    return all;
}
