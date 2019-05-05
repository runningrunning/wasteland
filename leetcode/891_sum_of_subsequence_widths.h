// should have easy way to do this !!!
// time limits !!!, how to optimize ?
// how to optimize this ?
// math
// CODE OPTIMIZATION !!!!

int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

#define MOD 1000000007

int sumSubseqWidths(int* A, int ASize)
{
    if (ASize < 2)
        return 0;

    qsort(A, ASize, sizeof(int), comp);

    int* f = malloc(sizeof(int) * ASize);
    f[0] = 1;

    for (int i = 1; i < ASize; i ++)
        f[i] = (((f[i - 1] - 1) * 2 + 1) % MOD) + 1;

    long r = 0;

    for (int i = 0; i < ASize - 1; i ++)
    {
        // offset 1 error !

        int e;
        int pe = -1;
        for (int j = 0; j <= i; j ++)
        {
            int n = i + 1;
            if (j + n >= ASize)
                break;

            if (pe == -1 || pe + 1 >= ASize)
                e = ((ASize - 1 - j) / n) * n + j;
            else
                e = pe + 1;

            pe = e;
            long d = A[e] - A[j];

            r += f[i] * d;
        }
        r %= MOD;
    }
    return r;
}

/* // should have easy way to do this !!! */

/* int comp(const void* e1, const void* e2) */
/* { */
/*     return *((int*)e1) - *((int*)e2); */
/* } */

/* #define MOD 1000000007 */

/* int sumSubseqWidths(int* A, int ASize) */
/* { */
/*     if (ASize < 2) */
/*         return 0; */

/*     qsort(A, ASize, sizeof(int), comp); */

/*     int* f = malloc(sizeof(int) * ASize); */

/*     f[0] = 1; */

/*     for (int i = 1; i < ASize; i ++) */
/*         f[i] = (((f[i - 1] - 1) * 2 + 1) % MOD) + 1; */

/*     long r = 0; */
/*     for (int i = 0; i < ASize; i ++) */
/*     { */
/*         for (int j = i + 1; j < ASize; j ++) */
/*         { */
/*             long d = A[j] - A[i]; */
/*             r += f[j - i - 1] * d; */
/*             r %= MOD; */
/*         } */
/*     } */

/*     return r; */
/* } */
