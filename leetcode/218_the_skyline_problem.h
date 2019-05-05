// stupid code error, careful !!!!!
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void aHeap(long* heap, int hi, long v)
{
    heap[hi] = v;
    if (!hi)
        return;

    while (hi)
    {
        int p = (hi - 1) / 2;

        if (heap[p] >= v)
            return;

        heap[hi] = heap[p];
        heap[p] = v;
        hi = p;
    }
}

long dHeap(long* heap, int hi)
{
    long t = heap[0];
    hi --;
    heap[0] = heap[hi];

    int x = 0;
    long p = heap[x];

    while (x * 2 + 1 < hi)
    {
        long l = heap[x * 2 + 1];
        long r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l >= r)
        {
            if (l <= p)
                break;
            heap[x] = l;
            heap[x * 2 + 1] = p;
            x = x * 2 + 1;
        }
        else
        {
            if (r <= p)
                break;
            heap[x] = r;
            heap[x * 2 + 2] = p;
            x = x * 2 + 2;
        }
    }

    return t;
}

int rHeap(long* heap, int hi, int h)
{
    while (hi && ((heap[0] & 0xFFFFFFFF) <= h))
    {
        dHeap(heap, hi);
        hi --;
    }
    return hi;
}

int** getSkyline(int** buildings, int buildingsRowSize, int buildingsColSize, int* returnSize)
{
    *returnSize = 0;

    if (!buildings || !buildingsRowSize || !buildingsColSize)
        return NULL;

    int ri = 0;
    int** rs = NULL;

    int hi = 0;
    long* heap = malloc(sizeof(long) * 256);

    int prx = 0;
    int prh = 0;

    for (int i = 0; i < buildingsRowSize; i ++)
    {
        long x = buildings[i][0];
        long y = buildings[i][1];
        long h = buildings[i][2];

        while (hi && (x > (heap[0] & 0xFFFFFFFF)))
        {
            long t = dHeap(heap, hi --);
            hi = rHeap(heap, hi, t & 0xFFFFFFFF);
            rs = realloc(rs, sizeof(int*) * (ri + 1));
            rs[ri] = malloc(sizeof(int) * 2);
            rs[ri][0] = t & 0xFFFFFFFF;
            rs[ri][1] = hi ? (heap[0] >> 32) : 0;
            ri ++;
        }

        if (!hi || (h > (heap[0] >> 32)))
        {
            if (!ri || prx < x)
            {
                rs = realloc(rs, sizeof(int*) * (ri + 1));
                rs[ri] = malloc(sizeof(int) * 2);
                rs[ri][0] = x;
                rs[ri][1] = h;
                prx = x;
                prh = h;
                ri ++;
            }
            else if (prx == x)
            {
                if (prh < h)
                {
                    rs[ri - 1][1] = h;
                    prh = h;
                }
            }
        }
        else
        {
            if (h == (heap[0] >> 32))
            {
                int e = heap[0] & 0xFFFFFFFF;
                heap[0] = (h << 32) | (e >= y ? e : y);
                continue;
            }
            else if (!(y > (heap[0] & 0xFFFFFFFF)))
                continue;
        }

        // add y, h
        if (!((hi + 1) % 256))
            heap = realloc(heap, sizeof(long) * (hi + 257));

        aHeap(heap, hi, h << 32 | y);
        hi ++;
    }

    while (hi)
    {
        long t = dHeap(heap, hi --);
        hi = rHeap(heap, hi, t & 0xFFFFFFFF);
        rs = realloc(rs, sizeof(int*) * (ri + 1));
        rs[ri] = malloc(sizeof(int) * 2);
        rs[ri][0] = t & 0xFFFFFFFF;
        rs[ri][1] = hi ? (heap[0] >> 32) : 0;
        ri ++;
    }

    free(heap);
    *returnSize = ri;
    return rs;
}
