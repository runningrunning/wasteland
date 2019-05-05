// TODO figure out how ?
// stupid wrong algorithm
// why it's so slow ? because of sort ????? yes, qsort will make this from 76ms - 36 ms
// try to use qsort, be careful about the qsort fucntion, as it's using long,
// so SHOULD NOT USE return  *((long*)elem1) - *((long*)elem2); as the result is overflow a INT VALUE
// use below comp method !!!!
// why it's so slow !!!! because there is simple method !!!, no hash at all ! still wrong algorithm

/* int comp (const void * elem1, const void * elem2) */
/* { */
/*     long f = *((long*)elem1); */
/*     long s = *((long*)elem2); */
/*     if (f > s) return  1; */
/*     if (f < s) return -1; */
/*     return 0; */
/* } */

void _sa(int* nums, int numsSize, int* ret, int* rs)
{
    int* sums_s = malloc(sizeof(int) * numsSize);
    int* sums_e = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        int s = i;
        int e = numsSize - 1 - i;

        sums_s[s] = nums[s];
        sums_e[e] = nums[e];

        if (i)
        {
            sums_s[s] += sums_s[s - 1];
            sums_e[e] += sums_e[e + 1];
        }
    }

    int all = sums_e[0];

    int size = 0;

    for (int i = 1; i < numsSize - 1; i ++)
    {
        if (sums_s[i] == sums_e[i])
            ret[size ++] = (all - nums[i]) / 2;
    }

    *rs = size;
}

bool splitArray(int* nums, int numsSize)
{
    int* sums_s = malloc(sizeof(int) * numsSize);
    int* sums_e = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        int s = i;
        int e = numsSize - 1 - i;

        sums_s[s] = nums[s];
        sums_e[e] = nums[e];

        if (i)
        {
            sums_s[s] += sums_s[s - 1];
            sums_e[e] += sums_e[e + 1];
        }
    }

    int* ts = malloc(sizeof(int) * numsSize);
    int* te = malloc(sizeof(int) * numsSize);

    for (int i = 3; i < numsSize - 3; i ++)
    {
        if (sums_s[i] == sums_e[i])
        {
            printf("same %d.\n", i);
            int tsi = 0;
            int tei = 0;
            _sa(nums, i, ts, &tsi);
            _sa(nums + i + 1, numsSize - i - 1, te, &tei);

            for (int j = 0; j < tsi; j ++)
                for (int k = 0; k < tei; k ++)
                    if (ts[j] == te[k])
                        return true;

        }
    }
    return false;
}

/*
#define PRIME 4099
bool splitArray(int* nums, int numsSize)
{
    if (numsSize < 7)
        return false;

    int* hash = calloc(sizeof(int), PRIME);
    int* hash_sum = calloc(sizeof(int), PRIME);
    int *sum = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        int x = nums[i];
        sum[i] = x;

        if (i) sum[i] += sum[i - 1];

        if (x < 0)
            x += 0x7FFFFFFF;
        x = x % PRIME;
        while (hash[x])
            x = (x + 1) % PRIME;
        hash[x] = i + 1;

        x = sum[i];
        if (x < 0)
            x += 0x7FFFFFFF;
        x = x % PRIME;
        while (hash_sum[x])
            x = (x + 1) % PRIME;
        hash_sum[x] = i + 1;
    }

    int all = sum[numsSize - 1];

    int x = 0;
    for (int i = numsSize - 1; i >= 6; i --)
    {
        x += nums[i];

        int find = x;

        if (find < 0)
            find += 0x7FFFFFFF;

        find %= PRIME;

        while (hash_sum[find])
        {
            if (sum[hash_sum[find] - 1] == x)
            {
                int is = hash_sum[find] - 1;

                if (is <= i - 6)
                {
                    int need = all - nums[i - 1] - nums[is + 1] - 4 * x;
                    int left = need;

                    if (left < 0)
                        left += 0x7FFFFFFF;

                    left %= PRIME;

                    while (hash[left])
                    {
                        if (nums[hash[left] - 1] == need)
                        {
                            int in = hash[left] - 1;

                            if (in > (is + 1) && in < (i - 1))
                                return true;
                        }
                        left = (left + 1) % PRIME;
                    }
                }
            }
            find = (find + 1) % PRIME;
        }
    }
    return false;
}
*/

/*
bool splitArray(int* nums, int numsSize)
{
    if (numsSize < 7)
        return false;

    int* hash = calloc(sizeof(int), PRIME);
    long *sum_s = malloc(sizeof(long) * numsSize);
    long *sum_e = malloc(sizeof(long) * numsSize);

    long pre_s = 0;
    long pre_e = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        int s = i;
        int e = numsSize - 1 - i;
        sum_s[s] = nums[s];
        sum_e[e] = nums[e];

        if (i)
        {
            sum_s[s] += pre_s;
            sum_e[e] += pre_e;
        }

        pre_s = sum_s[s];
        pre_e = sum_e[e];

        sum_s[s] = sum_s[s] << 32 | s;
        sum_e[e] = sum_e[e] << 32 | e;

        // printf("sum_e is %d at %d %d %d\n", sum_e[e] >> 32, e, i, numsSize);

        int x = nums[i];
        if (x < 0)
            x += 0x7FFFFFFF;
        x = x % PRIME;
        while (hash[x])
            x = (x + 1) % PRIME;
        hash[x] = i + 1;
    }

    long all = sum_s[numsSize - 1] >> 32;

    qsort(sum_s, numsSize, sizeof(long), comp);
    qsort(sum_e, numsSize, sizeof(long), comp);

    int si = 0;
    int ei = 0;

    while (si < numsSize && ei < numsSize)
    {
        long ss = sum_s[si] >> 32;
        long se = sum_e[ei] >> 32;

        // printf("ss %ld se %ld.\n", ss, se);
        if (ss == se)
        {
            int v = ss;
            int ti = ei;

            while (ti < numsSize && (sum_e[ti] >> 32) == v)
            {
                long is = sum_s[si] & 0xFFFFFFFF;
                long ie = sum_e[ti] & 0xFFFFFFFF;
                // printf("here %d %d %d.\n", ss, is, ie);

                if (ie >= is + 6)
                {
                    int need = all - nums[is + 1] - nums[ie - 1] - v * 4;

                    // printf("need is %d.\n", need);
                    int left = need;
                    if (left < 0)
                        left += 0x7FFFFFFF;
                    left %= PRIME;

                    while (hash[left])
                    {
                        if (nums[hash[left] - 1] == need)
                        {
                            int in = hash[left] - 1;

                            if (in > (is + 1) && in < (ie - 1))
                                return true;
                        }
                        left = (left + 1) % PRIME;
                    }
                }
                ti ++;
            }
            si ++;
        }
        else if (ss < se)
            si ++;
        else
            ei ++;
    }
    return false;
}
*/
/*
void _sa_sort(int* n, int s, int e, int* i)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = i[s];
        i[s] = i[e];
        i[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int j = s + 1; j <= e; j ++)
    {
        while (n[j] < n[s]) j ++;
        while (n[e] > n[s]) e --;

        if (j >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = i[s];
            i[s] = i[e];
            i[e] = t;
        }
        else
        {
            t = n[j];
            n[j] = n[e];
            n[e] = t;

            t = i[j];
            i[j] = i[e];
            i[e] = t;
        }
    }

    _sa_sort(n, cs, e - 1, i);
    _sa_sort(n, e + 1, ce, i);
}
bool splitArray(int* nums, int numsSize)
{
    if (numsSize < 7)
        return false;

    int* hash = calloc(sizeof(int), PRIME);
    int *sum_s = malloc(sizeof(int) * numsSize);
    int* id_s = malloc(sizeof(int) * numsSize);
    int *sum_e = malloc(sizeof(int) * numsSize);
    int* id_e = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        int s = i;
        int e = numsSize - 1 - i;
        id_s[i] = id_e[i] = i;

        sum_s[s] = nums[s];
        sum_e[e] = nums[e];

        if (i)
        {
            sum_s[s] += sum_s[s - 1];
            sum_e[e] += sum_e[e + 1];
        }

        int x = nums[i];
        if (x < 0)
            x += 0x7FFFFFFF;
        x = x % PRIME;
        while (hash[x])
            x = (x + 1) % PRIME;
        hash[x] = i + 1;
    }

    int all = sum_s[numsSize - 1];

    _sa_sort(sum_s, 0, numsSize - 1, id_s);
    _sa_sort(sum_e, 0, numsSize - 1, id_e);

    int si = 0;
    int ei = 0;

    while (si < numsSize && ei < numsSize)
    {
        if (sum_s[si] == sum_e[ei])
        {
            int v = sum_s[si];
            int ti = ei;
            while (ti < numsSize && sum_e[ti] == v)
            {
                int is = id_s[si];
                int ie = id_e[ti];

                if (ie >= is + 6)
                {
                    int need = all - nums[is + 1] - nums[ie - 1] - v * 4;
                    int left = need;
                    if (left < 0)
                        left += 0x7FFFFFFF;
                    left %= PRIME;

                    while (hash[left])
                    {
                        if (nums[hash[left] - 1] == need)
                        {
                            int in = hash[left] - 1;

                            if (in > (is + 1) && in < (ie - 1))
                                return true;
                        }
                        left = (left + 1) % PRIME;
                    }
                }
                ti ++;
            }
            si ++;
        }
        else if (sum_s[si] < sum_e[ei])
            si ++;
        else
            ei ++;
    }
    return false;
}
*/

/*
bool splitArray(int* nums, int numsSize)
{
    if (numsSize < 7)
        return false;

    int* hash = calloc(sizeof(int), PRIME);
    int *sum = malloc(sizeof(int) * numsSize);
    int* id = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i ++)
    {
        int x = nums[i];
        id[i] = i;
        sum[i] = x;

        if (i) sum[i] += sum[i - 1];

        if (x < 0)
            x += 0x7FFFFFFF;

        x = x % PRIME;

        while (hash[x])
            x = (x + 1) % PRIME;
        hash[x] = i + 1;
    }

    int all = sum[numsSize - 1];

    _sa_sort(sum, 0, numsSize - 1, id);

    int x = 0;
    for (int i = numsSize - 1; i >= 6; i --)
    {
        x += nums[i];

        int s = 0;
        int e = numsSize - 1;
        while (s < e)
        {
            int m = s + (e - s) / 2;

            if (sum[m] < x)
                s = m + 1;
            else
                e = m;
        }

        while (s < numsSize && sum[s] == x)
        {
            if (id[s] <= i - 6)
            {
                int need = all - nums[i - 1] - nums[id[s] + 1] - 4 * x;
                int left = need;

                if (left < 0)
                    left += 0x7FFFFFFF;

                left %= PRIME;

                while (hash[left])
                {
                    if (nums[hash[left] - 1] == need)
                    {
                        int in = hash[left] - 1;

                        if (in > (id[s] + 1) && in < (i - 1))
                            return true;
                    }
                    left = (left + 1) % PRIME;
                }
            }
            s ++;
        }
    }
    return false;
}
*/
