void _kth(struct TreeNode* r, int k, int* n, bool* done)
{
    if (*done)
        return;

    if (r->left)
        _kth(r->left, k, n, done);

    if (!(*done))
    {
        (*n) ++;
        if (*n == k)
        {
            *n = r->val;
            *done = true;
            return;
        }
    }

    if (r->right)
        _kth(r->right, k, n, done);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest(struct TreeNode* root, int k)
{
    if (!root)
        return 0;

    bool done = false;
    int n = 0;
    _kth(root, k, &n, &done);
    return n;
}
