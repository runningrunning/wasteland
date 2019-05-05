void rsq_sort(int* x, int s, int e, int* y)
{
    if (s >= e)
        return;

    int t;

    if (x[s] < x[e] || (x[s] == x[e] && y[s] > y[e]))
    {
        t = x[s];
        x[s] = x[e];
        x[e] = t;

        t = y[s];
        y[s] = y[e];
        y[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(x[i] > x[s] || (x[i] == x[s] && y[i] < y[s])) i ++;
        while(x[e] < x[s] || (x[e] == x[s] && y[e] > y[s])) e --;

        if (i >= e)
        {
            t = x[s];
            x[s] = x[e];
            x[e] = t;

            t = y[s];
            y[s] = y[e];
            y[e] = t;
        }
        else
        {
            t = x[i];
            x[i] = x[e];
            x[e] = t;

            t = y[i];
            y[i] = y[e];
            y[e] = t;
        }
    }

    rsq_sort(x, cs, e - 1, y);
    rsq_sort(x, e + 1, ce, y);
}


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize)
{
    int x[1101] = {0};
    int y[1101] = {0};
    int z[1101] = {0};

    int r = peopleRowSize;
    *returnSize = r;

    for (int i = 0; i < r; i ++)
    {
        x[i] = people[i][0];
        y[i] = people[i][1];
    }

    rsq_sort(x, 0, r - 1, y);

    memcpy(z, y, sizeof(int) * r);

    int c = 0;
    int cp = x[c];

    for (int i = 1; i < r; i++)
    {
        int j = y[i];
        int* n = &c;
        while(j --)
            n = &y[*n];
        int t = *n;
        *n = i;
        y[i] = t;
    }

    for (int i = 0; i < r; i ++)
    {
        people[i][0] = x[c];
        people[i][1] = z[c];
        c = y[c];
    }

    return people;
}
