bool isBoomerang(int** points, int pointsSize, int* pointsColSize)
{
    if (!points || !pointsSize)
        return false;

    int dx01 = points[0][0] - points[1][0];
    int dy01 = points[0][1] - points[1][1];

    if (!dx01 && !dy01)
        return false;

    int dx02 = points[0][0] - points[2][0];
    int dy02 = points[0][1] - points[2][1];

    if (!dx02 && !dy02)
        return false;

    return dx02 * dy01 != dx01 * dy02;
}
