int countCornerRectangles(int** grid, int gridRowSize, int *gridColSizes)
{
    if (!grid || gridRowSize < 2 || gridColSizes[0] < 2)
        return 0;

    int all = 0;
    for (int i = 0; i < gridRowSize - 1; i ++)
    {
        int* t = grid[i];
        for (int j = i + 1; j < gridRowSize; j ++)
        {
            int a = 0;
            int* p = grid[j];
            for (int k = 0; k < gridColSizes[i]; k ++)
                if (t[k] && p[k])
                    a ++;

            if (a >= 2)
                all += a * (a - 1) / 2;
        }
    }
    return all;
}
