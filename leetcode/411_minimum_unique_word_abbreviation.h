// TODO: FIND THE BETTER SOLUTION !!!
// MINE IS BRUTE FORCE
// pure code ?
// just find a way to record which encode can not be used
// then it's easy
// use bits to represent, 0 means character, 1 means number
// not the same, as same bits need to be prepared ?
// eg world vs wored, world, then ...l. and 'l' must be exist
// m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
// how to from bits back to strings, it's difficult !
// try !

// use hash ???, just brute force ???
// not at all, don't even need hash

// optimize the memory
// just use the bits flag to do so, not add the same value again?

// only bits represent is not enough, should use DFS  or backtracing
// otherwise, the memory is not enough
// it's BFS here
char* minAbbreviation(char* target, char** dictionary, int dictionarySize)
{
    int l = strlen(target);

    int x = 1;
    while (l --)
        x <<= 1;

    char* ret = malloc(24);
    l = strlen(target);

    if (!dictionarySize)
    {
        sprintf(ret, "%d", l);
        return ret;
    }

    int as = 1024;
    int ai = 0;
    int* a = malloc(sizeof(int) * as);

    int bs = 1024;
    int bi = 0;
    int* b = malloc(sizeof(int) * bs);

    int mi = 0;
    int* m = malloc(sizeof(int) *  (l + 1));

    int cs = as;
    int ci = 0;
    int* c = a;
    c[ci ++] = 0;

    int ns = bs;
    int ni = 0;
    int* n = b;

    int bl = x + 1;
    int* bits = calloc(sizeof(int), bl);

    for (int i = 0; i < dictionarySize; i ++)
    {
        mi = 0;

        int di = 0;
        char* d = dictionary[i];
        while (d[di] && target[di])
        {
            if (d[di] != target[di])
                m[mi ++] = 1 << di;
            di ++;
        }

        if (target[di] || d[di])
            continue;

        for (int j = 0; j < ci; j ++)
        {
            for (int k = 0; k < mi; k ++)
            {
                /* if (m[k] & c[j]) */
                /*     continue; */

                x = m[k] | c[j];


                if (bits[x] != i + 1)
                {
                    bits[x] = i + 1;

                    if (ni == ns)
                    {
                        ns += 2048;
                        n = realloc(n, sizeof(int) * ns);
                    }
                    n[ni ++] = x;
                }
            }
        }

        int* t = n;
        int ts = ns;
        int ti = ni;

        n = c;
        ns = cs;
        ni = 0;

        c = t;
        cs = ts;
        ci = ti;

        // printf("cs %d ns %d.\n", cs, ns);
        // memset(bits, 0, sizeof(int) * bl);
    }

    int mz = 0;
    int min = l;

    int h = 1 << (l - 1);

    for (int i = 0; i < ci; i ++)
    {
        x = c[i];


        int z = 0;
        while (x)
        {
            if (x & 1)
            {
                x >>= 1;
                z ++;

                if (!x)
                    break;
            }

            if (x & 1)
                continue;

            z ++;
            while (!(x & 1))
                x >>= 1;
        }

        z += !(c[i] & h);

        // printf("c[i] %x, z %d.\n", c[i], z);

        if (min > z)
        {
            min = z;
            mz = c[i];
        }
    }

    free(a);
    free(b);
    free(bits);

    if (min == l)
        return strdup(target);

    int i = 0;
    int p = 0;
    int ri = 0;
    for (; i < l; i ++)
    {
        if (mz & (1 << i))
        {
            if (p < i)
            {
                x = i - p;
                if (x >= 10)
                    ret[ri ++] = (x / 10) + '0';
                ret[ri ++] = (x % 10) + '0';
            }
            ret[ri ++] = target[i];
            p = i + 1;
        }
    }

    if (p < i)
    {
        x = i - p;
        if (x >= 10)
            ret[ri ++] = (x / 10) + '0';
        ret[ri ++] = (x % 10) + '0';
    }
    ret[ri] = 0;

    return ret;
}
