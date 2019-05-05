bool lemonadeChange(int* bills, int billsSize)
{
    int c[3] = {0}; // 5, 10, 20

    for (int i = 0, i < billsSize; i ++)
    {
        if (bills[i] == 5)
            c[0] ++;
        else if (bills[i] == 10)
        {
            c[0] --;
            c[1] ++;
        }
        else // no need to record 20
        {
            c[0] --;
            if (c[1])
                c[1] --;
            else
                c[0] -= 2;
        }

        if (c[0] < 0 || c[1] < 0)
            return false;
    }
    return true;
}
