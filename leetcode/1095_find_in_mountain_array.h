/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */
/*
typedef struct {
} MountainArray;
int get(MountainArray* m, int index)
{
    return 0;
}
int length(MountainArray* m)
{
    return 0;
}
*/

int fima_seq(int t, MountainArray* m, int s, int e, int sv, int ev, bool ascending)
{
    // skip compare when it's out
    if (ascending)
    {
        if (t < sv || t > ev)
            return -1;
    }
    else
    {
        if (t > sv || t < ev)
            return -1;
    }

    while (s < e)
    {
        int i = (s + e) / 2;
        int v = get(m, i);

        if (v == t)
            return i;

        if (ascending)
        {
            if (v < t)
                s = i + 1;
            else
                e = i;
        }
        else
        {
            if (v > t)
                s = i + 1;
            else
                e = i;
        }
    }
    return get(m, s) == t ? s : -1;
}

int fima_unknown(int t, MountainArray* m, int s, int e, int sv, int ev)
{
    if (s >= e)
        return -1;

    if (s == e - 1)
        return -1;

    int i = (s + e) / 2;
    int iv = get(m, i);

    if (s == e - 2)
    {
        if (iv != t)
            return -1;
    }

    int ai = i - 1;
    int bi = i + 1;
    int av = get(m, ai);
    int bv = get(m, bi);

    if (iv > av && iv > bv)
    {
        if (av == t)
            return ai;

        if (iv == t)
            return i;

        int x = fima_seq(t, m, s, ai, sv, av, true);

        if (x != -1)
            return x;

        if (bv == t)
            return bi;

        return fima_seq(t, m, bi, e, bv, ev, false);
    }

    if (av < iv && iv < bv)
    {
        if (av == t)
            return ai;

        if (iv == t)
            return i;

        if (bv == t)
            return bi;

        int x = fima_seq(t, m, s, ai, sv, av, true);

        if (x != -1)
            return x;

        return fima_unknown(t, m, bi, e, bv, ev);
    }

    // av > iv > bv
    int x = fima_unknown(t, m, s, ai, sv, av);

    if (x != -1)
        return x;

    if (av == t)
        return ai;

    if (iv == t)
        return i;

    if (bv == t)
        return bi;

    return fima_seq(t, m, bi, e, bv, ev, false);
}

int findInMountainArray(int target, MountainArray* mountainArr)
{
    int l = length(mountainArr);
    int s = 0;
    int e = l - 1;

    int sv = get(mountainArr, s);
    if (sv == target)
        return s;

    // be careful about corner case for ev
    int ev = get(mountainArr, e);
    if (l == 3)
        if (ev == target)
            return e;

    if (sv > target)
    {
        if (ev == target)
            return e;
        if (ev > target)
            return -1;
    }

    return fima_unknown(target, mountainArr, 0, l - 1, sv, ev);
}
