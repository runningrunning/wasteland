int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize)
{
    int n = 0;
    int pairs[100] = {0};
    for (int i = 0; i < dominoesSize; i ++)
    {
        int a = dominoes[i][0];
        int b = dominoes[i][1];
        int x = a < b ? (a * 10 + b) : (b * 10 + a);
        n += pairs[x];
        pairs[x] ++;
    }
    return n;
}

