int lup(struct TreeNode* root, int* n, int p)
{
    int l = 0;
    if (root->left && root->val == root->left->val)
        l = lup(root->left, n, root->val);

    int r = 0;
    if (root->right && root->val == root->right->val)
        r = lup(root->right, n, root->val);

    if (l + r > *n)
        *n = l + r;

    if (p == root->val)
        return (l > r ? l : r) + 1;
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
int longestUnivaluePath(struct TreeNode* root)
{
    if (!root)
        return 0;

    int n = 0;
    lup(root, &n, root->val - 1);
    return n;
}
