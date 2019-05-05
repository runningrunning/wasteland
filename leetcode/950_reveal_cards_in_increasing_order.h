// math
// corner case
// be careful, find good way to simulate this
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize)
{
    *returnSize = deckSize;
    if (!deck || !deckSize)
        return NULL;

    qsort(deck, deckSize, sizeof(int), comp);

    int ri = 0;
    int* r = malloc(sizeof(int) * deckSize);

    // do the simulation ?

    int st = 0;
    int nx = 1;
    int step = 2;

    for (int i = 0; i < deckSize; i ++)
    {
        // printf("st is %d i %d.\n", st, i);
        if (st < deckSize)
            r[st] = deck[i];
        else
            i --;

        if (st + step < deckSize)
            st += step;
        else
        {
            if (st + step / 2 < deckSize || st >= deckSize)
            {
                st = nx;
                nx = st + step;
            }
            else
            {
                st = nx + step;
            }
            step *= 2;
        }
    }
    return r;
}

/* void try(int* n, int s) */
/* { */
/*     int ai = 0; */
/*     int bi = 0; */
/*     int* a = malloc(sizeof(int) * s); */
/*     int* b = malloc(sizeof(int) * s); */

/*     ai = s; */
/*     memcpy(a, n, sizeof(int) * s); */

/*     int st = 0; */
/*     int ri = 0; */
/*     int* r = malloc(sizeof(int) * s); */
/*     while (ai) */
/*     { */
/*         for (int i = st; i < ai;) */
/*         { */
/*             r[ri ++] = a[i]; */
/*             if (i + 2 < ai) */
/*             { */
/*                 b[bi ++] = a[i + 1]; */
/*                 i += 2; */
/*                 st = 0; */
/*             } */
/*             else */
/*             { */
/*                 st = 1; */
/*                 break; */
/*             } */
/*         } */

/*         ai = bi; */
/*         int* t = a; */
/*         a = b; */
/*         b = t; */
/*         bi = 0; */

/*         if (st) */
/*         { */
/*             b[bi ++] = a[0]; */
/*         } */
/*     } */
/*     out(r, ri); */
/* } */
