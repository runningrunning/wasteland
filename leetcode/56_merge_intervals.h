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
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize)
{
    struct Interval** new = malloc(sizeof(struct Interval*) * intervalsSize);
    memset(new, 0, sizeof(struct Interval*) * intervalsSize);

    for(int i = 0; i < intervalsSize; i ++)
    {
        struct Interval* try = &intervals[i];
        int s = try->start;
        int e = try->end;

        for(int j = 0; j < i; j ++)
        {
            if (!new[j] || new[j]->start > e || new[j]->end < s)
                continue;

            s = s < new[j]->start ? s : new[j]->start;
            e = e > new[j]->end ? e : new[j]->end;
            new[j] = NULL;
        }

        new[i] = try;
        new[i]->start = s;
        new[i]->end = e;
    }

    int c = 0;

    for(int i = 0; i < intervalsSize; i ++)
    {
        if (new[i])
            c ++;
    }

    struct Interval* temp = malloc(sizeof(struct Interval) * c);
    *returnSize = c;

    int j = 0;
    for(int i = 0; i < intervalsSize; i ++)
    {
        if (new[i])
        {
            temp[j].start = new[i]->start;
            temp[j].end = new[i]->end;
            j ++;
        }
    }

    return temp;
}
*/

int comp(const void* a1, const void* a2)
{
    long t = ((*((long*)a1)) & ~0xFFFF) - ((*((long*)a2)) & ~0xFFFF);
    if (t == 0)
        return 0;
    return t > 0l ? 1 : -1;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize)
{
    long* all = malloc(sizeof(long) * intervalsSize);

    for(int i = 0; i < intervalsSize; i ++)
        all[i] = (((long) intervals[i].start) << 16) | ((long) i);

    qsort(all, intervalsSize, sizeof(long), comp);

    struct Interval* new = malloc(sizeof(struct Interval) * intervalsSize);

    int c = 0;
    for(int i = 0; i < intervalsSize;)
    {
        int si = all[i] & 0xFFFF;
        int e = intervals[si].end;

        int j = i + 1;
        for(; j < intervalsSize; j ++)
        {
            int sj = all[j] & 0xFFFF;
            if (intervals[sj].start <= e)
                e = e > intervals[sj].end ? e : intervals[sj].end;
            else
                break;
        }
        new[c].start = intervals[si].start;
        new[c].end = e;
        c ++;
        i = j;
    }

    *returnSize = c;
    return new;
}
