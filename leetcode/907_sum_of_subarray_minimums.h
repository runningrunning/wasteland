// 898 bitwise ORs of Subarrays ? similar ?
// TIME LIMIT !!!!!!!!
// similar with 898 ? Bitwise ORs of Subarrays ?
// try binary search method ?
// STUPID WRONG ALGORITHMS !!!!
// find better way !!!
// THINK TOO MU
// not heap, but using array sort
// time over !!!
// how to optimize code ? how to use data structure to optimize this ?
// segment tree ? or something else !!!!
// stack ??? try stack mode ?
// try treap ? not this way
// rotate stack ?

#define MOD 1000000007

int sumSubarrayMins(int* A, int ASize)
{
    if (!A || !ASize)
        return 0;

    if (ASize == 1)
        return A[0];

    int hi = 0;
    int* h = malloc(sizeof(int) * ASize);
    int* v = malloc(sizeof(int) * ASize);

    int pre = A[0];
    int num = A[0];

    h[hi] = A[0];
    v[hi] = A[0];

    for (int i = 1; i < ASize; i ++)
    {
        int x = A[i];

        if ((h[hi] & 0xFFFF) <= A[i])
        {
            h[++ hi] = i << 16 | A[i];
            pre = (pre + A[i]) % MOD;
            v[hi] = pre;
        }
        else
        {
            int s = 0;
            int e = hi;

            while (s < e)
            {
                int m = (s + e) / 2;
                int hm = h[m] & 0xFFFF;

                if (hm < x)
                    s = m + 1;
                else
                    e = m;
            }

            hi = s;
            h[s] = i << 16 | A[i];


            if (s)
            {
                pre = (v[s - 1] + (i - (h[s - 1] >> 16)) * A[i]) % MOD;
                v[s] = pre;
            }
            else
            {
                pre = ((i + 1) * A[i]) % MOD;
                v[s] = pre;
            }
            printf("s is %d %d.\n", s, pre);
        }
        num = (num + pre) % MOD;

        printf("num is %d %d.\n", i, num);
    }
    return num % MOD;
}

/* void aHeap(int* h, int v, int hi) */
/* { */
/*     h[hi] = v; */

/*     if (!hi) */
/*         return; */

/*     while (hi) */
/*     { */
/*         int p = (hi - 1) / 2; */

/*         if ((h[p] & 0xFFFF) <= (h[hi] & 0xFFFF)) */
/*             break; */

/*         h[hi] = h[p]; */
/*         h[p] = v; */
/*         hi = p; */
/*     } */
/* } */

/* int ssm(int* h, int s, int e, int rs, int re) */
/* { */
/*     if (re < rs) */
/*         return 0; */

/*     while (s <= e) */
/*     { */
/*         int v = h[s]; */
/*         int i = v >> 16; */
/*         v &= 0xFFFF; */
/*         if (i >= rs && i <= re) */
/*         { */
/*             int p1 = ssm(h, s + 1, e, rs, i - 1); */
/*             int p2 = ssm(h, s + 1, e, i + 1, re); */
/*             p1 += p2; */
/*             p2 = ((i - rs + 1) * (re - i + 1) * v) % MOD; */
/*             return (p1 + p2) % MOD; */
/*         } */
/*         s ++; */
/*     } */
/*     return 0; */
/* } */

/* int comp(const void* a, const void* b) */
/* { */
/*     int av = (*((int*) a)) & 0xFFFF; */
/*     int bv = (*((int*) b)) & 0xFFFF; */
/*     return av - bv; */
/* } */

/* int sumSubarrayMins(int* A, int ASize) */
/* { */
/*     int hi = 0; */
/*     int* h = malloc(sizeof(int) * ASize); */

/*     for (int i = 0; i < ASize; i ++) */
/*         h[i] = i << 16 | A[i]; */

/*     qsort(h, ASize, sizeof(int), comp); */

/*     // return ssm(h, 0, ASize - 1, 0, ASize - 1); */

/*     // stack mode */

/*     int sum = 0; */

/*     int si = 0; */
/*     long* s = malloc(sizeof(int) * ASize); */
/*     s[si ++] = ASize - 1; */


/*     while (si) */
/*     { */
/*         long t = s[-- si]; */
/*         long ti = t >> 32; */
/*         long ts = (t >> 16) & 0xFFFF; */
/*         long te = t & 0xFFFF; */
/*         // printf("si %d %ld %ld %ld %ld.\n", si, t, ti, ts, te); */

/*         for (long i = ti; i < ASize; i ++) */
/*         { */
/*             int hi = h[i] >> 16; */

/*             if (hi >= ts && hi <= te) */
/*             { */
/*                 if (hi > ts) */
/*                 { */
/*                     // printf("add %d %ld %d.\n", i + 1, ts, hi - 1); */
/*                     s[si ++] = (i + 1) << 32 | ts << 16 | hi - 1; */
/*                 } */
/*                 if (hi < te) */
/*                 { */
/*                     // printf("add %d %d %ld.\n", i + 1, hi + 1, te); */
/*                     s[si ++] = (i + 1) << 32 | (hi + 1) << 16 | te; */
/*                 } */

/*                 sum += (hi - ts + 1) * (te - hi + 1) * (h[i] & 0xFFFF); */
/*                 sum %= MOD; */
/*                 // printf("%ld %ld %d %d.\n", ts, te, hi, sum); */
/*                 break; */
/*             } */
/*         } */
/*     } */

/*     return sum; */
/* } */
