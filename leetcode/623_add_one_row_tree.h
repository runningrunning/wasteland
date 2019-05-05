void aor(struct TreeNode* r, struct TreeNode** p, bool left, int v, int d, int l)
{
    if (d == l)
    {
        struct TreeNode* n = malloc(sizeof(struct TreeNode));
        n->val = v;
        n->right = NULL;
        n->left = NULL;

        if (left)
            n->left = r;
        else
            n->right = r;

        *p = n;
    }
    else if (r)
    {
        aor(r->left, &r->left, true, v, d,  l + 1);
        aor(r->right, &r->right, false, v, d, l + 1);
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
struct TreeNode* addOneRow(struct TreeNode* root, int v, int d)
{
    if (!root)
        return NULL;
    struct TreeNode* r = root;
    aor(root, &r, true, v, d, 1);
    return r;
}
