// heap

void in_heap(int* h, int s, int v)
{
    h[s] = v;

    while (s)
    {
        int p = (s - 1) / 2;
        if (h[p] < v)
        {
            h[s] = h[p];
            h[p] = v;
        }
        s = p;
    }
}

int out_heap(int* h, int s)
{
    int o = h[0];
    h[0] = h[-- s];
    int x = 0;

    while (x * 2 + 1 < s)
    {
        int lv = h[x * 2 + 1];
        int rv = lv;

        if (x * 2 + 2 < s)
            rv = h[x * 2 + 2];

        if (lv >= rv)
        {
            if (h[s] >= lv)
                break;
            h[x] = lv;
            x = x * 2 + 1;
        }
        else
        {
            if (h[s] >= rv)
                break;
            h[x] = rv;
            x = x * 2 + 2;
        }

        h[x] = h[s];
    }
    return o;
}

int lastStoneWeight(int* stones, int stonesSize)
{
    int hi = 0;
    int* heap = malloc(sizeof(int) * stonesSize);

    for (int i = 0; i < stonesSize; i ++)
        in_heap(heap, hi ++, stones[i]);

    while (hi > 1)
    {
        int a = out_heap(heap, hi --);
        int b = out_heap(heap, hi --);

        if (a != b)
            in_heap(heap, hi ++, a - b);
    }

    hi = hi ? heap[0] : 0;
    free(heap);
    return hi;
}
