int numPairsDivisibleBy60(int* time, int timeSize)
{
    int ts[60] = {0};
    for (int i = 0; i < timeSize; i ++)
        ts[time[i] % 60] ++;

    int num = 0;
    for (int i = 1; i < 30; i ++)
        num += ts[i] * ts[60 - i];

    num += ts[0] * (ts[0] - 1) / 2;
    num += ts[30] * (ts[30] - 1) / 2;
    return num;
}
