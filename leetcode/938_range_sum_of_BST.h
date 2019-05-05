/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rangeSumBST(struct TreeNode* root, int L, int R)
{
    if (!root)
        return 0;

    int r = 0;
    int v = root->val;
    if (v >= L && v <= R)
        r = v;

    if (v <= L)
        return r + rangeSumBST(root->right, L, R);

    if (v >= R)
        return r + rangeSumBST(root->left, L, R);

    return r + rangeSumBST(root->right, L, R)
        + rangeSumBST(root->left, L, R);
}
