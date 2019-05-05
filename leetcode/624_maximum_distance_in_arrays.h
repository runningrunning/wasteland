int maxDistance(int** arrays, int arraysRowSize, int *arraysColSizes)
{
    int min1_r, min2_r;
    int max1_r, max2_r;

    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for (int i = 0; i < arraysRowSize; i ++)
    {
        int l = arraysColSizes[i];
        if (l)
        {
            int mi = arrays[i][0];
            int ma = arrays[i][l - 1];

            if (mi < min1)
            {
                min2 = min1;
                min2_r = min1_r;
                min1 = mi;
                min1_r = i;
            } else if (mi < min2)
            {
                min2 = mi;
                min2_r = i;
            }

            if (ma > max1)
            {
                max2 = max1;
                max2_r = max1_r;
                max1 = ma;
                max1_r = i;
            } else if (ma > max2)
            {
                max2 = ma;
                max2_r = i;
            }

        }
    }

    if (min1_r != max1_r)
        return max1 - min1;

    int d1 = max2 - min1;
    int d2 = max1 - min2;

    return d1 > d2 ? d1 : d2;
}
