// use string compare algorithm ?

// Try string algorithm
int findLength(int* A, int ASize, int* B, int BSize)
{
    int ref[100] = {0};
    int start[100] = {0};

    int* t = malloc(sizeof(int) * ASize);
    memset(t, 0, sizeof(int) * ASize);

    for (int i = 0; i < ASize; i ++)
    {
        int rf = ref[A[i]];
        if (rf)
            t[rf - 1] = i + 1;
        else
            start[A[i]] = i + 1;
        ref[A[i]] = i + 1;
    }

    int ret = 0;

    for (int i = 0; i < BSize; i ++)
    {
        if (!start[B[i]])
            continue;

        if (i + ret >= BSize)
            break;

        int s = start[B[i]] - 1;

        while (s >= 0)
        {
            int ai = s;
            int bi = i;

            if (ai + ret >= ASize || bi + ret >= BSize)
                break;

            while (ai < ASize && bi < BSize && A[ai] == B[bi])
            {
                ai ++;
                bi ++;
            }

            if (ret < ai - s)
                ret = ai - s;

            s = t[s] - 1;
        }
    }

    return ret;
}

/*
// STUPID WRONG ALGORITHM
void fl_sort(int *n, int s, int e)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
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
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    fl_sort(n, cs, e - 1);
    fl_sort(n, e + 1, ce);
}

int findLength(int* A, int ASize, int* B, int BSize)
{
    if (A == B)
        return ASize;

    if (!A || !ASize || !B || !BSize)
        return 0;

    int* max = A;
    int maxl = ASize;
    int* min = B;
    int minl = BSize;

    if (ASize < BSize)
    {
        max = B;
        maxl = BSize;
        min = A;
        minl = ASize;
    }

    int ref[100] = {0};

    int* t = malloc(sizeof(int) * maxl);
    for (int i = 0; i < maxl; i ++)
        t[i] = max[i] << 16 | i;
    fl_sort(t, 0, maxl - 1);

    const int mask = 0xFFFF << 16;

    int pre = (t[0] & mask) - 1;
    for (int i = 0; i < maxl; i ++)
    {
        int cur = t[i] & mask;
        if (cur != pre)
            ref[cur >> 16] = (i + 1);
        pre = cur;
    }

    int ret = 0;
    for (int i = 0; i < minl; i ++)
    {
        int s = ref[min[i]];
        if (!s)
            continue;

        if (i + ret >= minl)
            break;

        s -= 1;
        while (s < maxl)
        {
            if ((t[s] >> 16) != min[i])
                break;

            int mini = i;
            int maxi = t[s] & 0xFFFF;

            if (mini + ret >= minl || maxi + ret >= maxl)
                break;

            while (maxi < maxl && mini < minl && max[maxi] == min[mini])
            {
                mini ++;
                maxi ++;
            }

            if (ret < (mini - i))
                ret = mini - i;

            s ++;
        }
    }

    return ret;

}
*/
