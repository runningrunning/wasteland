bool _is(struct TreeNode* r, int sum)
{
    if (!r)
        return false;

    if (!r->left && !r->right)
        return sum == r->val;

    bool ret = false;
    if (r->left)
        ret = _is(r->left, sum - r->val);

    if (ret)
        return ret;

    if (r->right)
        ret = _is(r->right, sum - r->val);

    return ret;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum)
{
    return _is(root, sum);
}
