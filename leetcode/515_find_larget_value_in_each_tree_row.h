
void _lv(struct TreeNode* r, int h, int** a, int* c)
{
    if (*c < h + 1)
    {
        *c = h + 1;

        if (!((h + 1) % 256))
        {
            *a = realloc(*a, sizeof(int) * (h + 1 + 256));
            for (int i = 0; i < 256; i ++)
                (*a)[h + i] = INT_MIN;
        }
    }

    if ((*a)[h] < r->val)
        (*a)[h] = r->val;

    if (r->left)
        _lv(r->left, h + 1, a, c);

    if (r->right)
        _lv(r->right, h + 1, a, c);
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize)
{
    int c = 0;
    int* ret = malloc(sizeof(int) * 256);
    for (int i = 0; i < 256; i ++)
        ret[i] = INT_MIN;
    _lv(root, 0, &ret, &c);
    *returnSize = c;
    return ret;
}
