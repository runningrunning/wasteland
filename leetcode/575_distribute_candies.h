
int distributeCandies(int* candies, int candiesSize)
{
    int fg[6400] = {0};

    int num = 0;

    int x, y;
    for (int i = 0; i < candiesSize; i ++)
    {
        int z = candies[i] + 100000;
        x = z / 32;
        y = z % 32;
        if (!(fg[x] & (1 << y)))
        {
            fg[x] |= (1 << y);
            num ++;
        }
    }
    int h = candiesSize >> 1;
    return num > h ? h : num;
}
