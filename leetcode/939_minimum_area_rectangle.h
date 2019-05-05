// how to optimize the code, make it simple
int comp(const void* e1, const void* e2)
{
    int* n1 = *((int**)e1);
    int* n2 = *((int**)e2);

    if (n1[0] != n2[0])
        return n1[0] - n2[0];
    return n1[1] - n2[1];
}

int minAreaRect(int** points, int pointsRowSize, int *pointsColSizes)
{
    if (pointsRowSize < 4)
        return 0;

    qsort(points, pointsRowSize, sizeof(int*), comp);
    int ri = 0;
    // could be double here !!, so it's pointsRowSize * 2
    int* range = malloc(sizeof(int) * pointsRowSize * 2);

    int pre = -1;
    for (int i = 0; i < pointsRowSize; i ++)
        if (points[i][0] != pre)
        {
            if (i)
                range[ri ++] = i - 1;
            range[ri ++] = i;
            pre = points[i][0];
        }

    int m = INT_MAX;

    range[ri ++] = pointsRowSize - 1;

    /* out(range, ri); */
    /* for (int i = 0; i < pointsRowSize; i ++) */
    /*     printf("(%d : %d) ", points[i][0], points[i][1]); */

    for (int i = 0; i < ri; i += 2)
    {
        int s1_s = range[i];
        int s1_e = range[i + 1];

        if (s1_s == s1_e)
            continue;

        for (int j = i + 2; j < ri; j += 2)
        {
            int o_s = s1_s;
            int o_e = s1_e;

            int s2_s = range[j];
            int s2_e = range[j + 1];

            if (s2_s == s2_e)
                continue;

            int dx = points[s2_s][0] - points[o_s][0];

            if (dx > m)
                break;

            int y = -1;

            while (o_s <= o_e && s2_s <= s2_e)
            {
                if (points[o_s][1] == points[s2_s][1])
                {
                    if (y == -1)
                        y = points[o_s][1];
                    else
                    {
                        if (m > dx * (points[o_s][1] - y))
                            m = dx * (points[o_s][1] - y);
                        y = points[o_s][1];
                    }
                    o_s ++;
                    s2_s ++;
                }
                else if (points[o_s][1] > points[s2_s][1])
                    s2_s ++;
                else
                    o_s ++;
            }
        }
    }
    return m == INT_MAX ? 0 : m;
}
