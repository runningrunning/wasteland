void _dmin(struct TreeNode* node, int n, int* min)
{
    if (!node->left && !node->right)
    {
        if ((*min) > n)
            *min = n;
        return;
    }

    if (n >= (*min))
        return;

    if (node->left)
        _dmin(node->left, n + 1, min);

    if (node->right)
        _dmin(node->right, n + 1, min);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root)
{
    if (!root) return 0;
    int min = INT_MAX;
    _dmin(root, 1, &min);
    return min;
}
