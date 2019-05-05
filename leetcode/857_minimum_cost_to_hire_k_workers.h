// any better solutions ?
// can find them all ?
// max heap ?

void mthw_sort(double* n, int s, int e, int* id)
{
    if (s >= e)
        return;

    int t;
    double d;

    if (n[s] > n[e])
    {
        d = n[s];
        n[s] = n[e];
        n[e] = d;

        t = id[s];
        id[s] = id[e];
        id[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            d = n[s];
            n[s] = n[e];
            n[e] = d;

            t = id[s];
            id[s] = id[e];
            id[e] = t;
        }
        else
        {
            d = n[i];
            n[i] = n[e];
            n[e] = d;

            t = id[i];
            id[i] = id[e];
            id[e] =t;
        }
    }
    mthw_sort(n, cs, e - 1, id);
    mthw_sort(n, e + 1, ce, id);
}

void aHeap(int* heap, int hi, int v)
{
    heap[hi] = v;

    int x = hi;

    while (x)
    {
        int p = (x - 1) / 2;

        if (heap[p] >= heap[x])
            break;

        heap[x] = heap[p];
        heap[p] = v;
        x = p;
    }
}

void nHeap(int* heap, int hi, int v)
{
    int x = 0;
    heap[0] = v;

    while (x * 2 + 1 < hi)
    {
        int l = heap[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (l >= r)
        {
            if (v >= l)
                break;

            heap[x] = l;
            heap[x * 2 + 1] = v;
            x = x * 2 + 1;
        }
        else
        {
            if (v >= r)
                break;
            heap[x] = r;
            heap[x * 2 + 2] = v;
            x = x * 2 + 2;
        }
    }
}

double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int K)
{
    int* id = malloc(sizeof(int) * qualitySize);
    double* ratio = malloc(sizeof(double) * qualitySize);

    for (int i = 0; i < qualitySize; i ++)
    {
        id[i] = i;
        ratio[i] = ((double) wage[i]) / ((double) quality[i]);
    }
    mthw_sort(ratio, 0, qualitySize - 1, id);

    int hi = 0;
    int* heap = malloc(sizeof(int) * (K + 2));

    int a = 0;
    for (int i = 0; i < K; i ++)
    {
        int q = quality[id[i]];
        a += q;
        aHeap(heap, i, q);
    }

    double min = ((double) a) * ratio[K - 1];
    for (int i = K; i < qualitySize; i ++)
    {
        int top = heap[0];
        int q = quality[id[i]];
        double new = ratio[i] * ((double) (a - top + q));
        if (min > new)
            min = new;
        a = a - top + q;
        nHeap(heap, K, q);
    }
    return min;
}
