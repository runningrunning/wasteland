/* TODO rework find better way to handle it. */
int _nl(int h, int* l)
{
    int x = h / 31;
    int y = h % 31;

    int ll = 0;

    if (!x)
        ll = l[0] >> (31 - y);
    else
    {
        if (y)
        {
            ll |= l[x] >> (31 - y);
            ll |= l[x - 1] << y;
        }
        else
            ll = l[x - 1];
    }
    return ll;
}

void _snl(int h, int* l, int b)
{
    int x = h / 31;
    int y = h % 31;

    if (!y)
    {
        if (b)
            l[x - 1] |= 1;
        else
            l[x] &= 0;
    }
    else
    {
        y = 31 - y;
        int ll = 1 << y;

        if (b)
            l[x] |= ll;
        else
            l[x] &= ~ll;
    }
}

void _wobt(struct TreeNode* r, int h, int* n, int * l, int* m)
{
    if (!n[h])
        n[h] = _nl(h, l) | (1 << 31);
    else
    {
        int ma = _nl(h, l) - (n[h] & 0x7FFFFFFF);
        if (*m < ma)
            *m = ma;
    }

    if (r->left)
    {
        _snl(h + 1, l, 0);
        _wobt(r->left, h + 1, n, l, m);
    }

    if (r->right)
    {
        _snl(h + 1, l, 1);
        _wobt(r->right, h + 1, n, l, m);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int widthOfBinaryTree(struct TreeNode* root)
{
    if (!root)
        return 0;

    /* max 1024 level */
    int n[1024] = {0};
    int l[256] = {0};
    int m = 0;

    _wobt(root, 0, n, &l, &m);
    return m + 1;
}
