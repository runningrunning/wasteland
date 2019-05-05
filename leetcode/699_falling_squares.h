// normal segment tree
// fixed input length !!!
// optimze the code !!!
// use point to fix the recursive hight!!!! It can save a lot for checking !!
/* segment tree */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */


void _fs_sort(int* n, int s, int e)
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

    _fs_sort(n, cs, e - 1);
    _fs_sort(n, e + 1, ce);
}

int _fs(int** tree, int x, int l, int* h, int s, int a, int b, int of, int* ps)
{
    int max = b - a + 1;

    if (x > s)
        return -1;

    int t = x + 1;
    int st = (t << l) - 1;

    if (st > s)
        return -1;

    int ed = st + (1 << l) - 1;
    ed = ed > s ? s : ed;

    int vst = ps[st - of];
    int ved = ps[ed - of];

    if (vst > b || ved < a)
        return -1;

    if (a <= ved && b >= vst)
        if (tree[x])
            max += *(tree[x]);

    // continue to lower level !!!, don't return here.
    if (a <= vst && ved <= b)
        tree[x] = h; // use point to not compar all of collision rectangle !!

    if (l)
    {
        int m1 = _fs(tree, x * 2 + 1, l - 1, h, s, a, b, of, ps);
        if (max < m1)
            max = m1;
        m1 =  _fs(tree, x * 2 + 2, l - 1, h, s, a, b, of, ps);
        if (max < m1)
            max = m1;
    }
    return max;
}


int* fallingSquares(int** positions, int positionsRowSize, int positionsColSize, int* returnSize)
{
    *returnSize = positionsRowSize;
    if (positionsRowSize <= 1)
    {
        if (!positionsRowSize)
            return NULL;
        int* r = malloc(sizeof(int));
        r[0] = positions[0][1];
        return r;
    }

    int* ps = malloc(sizeof(int) * positionsRowSize * 2);
    for (int i = 0; i < positionsRowSize; i ++)
    {
        ps[i * 2] = positions[i][0];
        ps[i * 2 + 1] = positions[i][0] + positions[i][1] - 1;
    }

    _fs_sort(ps, 0, positionsRowSize * 2 - 1);

    int size = 1;
    for (int i = 1; i < positionsRowSize * 2; i ++)
        if (ps[i] != ps[i - 1])
            ps[size ++] = ps[i];

    int l = 0;
    int x = 1;

    while (x < size)
    {
        l ++;
        x <<= 1;
    }

    int start = x - 1;
    int** tree = calloc(sizeof(int*), start + size);
    int* r = malloc(sizeof(int) * positionsRowSize);
    int* t = malloc(sizeof(int) * positionsRowSize);

    for (int i = 0; i < positionsRowSize; i ++)
    {
        r[i] = _fs(tree, 0, l, &t[i], start + size - 1, positions[i][0], positions[i][0] + positions[i][1] - 1, start, ps);
        t[i] = r[i];
        if (i && r[i] < r[i - 1])
            r[i] = r[i - 1];
    }
    return r;
}
