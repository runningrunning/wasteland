/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
{
    if (!root || root->val < val)
    {
        struct TreeNode* r = malloc(sizeof(struct TreeNode));
        r->val = val;
        r->left = r->right = NULL;
        if (root)
            r->left = root;
        return r;
    }
    root->right = insertIntoMaxTree(root->right, val);
    return root;
}
