int maxCount(int m, int n, int** ops, int opsRowSize, int opsColSize)
{
    int x = m;
    int y = n;

    for (int i = 0; i < opsRowSize; i++)
    {
        if (x > ops[i][0])
            x = ops[i][0];
        if (y > ops[i][1])
            y = ops[i][1];
    }
    return x * y;
}
