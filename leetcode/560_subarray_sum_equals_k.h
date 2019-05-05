// find another better solutions !
// !!!! CORNER CASE corner case, can not be the last one
void sas_sort(int* n, int s, int e, int* id)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

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
            t = n[s];
            n[s] = n[e];
            n[e] = t;

            t = id[s];
            id[s] = id[e];
            id[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = id[i];
            id[i] = id[e];
            id[e] = t;
        }
    }

    sas_sort(n, cs, e - 1, id);
    sas_sort(n, e + 1, ce, id);
}

/* no hash or map, just plan algorithm */
/* HASH TABLE or MAP */
// this time just remove from the first ?
int subarraySum(int* nums, int numsSize, int k)
{
    if (!nums || !numsSize)
        return 0;

    int* t = malloc(sizeof(int) * numsSize);
    int* id = malloc(sizeof(int) * numsSize);

    id[0] = 0;
    t[0] = nums[0];

    if (numsSize == 1)
        return nums[0] == k ? 1 : 0;

    for (int i = 1; i < numsSize; i ++)
    {
        id[i] = i;
        t[i] = nums[i] + t[i - 1];
    }

    int sum = t[numsSize - 1];
    sas_sort(t, 0, numsSize - 1, id);

    int s, e;
    int all = 0;
    int x = sum - k - nums[numsSize - 1];
    if (numsSize > 2)
    {

        for (int j = numsSize - 2; j >= 1; j --)
        {
            // find another part
            s = 0;
            e = numsSize - 1;

            while (s < e)
            {
                int m = (s + e) / 2;
                if (t[m] < x)
                    s = m + 1;
                else
                    e = m;
            }

            if (t[s] == x)
            {
                for (int y = s; y < numsSize; y ++)
                {
                    if (t[y] != x)
                        break;
                    if (id[y] < j)
                        all ++;
                }
            }
            x -= nums[j];
        }
    }


    s = 0;
    e = numsSize - 1;
    x = k;

    while (s < e)
    {
        int m = (s + e) / 2;
        if (t[m] < x)
            s = m + 1;
        else
            e = m;
    }

    for (int y = s; y < numsSize ; y ++)
    {
        if (t[y] != x)
            break;
        all ++;
    }


    s = 0;
    e = numsSize - 1;
    x = sum - k;

    while (s < e)
    {
        int m = (s + e) / 2;
        if (t[m] < x)
            s = m + 1;
        else
            e = m;
    }

    for (int y = s; y < numsSize; y ++)
    {
        if (t[y] != x)
            break;
        // !!!! corner case, can not be the last one
        if (id[y] != numsSize - 1)
            all ++;
    }
    return all;
}
