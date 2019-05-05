int _d(struct TreeNode* node, int n, bool* not)
{
    if (!node)
        return n - 1;

    int r = _d(node->right, n + 1, not);
    int l = _d(node->left, n + 1, not);

    if (abs(l - r) > 1)
        *not = true;

    return l > r ? l : r;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root)
{
    if (!root)
        return true;

    bool not = false;
    _d(root, 1, &not);
    return !not;
}
