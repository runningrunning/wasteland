// the solution is very simple and correct compare with start from the end !!!!
// the idea is to find each step K with the lowest end time
// just add up from start to end sorted by the end time and then remove the current largest if current end time is larger then next

// the last inserted will at most have the largest length, so only one will be removed and add new one

// MY STUPID !!!!!!!!!!!!!!!
// TODO GREED + HEAP STUPID WRONG ALGORITHM
// how to make sure greedy is correct ?
// not a simple greedy !
// ? wrong (5, 5, 4, 6, 2, 6)
// reverse GREEDY !!!
// from the end to the start ??? the latest end is always needed !!! it's not TRUE!!
// E.g. 9, 14, 7, 12, 1, 11, 4, 7
// peak solution ?
// totally wrong solution !!!

void sc_sort(long* n, int s, int e)
{
    if (s >= e)
        return;

    long t;

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
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

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
    sc_sort(n, cs, e - 1);
    sc_sort(n, e + 1, ce);
}

int rHeap(int* heap, int hi)
{
    int r = heap[0];

    heap[0] = heap[-- hi];

    int x = 0;
    int v = heap[0];

    while (x * 2 + 1 < hi)
    {
        int l = heap[x * 2 + 1];
        int r = l;
        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l >= r)
        {
            if (v >= l)
                break;
            heap[x] = heap[x * 2 + 1];
            heap[x * 2 + 1] = v;
            x = x * 2 + 1;
        }
        else
        {
            if (v >= r)
                break;
            heap[x] = heap[x * 2 + 2];
            heap[x * 2 + 2] = v;
            x = x * 2 + 2;
        }
    }
    return r;
}

void aHeap(int* heap, int hi, int v)
{
    heap[hi ++] = v;
    int x = hi - 1;

    while (x)
    {
        int p = (x - 1) / 2;
        if (heap[p] >= heap[x])
            break;
        heap[x] = heap[p];
        heap[p] = v;
        x = p;
    }
}

int scheduleCourse(int** courses, int coursesRowSize, int *coursesColSizes)
{
    if (!coursesRowSize)
        return 0;

    long* cs = malloc(sizeof(long) * coursesRowSize);
    bool sort = false;
    for (int i = 0; i < coursesRowSize; i ++)
    {
        cs[i] = (((long) courses[i][1]) << 32) | courses[i][0];
        if (i && !sort && courses[i][1] < courses[i - 1][1])
            sort = true;
    }

    if (sort)
        sc_sort(cs, 0, coursesRowSize - 1);

    int hi = 0;
    int* heap = malloc(sizeof(int) * coursesRowSize);
    int start = 0;

    for (int i = 0; i < coursesRowSize; i ++)
    {
        int e = (cs[i] >> 32) & 0xFFFFFFFF;
        int t = cs[i] & 0xFFFFFFFF;
        aHeap(heap, hi ++, t);
        start += t;
        while (start > e && hi)
            start -= rHeap(heap, hi --);
    }
    return hi;
}

/* void sc_sort(int* n, int s, int e) */
/* { */
/*     if (s >= e) */
/*         return; */

/*     int t; */
/*     if (n[s] > n[e]) */
/*     { */
/*         t = n[s]; */
/*         n[s] = n[e]; */
/*         n[e] = t; */
/*     } */

/*     if (s + 1 == e) */
/*         return; */

/*     int cs = s; */
/*     int ce = e; */

/*     for (int i = s + 1; i <= e; i ++) */
/*     { */
/*         while (n[i] < n[s]) i ++; */
/*         while (n[e] > n[s]) e --; */

/*         if (i >= e) */
/*         { */
/*             t = n[s]; */
/*             n[s] = n[e]; */
/*             n[e] = t; */
/*         } */
/*         else */
/*         { */
/*             t = n[i]; */
/*             n[i] = n[e]; */
/*             n[e] = t; */
/*         } */
/*     } */

/*     sc_sort(n, cs, e - 1); */
/*     sc_sort(n, e + 1, ce); */
/* } */

/* void aHeap(int* heap, int hi, int v) */
/* { */
/*     heap[hi ++] = v; */

/*     int x = hi - 1; */
/*     int vx = v & 0xFFFF; */

/*     while (x) */
/*     { */
/*         int p = (x - 1) / 2; */
/*         int vp = heap[p] & 0xFFFF; */

/*         if (vp > vx) */
/*             break; */

/*         heap[x] = heap[p]; */
/*         heap[p] = v; */
/*         x = p; */
/*     } */
/* } */

/* int rHeap(int* heap, int hi) */
/* { */
/*     int v = heap[0]; */
/*     hi --; */
/*     heap[0] = heap[hi]; */

/*     int x = 0; */
/*     int p = heap[0]; */
/*     int pv = heap[0] & 0xFFFF; */

/*     while (x * 2 + 1 < hi) */
/*     { */
/*         int l = heap[x * 2 + 1] & 0xFFFF; */
/*         int r = l; */

/*         if (x * 2 + 2  < hi) */
/*             r = heap[x * 2 + 2] & 0xFFFF; */

/*         if (l >= r) */
/*         { */
/*             if (pv >= l) */
/*                 break; */

/*             heap[x] = heap[x * 2 + 1]; */
/*             heap[x * 2 + 1] = p; */
/*             x = x * 2 + 1; */
/*         } */
/*         else */
/*         { */
/*             if (pv >= r) */
/*                 break; */

/*             heap[x] = heap[x * 2 + 2]; */
/*             heap[x * 2 + 2] = p; */
/*             x = x * 2 + 2; */
/*         } */
/*     } */
/*     return v; */
/* } */

/* int scheduleCourse(int** courses, int coursesRowSize, int *coursesColSizes) */
/* { */
/*     if (coursesRowSize <= 1) */
/*         return coursesRowSize; */

/*     int* cs = malloc(sizeof(int) * coursesRowSize); */

/*     /\* int start_i = 0; *\/ */
/*     /\* int start = courses[0][1] - courses[0][0]; *\/ */

/*     for (int i = 0; i < coursesRowSize; i ++) */
/*     { */
/*         /\* if (start <= courses[i][1] - courses[i][0]) *\/ */
/*         /\* { *\/ */
/*         /\*     if (start == courses[i][1] - courses[i][0]) *\/ */
/*         /\*     { *\/ */
/*         /\*         if (courses[i][1] > courses[start_i][1]) *\/ */
/*         /\*         { *\/ */
/*         /\*             start = courses[i][1] - courses[i][0]; *\/ */
/*         /\*             start_i = i; *\/ */
/*         /\*         } *\/ */
/*         /\*     } *\/ */
/*         /\*     else *\/ */
/*         /\*     { *\/ */
/*         /\*         start = courses[i][1] - courses[i][0]; *\/ */
/*         /\*         start_i = i; *\/ */
/*         /\*     } *\/ */
/*         /\* } *\/ */
/*         cs[i] = courses[i][1] << 16 | (65535 - courses[i][0]); */
/*     } */

/*     sc_sort(cs, 0, coursesRowSize - 1); */

/*     int start_i = coursesRowSize - 1; */
/*     int end = (cs[start_i] >> 16) - (65535 - (cs[start_i] & 0xFFFF)); */

/*     int hi = 0; */
/*     int* heap = malloc(sizeof(int) * coursesRowSize); */

/*     int x = 1; */

/*     for (int i = coursesRowSize - 2; i >= 0;) */
/*     { */
/*         int c = end << 16; */
/*         /\* printf("end %d %d c %d.\n", end, cs[i], c); *\/ */

/*         if (cs[i] >= c) */
/*         { */
/*             while (i >= 0 && cs[i] >= c) */
/*             { */
/*                 aHeap(heap, hi ++, cs[i]); */
/*                 /\* printf("add heap. cs[i] %d t %d.\n", cs[i] >> 16, 65535 - (cs[i] & 0xFFFF)); *\/ */
/*                 i --; */
/*                 /\* printf("heap[0] %d.\n", 65535 - (heap[0] & 0xFFFF)); *\/ */
/*             } */
/*         } */

/*         int time; */

/*         int t; */

/*         if (hi) */
/*             t = rHeap(heap, hi --); */
/*         else */
/*             t = cs[i --]; */

/*         int start = t >> 16; */
/*         time = 65535 - (t & 0xFFFF); */

/*         /\* printf("get time %d.\n", time); *\/ */

/*         if (end >= time) */
/*         { */
/*             if (end <= start) */
/*                 end -= time; */
/*             else */
/*                 end = start - time; */
/*             x ++; */
/*         } */
/*         else */
/*         { */
/*             printf("end %d start %d time %d %d.\n", end, start, time, x); */
/*         } */
/*     } */

/*     while (hi) */
/*     { */
/*         int t = rHeap(heap, hi --); */
/*         int start = t >> 16; */
/*         int time = 65535 -  (t & 0xFFFF); */

/*         if (end >= time) */
/*         { */
/*             if (end <= start) */
/*                 end -= time; */
/*             else */
/*                 end = start - time; */
/*             x ++; */
/*         } */
/*         else */
/*             break; */
/*     } */

/*     return x; */
/* } */


/* int scheduleCourse(int** courses, int coursesRowSize, int *coursesColSizes) */
/* { */
/*     long* cs = malloc(sizeof(long) * coursesRowSize); */
/*     bool sort = false; */
/*     for (int i = 0; i < coursesRowSize; i ++) */
/*     { */
/*         cs[i] = ((long) (courses[i][1] - courses[i][0])) << 32 | (long) courses[i][0]; */

/*         if (i && !sort && cs[i] < cs[i - 1]) */
/*             sort = true; */
/*     } */

/*     if (sort) */
/*         sc_sort(cs, 0, coursesRowSize - 1); */

/*     int x = 0; */
/*     long c = 0; */

/*     outl(cs, coursesRowSize); */
/*     for (int i = 0; i < coursesRowSize; i ++) */
/*     { */
/*         long need = cs[i] & 0xFFFFFFFF; */
/*         long t = (need + c) << 32; */
/*         int f = i + 1; */
/*         int u = i; */
/*         printf("need is %d t %ld.\n", need, t); */
/*         while (f < coursesRowSize && cs[f] < t) */
/*         { */
/*             printf("cs[f] %ld t %ld.\n", cs[f], t); */
/*             if ((cs[f] & 0xFFFFFFFF) < need) */
/*             { */
/*                 need = cs[f] & 0xFFFFFFFF; */
/*                 t = (need + c) << 32; */
/*                 u = f; */
/*             } */
/*             f ++; */
/*         } */
/*         i = u; */
/*         if (c <= (cs[i] >> 32) & 0xFFFFFFFF) */
/*         { */
/*             c += need; */
/*             x ++; */
/*         } */
/*         printf("i is %d %d.\n", i, c); */
/*     } */

/*     return x; */
/* } */
