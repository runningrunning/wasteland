void cs3(int k, int* a, int s, int t, int* min, int* max, int** all, int n, int* cur)
{
    if (max[k] < t || min[k] > t)
        return;

    if (k > 2)
    {
        for (int i = s; i < 11 - k; i ++)
        {
            a[n - k] = i;
            cs3(k - 1, a, i + 1, t - i, min, max, all, n, cur);
        }
    }
    else
    {
        int e = 9;

        while(s < e)
        {
            int x = s + e;

            while (x > t && e > s + 1)
                x = s + -- e;

            while(x < t && s < e - 1)
                x = ++ s + e;
            if (x == t)
            {
                int* t = malloc(sizeof(int) * n);
                memcpy(t, a, sizeof(int) * n);
                t[n - 2] = s;
                t[n - 1] = e;

                all[*cur] = t;
                (*cur) ++;
                s ++;
                e --;
            }
            else
                break;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum3(int k, int n, int** columnSizes, int* returnSize)
{
    int min[] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};
    int max[] = {0, 9, 17, 24, 30, 35, 39, 42, 44, 45};

    if (!k || !n || min[k] > n || max[k] < n)
    {
        *returnSize = 0;
        return NULL;
    }

    int* cs = malloc(sizeof(int) * 256);
    int** ret = malloc(sizeof(int*) * 256);

    *columnSizes = cs;
    if (min[k] == n || max[k] == n || k == 1)
    {
        *returnSize = 1;
        cs[0] = k;
        ret[0] = malloc(sizeof(int) * k);
        if (k == 1)
            ret[0][0] = n;
        else
        {
            int a = min[k] == n ? 1 : (10 - k);
            for (int i = 0; i < k; i ++)
                ret[0][i] = a ++;
        }
    }
    else
    {
        int c[256] = {0};
        int cur = 0;
        cs3(k, c, 1, n, min, max, ret, k, &cur);
        for (int i = 0; i < cur; i ++)
            cs[i] = k;
        *returnSize = cur;
    }
    return ret;
}
