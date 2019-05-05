struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize)
{
    struct Interval* new = malloc(sizeof(struct Interval) * (intervalsSize + 1));

    bool done = false;
    int c = 0;

    for(int i = 0; i < intervalsSize;)
    {
        int s = intervals[i].start;
        int e = intervals[i].end;

        if (s > newInterval.end || e < newInterval.start)
        {
            if (s > newInterval.end && !done)
            {
                new[c].start = newInterval.start;
                new[c].end = newInterval.end;
                c ++;
                done = true;
            }

            new[c].start = s;
            new[c].end = e;
            c ++;
            i ++;
        }
        else if (!done)
        {
            s = s > newInterval.start ? newInterval.start : s;
            e = e > newInterval.end ? e : newInterval.end;

            int j = i + 1;
            for(; j < intervalsSize; j ++)
            {
                if (intervals[j].start <= e)
                    e = e > intervals[j].end ? e : intervals[j].end;
                else
                    break;
            }
            new[c].start = s;
            new[c].end = e;
            c ++;
            i = j;
            done = true;
        }
    }

    if (done == false)
    {
        new[c].start = newInterval.start;
        new[c].end = newInterval.end;
        c ++;
    }

    *returnSize = c;
    return new;
}
