void _aol(struct TreeNode* r, int h, long* a, int* b, int* c)
{
    if (*c < h + 1)
        *c = h + 1;

    a[h] += r->val;
    b[h] ++;

    if (r->left)
        _aol(r->left, h + 1, a, b, c);

    if (r->right)
        _aol(r->right, h + 1, a, b, c);
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
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    long int a[2048] = {0};
    int b[2048] = {0};
    int c = 0;
    _aol(root, 0, a, b, &c);
    *returnSize = c;

    double* ret = malloc(sizeof(double) * c);

    for (int i = 0; i < c; i ++)
        ret[i] = a[i] / (b[i] + 0.0);

    return ret;
}
