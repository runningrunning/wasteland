// segment tree or heap
// write segment tree with self balance
// TODO segment tree

/* segment tree version */
struct _TN {
    int n; // how many users
    int s; // start
    int e; // end
    int p; // random for balancing
    struct _TN* l;
    struct _TN* r;
};

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
}

// not heap at all, just two sorted array
/* two sorted array version */
/*
int comp_s(const void* a, const void* b)
{
    int* ta = *((int**)a);
    int* tb = *((int**)b);
    return ta[1] - tb[1];
}

int comp_e(const void* a, const void* b)
{
    int* ta = *((int**)a);
    int* tb = *((int**)b);
    return ta[2] - tb[2];
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
    int** ends = malloc(sizeof(int*) * tripsSize);
    memcpy(ends, trips, sizeof(int*) * tripsSize);
    qsort(trips, tripsSize, sizeof(int*), comp_s);
    qsort(ends, tripsSize, sizeof(int*), comp_e);

    int s = -1;
    int c = 0;
    int ei = 0;

    for (int i = 0; i < tripsSize; i ++)
    {
        s = trips[i][1];
        c += trips[i][0];

        while (ei < tripsSize && s >= ends[ei][2])
            c -= ends[ei ++][0];

        if (c > capacity)
            return false;
    }
    return true;
}
*/

/* heap */
/*
int comp(const void* a, const void* b)
{
    int* ta = *((int**)a);
    int* tb = *((int**)b);

    if (ta[1] != tb[1])
        return ta[1] - tb[1];

    return ta[2] - tb[2];
}

int oheap(int* heap, int hi)
{
    int o = heap[0];
    heap[0] = heap[-- hi];

    int x = 0;

    while (x * 2 + 1 < hi)
    {
        int lv = heap[x * 2 + 1];
        int rv = lv;
        if (x * 2 + 2 < hi)
            rv = heap[x * 2 + 2];

        if (lv <= rv)
        {
            if (heap[x] <= lv)
                break;
            heap[x * 2 + 1] = heap[x];
            heap[x] = lv;
            x = x * 2 + 1;
        }
        else
        {
            if (heap[x] <= rv)
                break;
            heap[x * 2 + 2] = heap[x];
            heap[x] = rv;
            x = x * 2 + 2;
        }
    }
    return o;
}

void iheap(int* heap, int hi, int v)
{
    heap[hi] = v;
    int x = hi;

    while (x)
    {
        int p = (x - 1) / 2;

        if (heap[p] <= v)
            break;
        heap[x] = heap[p];
        heap[p] = v;
        x = p;
    }
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
    qsort(trips, tripsSize, sizeof(int*), comp);
    int cur = 0;
    int hi = 0;
    int* heap = malloc(sizeof(int) * tripsSize);

    for (int i = 0; i < tripsSize; i ++)
    {
        int* t = trips[i];
        int n = t[0];
        int s = t[1];
        int e = t[2] << 16 | n;

        while(hi && (heap[0] >> 16) <= s)
        {
            int x = oheap(heap, hi --);
            cur -= x & 0xFFFF;
        }

        if (cur + n > capacity)
            return false;

        cur += n;
        iheap(heap, hi ++, e);
    }

    return true;
}
*/
