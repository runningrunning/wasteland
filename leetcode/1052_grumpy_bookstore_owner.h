int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X)
{
    int not_grumpy = 0;
    int max_grumpy = 0;
    int cur_grumpy = 0;

    for (int i = 0; i < X; i ++)
    {
        max_grumpy += customers[i] * grumpy[i];
        not_grumpy += customers[i] * !grumpy[i];
    }

    cur_grumpy = max_grumpy;
    for (int i = X; i < customersSize; i ++)
    {
        cur_grumpy -= customers[i - X] * grumpy[i - X];
        cur_grumpy += customers[i] * grumpy[i];
        not_grumpy += customers[i] * !grumpy[i];
        if (cur_grumpy >= max_grumpy)
            max_grumpy = cur_grumpy;
    }
    return not_grumpy + max_grumpy;
}

