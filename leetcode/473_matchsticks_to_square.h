// TODO FINGURE OUT WHY THE QSORT IS ERROR !!!!!!!!!!!!!!!!
// TODO HOW TO WRITE DFS CODE gracefully !!!

// how to write depth search ?
// SIMPLE CODE About DEPTH SEARCH !!!
// same as 621_task_scheduler.h
// divide it into 4 groups with same
// depth search here !!!!
// write my sort and all of standard library

// bigger to smaller
int comp(const void* a, const void* b)
{
    return *((int*)b) - *((int*)a);
}

// same as 621_task_scheduler.h
// depth search ?
bool makesquare(int* nums, int numsSize)
{
    if (numsSize < 4)
        return false;

    int a = 0;
    for (int i = 0; i < numsSize; i ++)
        a += nums[i];

    if (!a || a % 4)
        return false;

    a /= 4;

    // something wrong in qsort !!!!!!!!!!, when it's called multiple times
    /* printf("%p.\n", nums); */
    /* out(nums, numsSize); */
    // qsort(nums, numsSize, sizeof(int), comp);

    if (nums[0] > a)
        return false;

    // depth search here ?

    int si = 0;
    int st[32] = {0};
    st[si ++] = 0;
    int b = 1;

    int lv = 1;
    int c = nums[0];

    while (true)
    {
        int p;
        bool remove = true;

        if (c == a)
        {
            c = 0;
            p = 0;

            lv ++;

            if (lv == 4)
                return true;
        }
        else
        {
            p = st[si - 1];
            p ++;

            while (p < numsSize && (b & (1 << p)))
                p ++;
        }

        if (p == numsSize)
        {
            p = st[-- si];
            b &= ~(1 << p);
            c -= nums[p];

            if (c == 0)
            {
                c = a;
                lv --;

                if (!lv)
                    return false;
            }
        }
        else
        {
            while (p < numsSize && ((b & (1 << p)) || (c + nums[p] > a)))
                p ++;

            if (p < numsSize)
            {
                c += nums[p];
                st[si ++] = p;
                b |= 1 << p;
                remove = false;
            }
        }

        if (remove)
        {
            if (si == 1)
                return false;

            p = st[-- si];
            b &= ~(1 << p);
            c -= nums[p];

            p ++;

            while (p < numsSize && (b & (1 << p)))
                p ++;

            c += nums[p];
            st[si ++] = p;
            b |= 1 << p;
        }
    }
    return false;
}


/* void ms_sort(int* n, int s, int e) */
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

/*     ms_sort(n, cs, e - 1); */
/*     ms_sort(n, e + 1, ce); */
/* } */

