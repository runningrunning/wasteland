/* THINK TOO MUCH */
/*
int leastBricks(int** wall, int wallRowSize, int *wallColSizes)
{
    int* s = malloc(sizeof(int) * wallRowSize);
    int* a = malloc(sizeof(int) * (wallRowSize + 1));
    memset(a, 0, sizeof(int) * (wallRowSize + 1));

    int total = 0;
    for (int i = 0; i < wallColSizes[0]; i ++)
        total += wall[0][i];

    int v_min = INT_MAX;
    int c_min = 0;

    int a_max = 0;

    while(1)
    {
        v_min = INT_MAX;
        for (int i = 0; i < wallRowSize; i ++)
        {
            int t = wall[i][a[i]];
            if (v_min > t)
            {
                c_min = 0;
                v_min = t;
                s[c_min ++] = i;
            }
            else if (v_min == t)
                s[c_min ++] = i;
        }
        if (v_min == total)
            break;

        if (c_min > a_max)
            a_max = c_min;

        if (a_max == wallRowSize)
            return 0;

        for (int i = 0; i < c_min; i ++)
        {
            int j = s[i];
            a[j] ++;
            wall[j][a[j]] += wall[j][a[j] - 1];
        }
    }
    return wallRowSize - a_max;
}
*/

void lb_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(n[i] < n[s]) i ++;
        while(n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    lb_sort(n, cs, e - 1);
    lb_sort(n, e + 1, ce);
}


void lb_sort_2(int* n, int s, int e, int* max, int r)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
    {
        if (n[s] == n[e])
        {
            if (*max < 2)
                *max = 2;
        }
        return;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(n[i] <= n[s])
        {
            if (n[i] == n[s])
            {
                t = n[s + 1];
                n[s + 1] = n[s];
                n[i] = t;
                s ++;
            }
            i ++;
        }

        while(n[e] > n[s]) e --;

        if (i >= e)
        {
            if (n[e] == n[s] && e != s)
            {
                t = n[s + 1];
                n[s + 1] = n[s];
                n[e] = t;
                s ++;
            }
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            if (n[i] == n[s])
            {
                t = n[s + 1];
                n[s + 1] = n[s];
                s ++;
                n[i] = t;
            }
        }
    }

    if (n[s + 1] == n[s])
        s ++;

    if (s - cs + 1 > *max)
        *max = s - cs + 1;

    if (*max < r)
    {
        if (*max < e - s)
            lb_sort_2(n, s + 1, e, max, r);
        if (*max < ce - e)
            lb_sort_2(n, e + 1, ce, max, r);
    }
}

int leastBricks(int** wall, int wallRowSize, int *wallColSizes)
{
    int a = 0;
    // int* s = malloc(sizeof(int) * (20000 + 2));
    int s[20002];

    for (int i = 0; i < wallRowSize; i ++)
    {
        int c = 0;
        for (int j = 0; j < wallColSizes[i] - 1; j ++)
        {
            c += wall[i][j];
            s[a ++] = c;
        }
    }
    printf("a %d.\n", a);
    int max = 0;
    lb_sort_2(s, 0, a - 1, &max, wallRowSize);
    return wallRowSize - max;
}
