// Stupid WRONG ALGORITHM !!!!!!!!!!! IT's JUST HEAP !!!!!, my first impression is CORRECT, not DP !!!
// Similar with 630 Course schedule III, use heap and maintain current status, and add up / remove max/min heap from the current status
// it's NOT DP !!!!!!
// just heap ? YES !!
// stupid wrong DP, not THIS !
// only refuel once, can get
// only refuel twice, can get
// only refuel ..., can get

int minRefuelStops(int target, int startFuel, int** stations, int stationsRowSize, int * stationsColSizes)
{
    int hi = 0;
    int heap[512];

    int refuel = 0;
    int end = startFuel;

    if (!stationsRowSize || !stations)
        return target > startFuel ? -1 : 0;

    for (int i = 0; i < stationsRowSize; i ++)
    {
        if (end >= target)
            return refuel;

        while (end < stations[i][0])
        {
            if (!hi)
                return -1;

            end += heap[0];
            refuel ++;

            heap[0] = heap[-- hi];

            int x = 0;
            int v = heap[0];

            while (x * 2 + 1 < hi)
            {
                int l = heap[x * 2 + 1];
                int r = l;

                if (x * 2 + 2 < hi)
                    r = heap[x * 2  + 2];

                if (l >= r)
                {
                    if (l <= v)
                        break;
                    heap[x] = l;
                    heap[x * 2 + 1] = v;
                    x = x * 2 + 1;
                }
                else
                {
                    if (r <= v)
                        break;
                    heap[x] = r;
                    heap[x * 2 + 2] = v;
                    x = x * 2 + 2;
                }
            }
        }

        heap[hi ++] = stations[i][1];

        int x = hi - 1;
        while (x)
        {
            int p = (x - 1) / 2;
            if (heap[p] > heap[x])
                break;
            heap[x] = heap[p];
            heap[p] = stations[i][1];
            x = p;
        }
    }

    while (end < target)
    {
        if (!hi)
            return -1;

        end += heap[0];
        refuel ++;

        heap[0] = heap[-- hi];

        int x = 0;
        int v = heap[0];

        while (x * 2 + 1 < hi)
        {
            int l = heap[x * 2 + 1];
            int r = l;

            if (x * 2 + 2 < hi)
                r = heap[x * 2  + 2];

            if (l >= r)
            {
                if (l <= v)
                    break;
                heap[x] = l;
                heap[x * 2 + 1] = v;
                x = x * 2 + 1;
            }
            else
            {
                if (r <= v)
                    break;
                heap[x] = r;
                heap[x * 2 + 2] = v;
                x = x * 2 + 2;
            }
        }
    }
    return refuel;
}

/* void max_refuel(int i, long now, int** sts, int si, int strs, long* mem, int t, int* cur, int* max) */
/* { */
/*     if (now >= mem[si * 512 + i]) */
/*     { */
/*         mem[si * 512 + i] = now; */

/*         if (now >= t && i < *cur) */
/*         { */
/*             *cur = i; */
/*             *max = now; */
/*         } */
/*     } */
/*     else */
/*         return; */

/*     if (si >= strs || now < sts[si][0] || i >= *cur) */
/*         return; */

/*     max_refuel(i, now, sts, si + 1, strs, mem, t, cur, max); */
/*     max_refuel(i + 1, now + sts[si][1], sts, si + 1, strs, mem, t, cur, max); */
/* } */

/* int minRefuelStops(int target, int startFuel, int** stations, int stationsRowSize, int *stationsColSizes) */
/* { */
/*     if (startFuel >= target) */
/*         return 0; */
/*     int max = 0; */
/*     int cur = stationsRowSize + 1; */
/*     long* mem = calloc(sizeof(long), (stationsRowSize + 1) * 512); */
/*     max_refuel(0, startFuel, stations, 0, stationsRowSize, mem, target, &cur, &max); */
/*     return max >= target ? cur : -1; */
/* } */


/* int minRefuelStops(int target, int startFuel, int** stations, int stationsRowSize, int *stationsColSizes) */
/* { */
/*     if (startFuel >= target) */
/*         return 0; */
/*     int max = 0; */
/*     int cur = stationsRowSize + 1; */

/*     int* min = malloc(sizeof(int) * stationsRowSize); */
/*     int* nums = calloc(sizeof(int), stationsRowSize); */
/*     int* mem = calloc(sizeof(int), (stationsRowSize + 1) * 512); */

/*     int need = target; */
/*     for (int i = stationsRowSize - 1; i >= 0; i --) */
/*     { */
/*         need -= stations[i][1]; */
/*         min[i] = need; */
/*         nums[i] = i + 1; */
/*     } */

/*     if (need > startFuel) */
/*         return - 1; */

/*     max_refuel(0, startFuel, stations, 0, stationsRowSize, mem, target, &cur, &max, min, nums); */

/*     return max >= target ? cur : -1; */
/* } */

/* void max_refuel(int i, int now, int** sts, int si, int strs, int* mem, int t, int* cur) */
/* { */
/*     if (now >= mem[i]) */
/*         mem[i] = now; */

/*     if (now >= t && i < *cur) */
/*         *cur = i; */

/*     if (si >= strs || now < sts[si][0] || i >= *cur) */
/*         return; */

/*     max_refuel(i, now, sts, si + 1, strs, mem, t, cur); */
/*     max_refuel(i + 1, now + sts[si][1], sts, si + 1, strs, mem, t, cur); */
/* } */

/* int minRefuelStops(int target, int startFuel, int** stations, int stationsRowSize, int *stationsColSizes) */
/* { */
/*     if (startFuel >= target) */
/*         return 0; */

/*     int max = stationsRowSize; */
/*     int* mem = calloc(sizeof(int), (stationsRowSize + 1)); */
/*     mem[0] = startFuel; */
/*     max_refuel(0, startFuel, stations, 0, stationsRowSize, mem, target, &max); */
/*     return mem[max] >= target ? max : -1; */
/* } */

