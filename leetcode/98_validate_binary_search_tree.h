bool _val(struct TreeNode* root, int min, int max, bool* is_min, bool* is_max)
{
    if (root->val <= min && min != INT_MIN)
        return false;
    if (root->val >= max && max != INT_MAX)
        return false;

    if (root->val == INT_MAX)
    {
        if (*is_max)
            return false;
        *is_max = true;
    }

    if (root->val == INT_MIN)
    {
        if (*is_min)
            return false;
        *is_min = true;
    }

    if (root->left)
        if (!_val(root->left, min, root->val, is_min, is_max))
            return false;

    if (root->right)
        if (!_val(root->right, root->val, max, is_min, is_max))
            return false;

    return true;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root)
{
    if (!root)
        return true;
    bool is_max = false;
    bool is_min = false;
    return _val(root, INT_MIN, INT_MAX, &is_min, &is_max);
}
