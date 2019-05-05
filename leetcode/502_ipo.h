// qsort is 10 time faster then my own fmc_sort stupid !!!
// optimize to know how to get the top K values from the heap, or any other way to do so
// sort optimization again, simple heap !!
//
// TODO: sort the idea about how to solve stocks problems in leetcode
// if use heap, there is no easy way to just get the top x Value for the partial heap
// simply greedy, not dp at all ?
// worst code beat 0, how to optimize this?
// it doesn't need that much in the heap, just top K ?

// heap ?
// similar 879 profitable scheme, not same, 879 is DP, this one is Heap or Greedy
// similar but no that

int comp(const void* a1, const void* a2)
{
    long t = (*((long*)a1)) - (*((long*)a2));
    if (t == 0)
        return 0;
    return t > 0l ? 1 : -1;
}

void fmc_sort(int* n, int s, int e, int* p)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = p[s];
        p[s] = p[e];
        p[e] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = p[s];
            p[s] = p[e];
            p[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = p[i];
            p[i] = p[e];
            p[e] = t;
        }
    }

    fmc_sort(n, cs, e - 1, p);
    fmc_sort(n, e + 1, ce, p);
}

void aHeap(int* h, int hi, int v)
{
    h[hi ++] = v;
    int x = hi - 1;

    while (x)
    {
        int p = (x - 1) / 2;
        if (h[p] >= h[x])
            break;

        h[p] ^= h[x];
        h[x] ^= h[p];
        h[p] ^= h[x];
        x = p;
    }
}

int rHeap(int* h, int hi)
{
    int v = h[0];
    h[0] = h[-- hi];

    int x = 0;
    int n = h[x];
    while (x * 2 + 1 < hi)
    {
        int l = h[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < hi)
            r = h[x * 2 + 2];

        if (l >= r)
        {
            if (l <= n)
                break;

            h[x * 2 + 1] = n;
            h[x] = l;
            x = x * 2 + 1;
        }
        else
        {
            if (r <= n)
                break;
            h[x * 2 + 2] = n;
            h[x] = r;
            x = x * 2 + 2;
        }
    }

    return v;
}

int findMaximizedCapital(int k, int W, int* Profits, int ProfitsSize, int* Capital, int CapitalSize)
{
    if (!k || !ProfitsSize || !CapitalSize)
        return 0;

    long* all = malloc(sizeof(long) * CapitalSize);

    for(int i = 0; i < CapitalSize; i ++)
        all[i] = ((long) Capital[i] << 32) | (long) Profits[i];

    qsort(all, CapitalSize, sizeof(long), comp);

    // fmc_sort(Capital, 0, CapitalSize - 1, Profits);
    int hi = 0;
    int* heap = malloc(sizeof(int) * ProfitsSize);

    int ci = 0;
    long cur = W;

    for (int i = 0; i < k; i ++)
    {
        long _max = ((cur + 1) << 32) - 1;
        while (ci < CapitalSize && all[ci] <= _max)
        {
            aHeap(heap, hi ++, all[ci] & 0xFFFFFFFF);
            ci ++;
        }

        if (!hi)
            break;

        cur += rHeap(heap, hi --);
    }
    return cur;
}
