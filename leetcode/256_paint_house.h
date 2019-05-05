int minCost(int** costs, int costsRowSize, int costsColSize)
{
    if (!costs || !costsRowSize)
        return 0;

    int last = costsRowSize - 1;

    if (costsRowSize >= 1)
    {
        for (int i = 1; i < costsRowSize; i ++)
        {
            int p0 = costs[i - 1][0];
            int p1 = costs[i - 1][1];
            int p2 = costs[i - 1][2];

            costs[i][0] += p1 > p2 ? p2 : p1;
            costs[i][1] += p0 > p2 ? p2 : p0;
            costs[i][2] += p0 > p1 ? p1 : p0;
        }
    }

    int min = costs[last][0];
    if (min > costs[last][1])
        min = costs[last][1];
    if (min > costs[last][2])
        min = costs[last][2];
    return min;
}
