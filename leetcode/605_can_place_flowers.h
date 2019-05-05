bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
    if (!n)
        return true;

    if (!flowerbed || !flowerbedSize || (flowerbedSize + 1) < 2 * n)
        return false;

    // 1
    if (flowerbedSize == 1)
        return !flowerbed[0];

    if (!flowerbed[0] && !flowerbed[1])
    {
        flowerbed[0] = 1;
        n --;
    }

    if (!flowerbed[flowerbedSize - 1] && !flowerbed[flowerbedSize - 2])
    {
        flowerbed[flowerbedSize - 1] = 1;
        n --;
    }

    if (n <= 0)
        return true;

    int x = flowerbed[0] + flowerbed[1];
    for (int i = 1; i < flowerbedSize - 1; i ++)
    {
        x += flowerbed[i + 1];
        if (!x)
        {
            n --;
            x += 1;
            flowerbed[i] = 1;
        }
        x -= flowerbed[i - 1];
    }
    return n <= 0;
}
