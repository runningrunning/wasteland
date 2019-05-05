bool is_same(struct TreeNode* p, struct TreeNode* q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;

    if (p->val != q->val)
        return false;

    return is_same(p->left, q->left)
        && is_same(p->right, q->right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    return is_same(p, q);
}
