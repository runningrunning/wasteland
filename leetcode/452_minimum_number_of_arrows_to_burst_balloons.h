// HOW TO PROVE GREEDY IS CORRECT !!!!!
// greedy, but how to know it works or how to prove it's correct ???
// same with 435 non-overlapping intervals
void fmas_sort(int* n, int s, int e, int* id)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = id[s];
        id[s] = id[e];
        id[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = id[s];
            id[s] = id[e];
            id[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = id[i];
            id[i] = id[e];
            id[e] = t;
        }
    }

    fmas_sort(n, cs, e - 1, id);
    fmas_sort(n, e + 1, ce, id);
}

int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize)
{
    if (!pointsRowSize)
        return 0;

    int* id = malloc(sizeof(int) * pointsRowSize);
    int* ed = malloc(sizeof(int) * pointsRowSize);

    bool sort = false;
    for (int i = 0; i < pointsRowSize; i ++)
    {
        id[i] = i;
        ed[i] = points[i][1];

        if (i && !sort)
            if (ed[i] < ed[i - 1])
                sort = true;
    }

    if (sort)
        fmas_sort(ed, 0, pointsRowSize - 1, id);


    int n = 1;
    int e = points[id[0]][1];
    for (int i = 1; i < pointsRowSize; i ++)
    {
        int x = id[i];

        if (points[x][0] > e)
        {
            n ++;
            e = points[x][1];
        }
    }
    return n;
}
