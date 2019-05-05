// binary search ???????????? !!!!!!!!
// binary search vs heap ~~~
// corner case
//
// out of mind !
// simple heap ??????
// how to optimize this, is the most important part

double minmaxGasDist(int* stations, int stationsSize, int K)
{
    double d = stations[stationsSize - 1] - stations[0];
    double n = stationsSize - 1 + K;

    double s = d / n;
    double e = d;
    double max = 0.0;

    while (s + 0.000001 < e)
    {
        double m = (s + e) / 2.0;
        int n = 0;
        max = 0.0;

        for (int i = 0; i < stationsSize - 1; i ++)
        {
            double delta = stations[i + 1] - stations[i];

            if (delta < m)
            {
                if (max < delta)
                    max = delta;
                continue;
            }

            int divid = delta / m;

            // printf("di: %d:%d-%d:%d ", i, stations[i + 1], stations[i], divid);

            n += divid;

            if (max < delta / (divid + 1))
                max = delta / (divid + 1);
        }

        // printf("n is %d, s %f, e %f m %f.\n", n, s ,e, m);
        if (n == K)
            break;

        if (n > K)
            s = m;
        else
            e = m;
    }

    return max;
}


// stupid wrong algorithm !!!!!!!!
/* int comp(const void* a, const void* b) */
/* { */
/*     return *((int*)a) - *((int*)b); */
/* } */

/* void aHeap(long* heap, int hi, long v) */
/* { */
/*     heap[hi ++] = v; */
/*     int x = hi - 1; */

/*     int vv = v & 0xFFFFFFFF; */
/*     int vn = (v >> 32) + 1; */

/*     while (x) */
/*     { */
/*         int p = (x - 1) / 2; */
/*         int pv = heap[p] & 0xFFFFFFFF; */
/*         int pn = (heap[p] >> 32) + 1; */

/*         if (pv * vn >= vv * pn) */
/*             return; */

/*         heap[p] ^= heap[x]; */
/*         heap[x] ^= heap[p]; */
/*         heap[p] ^= heap[x]; */
/*         x = p; */
/*     } */
/* } */

/* void mHeap(long* heap, int hi) */
/* { */
/*     heap[0] += 1L << 32; */
/*     int x = 0; */
/*     long v = heap[0]; */
/*     int vv = v & 0xFFFFFFFF; */
/*     int vn = (v >> 32) + 1; */

/*     while(x * 2 + 1 < hi) */
/*     { */
/*         long l = heap[x * 2 + 1]; */
/*         long r = l; */

/*         if (x * 2 + 2 < hi) */
/*             r = heap[x * 2 + 2]; */

/*         int lv = l & 0xFFFFFFFF; */
/*         int ln = (l >> 32) + 1; */

/*         int rv = r & 0xFFFFFFFF; */
/*         int rn = (r >> 32) + 1; */

/*         if (lv * rn >= rv * ln) */
/*         { */
/*             if (lv * vn <= vv * ln) */
/*                 break; */
/*             heap[x] = l; */
/*             heap[x * 2 + 1] = v; */
/*             x = x * 2 + 1; */
/*         } */
/*         else */
/*         { */
/*             if (rv * vn <= vv * rn) */
/*                 break; */
/*             heap[x] = r; */
/*             heap[x * 2 + 2] = v; */
/*             x = x * 2 + 2; */
/*         } */
/*     } */
/* } */

/* double minmaxGasDist(int* stations, int stationsSize, int K) */
/* { */
/*     int hi = 0; */
/*     long* heap = malloc(sizeof(long) * (stationsSize + 1)); */
/*     qsort(stations, stationsSize, sizeof(int), comp); */

/*     int ok = K; */

/*     long max_d = stations[stationsSize - 1] - stations[0]; */
/*     long max_n = (stationsSize - 1 + K); */
/*     long max_v = (max_n << 32) | max_d; */

/*     while (true) */
/*     { */
/*         long num = 0; */
/*         long now = 0; */

/*         for (int i = 0; i < stationsSize - 1; i ++) */
/*         { */
/*             long d = stations[i + 1] - stations[i]; */
/*             if (d * max_n <= max_d) */
/*                 continue; */
/*             num += 1; */
/*             now += d; */
/*         } */

/*         if (max_d == now && max_n == (num + K)) */
/*         { */
/*             for (int i = 0; i < stationsSize - 1; i ++) */
/*             { */
/*                 long d = stations[i + 1] - stations[i]; */
/*                 /\* long n = d * max_n / max_d; *\/ */
/*                 /\* if (n) *\/ */
/*                 /\* { *\/ */
/*                 /\* n -= 1; *\/ */
/*                 /\* ok -= n; *\/ */
/*                 /\* } *\/ */
/*                 long n = 0; */
/*                 // printf("d %d n is %d %d %d/%d.\n", d, n, ok, max_d, max_n); */
/*                 aHeap(heap, hi ++, n << 32 | d); */
/*             } */
/*             break; */
/*         } */

/*         max_d = now; */
/*         max_n = num + K; */
/*     } */


/*     printf("ok is %d.\n", ok); */
/*     for (int i = 0; i < ok; i ++) */
/*         mHeap(heap, hi); */

/*     double d = heap[0] & 0xFFFFFFFF; */
/*     double n = (heap[0] >> 32) + 1; */
/*     return d / n; */
/* } */
