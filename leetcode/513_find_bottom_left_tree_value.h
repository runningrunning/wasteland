void fblv(struct TreeNode* r, int l, int *h, int* v)
{
    if (l > (*h))
    {
        *h = l;
        *v = r->val;
    }

    if (r->left)
        fblv(r->left, l + 1, h, v);

    if (r->right)
        fblv(r->right, l + 1, h, v);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findBottomLeftValue(struct TreeNode* root)
{
    int h = 0;
    int v = root->val;

    fblv(root, 0, &h, &v);
    return v;
}
