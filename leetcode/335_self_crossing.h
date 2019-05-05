// not that simple !!!!, try another method which check 5 lines each time
bool isSelfCrossing(int* x, int xSize)
{
    if (xSize < 4)
        return false;

    int pdd = -1;
    int pd = -1;

    bool large = x[2] > x[0];
    for (int i = 2; i < xSize; i ++)
    {
        if (large)
        {
            if (x[i] <= x[i - 2])
            {
                large = false;
                if (x[i] < x[i - 2])
                {
                    if (pdd != -1)
                    {
                        if (x[i] >= pdd)
                            x[i - 1] = pd;
                    }
                }
                else
                    x[i - 1] = pd;
            }

            pdd = pd;
            pd = x[i] - x[i - 2];
        }
        else
        {
            if (i != 2 && x[i] >= x[i - 2])
                return true;
        }
    }

    return false;

}
