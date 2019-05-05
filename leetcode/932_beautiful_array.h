/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// THIS is DP version for this questions !!!, Figure out how
// just simple even and odd sort
// cause every even and odd can not find anything in the middle
// then for even and odd part do it again for next bit b << 1
void sab(int* r, int s, int e, int b)
{
    if (s >= e)
        return;

    int os = s;
    int oe = e;

    while (s < e)
    {
        while (s < e && (r[s] & b))
            s ++;

        while (s < e && !(r[e] & b))
            e --;

        if (e > s)
        {
            r[s] ^= r[e];
            r[e] ^= r[s];
            r[s] ^= r[e];

            s ++;
            e --;
        }
    }

    if (s == e)
    {
        if (r[s] & b)
        {
            sab(r, os, s, b << 1);
            sab(r, s + 1, oe, b << 1);
        }
        else
        {
            sab(r, os, s - 1, b << 1);
            sab(r, s, oe, b << 1);
        }
    }
    else
    {
        sab(r, os, e, b << 1);
        sab(r, s, oe, b << 1);
    }
}

// can only do this trough bits or even/odd ways !
int* beautifulArray(int N, int* returnSize)
{
    *returnSize = N;
    int* r = malloc(sizeof(int) * N);

    for (int i = 0; i < N; i ++)
        r[i] = i + 1;
    sab(r, 0, N - 1, 1);
    return r;
}

// simple, but how to solve with C
// any simple method ?
// wrong method
// get 21 for : 1 17 9 5 3 2 21 13 19 20 11 4 12 16 8 10 6 7 18 14 15
// cause 20 11 4 12 7 10 15 16 18 8 6
/* int* beautifulArray(int N, int* returnSize) */
/* { */
/*     int* r = malloc(sizeof(int) * N); */
/*     int ni = 0; */
/*     int* n = malloc(sizeof(int) * N); */

/*     char* s = calloc(sizeof(char), N + 1); */
/*     char* b = calloc(sizeof(char), N + 1); */

/*     for (int i = 0; i < N; i ++) */
/*         r[i] = i + 1; */

/*     int sti = 0; */
/*     int* stacks = malloc(sizeof(int) * N); */

/*     for (int i = 0; i < N; i ++) */
/*     { */
/*         int x = r[i]; */
/*         memset(b, 0, sizeof(char) * (N + 1)); */
/*         ni = i; */
/*         n[ni ++] = x; */
/*         s[x] = 1; */
/*         b[x] = 1; */
/*         printf("hi is %d %d.\n", x, i); */
/*         out(r, N); */
/*         for (int j = i + 1; j < N; j ++) */
/*         { */
/*             int a = r[j] * 2 - x; */
/*             if ((a < 0) || !(!b[a] && !s[a] && a <= N)) */
/*             { */
/*                 if (!b[r[j]] && !s[r[j]]) */
/*                 { */
/*                     n[ni ++] = r[j]; */
/*                     b[r[j]] = 1; */
/*                 } */
/*             } */
/*             else */
/*             { */
/*                 sti = 0; */
/*                 while (a > 0 && !b[a] && !s[a] && a <= N) */
/*                 { */
/*                     printf("add a %d for %d.\n", a, r[j]); */
/*                     stacks[sti ++] = a; */
/*                     a = a * 2 - x; */
/*                 } */

/*                 for (int k = sti - 1; k >= 0; k --) */
/*                 { */
/*                     n[ni ++] = stacks[k]; */
/*                     b[stacks[k]] = 1; */
/*                 } */

/*                 if (!b[r[j]] && !s[r[j]]) */
/*                 { */
/*                 n[ni ++] = r[j]; */
/*                 b[r[j]] = 1; */
/*                 printf("j is %d r[j] is %d ni %d.\n", j, r[j], ni); */
/*                 } */
/*             } */
/*         } */
/*         int* t = r; */
/*         r = n; */
/*         n = t; */
/*     } */
/*     out(n, N); */
/* } */

// stupid just find the pattern
// STUPID WRONG ALGORITHM
/* int* beautifulArray(int N, int* returnSize) { */
/*     int s, e; */

/*     if (N & 1) */
/*     { */
/*         s = N / 2 + 1; */
/*         e = N / 2 + 2; */
/*     } */
/*     else */
/*     { */
/*         s = N / 2; */
/*         e = N / 2 + 1; */
/*     } */

/*     for (int i = 0; i < N / 2; i ++) */
/*     { */
/*         r[i] = s --; */
/*         r[N - 1 - i] = e ++; */
/*     } */

/*     *returnSize = N; */

/*     return r; */
/* } */

