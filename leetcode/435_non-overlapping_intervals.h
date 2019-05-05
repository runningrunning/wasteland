// GREEDY !!! simple GREEDY !!, the minimum will be in the last
// same with 452 minimum number of arrows to burst balloons
// find better solution by using greedy !!!!!!!!!!!!!!!!!!!!!!!!!!!
// just simple DP !!!!!!
// sort then done
// find another solutions !!!!!!
// same with 845 K-similar strings ????
// find the best divide !!

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */

void eoli_sort(int* n, int s, int e, int* id)
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

    eoli_sort(n, cs, e - 1, id);
    eoli_sort(n, e + 1, ce, id);
}

int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize)
{
    if (!intervalsSize)
        return 0;
    int* id = malloc(sizeof(int) * intervalsSize);
    int* ed = malloc(sizeof(int) * intervalsSize);

    bool sort = false;

    for (int i = 0; i < intervalsSize; i ++)
    {
        id[i] = i;
        ed[i] = intervals[i].end;
        if (i && !sort)
            if (ed[i] < ed[i - 1])
                sort = true;
    }

    if (sort)
        eoli_sort(ed, 0, intervalsSize - 1, id);

    int x = 1;
    int e = intervals[id[0]].end;
    for (int i = 1; i < intervalsSize; i ++)
        if (intervals[id[i]].start >= e)
        {
            x ++;
            e = intervals[id[i]].end;
        }
    return intervalsSize - x;
}

/* DP version
int _eoli(struct Interval* v, int* id, int c, int e, int num, int pre, int* mem, int* max)
{
    if (c > e)
    {
        if (num > *max)
            *max = num;
        return 0;
    }

    if (*max > num + e - c + 1)
        return 0;

    int m = 0;
    int x = id[c];

    if (num == 0 || pre <= v[x].start)
    {
        if (!mem[c])
            mem[c] = _eoli(v, id, c + 1, e, num + 1, v[x].end, mem, max) + 1;

        if (num + mem[c] > *max)
            *max = num + mem[c];
        m = mem[c];
    }
    if (m >= e - c)
        return m;

    int y = _eoli(v, id, c + 1, e, num, pre, mem, max);
    return m > y ? m : y;
}

void eoli_sort(int* n, int s, int e, struct Interval* v)
{
    if (s >= e)
        return;

    int t;
    if (v[n[s]].start > v[n[e]].start ||
        (v[n[s]].start == v[n[e]].start && v[n[s]].end > v[n[e]].end))
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
        while (v[n[i]].start < v[n[s]].start || (v[n[i]].start == v[n[s]].start && v[n[i]].end < v[n[s]].end)) i ++;
        while (v[n[e]].start > v[n[s]].start || (v[n[e]].start == v[n[s]].start && v[n[e]].end > v[n[s]].end)) e --;

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

    eoli_sort(n, cs, e - 1, v);
    eoli_sort(n, e + 1, ce, v);
}

int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize)
{
    int* id = malloc(sizeof(int) * intervalsSize);
    bool sort = false;

    for (int i = 0; i < intervalsSize; i ++)
    {
        id[i] = i;

        if (i && !sort)
        {
            if (intervals[i].start < intervals[i - 1].start ||
                ((intervals[i].start == intervals[i - 1].start) &&
                 (intervals[i].end < intervals[i - 1].end)))
                sort = true;
        }

    }

    if (sort)
        eoli_sort(id, 0, intervalsSize - 1, intervals);

    int max = 0;
    int* m = calloc(sizeof(int), intervalsSize);
    _eoli(intervals, id, 0, intervalsSize - 1, 0, 0, m, &max);
    return intervalsSize - max;
}
*/
/*
void _eoli(int** r, int* rc, int* rs, int x, int ri, char* f, int h, int* max)
{
    if (x == ri)
    {
        if (h > *max)
            *max = h;
        return;
    }

    if (*max > h + (ri - x))
        return;

    int c = rs[x];
    bool found = false;

    for (int i = 0; i < rc[c]; i ++)
        if (f[r[c][i]])
        {
            found = true;
            break;
        }

    if (found)
       _eoli(r, rc, rs, x + 1, ri, f, h, max);
    else
    {
        f[c] = 1;
        _eoli(r, rc, rs, x + 1, ri, f, h + 1, max);
        f[c] = 0;
        _eoli(r, rc, rs, x + 1, ri, f, h, max);
    }
}

int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize)
{
    if (!intervals || intervalsSize < 2)
        return 0;

    int ri = 0;
    int* rs = malloc(sizeof(int) * intervalsSize);
    int** r = calloc(sizeof(int*), intervalsSize);
    int* rc = calloc(sizeof(int), intervalsSize);

    for (int i = 0; i < intervalsSize; i ++)
    {
        int s = intervals[i].start;
        int e = intervals[i].end;

        for (int j = i + 1; j < intervalsSize; j ++)
        {
            int js = intervals[j].start;
            int je = intervals[j].end;

            if (!(e <= js || s >= je))
            {
                rc[i] ++;
                rc[j] ++;
                r[i] = realloc(r[i], sizeof(int) * rc[i]);
                r[j] = realloc(r[j], sizeof(int) * rc[j]);
                r[i][rc[i] - 1] = j;
                r[j][rc[j] - 1] = i;
            }
        }

        if (rc[i])
            rs[ri ++] = i;
    }

    int max = 0;
    char* f = calloc(sizeof(char), intervalsSize);
    _eoli(r, rc, rs, 0, ri, f, 0, &max);
    return ri - max;
}
*/

/*
int eraseOverlapIntervals(struct Interval* intervals, int intervalsSize)
{
    if (!intervals || intervalsSize < 2)
        return 0;

    int** r = calloc(sizeof(int*), intervalsSize);
    int* rc = calloc(sizeof(int), intervalsSize);
    int* rbc = calloc(sizeof(int), intervalsSize);

    int dup = 0;

    int ri = 0;
    int rm = 0;
    int rmi = 0;

    for (int i = 0; i < intervalsSize; i ++)
    {
        int s = intervals[i].start;
        int e = intervals[i].end;
        bool is_dup = false;
        for (int j = i + 1; j < intervalsSize; j ++)
        {
            int js = intervals[j].start;
            int je = intervals[j].end;

            if (s == js && e == je)
            {
                dup ++;
                is_dup = true;
                break;
            }
        }

        if (!is_dup)
        {
            for (int j = i + 1; j < intervalsSize; j ++)
            {
                int js = intervals[j].start;
                int je = intervals[j].end;

                if (!(e <= js || s >= je))
                {
                    rc[i] ++;
                    rc[j] ++;
                    r[i] = realloc(r[i], sizeof(int) * rc[i]);
                    r[j] = realloc(r[j], sizeof(int) * rc[j]);
                    r[i][rc[i] - 1] = j;
                    r[j][rc[j] - 1] = i;

                    if (rc[i] >= rc[j])
                    {
                        if (rm < rc[i])
                        {
                            rm = rc[i];
                            rmi = i;
                        }
                    }
                    else
                    {
                        if (rm < rc[j])
                        {
                            rm = rc[j];
                            rmi = j;
                        }
                    }
                }
            }

            if (rc[i])
                ri ++;
            rbc[i] = rc[i];
        }

    }

    out(rc, intervalsSize);
    out(rbc, intervalsSize);
    printf("ri %d %d %d.\n", ri, rm, rmi);

    int re = dup;
    while (ri)
    {
        ri --;
        re ++;

        for (int j = 0; j < rbc[rmi]; j ++)
        {
            rc[r[rmi][j]] --;
        }

        rc[rmi] = 0;

        printf("remove rmi %d.\n", rmi);
        out(rc, intervalsSize);

        rm = 0;
        for (int j = 0; j < intervalsSize; j ++)
        {
            if (rc[j] > rm)
            {
                rm = rc[j];
                rmi = j;
            }
        }
        if (rm == 0)
            return re;
    }

    return re;
}
*/
