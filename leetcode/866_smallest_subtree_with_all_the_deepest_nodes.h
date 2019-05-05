int swad(struct TreeNode* r, int c, struct TreeNode** n)
{
    if (!r->left && !r->right)
    {
        *n = r;
        return c;
    }

    int li = 0;
    struct TreeNode* ln = r->left;
    if (r->left)
        li = swad(r->left, c + 1, &ln);

    int ri = 0;
    struct TreeNode* rn = r->right;
    if (r->right)
        ri = swad(r->right, c + 1, &rn);

    if (ri == li)
    {
        *n = r;
        return ri;
    }

    if (ri > li)
    {
        *n = rn;
        return ri;
    }

    *n = ln;
    return li;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root)
{
    struct TreeNode* t = NULL;
    swad(root, 0, &t);
    return t;
}
