// STUPID ME, TRY MORE MATH and GEOMETRY PUZZLES
// just try every rectangle ?, how to represent the 90
// how to represent 90
// math, geometry must be very familiar
double minAreaFreeRect(int** points, int pointsRowSize, int *pointsColSizes)
{
    if (pointsRowSize < 4)
        return 0;

    double cur = INT_MAX;

    // in the middle
    for (int m = 0; m < pointsRowSize; m ++)
        for (int i = 0; i < pointsRowSize; i ++)
            for (int j = i + 1; j < pointsRowSize; j ++)
            {
                if (m == i || m == j)
                    continue;

                int xim = points[i][0] - points[m][0];
                int yim = points[i][1] - points[m][1];
                int xjm = points[j][0] - points[m][0];
                int yjm = points[j][1] - points[m][1];

                if (xim * xjm + yim * yjm)
                    continue;

                for (int k = 0; k < pointsRowSize; k ++)
                {
                    if (k == m || k == i || k == j)
                        continue;

                    int xik = points[i][0] - points[k][0];
                    int yik = points[i][1] - points[k][1];
                    int xjk = points[j][0] - points[k][0];
                    int yjk = points[j][1] - points[k][1];

                    if (xik * xjk + yik * yjk)
                        continue;

                    if (xjk * xjm + yjk * yjm)
                        continue;

                    double area = sqrt((double) (xik * xik + yik * yik)) *
                        sqrt((double) (xjk * xjk + yjk * yjk));

                    if (area < cur)
                        cur = area;
                }
            }

    return cur == INT_MAX ? 0 : cur;
}
