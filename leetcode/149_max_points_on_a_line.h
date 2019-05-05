// STUPID WRONG ALGORITHM !!
// HOW TO REPRESENT THE LINE in Computer, how to calculate line
// how to handle duplicate points here
// math !!
// corner case again and again
// stupid ERROR code !!
// try to use hash here ???
// just use stand library
// can not use the point of the x or y aix, use K d(x)/d(y)

// just write code here
// math only
// Brute-Force ???, just sort, it's enough
// how to represent a line
// corner cases !!
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 * }
 */

int comp(const void* a1, const void* a2)
{
    long t = (*((long*)a1)) - (*((long*)a2));
    if (t == 0)
        return 0;
    return t > 0l ? 1 : -1;
}

int compp(const void* a1, const void* a2)
{
    struct Point* pa = (struct Point*) a1;
    struct Point* pb = (struct Point*) a2;

    if (pa->x != pb->x)
        return pa->x < pb->x ?  - 1 : 1;

    if (pa->y == pb->y)
        return 0;

    return pa->y < pb->y ? - 1 : 1;
}

long gcd(long a, long b)
{
    long x = a % b;
    if (!x)
        return b;
    return gcd(b, x);
}

int maxPoints(struct Point* points, int pointsSize)
{
    if (pointsSize < 2)
        return pointsSize;

    qsort(points, pointsSize, sizeof(struct Point), compp);

    int ni = 0;
    int* ns = malloc(sizeof(int) * pointsSize);
    ns[ni] = 1;

    int mp = 0;

    for (int i = 1; i < pointsSize; i ++)
    {
        if (points[i].x == points[i - 1].x && points[i].y == points[i - 1].y)
        {
            ns[ni] ++;

            if (ns[ni] > mp)
                mp = ns[ni];
        }
        else
        {
            ++ ni;
            points[ni].x = points[i].x;
            points[ni].y = points[i].y;
            ns[ni] = 1;
        }
    }

    ni ++;

    int dp;
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri) / sizeof(pri[0]);

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp > 4 * pointsSize)
            break;
    }

    int pi = 0;
    int* hash = calloc(sizeof(int), dp);
    long* save = malloc(sizeof(long) * pointsSize * 2);

    int ki = 0;
    int* ks = malloc(sizeof(int) * pointsSize);


    for (int i = 0; i < ni; i ++)
    {
        ki = 0;
        pi = 0;

        for (int j = i + 1; j < ni; j ++)
        {

            long val;
            long x1 = points[i].x;
            long y1 = points[i].y;
            long x2 = points[j].x;
            long y2 = points[j].y;

            if (x1 == x2)
                val = x1;
            else if (y1 == y2)
                val = ((long) y1) << 32;
            else
            {
                long px = x1 - x2;
                long py = y1 - y2;

                long pd = 0;

                long pa = labs(px);
                long pb = labs(py);

                if (pa < pb)
                    pd = gcd(pb, pa);
                else
                    pd = gcd(pa, pb);

                px /= pd;
                py /= pd;

                val = labs(px) << 32 | labs(py);

                if (!((px < 0 && py < 0) || (px > 0 && py > 0)))
                    val = - val;
            }

            long k = val % dp;

            if (k < 0)
                k += dp;

            while (hash[k] && save[hash[k] - 1] != val)
                k = (k + 1) % dp;

            ks[ki ++] = k;

            if (hash[k])
                save[hash[k]] += ns[j];
            else
            {
                hash[k] = pi + 1;
                save[pi] = val;
                save[pi + 1] = ns[i] + ns[j];
                pi += 2;
            }
            if (save[hash[k]] > mp)
                mp = save[hash[k]];
        }

        for (int i = 0; i < ki; i ++)
            hash[ks[i]] = 0;
    }

    return mp;
}
