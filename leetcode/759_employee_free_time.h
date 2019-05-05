/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void add_heap(int* heap, int hi, struct Interval** schedule)
{
    heap[hi] = hi << 8;
    if (hi == 0)
        return;

    int x = hi;

    while (x)
    {
        int p = (x - 1) / 2;

        int xi = heap[x] >> 8;
        int pi = heap[p] >> 8;

        if (schedule[xi][0].start >= schedule[pi][0].start)
            break;

        heap[x] = heap[p];
        heap[p] = hi << 8;
        x = p;
    }
}

struct Interval* remove_heap(int* heap, int* phi, struct Interval** schedule, int* scheduleColSizes)
{
    int hi = *phi;

    int xi = heap[0] >> 8;
    int xii = heap[0] & 0xFF;
    // printf("xi %d xii %d.\n", xi, xii);

    struct Interval* r = &schedule[xi][xii];

    if (xii == scheduleColSizes[xi] - 1)
    {
        hi --;
        heap[0] = heap[hi];
        xi = heap[0] >> 8;
        xii = heap[0] & 0xFF;
    }
    else
    {
        xii ++;
        heap[0] = (xi << 8) | xii;
    }

    int x = 0;
    int x_v = heap[0];
    int x_start = schedule[xi][xii].start;

    while (x * 2 + 1 < hi)
    {
        int l = x * 2 + 1;
        int li = heap[l]  >> 8;
        int lii = heap[l] & 0xFF;

        // printf("l %d li %d lii %d\n", l, li, lii);

        int r = l;
        int ri = li;
        int rii = lii;

        if (x * 2 + 2 < hi)
        {
            r = x * 2 + 2;
            ri = heap[r] >> 8;
            rii = heap[r] & 0xFF;
        }

        if (schedule[li][lii].start <= schedule[ri][rii].start)
        {
            if (x_start <= schedule[li][lii].start)
                break;

            // printf("x %d l %d %d %d %d.\n", x, l, heap[x], heap[l], x_v);
            heap[x] = heap[l];
            heap[l] = x_v;
            x = x * 2 + 1;
        }
        else
        {
            if (x_start <= schedule[ri][rii].start)
                break;
            heap[x] = heap[r];
            heap[r] = x_v;
            x = x * 2 + 2;
        }
    }

    *phi = hi;
    return r;
}

struct Interval* employeeFreeTime(struct Interval** schedule, int scheduleRowSize, int *scheduleColSizes, int* returnSize)
{
    int hi = 0;
    int* heap = malloc(sizeof(int) * scheduleRowSize);

    for (int i = 0; i < scheduleRowSize; i ++)
        add_heap(heap, i, schedule);

    hi = scheduleRowSize;

    int ri = 0;
    struct Interval* r = NULL;

    int min = -1;
    int max = -1;

    while (hi >= 0)
    {
        struct Interval* h = remove_heap(heap, &hi, schedule, scheduleColSizes);
        int s = h->start;
        int e = h->end;

        // printf("%d %d.\n", s, e);
        // out(heap, scheduleRowSize);

        if (min == -1 && max == -1)
        {
            min = s;
            max = e;
        }
        else
        {
            if (s > max)
            {
                r = realloc(r, sizeof(struct Interval) * (ri + 1));
                r[ri].start = max;
                r[ri].end = s;
                ri ++;

                min = s;
                max = e;
            }
            else
            {
                if (e > max)
                    max = e;
            }
        }
    }

    *returnSize = ri;
    return r;
}
