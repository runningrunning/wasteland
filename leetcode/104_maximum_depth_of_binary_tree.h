int _max(struct TreeNode* root, int n)
{
    if (!root)
        return n;

    int l = _max(root->left, n + 1);
    int r = _max(root->right, n + 1);

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
int maxDepth(struct TreeNode* root)
{
    return _max(root, 0);
}
