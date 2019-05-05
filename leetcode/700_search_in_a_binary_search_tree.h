/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void sbst(struct TreeNode* r, int v, struct TreeNode** e)
{
    if (!r)
    {
        *e = NULL;
        return;
    }

    if (r->val == v)
    {
        *e = r;
        return;
    }

    if (r->val > v)
        sbst(r->left, v, e);
    else
        sbst(r->right, v, e);
}

struct TreeNode* searchBST(struct TreeNode* root, int val)
{
    struct TreeNode* r = NULL;
    sbst(root, val, &r);
    return r;
}
