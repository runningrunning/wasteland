int ft(struct TreeNode* n, int* t)
{
    if (!n)
        return 0;

    int l = ft(n->left, t);
    int r = ft(n->right, t);

    int x = r - l;
    *t += x < 0 ? -x : x;

    return n->val + r + l;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findTilt(struct TreeNode* root)
{
    int r = 0;
    ft(root, &r);
    return r;
}
