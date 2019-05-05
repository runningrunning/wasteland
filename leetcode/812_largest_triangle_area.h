// pure mathematics 2 points in line
// TODO know how to calculate the pon
double largestTriangleArea(int** points, int pointsRowSize, int *pointsColSizes)
{
    double max = 0.0;

    for (int i = 0; i < pointsRowSize - 2; i ++)
        for (int j = i + 1; j < pointsRowSize - 1; j ++)
        {
            double l1 = points[j][0] - points[i][0];
            double l2 = points[j][1] - points[i][1];
            double l = sqrt(l1 * l1 + l2 * l2);
            double d = points[i][0] * points[j][1] - points[i][1] * points[j][0];
            for (int k = j + 1; k < pointsRowSize; k ++)
            {
                double l3 = abs(points[k][0] * l2 - points[k][1] * l1 - d);
                /* l3 /= l; */
                /* printf("i %d %d j %d %d k %d %d %lf %lf.\n", points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1], l3, l); */

                if (max < l3 / 2)
                    max = l3 / 2;
            }
        }
    return max;
}
