// TODO: STUPID WRONG ALGORITHM
// FIND BETTER WAY
// HOW TO WRITE SEGMENT TREE !


// segment tree to find the most parallel lines
// fix number, find the most include points !

// like course problems ?
// how many meeting rooms are needed
// how to write segment trees !!!

// segment trees, but how to get the number from its parents to itself ?
// find better way, do not update the number every time, just find them at the last

void _br(int* tree, int x, int l, int o, int s, int e)
{
    int t = x + 1;
    int st = (t << l) - 1 - o;
    int ed = (1 << l) - 1 + st;

    if (st > e || ed < s)
        return;

    // printf("== %d %d %d l %d s %d e %d.\n", t, st, ed, l, s, e);

    if (st >= s && ed <= e)
    {
        tree[x] += 1;

        /* int on = (*num) >> 16; */
        /* int ok = (*num) & 0xFFFF; */
        /* int new = tree[x] + p; */

        /* printf("NNN %d %d is %d.\n", st, ed, new); */

        /* if (new > on || (new == on && st < ok)) */
        /* { */
        /*     printf("XXX %d %d %d %d %d.\n", st, ed, *num, tree[x], x); */
        /*     *num = (new << 16) | st; */
        /* } */
    }
    else if (l)
    {
        _br(tree, x * 2 + 1, l - 1, o, s, e);
        _br(tree, x * 2 + 2, l - 1, o, s, e);
    }
}

int bestRotation(int* A, int ASize)
{
    int l = 0;
    int x = 1;

    /* // 32768 2 ^ 15 */
    /* l = 15; */
    /* x = 32768; */

    while (x < ASize)
    {
        l ++;
        x <<= 1;
    }

    int start = x - 1;
    int* tree = calloc(sizeof(int), x * 2);

    int max = INT_MIN;

    // segment tree !
    for (int i = 0; i < ASize; i ++)
    {
        int a = A[i];

        if (a >= ASize)
            continue;

        int lmin, lmax;

        if (a <= i)
        {
            lmin = 0;
            lmax = i - a;
            {
                if (lmax > max)
                    max = lmax;
                _br(tree, 0, l, start, lmin, lmax);
            }

            lmin = i + 1;
            lmax = ASize - 1;
            if (i + 1 <= ASize - 1)
            {
                if (lmax > max)
                    max = lmax;
                _br(tree, 0, l, start, lmin, lmax);
            }
        }
        else
        {
            lmin = i + 1;
            lmax = i + ASize - a;
            if (lmax > max)
                max = lmax;
            _br(tree, 0, l, start, lmin, lmax);
        }
    }

    int k = 0;
    int k_max = INT_MIN;

    for (int i = 0; i <= max; i ++)
    {
        int s = 0;
        int x = i;
        int n = 0;

        for (int j = l - 1; j >= 0; j --)
        {
            s = s * 2 + 1;
            if (x & (1 << j))
                s ++;
            n += tree[s];
        }

        if (n > k_max)
        {
            k_max = n;
            k = i;
        }
    }

    return k;
}
