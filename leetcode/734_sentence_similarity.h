bool is_smaller(char* a, char* b)
{
    int al = strlen(a);
    int bl = strlen(b);

    if (al != bl)
        return al < bl;

    for (int i = 0; i < al; i ++)
    {
        if (a[i] != b[i])
            return a[i] < b[i];
    }
    return false;
}

bool areSentencesSimilar(char** words1, int words1Size, char** words2, int words2Size, char*** pairs, int pairsRowSize, int pairsColSize)
{
    if (!words1Size || !words1)
        return !words2Size || !words2;
    if (words1Size != words2Size)
        return false;

    for (int i = 0; i < pairsRowSize; i ++)
    {
        char* p1 = pairs[i][0];
        char* p2 = pairs[i][1];

        if (!is_smaller(p1, p2))
        {
            pairs[i][0] = p2;
            pairs[i][1] = p1;
        }

        printf("%s %s.\n", pairs[i][0], pairs[i][1]);
    }


    for (int i = 0; i < words1Size; i++)
    {
        char* w1 = words1[i];
        char* w2 = words2[i];

        if (!strcmp(w1, w2))
            continue;

        char* t;

        if (!is_smaller(w1, w2))
        {
            t = w2;
            w2 = w1;
            w1 = t;
        }

        printf("== %s %s.\n", w1, w2);

        bool found = false;
        for (int j = 0; j < pairsRowSize; j ++)
        {
            if (strcmp(w1, pairs[j][0]))
                continue;
            if (!strcmp(w2, pairs[j][1]))
            {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }
    return true;
}


/*
// using hash vs own 64 bits
// TODO is there any other ways to put different stuff into together and never
// SIMPLE IS FASTER, just do Brute-force attack !!!!
long key(char* s)
{
    long flag = 0;

    int i = 0;
    int c = s[i ++];
    int x = 0;
    int  a = 0;

    while (c)
    {
        x ^= c;
        a += c;
        flag |= 1 << ((32 + ((c - 'a') % 32)) % 32);
        c = s[i ++];
    }

    return flag << 30 | x << 22 | i << 14 | a;
}

void ass_sort(long* n, int s, int e, long* m)
{
    if (s >= e)
        return;

    long t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = m[s];
        m[s] = m[e];
        m[e] = t;
    }

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

            t = m[s];
            m[s] = m[e];
            m[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = m[i];
            m[i] = m[e];
            m[e] = t;
        }
    }

    ass_sort(n, cs, e - 1, m);
    ass_sort(n, e + 1, ce, m);
}

bool areSentencesSimilar(char** words1, int words1Size, char** words2, int words2Size, char*** pairs, int pairsRowSize, int pairsColSize)
{
    if (!words1Size || !words1)
        return !words2Size || !words2;
    if (words1Size != words2Size)
        return false;

    long* ps_keys = malloc(sizeof(long) * pairsRowSize);
    long* ps_values = malloc(sizeof(long) * pairsRowSize);

    for (int i = 0; i < pairsRowSize; i ++)
    {
        long k = key(pairs[i][0]);
        long v = key(pairs[i][1]);

        ps_keys[i] = k < v ? k : v;
        ps_values[i] = k < v ? v : k;
        // printf("%s %s %ld %ld\n", pairs[i][0], pairs[i][1], k, v);
    }

    ass_sort(ps_keys, 0, pairsRowSize - 1, ps_values);

    for (int i = 0; i < words1Size; i ++)
    {
        long k = key(words1[i]);
        long v = key(words2[i]);

        if (k == v)
            continue;

        long t;

        if (k > v)
        {
            t = k;
            k = v;
            v = t;
        }

        // printf("need %s %s %ld %ld\n", words1[i], words2[i], k, v);

        int s = 0;
        int e = pairsRowSize - 1;

        while (s < e)
        {
            int m = (s + e) / 2;
            if (ps_keys[m] < k)
                s = m + 1;
            else
                e = m;
        }

        if (ps_keys[s] != k)
            return false;

        // printf("s %d %ld %ld.\n", s, ps_keys[s], ps_values[s]);

        bool found = false;
        for (;s < pairsRowSize; s ++)
        {
            if (ps_keys[s] != k)
                break;

            if (ps_values[s] == v)
            {
                found = true;
                break;
            }
        }

        // printf("found is %d.\n", found);
        if (!found)
            return false;
    }
    return true;
}
*/
