/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _btg(struct TreeNode* r, int* v)
{
    if (!r)
        return;
    _btg(r->right, v);
    (*v) += r->val;
    r->val = *v;
    _btg(r->left, v);
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
    int v = 0;
    _btg(root, &v);
    return root;
}
