int superPow(int a, int* b, int bSize)
{
    int p = 1;
    int y = a % 1337;

    for (int i = bSize - 1; i >= 0; i --)
    {
        int py = y;
        y = 1;

        for (int j = 0; j < b[i]; j ++)
        {
            y *= py;
            y %= 1337;
        }

        p *= y;
        p %= 1337;

        for (int j = b[i]; j < 10; j ++)
        {
            y *= py;
            y %= 1337;
        }
    }
    return p;
}
