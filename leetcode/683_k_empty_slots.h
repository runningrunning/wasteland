// TODO it AGAIN with pure binary tree ~
// self balanced interval tree ?
// practice interval tree and others !!
// worst code at all
// stupid wrong algorithm ??
// balance tree ?
//
// segment tree, random balance segment tree
// fix size segment tree, and dynamic size segment tree (treap tree !!)
// how to write my segment tree, random ?
// just simple segment tree, or interval tree

bool _kes(int* tree, int x, int l, int s, int b, int k, int si)
{
    if (x > s || !l)
        return false;

    int t = x + 1;

    int st = (t << l) - 1;

    if (st > s)
        return false;

    int ed = st + (1 << l)  - 1;
    ed = ed > s ? s : ed;

    if (b - 1 < st - si || b - 1 > ed - si)
        return false;

    int pre = (st + (1 << (l - 1)) -1) - si + 1;
    int post = pre + 1;

    int _pre = tree[x] >> 16;
    int _post = tree[x] & 0xFFFF;

    if (b <= pre && (!_pre || b >= _pre))
        _pre = b;
    if (b >= post && (!_post || b <= _post))
        _post = b;

    if (_pre && _post && _post - _pre == k + 1)
        return true;

    tree[x] = _pre << 16 | _post;

    if (l)
    {
        if (_kes(tree, x * 2 + 1, l - 1, s, b, k, si))
            return true;

        if (_kes(tree, x * 2 + 2, l - 1, s, b, k, si))
            return true;
    }

    return false;
}

int kEmptySlots(int* flowers, int flowersSize, int k)
{
    int l = 0;
    int x = 1;

    while (x < flowersSize)
    {
        l ++;
        x <<= 1;
    }

    int start = x - 1;
    int* tree = calloc(sizeof(int), start + flowersSize);
    for (int i = 0; i < flowersSize; i ++)
        if (_kes(tree, 0, l, start + flowersSize - 1, flowers[i], k, start))
            return i + 1;

    return -1;
}
