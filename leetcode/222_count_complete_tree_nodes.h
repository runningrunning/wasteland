/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root)
{
    if (!root)
        return 0;

    int l = 0;
    struct TreeNode* h = root;

    while(h)
    {
        l ++;
        h = h->left;
    }

    int r = 0;
    h = root;

    while(h)
    {
        r ++;
        h = h->right;
    }

    int a = 1 << (l - 1);
    int b = (1 << l) - 1;

    if (l == r)
        return b;

    if (l == 2)
        return a;

    int lv = 1 << (l - 2);
    int t = a + (b - a) / 2;

    while(1)
    {
        h = root;
        l = lv;
        while(l && h)
        {
            if (t & l)
                h = h->right;
            else
                h = h->left;
            l >>= 1;
        }

        if (h)
            a = t;
        else
            b = t;
        t = a + (b - a) / 2;
        if (a == t)
            return t;
    }
    return 0;
}
