void udbt(struct TreeNode* r, struct TreeNode* l, struct TreeNode** n)
{
    if (r->left)
    {
        udbt(r->left, r, n);
        r->left->left = r->right;
    }
    else if (!*n)
        *n = r;
    r->right = l;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* upsideDownBinaryTree(struct TreeNode* root)
{
    if (!root)
        return NULL;

    struct TreeNode* node = NULL;
    udbt(root, NULL, &node);
    root->left = NULL;
    return node;
}
