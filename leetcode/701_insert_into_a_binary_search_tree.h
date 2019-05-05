/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void insert(struct TreeNode** r, int v)
{
    if (!(*r))
    {
        struct TreeNode* n = malloc(sizeof(struct TreeNode));
        n->val = v;
        n->left = n->right = NULL;
        *r = n;
        return;
    }

    if ((*r)->val > v)
        insert(&((*r)->left), v);
    else
        insert(&((*r)->right), v);
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    insert(&root, val);
    return root;
}
