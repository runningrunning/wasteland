void cv(struct TreeNode* r, double t, double* m, int* v)
{
    if (!r)
        return;

    double x = ((double)r->val) - t;

    if (x == 0.0)
    {
        *m = 0.0;
        *v = r->val;
    }
    else if (x > 0.0)
    {
        if (*m > x)
        {
            *m = x;
            *v = r->val;
        }
        cv(r->left, t, m, v);
    }
    else
    {
        x = -x;
        if (*m > x)
        {
            *m = x;
            *v = r->val;
        }
        cv(r->right, t, m, v);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int closestValue(struct TreeNode* root, double target)
{
    if (!root)
        return 0;

    int v = root->val;
    double min = root->val - target;
    min = min < 0.0 ? -min : min;
    cv(root, target, &min, &v);
    return v;
}
