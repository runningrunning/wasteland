/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void mas(struct TreeNode* r, int* v, int* n, double* d)
{
    if (!r)
        return;

    int lv = 0;
    int ln = 0;
    int rv = 0;
    int rn = 0;

    mas(r->left, &lv, &ln, d);
    mas(r->right, &rv, &rn, d);

    *v = lv + rv + r->val;
    *n = ln + rn + 1;

    double x = ((double) (*v)) / ((double)(*n));

    if (x > *d)
        *d = x;
}

double maximumAverageSubtree(struct TreeNode* root)
{
    double r = 0;
    int v = 0;
    int n = 0;
    mas(root, &v, &n, &r);
    return r;
}

