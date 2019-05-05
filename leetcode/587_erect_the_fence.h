// TODO how to detect clockwise or reverse clockwise
// just copy the solution from, cheating, figure out why
// http://www.algorithmist.com/index.php/Monotone_Chain_Convex_Hull.cpp
// just math !!
// simple convex hull algorithm
// same as 469. convex polygon, clockwise
// how to detect a point is inside or outside
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 * }
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comp(const void* elem1, const void* elem2)
{
    struct Point* p1 = (struct Point*) elem1;
    struct Point* p2 = (struct Point*) elem2;
    if (p1->x != p2->x)
        return p1->x - p2->x;
    return p1->y - p2->y;
}

long cross(struct Point* p1, struct Point* p2, struct Point* p3)
{
    return (p3->x - p1->x) * ((long)(p2->y - p1->y)) - (p3->y - p1->y) * ((long)(p2->x - p1->x));
}

struct Point* outerTrees(struct Point* points, int pointsSize, int* returnSize)
{
    if (pointsSize <= 3)
    {
        struct Point* r = malloc(sizeof(struct Point) * pointsSize);
        memcpy(r, points, sizeof(struct Point) * pointsSize);
        *returnSize = pointsSize;
        return r;
    }

    qsort(points, pointsSize, sizeof(struct Point), comp);
    int* up = malloc(sizeof(int) * pointsSize);
    int* down = malloc(sizeof(int) * pointsSize);



    int u = 0;
    up[u ++] = 0; up[u ++] = 1;
    int d = 0;
    down[d ++] = pointsSize - 1; down[d ++] = pointsSize - 2;

    for (int i = 2; i < pointsSize; i ++)
    {
        while (u >= 2 && cross(&points[up[u - 2]], &points[i], &points[up[u - 1]]) < 0) u --;
        up[u ++] = i;

        while (d >= 2 && cross(&points[down[d - 2]], &points[pointsSize - i - 1], &points[down[d - 1]]) < 0) d --;
        down[d ++] = pointsSize - i - 1;
    }

    int ui = 0;
    char* use = calloc(sizeof(char), pointsSize);

    struct Point* r = malloc(sizeof(struct Point) * pointsSize);
    for (int i = 0; i < pointsSize; i ++)
    {
        if (i < u && !use[up[i]])
        {
            use[up[i]] = 1;
            r[ui].x = points[up[i]].x;
            r[ui].y = points[up[i]].y;
            ui ++;
        }

        if (i < d && !use[down[i]])
        {
            use[down[i]] = 1;
            r[ui].x = points[down[i]].x;
            r[ui].y = points[down[i]].y;
            ui ++;
        }
    }

    *returnSize = ui;
    return r;
}
