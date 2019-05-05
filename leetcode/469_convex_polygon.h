// left /  right ?
// math, how to check it's on left or right, point on the right or on the left ?
// it's wrong to check it's right or left

// https://math.stackexchange.com/questions/274712/calculate-on-which-side-of-a-straight-line-is-a-given-point-located

/* To determine which side of the line from A=(x1,y1) */
/* to B=(x2,y2) a point P=(x,y) falls on you need to compute the value:- */
/* d=(x−x1)(y2−y1)−(y−y1)(x2−x1) */
/* If d<0 then the point lies on one side of the line, and if d>0 then it lies on the other side. If d=0 */
/* then the point lies exactly line. */
/* To see whether points on the left side of the line are those with positive or negative values compute the value for d */
/* for a point you know is to the left of the line, such as (x1−1,y1) and then compare the sign with the point you are interested in. */

bool isConvex(int** points, int pointsRowSize, int *pointsColSizes)
{
    int x1 = points[0][0];
    int y1 = points[0][1];

    int x2 = points[1][0];
    int y2 = points[1][1];

    int x, y;

    int i = 0;
    int d = 0;

    bool up_or_down;

    for (i = 2; i < pointsRowSize; i ++)
    {
        x = points[i][0];
        y = points[i][1];

        d = (x - x1)*(y2 - y1) - (y - y1)*(x2 - x1);

        if (d)
        {
            up_or_down = d > 0;
            break;
        }

        x1 = x2;
        y1 = y2;
        x2 = x;
        y2 = y;
    }

    if (i == pointsRowSize)
        return false;

    x1 = points[i - 2][0];
    y1 = points[i - 2][1];

    x2 = points[i - 1][0];
    y2 = points[i - 1][1];

    for (;i <= pointsRowSize + 1; i ++)
    {
        if (i < pointsRowSize)
        {
            x = points[i][0];
            y = points[i][1];
        }
        else if (i == pointsRowSize)
        {
            x = points[0][0];
            y = points[0][1];
        }
        else
        {
            x = points[1][0];
            y = points[1][1];
        }

        bool new;

        int newd = (x - x1)*(y2 - y1) - (y - y1)*(x2 - x1);

        if (newd)
        {
            new = newd > 0;
            if (new != up_or_down)
                return false;
        }

        x1 = x2;
        y1 = y2;
        x2 = x;
        y2 = y;
    }

    return true;
}
