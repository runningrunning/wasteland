// be careful use ***
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void _ibst(struct TreeNode*** r, struct TreeNode* n)
{
    if (!n)
        return;
    _ibst(r, n->left);
    (**r) = n;
    n->left = NULL;
    (*r) = &(n->right);
    _ibst(r, n->right);
}

struct TreeNode* increasingBST(struct TreeNode* root)
{
    struct TreeNode* r = NULL;
    struct TreeNode** pr = &r;
    _ibst(&pr, root);
    return r;
}
