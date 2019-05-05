void invert(struct TreeNode* h)
{
    if (!h)
        return;

    struct TreeNode* t = h->right;
    h->right = h->left;
    h->left = t;

    invert(h->right);
    invert(h->left);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root)
{
    invert(root);
    return root;
}
