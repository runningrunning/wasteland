// practice more !
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* scs(struct TreeNode* o, int m, int u)
{
    if (!o)
        return NULL;
    u += o->val;
    if (!o->left && !o->right)
        return u < m ? NULL : o;
    o->left = scs(o->left, m, u);
    o->right = scs(o->right, m, u);
    return (o->left || o->right) ? o : NULL;
}

struct TreeNode* sufficientSubset(struct TreeNode* root, int limit)
{
    return scs(root, limit, 0);
}

