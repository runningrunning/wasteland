// TODO try to learn how GREEDY works !!!
// stupid wrong algorithms !!!!!!, use GREEDY !!
// not only greedy, but also heap !!! min heap + GREEDY !!!!
// STILL WRONG !!!
// sort by start add it into min heap by end, then merge it as much as possible !!
// not same with 435 non-overlapping_intervals and 452 minimum number of arrows to burst balloons.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */

void mr_sort(int* n, int s, int e, int* id)
{
    if (s > e)
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

    mr_sort(n, cs, e - 1, id);
    mr_sort(n, e + 1, ce, id);
}

void rHeap(int* h, int hi)
{
    int x = 0;
    int p = h[0];

    while (x * 2 + 1 < hi)
    {
        int l = h[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < hi)
            r = h[x * 2 + 2];

        if (l <= r)
        {
            if (p <= l)
                break;
            h[x] = l;
            h[x * 2 + 1] = p;
            x = x * 2 + 1;
        }
        else
        {
            if (p <= r)
                break;
            h[x] = r;
            h[x * 2 + 2] = p;
            x = x * 2 + 2;
        }
    }
}

void aHeap(int* h, int hi, int v)
{
    h[hi ++] = v;

    int x = hi - 1;
    while (x)
    {
        int p = (x - 1) / 2;

        if (h[p] <= h[x])
            break;

        h[x] = h[p];
        h[p] = v;
        x = p;
    }
}

int minMeetingRooms(struct Interval* intervals, int intervalsSize)
{
    if (!intervalsSize)
        return 0;

    int* id = malloc(sizeof(int) * intervalsSize);
    int* sd = malloc(sizeof(int) * intervalsSize);

    bool sort = false;

    for (int i = 0; i < intervalsSize; i ++)
    {
        id[i] = i;
        sd[i] = intervals[i].start;

        if (i && !sort)
            if (sd[i] < sd[i - 1])
                sort = true;
    }

    if (sort)
        mr_sort(sd, 0, intervalsSize - 1, id);

    int hi = 0;
    int* heap = malloc(sizeof(int) * intervalsSize);

    int n = 1;
    heap[hi ++] = intervals[id[0]].end;

    for (int i = 1; i < intervalsSize; i ++)
    {
        int x = id[i];
        int s = intervals[x].start;
        int e = intervals[x].end;

        if (s < heap[0])
        {
            aHeap(heap, hi, e);
            hi ++;
        }
        else
        {
            heap[0] = e;
            rHeap(heap, hi);
        }
    }
    return hi;
}


/* /\* MIN HEAP *\/ */
/* void mmr_sort(struct Interval* in, int s, int e) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     struct Interval t; */
/*     if (in[s].start > in[e].start) */
/*     { */
/*         t = in[s]; */
/*         in[s] = in[e]; */
/*         in[e] = t; */
/*     } */

/*     if (s + 1 == e) */
/*         return; */

/*     int cs = s; */
/*     int ce = e; */

/*     for (int i = s + 1; i <= e; i ++) */
/*     { */
/*         while(in[i].start < in[s].start) i ++; */
/*         while(in[e].start > in[s].start) e --; */

/*         if (i >= e) */
/*         { */
/*             t = in[s]; */
/*             in[s] = in[e]; */
/*             in[e] = t; */
/*         } */
/*         else */
/*         { */
/*             t = in[i]; */
/*             in[i] = in[e]; */
/*             in[e] = t; */
/*         } */
/*     } */

/*     mmr_sort(in, cs, e - 1); */
/*     mmr_sort(in, e + 1, ce); */
/* } */

/* /\** */
/*  * Definition for an interval. */
/*  * struct Interval { */
/*  *     int start; */
/*  *     int end; */
/*  * }; */
/*  *\/ */
/* int minMeetingRooms(struct Interval* intervals, int intervalsSize) */
/* { */
/*     if (!intervals || !intervalsSize) */
/*         return 0; */

/*     if (intervalsSize < 2) */
/*         return 1; */

/*     mmr_sort(intervals, intervalsSize); */

/*     int min = 1; */

/*     int si = 0; */
/*     int* stack = malloc(sizeof(int) * intervalsSize); */

/*     stack[si ++] = 0; */
/*     for(int i = 1; i < intervalsSize;) */
/*     { */
/*         if (intervals[i].start <) */
/*     } */

/* } */

