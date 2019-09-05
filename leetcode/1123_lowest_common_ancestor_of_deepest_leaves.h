/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int lca(struct TreeNode* o, struct TreeNode** c, int n, int* s)
{
    int l = n;
    int r = n;

    if (o->left)
        l = lca(o->left, c, n + 1, s);
    if (o->right)
        r = lca(o->right, c, n + 1, s);

    if (l == r)
    {
        if (*s <= l)
        {
            *s = l;
            *c = o;
        }
    }
    return l > r ? l : r;
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
{
    int s = -1;
    struct TreeNode* r = NULL;
    lca(root, &r, 0, &s);
    return r;
}
