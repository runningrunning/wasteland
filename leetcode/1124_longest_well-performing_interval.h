int longestWPI(int* hours, int hoursSize)
{
    int top = -1;
    int cval = 0;
    int cmax = 0;
    int max = 0;

    for (int i = 0; i < hoursSize; i ++)
    {
        if (hours[i] > 8)
        {
            if (cval < 0)
            {
                hours[++ top] = cval;
                cval = 0;
                cmax = 0;
            }

            cmax ++;
            cval ++;

            while (top >= 0)
            {
                int x = hours[top];

                if (x > 0)
                    cmax += x;
                else
                {
                    x = -x;
                    if (cval <= x)
                    {
                        printf("%d %d %d.\n", cmax, cval, max);
                        if (cmax + cval - 1 > max)
                            max = cmax + cval - 1;
                        break;
                    }
                    cval -= x;
                    cmax += x;
                }
                top --;
            }
        }
        else
        {
            if (cval == 1 && cmax > 0)
            {
                if (cmax > max)
                    max = cmax;

                cmax ++;
                hours[++ top] = cmax;
                cmax = 0;
            }
            else
                cmax ++;

            cval --;
        }
        out(hours, top + 1);
        printf("%d %d.\n", cmax, cval);
    }
    return max;
}
