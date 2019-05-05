// min heap

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void aHeap(int** ns, long v, long* h, int hi)
{
    h[hi] = v;

    if (!hi)
        return;

    int x = v >> 32;

    while (hi)
    {
        int p = (hi - 1) >> 1;
        int px = h[p] >> 32;

        if (ns[px][0] <= ns[x][0])
            break;

        h[hi] = h[p];
        h[p] = v;
        hi = p;
    }
}

bool dHeap(int** ns, int* cs, long* heap, int hi, int* min, int* max)
{
    heap[0] ++;

    long th = heap[0];
    int tx = th >> 32;
    int ti = th & 0xFFFFFFFF;

    if (ti == cs[tx])
        return false;

    int t = ns[tx][ti];

    if (t > *max)
        *max = t;

    int x = 0;

    while (x * 2 + 1 < hi)
    {
        long l = heap[x * 2 + 1];
        long r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        int lx = l >> 32;
        int li = l & 0xFFFFFFFF;
        int lv = ns[lx][li];

        int rx = r >> 32;
        int ri = r & 0xFFFFFFFF;
        int rv = ns[rx][ri];

        if (lv <= rv)
        {
            if (lv >= t)
                break;

            heap[x] = heap[x * 2 + 1];
            heap[x * 2 + 1] = th;
            x = x * 2 + 1;
        }
        else
        {
            if (rv >= t)
                break;

            heap[x] = heap[x * 2 + 2];
            heap[x * 2 + 2] = th;
            x = x * 2 + 2;
        }
    }

    th = heap[0];
    tx = th >> 32;
    ti = th & 0xFFFFFFFF;
    *min = ns[tx][ti];
    return true;
}

int* smallestRange(int** nums, int numsRowSize, int *numsColSizes, int* returnSize) {
    *returnSize = 0;
    if (!numsRowSize)
        return NULL;

    int hi = 0;
    long* heap = malloc(sizeof(long) * numsRowSize);

    int* r = malloc(sizeof(int) * 2);
    *returnSize = 2;

    if (numsRowSize == 1)
    {
        r[1] = r[0] = nums[0][0];
        return r;
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < numsRowSize; i ++)
    {
        int t = nums[i][0];

        if (min > t)
            min = t;
        if (max < t)
            max = t;
        aHeap(nums, ((long) i) << 32, heap, hi ++);
    }

    r[0] = min;
    r[1] = max;

    while (dHeap(nums, numsColSizes, heap, hi, &min, &max))
    {
        if (max - min < r[1] - r[0])
        {
            r[0] = min;
            r[1] = max;
        }
    }

    return r;
}
