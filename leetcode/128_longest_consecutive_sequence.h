// different method for union find ??
// why pass, can I prove this ?
#define FMASK 0x80000000
#define VMASK 0x7FFFFFFF

int _h(int* hash, int dp, int v, int* n)
{
    int x = v % dp;
    if (x < 0)
        x += dp;

    while ((hash[x] & FMASK) && (n[hash[x] & VMASK] != v))
        x = (x + 1) % dp;
    return x;
}

// can have same number ?
// use hash
int longestConsecutive(int* nums, int numsSize)
{
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};
    int pl = sizeof(pri) / sizeof(pri[0]);

    int dp;
    for (int i = 0; i < pl; i ++)
    {
        if (pri[i] > (numsSize << 2))
        {
            dp = pri[i];
            break;
        }
    }

    int max = INT_MIN;
    int* hash = calloc(sizeof(int), dp);
    int* bs = malloc(sizeof(int) * numsSize);
    int* as = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        int v = nums[i];
        int x = _h(hash, dp, v, nums);

        if (!(hash[x] & FMASK))
        {
            hash[x] = i | FMASK;

            int before = v;
            int bx = -1;
            if (v != INT_MIN)
            {
                bx = _h(hash, dp, v - 1, nums);
                if (!(hash[bx] & FMASK))
                    bx = -1;
                else
                {
                    before = bs[hash[bx] & VMASK];
                    bx = _h(hash, dp, before, nums);
                    bx = hash[bx] & VMASK;
                    before = bs[bx];
                }
            }

            int after = v;
            int ax = -1;
            if (v != INT_MAX)
            {
                ax = _h(hash, dp, v + 1, nums);
                if (!(hash[ax] & FMASK))
                    ax = -1;
                else
                {
                    after = as[hash[ax] & VMASK];
                    ax = _h(hash, dp, after, nums);
                    ax = hash[ax] & VMASK;
                    after = as[ax];
                }
            }

            as[i] = after;
            bs[i] = before;

            if (ax != -1 && bx != -1)
            {
                as[i] = after;
                bs[i] = before;
                as[bx] = after;
                bs[ax] = before;
            }
            else if (ax != -1)
            {
                as[i] = after;
                bs[i] = v;
                bs[ax] = v;
            }
            else if (bx != -1)
            {
                as[i] = v;
                bs[i] = before;
                as[bx] = v;
            }
            // printf("%d %d for %d.\n", before, after, v);
            if (max < after - before + 1)
                max = after - before + 1;
        }
    }
    free(hash);
    free(bs);
    free(as);
    return max;
}

/* void min_heap(int* ns, int s) */
/* { */
/*     for(int i = 1; i < s; i ++) */
/*     { */
/*         int j = i; */
/*         int p = (j - 1) / 2; */
/*         while(ns[p] > ns[j]) */
/*         { */
/*             int t = ns[p]; */
/*             ns[p] = ns[j]; */
/*             ns[j] = t; */
/*             j = p; */
/*             p = (p - 1) / 2; */
/*         } */
/*     } */
/* } */

/* int con(int *ns, int c, int s, int* max_n, ) */
/* { */
/*     int a = 2 * c + 1; */
/*     int b = 2 * c + 2; */
/*     if (a >= s) /*
/*         return 0; */

/*     if (a == s - 1) */
/*     { */
/*         return  */
/*     } */
/*     else */
/*     { */
/*     } */
/* } */

/* int longestConsecutive(int* nums, int numsSize) */
/* { */
/*     if (numsSize < 2) */
/*         return numsSize; */
/*     min_heap(nums, numsSize); */
/*     int max_n = 0; */
/*     con(nums, 0, numsSize, &max_n); */
/*     return max_n; */
/* } */

