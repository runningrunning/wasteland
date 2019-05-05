/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void _ic(struct TreeNode* r, int l, int p, int x, int y, int* ix, int* iy)
{
    if (!r)
        return;
    if (r->val == x)
        *ix = l << 16 | p;
    else if (r->val == y)
        *iy = l << 16 | p;

    _ic(r->left, l + 1, r->val, x, y, ix, iy);
    _ic(r->right, l + 1, r->val, x, y, ix, iy);
}

bool isCousins(struct TreeNode* root, int x, int y)
{
    int ix = 0;
    int iy = 0;
    _ic(root, 0, 255, x, y, &ix, &iy);

    // level
    if ((ix & 0xFFFF0000) != (iy & 0xFFFF0000))
        return false;

    // parent
    return (ix & 0xFFFF) != (iy & 0xFFFF);
}
