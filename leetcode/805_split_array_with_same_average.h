// TODO Do my best ? !
// assuming 0 is the average of empty array ?
// the average can be 4.5
// similar with 416. Partition Equal Subset Sum ?
// TIME LIMIT AGAIN !!!, just quick skip the same number !!

// import method here !! LEARN A LOT
// no recursion
bool can(int* n, int s, int e, int x, int y)
{
    int ix[64] = {0};
    int si = 1;

    int nxt = 0;
    int cur = 0;

    while (true)
    {
        int try = cur + n[nxt];

        if (try == y && si == x)
            return true;

        if (x < si || try > y || nxt >= e)
        {
            si --;
            if (!si)
                return false;

            int o = ix[si];
            cur -= n[ix[si]];
            nxt = o + 1;

            while (nxt < e && n[nxt] == n[o]) // skip the same one, just like permutations !! SKIP THE SAME PREMUTATION !!
                nxt ++;
        }
        else
        {
            ix[si ++] = nxt;
            cur = try;
            nxt ++;
        }
    }
    return false;
}

int gcd(int a, int b)
{
    if (!(a % b))
        return b;
    return gcd(b, a % b);
}

void _sa_sort(int* n, int s, int e)
{
    if (s > e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 >= e)
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

    _sa_sort(n, cs, e - 1);
    _sa_sort(n, e + 1, ce);
}

bool splitArraySameAverage(int* A, int ASize)
{
    if (!A || !ASize)
        return true;

    if (ASize == 1)
        return false;

    if (ASize == 2)
        return A[0] == A[1];

    _sa_sort(A, 0, ASize - 1);

    int all = 0;
    for (int i = 0; i < ASize; i ++)
        all += A[i];

    // 4.5 is also valid value !
    /* if (all % ASize) */
    /*     return false; */

    // 0 is another method
    if (all)
    {
        int d = all > ASize ? gcd(all, ASize) : gcd(ASize, all);
        int x = ASize / d;
        int y = all / d;

        if (x > ASize / 2)
            return false;

        while (x <= ASize / 2)
        {
            if (can(A, 0, ASize - 1, x, y))
                return true;
            x += ASize / d;
            y += all / d;
        }
    }
    else
    {
        int x = 1;
        while (x <= ASize / 2)
        {
            if (can(A, 0, ASize - 1, x, 0))
                return true;
            x ++;
        }
    }
    return false;
}
