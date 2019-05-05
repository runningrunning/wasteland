/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool pt(struct TreeNode* r)
{
    if (!r)
        return true;

    bool le = pt(r->left);
    bool ri = pt(r->right);

    if (le)
        r->left = NULL;
    if (ri)
        r->right = NULL;

    if (le && ri)
        return r->val == 0;

    return false;
}

struct TreeNode* pruneTree(struct TreeNode* root) {
    pt(root);
    return root;
}
