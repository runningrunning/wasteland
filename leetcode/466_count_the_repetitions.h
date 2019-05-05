// better solution ????
// TLE !!!
// just generate the fast calculation table ?
// should be that simple?
// how about just calculate ? brute force ?
int getMaxRepetitions(char* s1, int n1, char* s2, int n2)
{
    if (!n1 || !s1)
        return 0;

    if (!n2 || !s2)
        return n2;

    int b1 = 0;
    int b2 = 0;

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    for (int i = 0; i < l1; i ++)
        b1 |= 1 << (s1[i] - 'a');
    for (int i = 0; i < l2; i ++)
        b2 |= 1 << (s2[i] - 'a');

    if ((b1 & b2) != b2)
        return 0;

    int* bs = calloc(sizeof(int), l1);

    int* of = malloc(sizeof(int) * l2);

    int i = 0;
    int j = 0;

    for (i = 0; i < l1 && j < l2; i ++)
    {
        if (s1[i] == s2[j])
        {
            of[j] = i;
            j ++;
        }
    }

    for (i = l1 - 1; i >= 0; i --)
    {
        bool found = false;

        int si = i;
        j = 0;

        for (; si < l1 * 2 && j < l2; si ++)
            if (s1[si % l1] == s2[j])
            {
                if (si >= l1 && (of[j] == si % l1))
                {
                    found = true;
                    break;
                }

                j ++;
            }

        if (!found)
            break;

        bs[i] = 1;
    }


    i = 0;
    j = 0;
    int ni = 0;
    int nj = 0;

    int e1 = l1 * n1;
    int e2 = l2 * n2;

    while (i < e1)
    {
        while (s1[i % l1] != s2[j % l2])
            i ++;

        i ++;
        j ++;

        if ((bs[i % l1] || !(i % l1)) && !(j % l2))
        {
            ni = (i + l1 - 1) / l1;
            nj = j / l2;
            return (n1 * nj) / (n2 * ni);
        }
    }

    return j / e2;

    int* next = malloc(sizeof(int) * l1);
    for (i = 0; i < l1; )
    {
        int oi = i;

        while (i < l1 && s1[i] != s2[0])
            i ++;

        if (i >= l1)
        {
            if (!oi)
                return 0;

            for (int k = l1 - 1; k >= oi; k --)
                next[k] = - (next[0] + l1 - k);
            break;
        }

        int si = i;
        for (int j = 0; j < l2 * n2; j ++)
        {
            int ei = i;
            while (s1[i % l1] != s2[j % l2])
            {
                i ++;

                if (i % l1 == ei % l1)
                    return 0;
            }
            i ++;
        }

        for (int k = si; k >= oi; k --)
            next[k] = i - k;
        i = si + 1;
    }

    // out(next, l1);

    int s = 0;
    int e = l1 * n1;
    int si = -1;

    while (s <= e)
    {
        si ++;
        int n = next[s % l1];
        if (n < 0)
        {
            n = (s + l1 - 1) / l1;
            return n1 * si / n;
        }
        n = n < 0 ? - n : n;
        s += n;
    }
    return si;
}
