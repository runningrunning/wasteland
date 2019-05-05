void lra_sort(int* n, int s, int e, int* i)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = i[s];
        i[s] = i[e];
        i[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int j = s + 1; j <= e; j ++)
    {
        while (n[j] < n[s]) j ++;
        while (n[e] > n[s]) e --;

        if (j >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = i[s];
            i[s] = i[e];
            i[e] = t;
        }
        else
        {
            t = n[j];
            n[j] = n[e];
            n[e] = t;

            t = i[j];
            i[j] = i[e];
            i[e] = t;
        }
    }

    lra_sort(n, cs, e - 1, i);
    lra_sort(n, e + 1, ce, i);
}

void lra_find(int* h, int s, int e, int* id, int i, int n, int* max)
{
    if (e < s || i >= n)
        return;

    for (; i < n; i ++)
        if (id[i] >= s && id[i] <= e)
            break;

    if (i < n)
    {
        int l = e - s + 1;

        if ((*max) / l >= h[n - 1])
            return;

        int x = l * h[i];
        if (x > *max)
            *max = x;

        lra_find(h, s, id[i] - 1, id, i + 1, n, max);
        lra_find(h, id[i] + 1, e, id, i + 1, n, max);
    }
}

int largestRectangleArea(int* heights, int heightsSize)
{
    int i = 0;

    for (; i < heightsSize - 1; i ++)
        if (heights[i] > heights[i + 1])
            break;

    int max = 0;
    if (i != heightsSize - 1)
    {
        int* id = malloc(sizeof(int) * heightsSize);
        for (int i = 0; i < heightsSize; i ++)
            id[i] = i;
        lra_sort(heights, 0, heightsSize - 1, id);
        lra_find(heights, 0, heightsSize - 1, id, 0, heightsSize, &max);
    }
    else
    {
        int pre = -1;
        int last = heights[heightsSize - 1];

        for (i = 0; i < heightsSize; i ++)
        {
            int l = heightsSize - i;
            if (max / l >= last)
                break;

            if (pre == heights[i])
                continue;


            int x = heights[i] * l;
            if (x > max)
                max = x;
            pre = heights[i];
        }
    }
    return max;
}
