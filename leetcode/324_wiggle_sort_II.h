// TODO FIND THE SOLUTION !!! REWORK
// OPTIMIZE code and find why qsort is much faster than mine !!!, just copy the qsort code is faster !!
// how to do index changing mapping
// find median !!!
// TODO !!!!!!!!!!!!!! why QSORT IS FUCKING S FASTEST THAN MINE ???? !!!!!!!!!!
// for index 0 - 9, the largest difference indexing should be
// 4 9 3 8 2 7 1 6 0 5  DIFF is 4 and 6 !!!!!!!!!!!
// NOT 0 5 1 6 2 7 3 8 4 9  DIFF is 5 and 4 !!!!!!!!!
// wrong algorithm ? !!!
// why my qsort is that BAD !!!!
// stdlib qsort is MUCH FASTEST THAN MINE !!!!!

#define THRESHOLD_N 4

void _my_qsort2(int* n, int _s, int _e)
{

    if (_s >= _e)
        return;

    int os = _s;
    int oe = _e;

    int s = _s;
    int e = _e;
    // for insert sort
    if (_e - _s + 1 > THRESHOLD_N)
    {
        int si = 0;
        int stack[64];
        // printf("%d %d.\n", CHAR_BIT, sizeof(size_t));

        int max = 0;
        while (true)
        {
            // printf("= si is %d.\n", si);

            int t;
            int m = s + (e - s + 1) / 2;

            if (n[m] < n[s])
            {
                t = n[m];
                n[m] = n[s];
                n[s] = t;
            }

            if (n[e] < n[m])
            {
                t = n[m];
                n[m] = n[e];
                n[e] = t;

                if (n[m] < n[s])
                {
                    t = n[m];
                    n[m] = n[s];
                    n[s] = t;
                }
            }

            int cs = s;
            int ce = e;

            while (s < e)
            {
                while (n[s] < n[m])
                    s ++;
                while (n[e] > n[m])
                    e --;

                if (s == e)
                    break;

                t = n[s];
                n[s] = n[e];
                n[e] = t;

                if (s == m)
                    m = e;
                else if (e == m)
                    m = s;
                s ++;
                e --;
            }

            // brilliant part to save stack size, always put the largest part in the stack !!
            if (m - cs <= THRESHOLD_N)
            {
                if (ce - m <= THRESHOLD_N)
                {
                    if (!si)
                        break;

                    e = stack[-- si];
                    s = stack[-- si];
                }
                else
                {
                    s = m + 1;
                    e = ce;
                }
            }
            else if (ce - m <= THRESHOLD_N)
            {
                s = cs;
                e = m - 1;
            }
            else if (m - cs < ce - m)
            {
                stack[si ++] = m + 1;
                stack[si ++] = ce;

                s = cs;
                e = m - 1;
            }
            else
            {
                stack[si ++] = cs;
                stack[si ++] = m - 1;

                s = m + 1;
                e = ce;
            }
        }
    }

    s = os;
    e = oe;

    int th = e < (THRESHOLD_N - 1) ? e : (THRESHOLD_N - 1);
    int min_i = 0;
    for (int i = 1; i <= th; i ++)
        if (n[i] < n[min_i])
            min_i = i;

    int t;
    if (min_i)
    {
        t = n[0];
        n[0] = n[min_i];
        n[min_i] = t;
    }

    int i = 1;
    while (i <= e)
    {
        int t = i - 1;
        while (n[i] < n[t])
            t --;

        if (t != i - 1)
        {
            int tr = i - 1;
            int c = n[i];
            while (tr != t)
            {
                n[tr + 1] = n[tr];
                tr --;
            }
            n[t + 1] = c;
        }

        i ++;
    }

    for (int i = 2; i <= e; i ++)
    {
        if (n[i] >= n[i - 1])
            continue;

        int t = n[i];
        int x = i - 1;

        while (n[x] > t)
        {
            n[x + 1] = n[x];
            x --;
        }
        n[x + 1] = t;
    }
}

void wiggleSort(int* nums, int numsSize)
{
    int n = 0;
    _my_qsort2(nums, 0, numsSize - 1);

    int* r = malloc(sizeof(int) * numsSize);
    int s = numsSize - 1;
    for (int i = 1; i < numsSize; i += 2)
    {
        r[i] = nums[s --];
    }

    s = (numsSize - 1) / 2;
    for (int i = 0; i < numsSize; i += 2)
    {
        r[i] = nums[s --];
    }

    memcpy(nums, r, sizeof(int) * numsSize);
}
