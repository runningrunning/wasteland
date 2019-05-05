/* CAREFUL ! do not use itself !!! */
bool fbt(struct TreeNode* r, int k)
{
    if (k == r->val)
        return true;

    if (k < r->val)
        return r->left && fbt(r->left, k);

    return r->right && fbt(r->right, k);
}

bool ft(struct TreeNode* r, int k, struct TreeNode* or, int min, int max)
{
    int n = k - r->val;
    if (n >= min && n <= max && n != r->val)
    {
        if (n == min || n == max)
            return true;

        if (fbt(or, n))
            return true;
    }

    if (r->left && ft(r->left, k, or, min, max))
        return true;

    return r->right && ft(r->right, k, or, min, max);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool findTarget(struct TreeNode* root, int k)
{
    if (!root)
        return false;

    struct TreeNode* l = root;
    while(l->left)
        l = l->left;

    struct TreeNode* r = root;
    while(r->right)
        r = r->right;

    if ((k <= l->val * 2) || (k >= r->val * 2))
        return false;
    return ft(root, k, root, l->val, r->val);
}
