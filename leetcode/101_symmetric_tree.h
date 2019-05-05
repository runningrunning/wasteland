bool is_sys(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q)
        return true;

    if (!p || !q)
        return false;

    if (p->val != q->val)
        return false;

    return is_sys(p->left, q->right)
        && is_sys(p->right, q->left);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root)
{
    if (!root)
        return true;
    return is_sys(root->left, root->right);
}
