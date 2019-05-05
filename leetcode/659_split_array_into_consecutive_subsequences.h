// PEEK HINT !!!!!!!
// similar with 846. Hand of Straights : not true
// similar with top k frequent elements
// peek hint ? heap ?
// learn a lot
// can handle negative number ?
// how to handle greedy !!!!!! just encode the matched size
// find better solution !!!
void bHeap(long* heap, int h)
{
    int x = 0;
    long p = heap[0];

    while (x * 2 + 1 < h)
    {
        long l = heap[x * 2 + 1];
        long r = l;
        if (x * 2 + 2 < h)
            r = heap[x * 2 + 2];

        if (l <= r)
        {
            if (p <= l)
                return;
            heap[x] = l;
            heap[x * 2 + 1] = p;
            x = x * 2 + 1;
        }
        else
        {
            if (p <= r)
                return;
            heap[x] = r;
            heap[x * 2 + 2] = p;
            x = x * 2 + 2;
        }
    }
}

bool isPossible(int* nums, int numsSize)
{
    int hi = 0;
    long* heap = malloc(sizeof(long) * numsSize / 2);

    for (int i = 0; i < numsSize; i ++)
    {
        long n = nums[i];

        while (hi)
        {
            long t = heap[0];
            // be careful about convert here !!!
            int te = (t >> 32) & 0xFFFFFFFF;
            int ts = t & 0xFFFFFFFF;

            if (n == te + 1)
            {
                heap[0] = (n & 0xFFFFFFFF) << 32 | (ts + 1);
                bHeap(heap, hi);
                break;
            }
            else if (n == te)
            {
                long t = (n & 0xFFFFFFFF) << 32 | 1; // be careful, it's C !!!
                heap[hi ++] = t;

                int h = hi - 1;
                while (h)
                {
                    int p = (h - 1) / 2;
                    if (heap[p] <= t)
                        break;
                    heap[h] = heap[p];
                    heap[p] = t;
                    h = p;
                }
                break;
            }
            else
            {
                if (ts < 3)
                    return false;

                heap[0] = heap[-- hi];
                bHeap(heap, hi);
            }
        }

        if (hi == 0)
            heap[hi ++] = (n & 0xFFFFFFFF) << 32 | 1; // be careful, it's C !!!
    }

    for (int i = 0; i < hi; i ++)
    {
        long t = heap[i];
        int ts = t & 0xFFFFFFFF;
        if (ts < 3)
            return false;
    }

    return true;
}
