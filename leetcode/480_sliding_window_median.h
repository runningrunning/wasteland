// more careful
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void rHeap_max(int* heap, int hi, int* nums)
{
    int x = 0;
    int p = heap[x];

    while (x * 2 + 1 < hi)
    {
        int l = heap[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (nums[l] >= nums[r]) // compare with the nums
        {
            if (nums[p] >= nums[l])
                return;

            heap[x] = l;
            heap[x * 2 + 1] = p;
            x = x * 2 + 1;
        }
        else
        {
            if (nums[p] >= nums[r])
                return;

            heap[x] = r;
            heap[x * 2 + 2] = p;
            x = x * 2 + 2;
        }
    }
}

void rHeap_min(int* heap, int hi, int* nums)
{
    int x = 0;
    int p = heap[x];

    while (x * 2 + 1 < hi)
    {
        int l = heap[x * 2 + 1];
        int r = l;

        if (x * 2 + 2 < hi)
            r = heap[x * 2 + 2];

        if (nums[l] <= nums[r])  // compare with nums
        {
            if (nums[p] <= nums[l])
                return;

            heap[x] = l;
            heap[x * 2 + 1] = p;
            x = x * 2 + 1;
        }
        else
        {
            if (nums[p] <= nums[r])
                return;

            heap[x] = r;
            heap[x * 2 + 2] = p;
            x = x * 2 + 2;
        }
    }
}

int dHeap_max(int* heap, int hi, int* nums, int r)
{
    while ((hi >= 0) && heap[0] <= r)
    {
        heap[0] = heap[-- hi];
        rHeap_max(heap, hi, nums);
    }
    return hi;
}

int dHeap_min(int* heap, int hi, int* nums, int r)
{
    while ((hi >= 0) && heap[0] <= r)
    {
        heap[0] = heap[-- hi];
        rHeap_min(heap, hi, nums);
    }
    return hi;
}

void aHeap(int* heap, int hi, int* nums, int v, bool max)
{
    heap[hi] = v;

    if (!hi)
        return;

    while (hi)
    {
        int p = (hi - 1) / 2;

        if (max)
        {
            if (nums[heap[p]] >= nums[v])
                return;
        }
        else
        {
            if (nums[heap[p]] <= nums[v])
                return;
        }

        heap[hi] = heap[p];
        heap[p] = v;
        hi = p;
    }
}

double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    *returnSize = 0;

    if (!nums || !numsSize)
        return NULL;

    *returnSize = numsSize - k + 1;
    double *r = malloc(sizeof(double) * numsSize);

    if (k == 1)
    {
        for (int i = 0; i < numsSize; i ++)
            r[i] = (double) nums[i];
    }
    else if (k == 2)
    {
        for (int i = 0; i < numsSize - 1; i ++)
            r[i] = ((double) nums[i] + (double) nums[i + 1]) / 2.0;
    }
    else
    {
        int max_s = 256;
        int max_i = 0;
        int max_r = 0;
        int* max_heap = malloc(sizeof(int) * max_s);;

        int min_s = 256;
        int min_i = 0;
        int min_r = 0;
        int* min_heap = malloc(sizeof(int) * min_s);

        char* is_min = malloc(numsSize);

        for (int i = 0; i < k - 1; i ++)
        {
            int v = i;
            int x = nums[i];
            if (max_i >= min_i)
            {
                if (max_i && x < nums[max_heap[0]])
                {
                    v = max_heap[0];
                    max_heap[0] = i;
                    is_min[i] = 0;
                    rHeap_max(max_heap, max_i, nums);
                }

                if (min_i == min_s)
                {
                    min_s *= 2;
                    min_heap = realloc(min_heap, sizeof(int) * min_s);
                }

                is_min[v] = 1;
                aHeap(min_heap, min_i, nums, v, false);
                min_i ++;
            }
            else
            {
                if (x > nums[min_heap[0]])
                {
                    v = min_heap[0];
                    min_heap[0] = i;
                    is_min[i] = 1;
                    rHeap_min(min_heap, min_i, nums);
                }

                if (max_i == max_s)
                {
                    max_s *= 2;
                    max_heap = realloc(max_heap, sizeof(int) * max_s);
                }

                is_min[v] = 0;
                aHeap(max_heap, max_i, nums, v, true);
                max_i ++;
            }
        }

        min_r = min_i;
        max_r = max_i;

        for (int i = k - 1; i < numsSize; i ++)
        {
            int v = i;
            int x = nums[i];

            if (i - k >= 0)
            {
                if (is_min[i - k])
                    min_r --;
                else
                    max_r --;
            }

            if (max_r >= min_r)
            {
                if (x < nums[max_heap[0]])
                {
                    v = max_heap[0];
                    max_heap[0] = i;
                    is_min[i] = 0;
                    rHeap_max(max_heap, max_i, nums);
                }

                if (min_i == min_s)
                {
                    min_s *= 2;
                    min_heap = realloc(min_heap, sizeof(int) * min_s);
                }

                is_min[v] = 1;
                aHeap(min_heap, min_i, nums, v, false);
                min_i ++;
                min_r ++;
            }
            else
            {
                if (x > nums[min_heap[0]])
                {
                    v = min_heap[0];
                    min_heap[0] = i;
                    is_min[i] = 1;
                    rHeap_min(min_heap, min_i, nums);
                }

                if (max_i == max_s)
                {
                    max_s *= 2;
                    max_heap = realloc(max_heap, sizeof(int) * max_s);
                }

                is_min[v] = 0;
                aHeap(max_heap, max_i, nums, v, true);
                max_i ++;
                max_r ++;
            }

            min_i = dHeap_min(min_heap, min_i, nums, i - k);
            max_i = dHeap_max(max_heap, max_i, nums, i - k);

            if (k & 1)
                r[i - k + 1] = (double) (min_r > max_r ? nums[min_heap[0]] : nums[max_heap[0]]);
            else
                r[i - k + 1] = ((double) nums[min_heap[0]] + (double) nums[max_heap[0]]) / 2.0;
        }
    }
    return r;
}
