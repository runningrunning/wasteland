// balance tree, how to or max heap, min heap
typedef struct {
    int max_s;
    int max_i;
    int* max_heap; // left part
    int min_s;
    int min_i;
    int* min_heap; // right part
} MedianFinder;

void aHeap(int* heap, int v, int i, bool max)
{
    heap[i] = v;

    if (!i)
        return;

    while (i)
    {
        int p = (i - 1) / 2;

        if (max)
        {
            if (heap[p] >= heap[i])
                return;
        }
        else
        {
            if (heap[p] <= heap[i])
                return;
        }

        heap[i] = heap[p];
        heap[p] = v;

        i = p;
    }
}

void rHeap_min(int* heap, int i)
{
    int x = 0;
    int v = heap[x];
    while (x * 2 + 1 < i)
    {
        int l = heap[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < i)
            r = heap[x * 2 + 2];

        if (l <= r)
        {
            if (v <= l)
                return;
            heap[x] = l;
            heap[x * 2 + 1] = v;
            x = x * 2 + 1;
        }
        else
        {
            if (v <= r)
                return;
            heap[x] = r;
            heap[x * 2 + 2] = v;
            x = x * 2 + 2;
        }
    }
}

void rHeap_max(int* heap, int i)
{
    int x = 0;
    int v = heap[x];

    while (x * 2 + 1 < i)
    {
        int l = heap[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < i)
            r = heap[x * 2 + 2];

        if (l >= r)
        {
            if (v >= l)
                return;
            heap[x] = l;
            heap[x * 2 + 1] = v;
            x = x * 2 + 1;
        }
        else
        {
            if (v >= r)
                return;
            heap[x] = r;
            heap[x * 2 + 2] = v;
            x = x * 2 + 2;
        }
    }
}

/** initialize your data structure here. */
MedianFinder* medianFinderCreate() {
    MedianFinder* m = malloc(sizeof(MedianFinder));
    m->max_i = 0;
    m->max_s = 256;
    m->max_heap = malloc(sizeof(int) * m->max_s);
    m->min_i = 0;
    m->min_s = 256;
    m->min_heap = malloc(sizeof(int) * m->min_s);
    return m;
}

void medianFinderAddNum(MedianFinder* m, int num)
{
    if (m)
    {
        int val = num;

        if (m->max_i >= m->min_i)
        {
            if (m->max_i && (num < m->max_heap[0]))
            {
                val = m->max_heap[0];
                m->max_heap[0] = num;
                rHeap_max(m->max_heap, m->max_i);
            }

            if (m->min_i == m->min_s)
            {
                m->min_s *= 2;
                m->min_heap = realloc(m->min_heap, sizeof(int) * m->min_s);
            }

            aHeap(m->min_heap, val, m->min_i, false);
            m->min_i ++;
        }
        else
        {
            if (num > m->min_heap[0])
            {
                val = m->min_heap[0];
                m->min_heap[0] = num;
                rHeap_min(m->min_heap, m->min_i);
            }

            if (m->max_i == m->max_s)
            {
                m->max_s *= 2;
                m->max_heap = realloc(m->max_heap, sizeof(int) * m->max_s);
            }

            aHeap(m->max_heap, val, m->max_i, true);
            m->max_i ++;
        }
    }
}

double medianFinderFindMedian(MedianFinder* m)
{
    if (m)
    {
        if (!m->max_i && !m->min_i)
            return 0.0;

        if ((m->max_i + m->min_i) & 1)
            return (double) (m->max_i > m->min_i ? m->max_heap[0] : m->min_heap[0]);
        else
            return (((double) m->max_heap[0]) + ((double) m->min_heap[0])) / 2.0;
    }
    return 0.0;
}

void medianFinderFree(MedianFinder* obj) {
    if (obj)
    {
        free(obj->max_heap);
        free(obj->min_heap);
        free(obj);
    }
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * struct MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 * double param_2 = medianFinderFindMedian(obj);
 * medianFinderFree(obj);
 */
