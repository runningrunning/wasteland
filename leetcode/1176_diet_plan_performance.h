int dietPlanPerformance(int* calories, int caloriesSize, int k, int lower, int upper)
{
    int c = 0;
    for (int i = 0; i < k - 1; i ++)
        c += calories[i];

    int p = 0;
    for (int i = k - 1; i < caloriesSize; i ++)
    {
        c += calories[i];
        if (c < lower)
            p --;
        else if (c > upper)
            p ++;
        c -= calories[i + 1 - k];
    }
    return p;
}

