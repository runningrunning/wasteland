int minCostClimbingStairs(int* cost, int costSize)
{
    if (!cost || costSize < 2)
        return (cost && costSize) ? cost[0] : 0;

    /* for (int i = 2; i < costSize; i ++) */
    /*     cost[i] += cost[i - 1] < cost[i - 2] ? cost[i - 1] : cost[i - 2]; */
    /* return cost[costSize - 1] < cost[costSize - 2] ? cost[costSize - 1] : cost[costSize - 2]; */

    int cp = cost[1];
    int cpp = cost[0];

    int min_p;
    for (int i = 2; i < costSize; i ++)
    {
        min_p = cpp < cp ? cpp : cp;
        cpp = cp;
        cp = cost[i] + min_p;
    }
    return cpp < cp ? cpp : cp;
}
