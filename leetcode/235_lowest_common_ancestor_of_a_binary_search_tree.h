/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lc(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (root == p || root == q)
        return root;

    if (root->val < p->val)
        return lc(root->right, p, q);
    else if (root->val > q->val)
        return lc(root->left, p, q);
    return root;
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (p == q)
        return p;

    struct TreeNode* ma = p-> val > q->val ? p : q;
    struct TreeNode* mi = ma == p ? q : p;

    return lc(root, mi, ma);
}
