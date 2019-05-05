int _max(struct TreeNode* h, int* max_n)
{
    if (h)
    {
        int l = _max(h->left, max_n);
        int r = _max(h->right, max_n);

        l = l < 0 ? 0 : l;
        r = r < 0 ? 0 : r;

        int c = h->val + l + r;

        if (*max_n < c)
            *max_n = c;

        if (l > r)
            c = h->val + l;
        else
            c = h->val + r;

        return c > 0 ? c : 0;
    }
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxPathSum(struct TreeNode* root)
{
    if (!root)
        return 0;

    int max_n = INT_MIN;
    _max(root, &max_n);
    return max_n;
}
