void gmd(struct TreeNode* r, int min, int max, int* cur)
{
    if (r->left)
        gmd(r->left, min, r->val, cur);

    if (r->right)
        gmd(r->right, r->val, max, cur);

    int _mi = INT_MAX;
    int _ma = INT_MAX;

    if (min >= 0)
        _mi = r->val - min;

    if (max >= 0)
        _ma = max - r->val;

    int les = _ma > _mi ? _mi : _ma;

    if (*cur > les)
        *cur = les;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getMinimumDifference(struct TreeNode* root)
{
    int min = -1;
    int max = -1;
    int cur = INT_MAX;
    gmd(root, min, max, &cur);
    return cur;
}
