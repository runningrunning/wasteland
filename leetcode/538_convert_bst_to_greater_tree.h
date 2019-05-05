void cbst(struct TreeNode* r, int* a)
{
    if (r->right)
        cbst(r->right, a);
    *a += r->val;
    r->val = *a;
    if (r->left)
        cbst(r->left, a);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* convertBST(struct TreeNode* root)
{
    if (!root)
        return root;
    int n = 0;
    cbst(root, &n);
    return root;
}
