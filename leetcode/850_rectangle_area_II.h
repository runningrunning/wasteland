// stupid wrong algorithm !!!!!!!!!!!!!!!!!!!!
// TODO USE SEGMENT TREE IN A WRONG WAY, SCAN LINE + SEGMENT TREE HDU 1255!
//
// no one use segment tree ?
// how to use segment tree ?
// my way to do segment tree !!, segment tree is static
// try another method without segment tree !!

// SEGMENT TREE !!!, ALL of its internal nodes are intervals !!!
// segment tree, internal nodes are intervals !!!
// segment tree, leaves nodes are elementary intervals induced by the endpoints !!!

void _ra_sort(int* n, int s, int e)
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

    _ra_sort(n, cs, e - 1);
    _ra_sort(n, e + 1, ce);
}

typedef struct
{
    bool i; // init
    int s;
    int e;
    int is;
    int ie;
    int n;
    int c;
    long* ls;
} Node;

void _ra_out(long* t, int c)
{
    for (int i = 0; i < c; i ++)
    {
        long _ys1 = t[i] >> 32;
        long _ys2 = t[i] & 0xFFFFFFFF;

        printf("%ld -> %ld : ", _ys1, _ys2);
        printf("\n");
    }
}

long _ra_merge_high(Node* t, long y1, long y2)
{
    long cut = 0;
    long* ys = t->ls;
    int i = 0;
    int j = 0;
    long in = y1 << 32 | y2;
    bool insert = true;
    for (i = 0; i < t->c; i ++)
    {
        long _ys1 = ys[i] >> 32;
        long _ys2 = ys[i] & 0xFFFFFFFF;

        if (_ys1 <= y1 && _ys2 >= y2)
            return y2 - y1 + 1;

        if (_ys1 > y2)
            break;

        if (ys[i] < in && (ys[i] & 0xFFFFFFFF) < y1)
            continue;
        else if (ys[i] < in)
        {
            j = i;
            for (; j < t->c; j ++)
            {
                long _ys1 = ys[j] >> 32;
                long _ys2 = ys[j] & 0xFFFFFFFF;

                if (_ys1 > y2)
                    break;

                if (j == i)
                    cut += (y2 >= _ys2 ? _ys2 : y2) - y1 + 1;
                else
                    cut += (y2 >= _ys2 ? _ys2 : y2) - _ys1 + 1;
                // printf("%d %d %d %d.\n", y1, y2, _ys1, _ys2);
            }

            // merge i - > j
            long _ys1 = ys[i] >> 32;
            long _ys2 = ys[j - 1] & 0xFFFFFFFF;
            ys[i ++] = _ys1 << 32 | (y2 >= _ys2 ? y2 : _ys2);

            for (; j < t->c; j ++)
                ys[i ++] = ys[j];
            t->c = i;
            insert = false;
            break;
        }
        else if ((ys[i] >> 32) <= y2)
        {
            j = i;

            for (; j < t->c; j ++)
            {
                long _ys1 = ys[j] >> 32;
                long _ys2 = ys[j] & 0xFFFFFFFF;
                if (_ys1 > y2)
                    break;
                cut += (y2 >= _ys2 ? _ys2 : y2) - _ys1 + 1;
            }
            // merge i - > j
            long _ys2 = ys[j - 1] & 0xFFFFFFFF;
            ys[i ++] = y1 << 32 | (y2 >= _ys2 ? y2 : _ys2);

            for (; j < t->c; j ++)
                ys[i ++] = ys[j];
            t->c = i;
            insert = false;
            break;
        }
    }

    if (insert)
    {
        if (t->c == t->n)
        {
            t->ls = realloc(t->ls, sizeof(long) * (t->n + 10));
            t->n += 10;
        }
        ys = t->ls;
        for (int j = t->c; j > i; j --)
            ys[j] = ys[j - 1];

        t->ls[i] = in;
        t->c = t->c + 1;
    }
    // printf("cut is %d.\n");
    return cut;
}

long _ra(Node* tree, int x, int l, int s, long x1, long x2, long y1, long y2, int* ps, int of)
{
    if (x > s)
        return 0;

    int t = x + 1;
    int st = (t << l) - 1;

    if (st > s)
        return 0;

    int ed = st + (1 << l) - 1;
    ed = ed > s ? s : ed;

    long vst = ps[st - of];
    long ved = ps[ed - of];

    if (vst > x2 || ved < x1)
        return 0;

    long r = 0;

    if (tree[x].i)
    {
        // printf("x %d x2 %d x1 %d, vst %d ved %d.\n", x2, x1, vst, ved);
        if (x1 <= tree[x].is && tree[x].ie <= x2)
        {
            if (!tree[x].ls)
            {
                tree[x].n = 10;
                tree[x].c = 1;
                tree[x].ls = malloc(sizeof(long) * 10);
                tree[x].ls[0] = ((long) y1) << 32 | ((long) y2);
                if (l)
                    r = ((long) (tree[x].ie - tree[x].is - 1)) * ((long)(y2 - y1 + 1));
                else
                    r = ((long)(y2 - y1 + 1));
                // printf("x %d l %d 1 r is %ld %d->%d %d.\n", x, l, r, tree[x].ie ,tree[x].is, y2 -y1 + 1);
            }
            else
            {
                // printf("add y1 %d -> y2 %d.\n", y1, y2);
                // _ra_out(tree[x].ls, tree[x].c);
                long cut = _ra_merge_high(&tree[x], y1, y2);
                // _ra_out(tree[x].ls, tree[x].c);

                if (l)
                    r = ((long) (tree[x].ie - tree[x].is - 1)) * ((long)(y2 - y1 + 1 - cut));
                else
                    r = ((long)(y2 - y1 + 1 - cut));
                // printf("x %d l %d 2 r is %ld %d->%d %d cut %d.\n", x, l, r, tree[x].ie ,tree[x].is, y2 -y1 + 1 - cut, cut);
            }
        }
    }

    if (l)
    {
        long lc = _ra(tree, x * 2 + 1, l - 1, s, x1, x2, y1, y2, ps, of);
        long rc = _ra(tree, x * 2 + 2, l - 1, s, x1, x2, y1, y2, ps, of);

        // printf("self %ld left %ld right %ld = ", r, lc, rc);
        r += lc + rc;
    }
    // printf("r is %d.\n", r);
    return r;
}

int rectangleArea(int** rectangles, int rectanglesRowSize, int *rectanglesColSizes)
{
    int* xs = malloc(sizeof(int) * rectanglesRowSize * 2);

    for (int i = 0; i < rectanglesRowSize; i ++)
    {
        xs[i * 2] = rectangles[i][0];
        xs[i * 2 + 1] = rectangles[i][2] - 1;
    }

    _ra_sort(xs, 0, rectanglesRowSize * 2 - 1);

    int size = 1;
    for (int i = 1; i < rectanglesRowSize * 2; i ++)
        if (xs[i] != xs[i - 1])
            xs[size ++] = xs[i];

    int l = 0;
    int x = 1;

    while (x < size)
    {
        x <<= 1;
        l ++;
    }

    int start = x - 1;
    Node* tree = calloc(sizeof(Node), start + size);

    // populate the tree
    for (int i = 0; i < size; i ++)
    {
        int x = i + start;
        tree[x].i = true;
        tree[x].s = xs[i];
        tree[x].e = xs[i];
        tree[x].is = xs[i];
        tree[x].ie = xs[i];

        while (x)
        {
            int p = (x - 1) / 2;

            if (tree[p].i)
            {
                if (xs[i] > tree[p].e)
                    tree[p].e = xs[i];

                if (xs[i] < tree[p].s)
                    tree[p].s = xs[i];
            }
            else
            {
                tree[p].i = true;
                tree[p].s = xs[i];
                tree[p].e = xs[i];
                tree[p].is = INT_MIN;
                tree[p].ie = INT_MAX;
            }

            // left
            if (x == p * 2 + 1)
            {
                if (tree[x].e > tree[p].is)
                    tree[p].is = tree[x].e;
            }
            else
            {
                if (tree[x].s < tree[p].ie)
                    tree[p].ie = tree[x].s;
            }
            x = p;
        }
    }

    /* for(int i = 0; i < start + size; i ++) */
    /*     printf("%d: %d %d %d %d.\n", i, tree[i].s, tree[i].e, tree[i].is, tree[i].ie); */

    long r = 0;
    for (int i = 0; i < rectanglesRowSize; i ++)
    {
        r += _ra(tree, 0, l, start + size - 1, rectangles[i][0], rectangles[i][2] - 1, rectangles[i][1], rectangles[i][3] - 1, xs, start);
        r %= 1000000007;
    }
    return r;
}
