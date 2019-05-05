/* Have better solution ? */
/* Becareful about Interval Structure !!*/
void fri_sort(int* ss, int s, int e, int* si)
{
    if (s >= e)
        return;

    int t;
    if (ss[s] > ss[e])
    {
        t = ss[e];
        ss[e] = ss[s];
        ss[s] = t;

        t = si[e];
        si[e] = si[s];
        si[s] = t;
    }

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (ss[i] < ss[s]) i ++;
        while (ss[e] > ss[s]) e --;

        if (i >= e)
        {
            t = ss[e];
            ss[e] = ss[s];
            ss[s] = t;

            t = si[e];
            si[e] = si[s];
            si[s] = t;
        }
        else
        {
            t = ss[e];
            ss[e] = ss[i];
            ss[i] = t;

            t = si[e];
            si[e] = si[i];
            si[i] = t;
        }
    }

    fri_sort(ss, cs, e - 1, si);
    fri_sort(ss, e + 1, ce, si);
}

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

/*
int* findRightInterval(struct Interval* intervals, int intervalsSize, int* returnSize)
{
    *returnSize = 0;

    if (!intervals || !intervalsSize)
        return NULL;

    *returnSize = intervalsSize;
    int *r = malloc(sizeof(int) * intervalsSize);

    if (intervalsSize == 1)
    {
        r[0] = -1;
        return r;
    }

    int* ss = malloc(sizeof(int) * intervalsSize);
    int* si = malloc(sizeof(int) * intervalsSize);

    int* hs = malloc(sizeof(int) * intervalsSize);
    int* hi = malloc(sizeof(int) * intervalsSize);

    for (int i = 0; i < intervalsSize; i ++)
    {
        ss[i] = intervals[i].start;
        hs[i] = intervals[i].end;
        si[i] = i;
        hi[i] = i;
    }

    fri_sort(ss, 0, intervalsSize - 1, si);
    fri_sort(hs, 0, intervalsSize - 1, hi);

    int last = ss[intervalsSize - 1];

    int k = intervalsSize;
    int i = intervalsSize - 1;
    while (hs[i] > last)
    {
        r[hi[i]] = -1;
        i --;
    }

    while (i + 1)
    {
        while (ss[k - 1] >= hs[i])
            k --;
        r[hi[i]] = si[k];
        i --;
    }

    // for (int i = 0; i < intervalsSize; i ++)
    // {
    //     int t = intervals[i].end;

    //     if (t > last)
    //     {
    //         r[i] = -1;
    //         continue;
    //     }

    //     int s = 0;
    //     int e = intervalsSize - 1;

    //     while(s < e)
    //     {
    //         int m = s + (e - s) / 2;
    //         if (ss[m] < t)
    //             s = m + 1;
    //         else
    //             e = m;
    //     }
    //     r[i] = si[s];
    // }

    return r;
}
*/

int* findRightInterval(struct Interval* intervals, int intervalsSize, int* returnSize)
{
    *returnSize = 0;

    if (!intervals || !intervalsSize)
        return NULL;

    *returnSize = intervalsSize;
    int *r = malloc(sizeof(int) * intervalsSize);

    if (intervalsSize == 1)
    {
        r[0] = -1;
        return r;
    }

    int* ss = malloc(sizeof(int) * intervalsSize);
    int* si = malloc(sizeof(int) * intervalsSize);


    for (int i = 0; i < intervalsSize; i ++)
    {
        ss[i] = intervals[i].start;
        si[i] = i;
    }

    fri_sort(ss, 0, intervalsSize - 1, si);

    int last = ss[intervalsSize - 1];
    for (int i = 0; i < intervalsSize; i ++)
    {
        int t = intervals[i].end;

        if (t > last)
        {
            r[i] = -1;
            continue;
        }

        int s = 0;
        int e = intervalsSize - 1;

        while(s < e)
        {
            int m = s + (e - s) / 2;
            if (ss[m] < t)
                s = m + 1;
            else
                e = m;
        }
        r[i] = si[s];
    }

    return r;
}
