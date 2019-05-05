// liner time ??? how can I O(n) solution !!!, use list ??
// use heap ?
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = 0;
    if (!numsSize || !nums || !k)
        return NULL;

    int ri = numsSize - k + 1;
    int* r = malloc(sizeof(int) * ri);
    *returnSize = ri;

    if (k == 1)
    {
        for (int i = 0; i < numsSize; i ++)
            r[i] = nums[i];
    }
    else if (k == numsSize)
    {
        int max = nums[0];
        for (int i = 1; i < numsSize; i ++)
            if (max < nums[i])
                max = nums[i];
        r[0] = max;
    }
    else
    {
        int i = 0;
        int hi = 0;
        int* heap = malloc(sizeof(int) * numsSize);

        for (i = 0; i < k - 1; i ++)
        {
            heap[hi ++] = i;
            int x = hi - 1;
            while (x)
            {
                int p = (x - 1) / 2;
                if (nums[heap[p]] >= nums[heap[x]])
                    break;
                int t = heap[x];
                heap[x] = heap[p];
                heap[p] = t;
                x = p;
            }
        }

        for (; i < numsSize; i ++)
        {
            while (heap[0] <= i - k)
            {
                heap[0] = heap[-- hi];
                int x = 0;
                while (x * 2 + 1 < hi)
                {
                    int hx = heap[x];
                    int lx = heap[x * 2 + 1];
                    int rx = lx;

                    if (x * 2 + 2 < hi)
                        rx = heap[x * 2 + 2];

                    if (nums[lx] >= nums[rx])
                    {
                        if (nums[lx] <= nums[hx])
                            break;
                        heap[x] = lx;
                        heap[x * 2 + 1] = hx;
                        x = 2 * x + 1;
                    }
                    else
                    {
                        if (nums[rx] <= nums[hx])
                            break;
                        heap[x] = rx;
                        heap[x * 2 + 2] = hx;
                        x = 2 * x + 2;
                    }
                }
            }

            heap[hi ++] = i;
            int x = hi - 1;
            while (x)
            {
                int p = (x - 1) / 2;
                if (nums[heap[p]] >= nums[heap[x]])
                    break;
                int t = heap[x];
                heap[x] = heap[p];
                heap[p] = t;
                x = p;
            }
            r[i - k + 1] = nums[heap[0]];
        }
    }
    return r;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) */
/* { */
/*     returnSize = 0; */
/*     if (!numsSize || !nums || !k) */
/*         return NULL; */

/*     int ri = numsSize - k + 1; */
/*     int* r = malloc(sizeof(int) * ri); */
/*     *returnSize = ri; */

/*     if (k == 1) */
/*     { */
/*         for (int i = 0; i < numsSize; i ++) */
/*             r[i] = nums[i]; */
/*     } */
/*     else if (k == numsSize) */
/*     { */
/*         int max = nums[0]; */
/*         for (int i = 1; i < numsSize; i ++) */
/*             if (max < nums[i]) */
/*                 max = nums[i]; */
/*         r[0] = max; */
/*     } */
/*     else */
/*     { */
/*         int max_i = 0; */
/*         int max = nums[0]; */
/*         int sec_i = -1; */
/*         int i = 1; */
/*         for (; i < k; i ++) */
/*         { */
/*             if (max < nums[i]) */
/*             { */
/*                 max_i = 0; */
/*                 max = nums[i]; */
/*                 sec_i = -1; */
/*             } */
/*             else if (sec_i != -1) */
/*             { */
/*                 if (nums[i] > nums[sec_i]) */
/*                     sec_i = i; */
/*             } */
/*         } */
/*         r[0] = max; */

/*         for (; i < numsSize; i ++) */
/*         { */
/*             if (i < max_i + k) */
/*                 r[i - k] = max; */
/*             else */
/*             { */
/*             } */
/*         } */
/*     } */
/*     return r; */
/* } */
