/* TODO Better solutions ? */
void nb_sort(int* n, int s, int e)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;
        }
    }

    nb_sort(n, cs, e - 1);
    nb_sort(n, e + 1, ce);
}

int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize)
{
    if (pointsRowSize < 3)
        return 0;
    int all = 0;

    int* t = malloc(sizeof(int) * (pointsRowSize + 1));
    int* vs = malloc(sizeof(int) * pointsRowSize * pointsRowSize);

    t[pointsRowSize] = -1;
    for (int i = 0; i < pointsRowSize; i ++)
    {
        if (i)
        {
            int* tmp = points[i];
            points[i] = points[0];
            points[0] = tmp;
        }

        int x1 = points[0][0];
        int y1 = points[0][1];

        for (int j = 1; j < pointsRowSize; j ++)
        {
            if (j <= i)
                t[j] = vs[j * pointsRowSize + i];
            else
            {
                t[j] = (x1 - points[j][0]) * (x1 - points[j][0])
                    + (y1 - points[j][1]) * (y1 - points[j][1]);
                vs[i * pointsRowSize + j] = t[j];
            }
        }

        t[i] = vs[i];

        if (i)
        {
            int* tmp = points[i];
            points[i] = points[0];
            points[0] = tmp;
        }

        nb_sort(t, 1, pointsRowSize - 1);
        int cur = 0;
        int pre = t[1];

        for (int j = 1; j < pointsRowSize + 1; j ++)
        {
            if (pre != t[j])
            {
                pre = t[j];
                all += cur * (cur - 1);
                cur = 0;
            }
            cur ++;
        }
    }
    return all;
}
