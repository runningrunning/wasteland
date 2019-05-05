// STUPID type is struct Interval* not struct Interval**
/*
void cam_sort(struct Interval* in, int s, int n)
{
    if (s >= e)
        return;

    struct Interval* t;
    if (in[s]->start > in[e]->start)
    {
        t = in[s];
        in[s] = in[e];
        in[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(in[i]->start < in[s]->start) i ++;
        while(in[e]->start > in[s]->start) e --;

        if (i >= e)
        {
            t = in[s];
            in[s] = in[e];
            in[e] = t;
        }
        else
        {
            t = in[i];
            in[i] = in[e];
            in[e] = t;
        }
    }

    cam_sort(in, cs, e - 1);
    cam_sort(in, e + 1, ce);
}

bool canAttendMeetings(struct Interval* intervals, int intervalsSize)
{
    if (!intervals || intervalsSize < 2)
        return true;

    cam_sort(intervals, 0, intervalsSize - 1);

    for (int i = 0; i < intervalsSize - 1; i ++)
    {
        if (intervals[i]->end > intervals[i + 1]->start)
            return false;
    }
    return true;
}
*/

void cam_sort(struct Interval* in, int s, int e)
{
    if (s >= e)
        return;

    struct Interval t;
    if (in[s].start > in[e].start)
    {
        t = in[s];
        in[s] = in[e];
        in[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(in[i].start < in[s].start) i ++;
        while(in[e].start > in[s].start) e --;

        if (i >= e)
        {
            t = in[s];
            in[s] = in[e];
            in[e] = t;
        }
        else
        {
            t = in[i];
            in[i] = in[e];
            in[e] = t;
        }
    }

    cam_sort(in, cs, e - 1);
    cam_sort(in, e + 1, ce);
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
bool canAttendMeetings(struct Interval* intervals, int intervalsSize)
{
    if (!intervals || intervalsSize < 2)
        return true;

    cam_sort(intervals, 0, intervalsSize - 1);

    for (int i = 0; i < intervalsSize - 1; i ++)
    {
        if (intervals[i].end > intervals[i + 1].start)
            return false;
    }
    return true;
}
