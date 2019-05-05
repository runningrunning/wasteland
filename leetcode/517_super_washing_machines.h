// NOT dp, just math
// simple ???
// {0, 3, 0} is 2, not 1
int findMinMoves(int* machines, int machinesSize)
{
    int all = 0;
    for (int i = 0; i < machinesSize; i ++)
        all +=  machines[i];

    if (all % machinesSize)
        return -1;

    int need = all / machinesSize;

    long in = machines[0] - need;
    long step = abs(in);
    for (int i = 1; i < machinesSize; i ++)
    {
        long pin = in;
        long m = machines[i] + pin;
        in = m - need;

        if (pin < 0 && in > 0)
        {
            if (abs(in) + abs(pin) > step)
                step = abs(in) + abs(pin);
        }
        else if (abs(in) > step)
            step = abs(in);
    }
    return step;
}
