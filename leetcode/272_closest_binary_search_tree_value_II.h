void ckv_l(struct TreeNode* t, int* r, int* i, int k, double n, bool* done)
{
    if (*done)
        return;

    if (t->left)
        ckv_l(t->left, r, i, k, n, done);

    int in = *i;

    (*i) ++;

    if (in < k)
        r[in] = t->val;
    else
    {
        in %= k;

        double f = fabs(n - (double)r[in]);
        double p = fabs((double) t->val - n);

        if (p > f)
        {
            *done = true;
            return;
        }
        r[in] = t->val;
    }

    if (t->right)
        ckv_l(t->right, r, i, k, n, done);
}

void ckv_r(struct TreeNode* t, int* r, int* i, int k, double n, bool* done)
{
    if (*done)
        return;

    if (t->right)
        ckv_r(t->right, r, i, k, n, done);

    int in = *i;

    (*i) ++;

    if (in < k)
        r[in] = t->val;
    else
    {
        in %= k;
        double f = fabs(n - (double)r[in]);
        double p = fabs((double) t->val - n);

        if (p > f)
        {
            *done = true;
            return;
        }
        r[in] = t->val;
    }

    if (t->left)
        ckv_r(t->left, r, i, k, n, done);
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
int* closestKValues(struct TreeNode* root, double target, int k, int* returnSize)
{
    *returnSize = k;
    if (!k)
        return NULL;

    struct TreeNode* t = root;
    while (t->left)
        t = t->left;
    int lv = t->val;

    t = root;
    while (t->right)
        t = t->right;
    int rv = t->val;

    double f = fabs(target - lv);
    double p = fabs(rv - target);

    bool done = false;
    int i = 0;
    int* r = malloc(sizeof(int) * k);

    if (f < p)
        ckv_l(root, r, &i, k, target, &done);
    else
        ckv_r(root, r, &i, k, target, &done);

    return r;
}
