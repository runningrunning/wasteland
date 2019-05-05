void mp_sort(int* n, int s, int e, int* f)
{
    if (s >= e)
        return;

    int t;
    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;

        t = f[s];
        f[s] = f[e];
        f[e] = t;
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

            t = f[s];
            f[s] = f[e];
            f[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;

            t = f[i];
            f[i] = f[e];
            f[e] = t;
        }
    }

    mp_sort(n, cs, e - 1, f);
    mp_sort(n, e + 1, ce, f);
}

int maxProduct(char** words, int wordsSize)
{
    if (!words || wordsSize < 2)
        return 0;
    int* fs = malloc(sizeof(int) * wordsSize);
    int* ns = malloc(sizeof(int) * wordsSize);

    int all = 0xFFFFFFFF;
    for (int i = 0; i < wordsSize; i ++)
    {
        char* w = words[i];

        int f = 0;
        int ci = 0;
        int c = w[ci ++];

        while (c)
        {
            f |= 1 << (c - 'a');
            c = w[ci ++];
        }

        fs[i] = f;
        ns[i] = ci - 1;

        all &= f;
    }

    if (all)
        return 0;

    mp_sort(ns, 0, wordsSize - 1, fs);

    int s = 0;
    int max = 0;

    for (int i = wordsSize - 1; i >= s + 1; i --)
    {
        int l = ns[i];
        int f = fs[i];
        for (int j = i  - 1; j >= s; j --)
        {
            if (!(f & fs[j]))
            {
                if (max < l * ns[j])
                    max = l * ns[j];
                s = j;
                break;
            }
        }
    }

    return max;
}
