void _flatten(struct TreeNode* r, struct TreeNode*** l)
{
    if (r->left)
        _flatten(r->left, l);
    else
        *l = &r->left;

    if (r->right)
    {
        **l = r->right;
        *l = NULL;
        r->right = NULL;
        _flatten(r->left, l);
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
void flatten(struct TreeNode* root)
{
    if (!root)
        return;

    struct TreeNode** n = NULL;
    _flatten(root, &n);

    while(root->left)
    {
        root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
    return;
}
