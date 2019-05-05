// write node about difference between DP and GREEDY
// SIMPLE GREEDY, NO DP !!!!!!!!
// greedy, but how to prove GREEDY is the correct answer ? ??????
// LEARN A LOT
// GREEDY always combined with sort and get the last optimized result
// and the last optimized result are always correct !

//
// dp with start and end range ????
// there is some questions similar, find it !!
// segment trees ?
// one similar with DP ?
// read the wrongly ????
// read the program wrongly !!!!!!!!!!!!!!!!!!!!!!!!!!!!
// the result is a set not a intersection !!!!
// with hash ?
// just brute force ???
// common area question ?
// how to solve those common intersection problesm ?

int comp(const void* e1, const void* e2)
{
    int* i1 = *((int**) e1);
    int* i2 = *((int**) e2);
    return i1[1] == i2[1] ? (i1[0] - i2[0]) : (i1[1] - i2[1]);
}

int intersectionSizeTwo(int** intervals, int intervalsRowSize, int intervalsColSize)
{
    if (!intervals || !intervalsRowSize || !intervalsColSize)
        return 0;

    qsort(intervals, intervalsRowSize, sizeof(int*), comp);

    int ni = 0;
    int* nt = malloc(sizeof(int) * intervalsRowSize * 2);

    int l1, l2;
    for (int i = 0; i < intervalsRowSize; i ++)
    {
        int is = intervals[i][0];
        int ie = intervals[i][1];

        if (ni >= 2)
        {
            if (l2 >= is && l2 <= ie)
            {
                if (l1 >= is && l1 <= ie)
                    continue;

                if (l2 != ie)
                {
                    nt[ni ++] = ie;
                    l1 = l2;
                    l2 = ie;
                    continue;
                }

                ni --;
            }
        }

        nt[ni ++] = ie - 1;
        nt[ni ++] = ie;

        l1 = ie - 1;
        l2 = ie;
    }

    return ni;

}

/* int intersectionSizeTwo(int** intervals, int intervalsRowSize, int intervalsColSize) */
/* { */
/*     if (!intervals || !intervalsRowSize || !intervalsColSize) */
/*         return 0; */

/*     int e = INT_MIN; */

/*     for (int i = 0; i < intervalsRowSize; i ++) */
/*     { */
/*         int is = intervals[i][0]; */
/*         int ie = intervals[i][1]; */

/*         if (s > ie - 1) */
/*             s = ie - 1; */
/*         if (e < is + 1) */
/*             e = is + 1; */
/*     } */

/*     if (s == e) */
/*         return 2; */

/*     int si = 0; */
/*     int* st = malloc(sizeof(int) * intervalsRowSize); */
/*     char* bits = calloc(sizeof(char), e - s + 1); */

/*     int ci = 0; */
/*     int* ct = malloc(sizeof(int) * (e - s + 1)); */
/*     for (int i = 0; i < intervalsRowSize; i ++) */
/*     { */
/*         int is = intervals[i][0]; */
/*         int ie = intervals[i][1]; */

/*         if (is + 1 == ie) */
/*         { */
/*             if (!bits[is - s]) */
/*             { */
/*                 bits[is - s] = 1; */
/*                 ct[ci ++] = is; */
/*             } */

/*             if (!bits[ie - s]) */
/*             { */
/*                 bits[ie - s] = 1; */
/*                 ct[ci ++] = ie; */
/*             } */
/*         } */
/*         else */
/*             st[si ++] = i; */
/*     } */

/*     int* nums = calloc(sizeof(int), (e - s + 1)); */
/*     int bi = 0; */
/*     int* bt = malloc(sizeof(int) * si); */
/*     for (int i = 0; i < si; i ++) */
/*     { */
/*         int is = intervals[st[i]][0]; */
/*         int ie = intervals[st[i]][1]; */
/*         int cn = 0; */
/*         for (int j = 0; j < ci; j ++) */
/*         { */
/*             if (ct[j] >= is && ct[j] <= ie) */
/*                 cn ++; */

/*             if (cn >= 2) */
/*                 break; */
/*         } */

/*         if (cn < 2) */
/*         { */
/*             for (int k = s; k <= e; k ++) */
/*             { */
/*                 if ((k >= is && k <= ie) && !bits[k - s]) */
/*                     nums[k - s] ++; */
/*                 if (k >= ie) */
/*                     break; */
/*             } */
/*             bt[bi ++] = i; */
/*         } */
/*     } */

/*     int n = ci; */


/*     return s == e ? 2 : (e - s + 1); */
/* } */
