/* can not just use b_search to find the next one, when it's equal, it cause issues. */
/* minimize smallest heap ? */
/* use minimize heap */
/* HEAP */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

long ksp_heap_remove(long* ks, int kn, int* n1, int* n2)
{
    long r = ks[0];
    if (kn == 1)
        return r;

    ks[0] = ks[kn - 1];

    kn --;

    long x = ks[0];

    int s = n1[x >> 32] + n2[x & 0xFFFFFFFF];

    int h = 0;

    // must know whether the last is in kn
    while (h * 2 + 1 < kn)
    {
        long lx = ks[2 * h + 1];
        int ls = n1[lx >> 32] + n2[lx & 0xFFFFFFFF];

        long rx = lx;
        int rs = ls;

        if (2 * h + 2  < kn)
        {
            rx = ks[2 * h + 2];
            rs = n1[rx >> 32] + n2[rx & 0xFFFFFFFF];
        }

        if (ls <= rs)
        {
            if (s <= ls)
                break;

            ks[h] = lx;
            ks[2 * h + 1] = x;
            h = 2 * h + 1;
        }
        else
        {
            if (s <= rs)
                break;

            ks[h] = rx;
            ks[2 * h + 2] = x;
            h = 2 * h + 2;
        }
    }
    return r;
}

void ksp_heap_add(long* ks, int kn, int* n1, int* n2, long x)
{
    ks[kn ++] = x;

    int s = n1[x >> 32] + n2[x & 0xFFFFFFFF];

    int h = kn - 1;

    while (h > 0)
    {
        int p = (h - 1) / 2;
        long px = ks[p];
        int ps = n1[px >> 32] + n2[px & 0xFFFFFFFF];

        if (ps <= s)
            break;

        ks[h] = px;
        ks[p] = x;
        h = p;
    }
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int** columnSizes, int* returnSize)
{
    *returnSize = 0;
    if (!nums1 || !nums1Size || !nums2 || !nums2Size || !k)
        return NULL;

    k = nums1Size * nums2Size < k ? nums1Size * nums2Size : k;

    int* cs = malloc(sizeof(int) * k);
    int** r = malloc(sizeof(int*) * k);

    *returnSize = k;
    *columnSizes = cs;

    if (nums1Size == 1 || nums2Size == 1)
    {
        for (int i = 0; i < k; i ++)
        {
            cs[i] = 2;
            r[i] = malloc(sizeof(int) * 2);
            r[i][0] = nums1Size == 1 ? nums1[0] : nums1[i];
            r[i][1] = nums2Size == 1 ? nums2[0] : nums2[i];
        }
    }
    else
    {
        int* n1 = malloc(sizeof(int) * nums1Size);
        memset(n1, 0, sizeof(int) * nums2Size);
        n1[0] = 1;

        int ki = 1;
        long* ks = malloc(sizeof(long) * k * 2);
        ks[0] = 0;

        int i = 0;
        while (i < k)
        {
            long x = ksp_heap_remove(ks, ki --, nums1, nums2);
            long x1 = x >> 32;
            long x2 = x & 0xFFFFFFFF;
            cs[i] = 2;
            r[i] = malloc(sizeof(int) * 2);
            r[i][0] = nums1[x1];
            r[i][1] = nums2[x2];
            i ++;

            if (n1[x1] == x2 + 1 && x2 + 1 < nums2Size)
            {
                n1[x1] ++;
                x = x1 << 32 | (x2 + 1);
                ksp_heap_add(ks, ki ++, nums1, nums2, x);
            }

            if (x1 + 1 < nums1Size && n1[x1 + 1] == x2)
            {
                n1[x1 + 1] ++;
                x = (x1 + 1) << 32 | x2;
                ksp_heap_add(ks, ki ++, nums1, nums2, x);
            }
        }
    }
    return r;
}

