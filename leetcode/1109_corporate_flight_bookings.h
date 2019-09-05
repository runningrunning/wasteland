// brilliant new solution ~!!!
// segment tree or better solution
// simple heap should be enough
// or just simple sort this array two times, one from the start, the other one from the end
// worst code beat zero
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comp_s(const void* a, const void* b)
{
    int* pa = *((int**)a);
    int* pb = *((int**)b);
    return pa[0] - pb[0];
}

int comp_e(const void* a, const void* b)
{
    int* pa = *((int**)a);
    int* pb = *((int**)b);
    return pa[1] - pb[1];
}

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    qsort(bookings, bookingsSize, sizeof(int*), comp_s);
    int** ends = malloc(sizeof(int*) * bookingsSize);
    memcpy(ends, bookings, sizeof(int*) * bookingsSize);
    qsort(ends, bookingsSize, sizeof(int*), comp_e);

    int* r = malloc(sizeof(int) * n);
    int c = 0;
    int out = 0;
    int in = 0;

    for (int i = 0; i < n; i ++)
    {
        int f = i + 1;

        while (out < bookingsSize && f > ends[out][1])
            c -= ends[out++][2];

        while (in < bookingsSize && f >= bookings[in][0])
            c += bookings[in ++][2];
        r[i] = c;
    }

    *returnSize = n;
    return r;
}


// heap version
/*
void _out(int** heap, int hi)
{
    heap[0] = heap[-- hi];
    int x = 0;

    while (x * 2 + 1 < hi)
    {
        int* l = heap[x * 2 + 1];
        int* r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l[1] <= r[1])
        {
            if (l[1] > heap[x][1])
                break;
            heap[x] = l;
            heap[x * 2 + 1] = heap[hi];
            x = x * 2 + 1;
        }
        else
        {
            if (r[1] > heap[x][1])
                break;
            heap[x] = r;
            heap[x * 2 + 2] = heap[hi];
            x = x * 2 + 2;
        }
    }
}

void _in(int** heap, int hi, int* v)
{
    heap[hi ++] = v;

    int x = hi - 1;
    while (x)
    {
        int p = (x - 1) / 2;
        if (heap[p][1] <= heap[x][1])
            break;
        heap[x] = heap[p];
        heap[p] = v;
        x = p;
    }
}

int comp(const void* a, const void* b)
{
    int* pa = *((int**)a);
    int* pb = *((int**)b);
    return pa[0] == pb[0] ? (pa[1] - pb[1]): (pa[0] - pb[0]);
}

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    qsort(bookings, bookingsSize, sizeof(int*), comp);

    int* r = malloc(sizeof(int) * n);
    int c = 0;
    int out = 0;
    int in = 0;

    int hi = 0;
    int** heap = malloc(sizeof(int*) * bookingsSize);

    for (int i = 0; i < n; i ++)
    {
        int f = i + 1;

        while (hi && f > heap[0][1])
        {
            c -= heap[0][2];
            _out(heap, hi --);
        }

        while (in < bookingsSize && f >= bookings[in][0])
        {
            c += bookings[in][2];
            _in(heap, hi ++, bookings[in ++]);
        }
        r[i] = c;
    }

    *returnSize = n;
    return r;
}
*/
